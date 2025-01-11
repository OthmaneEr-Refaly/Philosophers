/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:21:40 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 21:01:44 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nbr_meals_philo_had(philo) >= data->number_of_meals)
		result = true;
	return (result);
}

bool	nbr_meals_option(t_data *data)
{
	if (data->number_of_meals > 0)
		return (true);
	return (false);
}

int	active_threads(t_data *data)
{
	int	i;
	int	nbr_of_philos;

	nbr_of_philos = get_nbr_of_philos(data);
	i = -1;
	data->start_time = get_time();
	while (++i < nbr_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL, &routine,
				&data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL, &all_alive_routine, data))
		return (1);
	if (nbr_meals_option(data) == true && pthread_create(&data->monit_all_full,
			NULL, &all_full_routine, data))
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nbr_of_philos(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nbr_meals_option(data) == true && pthread_join(data->monit_all_full,
			NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}
