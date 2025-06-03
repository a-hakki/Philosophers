/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:00:42 by ahakki            #+#    #+#             */
/*   Updated: 2025/06/03 15:02:38 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define IS_T_FORK "has taken a fork"
# define IS_EAT "is eating"
# define IS_SLP "is sleeping"
# define IS_TNK "is thinking"

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meal_count;
	long			last_meal;
	long			start_time;
	struct s_rules	*rules;
}				t_philo;

typedef struct s_rules
{
	// long			start_time;
	int				philo_n;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meal_n;
	int				someone_died;
	int				all_ate_enough;
	int				philo_die;
	long			philo_time_die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_check;
	t_philo			*philos;
}				t_rules;

long	get_time(void);
void	log_status(t_philo *philo, char *msg);
int		is_dead_or_full(t_philo *philo);
void	check_is_die(t_rules *rules);
void	check_is_full(t_rules *rules);
int		parse_args(t_rules *rules, char **av, int ac);
int		init_philosophers(t_rules *rules);
void	free_all(t_rules *rules);
void	*monitor(void *arg);
int		start_simulation(t_rules *rules);
int		ft_lock_fork(t_philo *philo);
void	ft_unlock_fork(t_philo *philo);
void	smart_sleep(long duration_ms, t_philo *philo);

#endif