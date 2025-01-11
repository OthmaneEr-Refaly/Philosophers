/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_s2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:57:52 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 20:58:50 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

int	get_nbr_meals_philo_had(t_philo *philo)
{
	int	nbr_meals_had;

	pthread_mutex_lock(&philo->mutex_nbr_meals_had);
	nbr_meals_had = philo->meals_eaten;
	pthread_mutex_unlock(&philo->mutex_nbr_meals_had);
	return (nbr_meals_had);
}
