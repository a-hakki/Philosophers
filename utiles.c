/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:02:04 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 15:03:37 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (time < 0)
		return (1);
	return (time);
}

void	free_all(t_rules *rules)
{
	int	i;

	if (rules->forks)
	{
		i = 0;
		while (i < rules->philo_n)
		{
			pthread_mutex_destroy(&rules->forks[i]);
			i++;
		}
		free(rules->forks);
	}
	pthread_mutex_destroy(&rules->print_mutex);
	pthread_mutex_destroy(&rules->meal_check);
	if (rules->philos)
		free(rules->philos);
}

int	parse_args(t_rules *rules, char **av, int ac)
{
	rules->philo_n = atoi(av[1]);
	rules->die_time = atoi(av[2]);
	rules->eat_time = atoi(av[3]);
	rules->sleep_time = atoi(av[4]);
	rules->meal_n = -1;
	if (ac == 6)
		rules->meal_n = atoi(av[5]);
	if (rules->philo_n <= 0 || rules->die_time <= 0 || \
		rules->eat_time <= 0 || rules->sleep_time <= 0)
		return (0);
	if (ac == 6 && rules->meal_n <= 0)
		return (0);
	return (1);
}
