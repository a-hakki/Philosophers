#ifndef PHILO_H
# define PHILO_H


# include <stdio.h>
# include <pthread.h>


typedef struct s_philo
{
	int philo_n;
	int sleep_time;
	int die_time;
	int eat_time;
	int boul;
	pthread_mutex_t mut;
}		t_philo;

typedef struct s_vars {
	int philo_n;
	int sleep_time;
	int die_time;
	int eat_time;
	int boul;
	pthread_mutex_t mut;
}		t_vars;

#endif