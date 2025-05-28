/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:13:08 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/28 22:30:44 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft/libft.h"

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

int	init_philosophers(t_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->philo_n);
	if (!rules->forks)
		return (1);
	i = 0;
	while (i < rules->philo_n)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	rules->philos = malloc(sizeof(t_philo) * rules->philo_n);
	if (!rules->philos)
		return (free(rules->forks), 1);
	i = 0;
	while (i < rules->philo_n)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].left_fork = i;
		rules->philos[i].right_fork = (i + 1) % rules->philo_n;
		rules->philos[i].meal_count = 0;
		rules->philos[i].last_meal = 0;
		rules->philos[i].rules = rules;
		i++;
	}
	pthread_mutex_init(&rules->print_mutex, NULL);
	return (0);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	t_rules *rules;
	if (ac < 5 || ac > 6)
		return (printf("arg requared -> number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_meals]\n"));
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (printf("malloc failed\n"));
	if (!parse_args(rules, av, ac))
		return (printf("Invalid args\n"), printf("Initialization failed\n"), 1);
	if (init_philosophers(rules))
		return (free(rules), 1);
	for (int i = 0; i < rules->philo_n; i++)
		printf("Philo %d forks (%d, %d)\n", rules->philos[i].id, rules->philos[i].left_fork, rules->philos[i].right_fork);
	free(rules->forks);
	free(rules->philos);
	return (free(rules), 0);
}
