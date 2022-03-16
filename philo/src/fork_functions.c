/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 15:04:44 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 10:29:43 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * This function locks left and right forks
 * and depending on what philosopher it is
 * it has to either lock the fork to the left
 * or it has to lock the fork with
 * number of the amount of philosophers
 * otherwise the array will underflow.
 * so i is the right fork
 * and i - 1 is the left fork.
 * it will than set the state of the philo 
 * to grabbing
 * and will than go to the mutex print function
 * to print the has taken fork message.
 */
void	attempt_grab_forks(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->left_fork]);
	philo->state_philo = GRABBING;
	mutex_locked_printf(philo);
	pthread_mutex_lock(&philo->data->fork_locks[philo->right_fork]);
	mutex_locked_printf(philo);
	pthread_mutex_lock(&philo->data->meal_lock);
}

/*
 * This function will put the forks back
 * onto the table which had been grabbed before.
 * here is the same that i is the right fork
 * and i - 1 or phil_count - 1 is the left fork.
 */
void	drop_forks(t_philos *philo)
{
	pthread_mutex_unlock(&philo->data->fork_locks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->right_fork]);
}
