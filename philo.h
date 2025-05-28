#ifndef PHILO_H
# define PHILO_H


# include <stdio.h>
# include <pthread.h>


typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long			last_meal;
	int				meal_count;
	struct s_rules	*rules;
}		t_philo;

typedef struct s_rules
{
	int				philo_n;
	int				sleep_time;
	int				die_time;
	int				eat_time;
	int				meal_n;
	t_philo			*philos;
	pthread_mutex_t	mut;
	pthread_mutex_t	*forks;
	pthread_mutex_t print_mutex;
}		t_rules;


// typedef struct s_vars {
// 	int philo_n;
// 	int sleep_time;
// 	int die_time;
// 	int eat_time;
// 	int boul;
// 	pthread_mutex_t mut;
// }		t_vars;

#endif