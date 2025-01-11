/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:38:53 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/25 16:04:44 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"
// clang-format off

int	main(int argc, char **argv)
{
	if (is_valid_input(argc, argv) != 0)
	{
		print_valid_example();
		return (1);
	}
	if (init_and_run(argc, argv) != 0)
		return (1);
	return (0);
}
