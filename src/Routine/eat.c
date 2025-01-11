/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:17:55 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:22:57 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

int	take_forks(t_philo *philo)
{
	if (get_nbr_of_philos(philo->data) == 1)
		return (only_one_philo(philo));
	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		drop_right_fork(philo);
		return (1);
	}
	return (0);
}

void	sleep_while_eating(t_philo *philo)
{
	ft_usleep(get_eat_time(philo->data));
}

void	update_nbr_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_nbr_meals_had);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_nbr_meals_had);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	print_msg(philo->data, philo->id, EAT);
	last_meal_time_update(philo);
	sleep_while_eating(philo);
	update_nbr_meals_had(philo);
	drop_forks(philo);
	return (0);
}
