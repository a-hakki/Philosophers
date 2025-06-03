/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:07:10 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 15:17:26 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead_or_full(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->rules->meal_check);
	result = (philo->rules->someone_died || philo->rules->all_ate_enough);
	pthread_mutex_unlock(&philo->rules->meal_check);
	return (result);
}

void	smart_sleep(long duration_ms, t_philo *philo)
{
	long	start;

	start = get_time();
	while (!is_dead_or_full(philo) && (get_time() - start) < duration_ms)
	{
		if (philo->rules->philo_n < 100)
			usleep(500);
		else
			usleep(5 * philo->rules->philo_n);
	}
}

void	ft_unlock_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->rules->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->rules->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->rules->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->rules->forks[philo->right_fork]);
	}
}

int	ft_lock_fork(t_philo *philo)
{
	if (is_dead_or_full(philo))
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork]);
		log_status(philo, IS_T_FORK);
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork]);
		log_status(philo, IS_T_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork]);
		log_status(philo, IS_T_FORK);
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork]);
		log_status(philo, IS_T_FORK);
	}
	if (is_dead_or_full(philo))
	{
		ft_unlock_fork(philo);
		return (0);
	}
	return (1);
}
