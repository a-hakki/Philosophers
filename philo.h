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
	int             id;
	int             left_fork;
	int             right_fork;
	int             meal_count;
	long            last_meal;
	long            start_time;
	struct s_rules   *rules;
} t_philo;

typedef struct s_rules
{
	// long            start_time;
	int             philo_n;
	int             die_time;
	int             eat_time;
	int             sleep_time;
	int             meal_n;
	int             someone_died;
	int             all_ate_enough;
	int				philo_die;
	long			philo_time_die;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
	pthread_mutex_t meal_check;
	t_philo         *philos;
} t_rules;

#endif