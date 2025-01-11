/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:13:45 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 21:02:16 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

void	notify_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nbr_philos;

	nbr_philos = get_nbr_of_philos(data);
	philos = data->philos;
	i = -1;
	while (++i < nbr_philos)
		set_philo_state(&philos[i], DEAD);
}

void	*all_alive_routine(void *data_p)
{
	int		i;
	int		nbr_philos;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	nbr_philos = get_nbr_of_philos(data);
	i = -1;
	while (++i < nbr_philos && get_keep_iter(data))
	{
		if (is_philo_died(&philos[i]) && get_keep_iter(data))
		{
			print_msg(data, philos[i].id, DIED);
			set_keep_iterating(data, false);
			notify_all_philos(data);
			break ;
		}
		if (i == nbr_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	data = (t_data *)data_p;
	i = -1;
	nb_philos = get_nbr_of_philos(data);
	while (++i < nb_philos && get_keep_iter(data))
	{
		usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false)
			i = -1;
	}
	if (get_keep_iter(data) == true)
	{
		set_keep_iterating(data, false);
		notify_all_philos(data);
	}
	return (NULL);
}

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	last_meal_time_update(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}
