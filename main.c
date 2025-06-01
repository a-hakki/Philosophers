/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:13:08 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/01 15:28:12 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft/libft.h"
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	free_all(t_rules *rules)
{
	int	i;

	if (!rules)
		return ;

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

	free(rules);
}

int parse_args(t_rules *rules, char **av, int ac)
{
	rules->philo_n = ft_atoi(av[1]);
	rules->die_time = ft_atoi(av[2]);
	rules->eat_time = ft_atoi(av[3]);
	rules->sleep_time = ft_atoi(av[4]);
	rules->meal_n = -1;
	if (ac == 6)
		rules->meal_n = ft_atoi(av[5]);
	if (rules->philo_n <= 0 || rules->die_time <= 0 || rules->eat_time <= 0 || rules->sleep_time <= 0)
		return (0);
	if (ac == 6 && rules->meal_n <= 0)
		return (0);
	return (1);
}

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
			return (ft_free("11", rules->forks, rules->philos), 1);
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
		return (ft_free("11", rules->forks, rules->philos), 1);
	if (set_philo_data(rules))
		return (1);
	i = 0;
	if (pthread_mutex_init(&rules->print_mutex, NULL) != 0)
	{
		while (i < rules->philo_n)
			pthread_mutex_destroy(&rules->forks[i++]);
		return (ft_free("11", rules->forks, rules->philos), 1);
	}
	// Initialize meal_check mutex
	if (pthread_mutex_init(&rules->meal_check, NULL) != 0)
	{
		pthread_mutex_destroy(&rules->print_mutex);
		while (i < rules->philo_n)
			pthread_mutex_destroy(&rules->forks[i++]);
		return (ft_free("11", rules->forks, rules->philos), 1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	return ;
}

void	*routine(void *arg)
{
	return ;
}

int start_simulation(t_rules *rules)
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
		rules->philos[i].last_meal = get_time();
		if (pthread_create(&threads[i], NULL, routine, &rules->philos[i]) != 0)
			return (free(threads), 1);
		i++;
	}

	if (pthread_create(&monitor_thread, NULL, monitor, rules) != 0)
		return (free(threads), 1);

	i = 0;
	while (i < rules->philo_n)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);

	free(threads);
	return (0);
}

int main(int ac, char **av)
{
	t_rules *rules;

	if (ac < 5 || ac > 6)
		return (printf("arg required -> number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_meals]\n"));
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (printf("malloc failed\n"));
	if (!parse_args(rules, av, ac))
		return (printf("Invalid args\n"), printf("Initialization failed\n"), 1);
	if (init_philosophers(rules))
		return (free(rules), 1);
	if (start_simulation(rules))
		return (free_all(rules), 1);
	free_all(rules);
	return (0);
}
