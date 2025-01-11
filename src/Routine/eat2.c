/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:22:42 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:23:05 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

bool	is_philo_died(t_philo *philo)
{
	bool	result;
	t_data	*data;

	data = philo->data;
	result = false;
	if (get_time() - get_last_eat_time(philo) > get_die_time(data)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}

int	take_left_fork(t_philo *philo)
{
	if (is_philo_died(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	only_one_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, DEAD);
	return (1);
}

int	take_right_fork(t_philo *philo)
{
	if (is_philo_died(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_fork);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}
