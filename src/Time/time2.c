/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:21:07 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:21:24 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

uint64_t	get_eat_time(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&data->mutex_eat_time);
	eat_time = data->time_to_eat;
	pthread_mutex_unlock(&data->mutex_eat_time);
	return (eat_time);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mutex_start_time);
	time = data->start_time;
	pthread_mutex_unlock(&data->mutex_start_time);
	return (time);
}

uint64_t	get_die_time(t_data *data)
{
	uint64_t	die_time;

	pthread_mutex_lock(&data->mutex_die_time);
	die_time = data->time_to_die;
	pthread_mutex_unlock(&data->mutex_die_time);
	return (die_time);
}
