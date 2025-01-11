/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:39:53 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:21:20 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t	last_eat_time;

	pthread_mutex_lock(&philo->mutex_last_eat_time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mutex_last_eat_time);
	return (last_eat_time);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	last_meal_time_update(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_last_eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mutex_last_eat_time);
}
