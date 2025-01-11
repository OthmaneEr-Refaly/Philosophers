/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:52:41 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:17:28 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

int	init_forks(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = data->philos;
	i = -1;
	while (++i < data->number_of_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].left_fork = &data->forks[0];
	philos[0].right_fork = &data->forks[data->number_of_philos - 1];
	while (++i < data->number_of_philos)
	{
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	while (++i < data->number_of_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mutex_state, NULL);
		pthread_mutex_init(&philos[i].mutex_nbr_meals_had, NULL);
		pthread_mutex_init(&philos[i].mutex_last_eat_time, NULL);
		last_meal_time_update(&philos[i]);
	}
	return (0);
}
