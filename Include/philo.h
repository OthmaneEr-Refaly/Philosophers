/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:37:54 by oer-refa          #+#    #+#             */
/*   Updated: 2024/12/26 22:51:33 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	THINKING = 0,
	SLEEPING = 1,
	EATING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}					t_state;

struct	s_data;

typedef struct s_malloc
{
	void			*data;
	struct s_malloc	*next;
}					t_malloc;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex_nbr_meals_had;
	pthread_mutex_t	mutex_last_eat_time;
	pthread_mutex_t	mutex_state;
	u_int64_t		last_eat_time;
}					t_philo;

typedef struct s_data
{
	bool			keep_iterating;
	int				number_of_philos;
	int				nbr_full_philos;
	int				number_of_meals;
	u_int64_t		start_time;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_die;
	u_int64_t		time_to_sleep;
	pthread_mutex_t	mutex_sleep_time;
	pthread_mutex_t	mutex_eat_time;
	pthread_mutex_t	mutex_think;
	pthread_mutex_t	mutex_die_time;
	pthread_mutex_t	mutex_number_of_philos;
	pthread_mutex_t	mutex_start_time;
	pthread_mutex_t	mutex_keep_iter;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	pthread_t		*philo_ths;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	t_philo			*philos;
}					t_data;

/*
!=======Function==========

^=======Declare===========
*/
int					is_valid_input(int argc, char **argv);
int					check_if_digit(int argc, char **argv);
void				print_valid_example(void);
int					check_if_digit(int argc, char **argv);
void				last_meal_time_update(t_philo *philo);
void				*ft_malloc(size_t size, char f_or_m);
int					init_and_run(int argc, char **argv);
int					ft_atoi(char *str);
int					init_philos(t_data *data);
int					init_forks(t_data *data);
int					active_threads(t_data *data);
int					get_nbr_of_philos(t_data *data);
t_state				get_philo_state(t_philo *philo);
int					take_forks(t_philo *philo);
int					eat(t_philo *philo);
u_int64_t			get_time(void);
void				last_meal_time_update(t_philo *philo);
void				ft_usleep(uint64_t sleep_time);
void				*routine(void *philo_p);
uint64_t			get_die_time(t_data *data);
uint64_t			get_last_eat_time(t_philo *philo);
uint64_t			get_start_time(t_data *data);
void				print_msg(t_data *data, int id, char *msg);
bool				get_keep_iter(t_data *data);
void				set_philo_state(t_philo *philo, t_state state);
void				sleep_while_eating(t_philo *philo);
uint64_t			get_eat_time(t_data *data);
int					ft_sleep(t_philo *philo);
int					think(t_philo *philo);
void				*all_alive_routine(void *data_p);
void				set_keep_iterating(t_data *data, bool set_to);
bool				is_philo_died(t_philo *philo);
int					think(t_philo *philo);
void				notify_all_philos(t_data *data);
int					join_threads(t_data *data);
void				*all_full_routine(void *data_p);
int					get_nbr_meals_philo_had(t_philo *philo);
bool				is_philo_full(t_data *data, t_philo *philo);
int					take_forks(t_philo *philo);
int					only_one_philo(t_philo *philo);
int					take_right_fork(t_philo *philo);
int					take_left_fork(t_philo *philo);
void				drop_right_fork(t_philo *philo);

#endif
