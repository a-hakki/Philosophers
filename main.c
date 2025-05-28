/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:13:08 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/28 12:14:00 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void *f1(void *vars)
{
	t_vars *args = (t_vars *)vars;
	int i = 0;
	while (1)
	{
		pthread_mutex_lock(&args->mut);
		args->eat_time++;
		pthread_mutex_unlock(&args->mut);
		
		i++;
		if (i == 1000000)
			break;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_vars vars;
	vars.philo_n = 4;
	vars.sleep_time = 200;
	vars.die_time = 500;
	vars.eat_time = 0;
	vars.boul = 1;
	pthread_mutex_init(&vars.mut, NULL);

	pthread_t t1, t2;
	pthread_create(&t1, NULL, f1, &vars);
	pthread_create(&t2, NULL, f1, &vars);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("%d\n", vars.eat_time);
	pthread_mutex_destroy(&vars.mut);
	return 0;
}
