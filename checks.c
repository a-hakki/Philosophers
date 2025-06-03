/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:08:15 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 14:57:20 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_is_die(t_rules *rules)
{
	int		i;
	long	now;
	long	time_diff;

	now = get_time();
	i = 0;
	while (i < rules->philo_n)
	{
		pthread_mutex_lock(&rules->meal_check);
		time_diff = now - rules->philos[i].last_meal;
		if (time_diff > rules->die_time && !rules->someone_died)
		{
			rules->someone_died = 1;
			pthread_mutex_unlock(&rules->meal_check);
			pthread_mutex_lock(&rules->print_mutex);
			rules->philo_die = rules->philos[i].id;
			rules->philo_time_die = get_time() - rules->philos->start_time;
			pthread_mutex_unlock(&rules->print_mutex);
			return ;
		}
		pthread_mutex_unlock(&rules->meal_check);
		i++;
	}
}

void	check_is_full(t_rules *rules)
{
	int	i;
	int	full;

	if (rules->meal_n <= 0)
		return ;
	full = 0;
	i = 0;
	while (i < rules->philo_n)
	{
		pthread_mutex_lock(&rules->meal_check);
		if (rules->philos[i].meal_count >= rules->meal_n)
			full++;
		pthread_mutex_unlock(&rules->meal_check);
		i++;
	}
	if (full == rules->philo_n && !rules->all_ate_enough)
	{
		pthread_mutex_lock(&rules->meal_check);
		rules->all_ate_enough = 1;
		pthread_mutex_unlock(&rules->meal_check);
	}
}
