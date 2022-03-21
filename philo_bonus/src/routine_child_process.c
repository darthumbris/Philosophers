/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_child_process.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 09:57:19 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 15:14:08 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

static void	check_philo_full(t_philos *philo, int *meals_eaten)
{
	sem_wait(philo->print_lock);
	(*meals_eaten)++;
	if ((*meals_eaten) == philo->data->amount_of_meals)
		sem_post(philo->meals_lock);
	sem_post(philo->print_lock);
}

static void	sleep_routine(t_philos *philo)
{
	semaphore_locked_print(philo, SLEEPING);
	sleep_ms(philo->data->time_to_sleep);
}

static void	think_routine(t_philos *philo)
{
	semaphore_locked_print(philo, THINKING);
}

static void	eat_routine(t_philos *philo, int *meals_eaten)
{
	grab_forks(philo);
	philo->time_since_meal = get_time_in_ms();
	semaphore_locked_print(philo, EATING);
	sem_post(philo->fork_lock);
	check_philo_full(philo, meals_eaten);
	sleep_ms(philo->data->time_to_eat);
	drop_forks(philo);
}

bool	routine_child_process(t_philos *philo)
{
	pthread_t	death_thread;
	int			meals_eaten;

	meals_eaten = 0;
	philo->time_since_meal = get_time_in_ms();
	if (pthread_create(&death_thread, NULL, &check_state_philo, philo) != 0)
		return (false);
	pthread_detach(death_thread);
	while (1)
	{
		eat_routine(philo, &meals_eaten);
		sleep_routine(philo);
		think_routine(philo);
	}
	exit(EXIT_SUCCESS);
	return (true);
}
