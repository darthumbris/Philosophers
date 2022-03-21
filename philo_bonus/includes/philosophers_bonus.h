/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers_bonus.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:31:06 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 15:23:11 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include "utils_bonus.h"
# include <stdio.h>
# include <stdbool.h>
# include <semaphore.h>
# include <unistd.h>

# define SLEEPING			"\e[0;37m\e[0m[%ld]\t%d\e[0;32m is sleeping\e[0m\n"
# define EATING				"\e[0;37m\e[0m[%ld]\t%d\e[1;34m is eating\e[0m\n"
# define THINKING			"\e[0;37m\e[0m[%ld]\t%d\e[0;33m is thinking\e[0m\n"
# define GRABBING			"\e[0;37m\e[0m[%ld]\t%d\e[0;35m has taken a fork\e[0m\n"
# define DEAD				"\e[0;37m\e[0m[%ld]\t%d\e[0;31m died\e[0m\n"

# define ERROR_MUTEX		"Error: Mutex failed to init"
# define ERROR_MALLOC		"Error: Failed to allocate memory"
# define ERROR_THREAD		"Error: Failed to create thread"
# define ERROR_FORK			"Error: Failed to fork"

# define SEM_FORK_LOCK		"fork_lock"
# define SEM_PRINT_LOCK		"print_lock"
# define SEM_FORKS_TABLE	"forks_on_table"
# define SEM_DEAD_LOCK		"dead_lock"
# define SEM_MEALS_LOCK		"meals_eaten"

typedef struct s_data
{
	int					philo_count;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					amount_of_meals;
	long				start_time;
}			t_data;

typedef struct s_philos
{
	long			time_since_meal;
	int				phil_nbr;
	pid_t			pid;
	sem_t			*fork_lock;
	sem_t			*print_lock;
	sem_t			*forks_on_table;
	sem_t			*dead_lock;
	sem_t			*meals_lock;
	t_data			*data;
	pthread_t		thread;
}			t_philos;

void	parse_input(char **argv, int argc, t_data *data);
long	get_time_in_ms(void);
void	sleep_ms(long ms);
t_data	*init_data(void);
void	init_processes(t_philos *philo);
bool	init_philo(t_data *data, t_philos *philo);
void	semaphore_locked_print(t_philos *philo, char *msg);
void	drop_forks(t_philos *philo);
void	grab_forks(t_philos *philo);
void	*check_state_philo(void *arg);
void	*check_state_meals(void *arg);
bool	routine_child_process(t_philos *philo);
void	unlink_and_close_semaphores(t_philos philo);

#endif