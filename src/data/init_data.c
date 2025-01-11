/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:52 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:16:48 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

int	malloc_data(t_data *data)
{
	data->philos = ft_malloc(sizeof(t_philo) * data->number_of_philos, 'm');
	if (data->philos == NULL)
		return (1);
	data->forks = ft_malloc(sizeof(pthread_mutex_t) * data->number_of_philos,
			'm');
	if (data->forks == NULL)
		return (ft_malloc(0, 'f'), 1);
	data->philo_ths = ft_malloc(sizeof(pthread_t) * data->number_of_philos,
			'm');
	if (data->philo_ths == NULL)
		return (ft_malloc(0, 'f'), 1);
	return (0);
}

void	pthreads_init(t_data *data)
{
	pthread_mutex_init(&data->mutex_sleep_time, NULL);
	pthread_mutex_init(&data->mutex_eat_time, NULL);
	pthread_mutex_init(&data->mutex_die_time, NULL);
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_number_of_philos, NULL);
	pthread_mutex_init(&data->mutex_keep_iter, NULL);
	pthread_mutex_init(&data->mutex_start_time, NULL);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nbr_full_philos = 0;
	data->keep_iterating = true;
	data->number_of_meals = -1;
	if (argc == 6)
		data->number_of_meals = ft_atoi(argv[5]);
	pthreads_init(data);
	return (malloc_data(data));
}

void	free_data(t_data *data)
{
	ft_malloc(0, 'f');
}

/*
! "init_and_run" init the data and the philos and forks
!then run threads and then join them
!(./philo 4 800 200 200 5)
*/
int	init_and_run(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) != 0)
		return (1);
	init_philos(&data);
	init_forks(&data);
	active_threads(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}
