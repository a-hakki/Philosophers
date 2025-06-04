/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:05:11 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 15:16:36 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_helper(t_philo *philo)
{
	if (is_dead_or_full(philo))
		return ;
	if (!ft_lock_fork(philo))
		return ;
	if (is_dead_or_full(philo))
	{
		pthread_mutex_unlock(&philo->rules->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->rules->forks[philo->left_fork]);
		return ;
	}
	log_status(philo, IS_EAT);
	smart_sleep(philo->rules->eat_time, philo);
	pthread_mutex_lock(&philo->rules->meal_check);
	philo->last_meal = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->rules->meal_check);
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork]);
	if (is_dead_or_full(philo))
		return ;
	log_status(philo, IS_SLP);
	smart_sleep(philo->rules->sleep_time, philo);
	if (is_dead_or_full(philo))
		return ;
	log_status(philo, IS_TNK);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
	{
		if (philo->rules->philo_n < 100)
			usleep(1000);
		else
			usleep(10 * philo->rules->philo_n);
	}
	while (1)
	{
		if (is_dead_or_full(philo))
			break ;
		routine_helper(philo);
		if (philo->rules->philo_n < 100)
			usleep(1000);
		else
			usleep(10 * philo->rules->philo_n);
	}
	return (NULL);
}

int	start_simulation(t_rules *rules)
{
	pthread_t	*threads;
	pthread_t	monitor_thread;
	int			i;

	threads = malloc(sizeof(pthread_t) * rules->philo_n);
	if (!threads)
		return (1);
	i = 0;
	rules->someone_died = 0;
	rules->all_ate_enough = 0;
	while (i < rules->philo_n)
	{
		rules->philos[i].start_time = get_time();
		rules->philos[i].last_meal = get_time();
		if (pthread_create(&threads[i], NULL, routine, &rules->philos[i]) != 0)
			return (free(threads), 1);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor, rules) != 0)
		return (free(threads), 1);
	i = 0;
	while (i < rules->philo_n)
		pthread_join(threads[i++], NULL);
	pthread_join(monitor_thread, NULL);
	return (free(threads), 0);
}
