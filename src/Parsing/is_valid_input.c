/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:01:32 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:19:58 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/philo.h"

// input valid example ==> ./philo 4 800 200 200 5.

void	print_valid_example(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("./philo nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat ");
	printf("(optional argument)\n");
	printf("Example:\n\n");
	printf("./philo 4 800 200 200 5\n\n");
	printf("nb_philos: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("number_of_times_each_philosopher_must_eat: ");
	printf("0+\n");
}
/*
! "wrong_input_check" Check if the input is number :
!input example (./philo 4 800 200 200 5)
*check if the last number is  0 or less then 0
*check the number of philosophers is between 1 and 200
*check if the time to die, eat and sleep is 60 or more
*/

int	wrong_input_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 2;
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (1);
	else if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (1);
	while (i < 5)
	{
		if (ft_atoi(argv[i]) < 60)
			return (1);
		i++;
	}
	return (0);
}

int	check_if_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
! "is_valid_input" Check if the input is valid :
!input example (./philo 4 800 200 200 5)
*check if the number of arguments is correct "argc and argv"
*check if the arguments are numbers
*check if its wrong input
*/

int	is_valid_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		print_valid_example();
		return (1);
	}
	if (check_if_digit(argc, argv) != 0)
	{
		print_valid_example();
		return (1);
	}
	if (wrong_input_check(argc, argv) != 0)
	{
		print_valid_example();
		return (1);
	}
	return (0);
}

//./philo 3 400 200 200 5
