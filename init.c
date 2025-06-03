/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:03:53 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 15:16:18 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_philo_data(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philo_n)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&rules->forks[i]);
			return (free(rules->forks), free(rules->philos), 1);
		}
		rules->philos[i].id = i + 1;
		rules->philos[i].left_fork = i;
		rules->philos[i].right_fork = (i + 1) % rules->philo_n;
		rules->philos[i].meal_count = 0;
		rules->philos[i].last_meal = 0;
		rules->philos[i].rules = rules;
		i++;
	}
	return (0);
}

int	init_philosophers(t_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->philo_n);
	if (!rules->forks)
		return (1);
	rules->philos = malloc(sizeof(t_philo) * rules->philo_n);
	if (!rules->philos)
		return (free(rules->forks), free(rules->philos), 1);
	if (set_philo_data(rules))
		return (1);
	i = 0;
	if (pthread_mutex_init(&rules->print_mutex, NULL) != 0)
	{
		while (i < rules->philo_n)
			pthread_mutex_destroy(&rules->forks[i++]);
		return (free(rules->forks), free(rules->philos), 1);
	}
	if (pthread_mutex_init(&rules->meal_check, NULL) != 0)
	{
		pthread_mutex_destroy(&rules->print_mutex);
		while (i < rules->philo_n)
			pthread_mutex_destroy(&rules->forks[i++]);
		return (free(rules->forks), free(rules->philos), 1);
	}
	return (0);
}
