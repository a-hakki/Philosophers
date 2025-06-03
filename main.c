/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:13:08 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 22:25:56 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	if (is_dead_or_full(philo))
	{
		pthread_mutex_unlock(&philo->rules->print_mutex);
		return ;
	}
	printf("%ld %d %s\n", get_time() - philo->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}

void	*monitor(void *arg)
{
	t_rules	*rules;

	rules = (t_rules *)arg;
	while (1)
	{
		pthread_mutex_lock(&rules->meal_check);
		if (rules->someone_died || rules->all_ate_enough)
		{
			pthread_mutex_unlock(&rules->meal_check);
			break ;
		}
		pthread_mutex_unlock(&rules->meal_check);
		check_is_die(rules);
		check_is_full(rules);
		usleep(100 * rules->philo_n);
	}
	return (NULL);
}

void	*ft_philo_one(t_rules *rules)
{
	rules->all_ate_enough = 0;
	rules->someone_died = 0;
	rules->philos[0].start_time = get_time();
	pthread_mutex_lock(rules->forks);
	log_status(rules->philos, "has taken a fork");
	pthread_mutex_unlock(rules->forks);
	usleep(rules->die_time * 1000);
	log_status(rules->philos, "died");
	return (NULL);
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac < 5 || ac > 6)
		return (printf("arg required -> number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_meals]\n"));
	if (!parse_args(&rules, av, ac))
		return (printf("Invalid args\n"), printf("Initialization failed\n"), 1);
	if (init_philosophers(&rules))
		return (1);
	if (rules.philo_n == 1)
		ft_philo_one(&rules);
	else if (start_simulation(&rules))
		return (free_all(&rules), 1);
	if (rules.someone_died)
	{
		printf("%ld %d died\n", rules.philo_time_die, rules.philo_die);
	}
	free_all(&rules);
	return (0);
}
