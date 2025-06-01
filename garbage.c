
// void	*monitor(void *arg)
// {
// 	t_rules *rules = (t_rules *)arg;
// 	int i;
// 	long now;

// 	while (1)
// 	{
// 		i = 0;
// 		while (i < rules->philo_n)
// 		{
// 			pthread_mutex_lock(&rules->meal_check);
// 			now = get_time();
// 			if ((now - rules->philos[i].last_meal) > rules->die_time)
// 			{
// 				pthread_mutex_lock(&rules->print_mutex);
// 				printf("%ld %d died\n", now, rules->philos[i].id);
// 				pthread_mutex_unlock(&rules->print_mutex);
// 				rules->someone_died = 1;
// 				pthread_mutex_unlock(&rules->meal_check);
// 				return (NULL);
// 			}
// 			pthread_mutex_unlock(&rules->meal_check);
// 			i++;
// 		}

// 		if (rules->meal_n > 0)
// 		{
// 			int all_done = 1;
// 			pthread_mutex_lock(&rules->meal_check);
// 			for (i = 0; i < rules->philo_n; i++)
// 			{
// 				if (rules->philos[i].meal_count < rules->meal_n)
// 				{
// 					all_done = 0;
// 					break;
// 				}
// 			}
// 			if (all_done)
// 				rules->all_ate_enough = 1;
// 			pthread_mutex_unlock(&rules->meal_check);

// 			if (all_done)
// 				return (NULL);
// 		}

// 		usleep(1000);
// 	}
// }

// void	*routine(void *arg)
// {
// 	t_philo	*philo = (t_philo *)arg;
// 	t_rules *rules = philo->rules;

// 	if (philo->id % 2 == 0)
// 		usleep(1000);

// 	while (1)
// 	{
// 		pthread_mutex_lock(&rules->meal_check);
// 		if (rules->someone_died || rules->all_ate_enough)
// 		{
// 			pthread_mutex_unlock(&rules->meal_check);
// 			break ;
// 		}
// 		pthread_mutex_unlock(&rules->meal_check);

// 		// Take forks
// 		pthread_mutex_lock(&rules->forks[philo->left_fork]);
// 		pthread_mutex_lock(&rules->print_mutex);
// 		printf("%ld %d has taken a fork\n", get_time(), philo->id);
// 		pthread_mutex_unlock(&rules->print_mutex);

// 		pthread_mutex_lock(&rules->forks[philo->right_fork]);
// 		pthread_mutex_lock(&rules->print_mutex);
// 		printf("%ld %d has taken a fork\n", get_time(), philo->id);
// 		pthread_mutex_unlock(&rules->print_mutex);

// 		// Eat
// 		pthread_mutex_lock(&rules->print_mutex);
// 		printf("%ld %d is eating\n", get_time(), philo->id);
// 		pthread_mutex_unlock(&rules->print_mutex);

// 		pthread_mutex_lock(&rules->meal_check);
// 		philo->last_meal = get_time();
// 		philo->meal_count++;
// 		pthread_mutex_unlock(&rules->meal_check);

// 		usleep(rules->eat_time * 1000);

// 		// Put down forks
// 		pthread_mutex_unlock(&rules->forks[philo->left_fork]);
// 		pthread_mutex_unlock(&rules->forks[philo->right_fork]);

// 		// Sleep
// 		pthread_mutex_lock(&rules->print_mutex);
// 		printf("%ld %d is sleeping\n", get_time(), philo->id);
// 		pthread_mutex_unlock(&rules->print_mutex);
// 		usleep(rules->sleep_time * 1000);

// 		// Think
// 		pthread_mutex_lock(&rules->print_mutex);
// 		printf("%ld %d is thinking\n", get_time(), philo->id);
// 		pthread_mutex_unlock(&rules->print_mutex);
// 	}
// 	return (NULL);
// }