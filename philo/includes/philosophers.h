/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:31:06 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/18 09:52:43 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include "utils.h"
# include <stdio.h>
# include <stdbool.h>

# define SLEEPING		"[%ld]\t%d\e[0;32m is sleeping\n\e[0m"
# define EATING			"[%ld]\t%d\e[1;34m is eating\n\e[0m"
# define THINKING		"[%ld]\t%d\e[0;33m is thinking\n\e[0m"
# define GRABBING		"[%ld]\t%d\e[0;35m has taken a fork\n\e[0m"
# define DEAD			"[%ld]\t%d\e[0;31m died\n\e[0m"
# define ERROR_MUTEX	"Error: Mutex failed to init"
# define ERROR_MALLOC	"Error: Failed to allocate memory"
# define ERROR_THREAD	"Error: Failed to create thread"

typedef enum e_state_phil
{
	ACTIVE,
	FINISHED
}			t_state_phil;

typedef struct s_data
{
	int					philo_count;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					amount_of_meals;
	long				start_time;
	t_state_phil		state_main;
	pthread_mutex_t		*fork_locks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		meal_lock;
	struct s_philos		*philos;
}			t_data;

typedef struct s_philos
{
	int				meals_remaining;
	long			time_since_meal;
	int				phil_nbr;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	t_data			*data;
}			t_philos;

void	parse_input(char **argv, int argc, t_data *data);
t_data	*init_data(void);
void	free_data_and_philos(t_data *data);
long	get_time_in_ms(void);
bool	create_philos(t_data *data);
void	*philos_routine(void *arg);
void	mutex_locked_printf(t_philos *philo, char *msg);
void	attempt_grab_forks(t_philos *philo);
void	drop_forks(t_philos *philo);
void	sleep_ms(long ms);
void	check_state_philos(t_data *data, t_philos *philos);
void	join_threads(t_data *data);
void	destroy_mutex(t_data *data);
bool	error_msg(char *msg);

#endif