/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_child_process.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 09:57:19 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:44:38 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

/*
 * This function will
 * first lock the print lock
 * then increases the meals_eaten
 * then checks if that has reached the 
 * amount_of_meals.
 * If the option has not been given
 * it is set at -1 and it will never satisfy
 * this if statement.
 * if it is set and the philo has eaten
 * its fill it will increase the semaphore
 * for the meals_lock. When all philos
 * have eaten their meals then it will be
 * finally unlocked (because the mealsthread
 * will do a sem_wait for the amount_of_meals)
 * after this it will unlock the print again
 * so other philos can start printing again.
 */
static void	check_philo_full(t_philos *philo)
{
	sem_wait(philo->print_lock);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->data->amount_of_meals)
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

/*
 * The eating routine function
 * will first try to grab forks
 * then it will set the time_sinc_meal
 * to the current time and then
 * prints a message that it eating
 * it will than do a check if the philosopher
 * has eaten all their meals
 * it will than sleep the time given by 
 * the time_to_die argument and
 * then drop the forks.
 */
static void	eat_routine(t_philos *philo)
{
	grab_forks(philo);
	philo->time_since_meal = get_time_in_ms();
	semaphore_locked_print(philo, EATING);
	sem_post(philo->fork_lock);
	check_philo_full(philo);
	sleep_ms(philo->data->time_to_eat);
	drop_forks(philo);
}

/*
 * This function starts a thread for 
 * checking if a philo needs to die
 * and after that it will start the routines
 * for eating sleeping and thinking.
 */
bool	routine_child_process(t_philos *philo)
{
	pthread_t	death_thread;

	philo->time_since_meal = get_time_in_ms();
	if (pthread_create(&death_thread, NULL, &check_state_philo, philo) != 0)
		return (false);
	pthread_detach(death_thread);
	while (1)
	{
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
	}
	return (true);
}
