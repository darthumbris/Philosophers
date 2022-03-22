/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:14:33 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:34:10 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*
 * This function will
 * first lock the grabbing of the forks
 * than it will reduce the amount of the forks
 * on the table by using the sem_wait on
 * the semaphore for the amount of forks
 * on the table. If this reaches 0 the philos
 * have to wait for a fork to be dropped
 * back on the table.
 * The function will than print the messages of 
 * grabbing the fork.
 */
void	grab_forks(t_philos *philo)
{
	sem_wait(philo->fork_lock);
	sem_wait(philo->forks_on_table);
	sem_wait(philo->forks_on_table);
	semaphore_locked_print(philo, GRABBING);
	semaphore_locked_print(philo, GRABBING);
}

/*
 * This function will
 * increase the semaphore for the amount
 * of forks on the table again so that
 * the next philos can grab them again.
 */
void	drop_forks(t_philos *philo)
{
	sem_post(philo->forks_on_table);
	sem_post(philo->forks_on_table);
}
