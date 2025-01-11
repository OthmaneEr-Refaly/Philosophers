/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:01:11 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:24:05 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

void	print_msg(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mutex_print);
	if (get_keep_iter(data))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mutex_print);
}
