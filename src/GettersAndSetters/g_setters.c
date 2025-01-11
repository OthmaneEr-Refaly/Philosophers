/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_setters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:51:57 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 02:50:01 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

void	set_keep_iterating(t_data *data, bool set_to)
{
	pthread_mutex_lock(&data->mutex_keep_iter);
	data->keep_iterating = set_to;
	pthread_mutex_unlock(&data->mutex_keep_iter);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mutex_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mutex_state);
	return (state);
}

bool	get_keep_iter(t_data *data)
{
	bool	keep_iterating;

	pthread_mutex_lock(&data->mutex_keep_iter);
	keep_iterating = data->keep_iterating;
	pthread_mutex_unlock(&data->mutex_keep_iter);
	return (keep_iterating);
}

int	get_nbr_of_philos(t_data *data)
{
	int	nbr_philos;

	pthread_mutex_lock(&data->mutex_number_of_philos);
	nbr_philos = data->number_of_philos;
	pthread_mutex_unlock(&data->mutex_number_of_philos);
	return (nbr_philos);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mutex_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mutex_state);
}
