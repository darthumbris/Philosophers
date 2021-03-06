/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unlink_and_close_sems.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 14:03:26 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:47:48 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

/*
 * This function will unlink and close all
 * the semaphores opened in the init_philo function
 * it will also free the data struct.
 */
void	unlink_and_close_semaphores(t_philos philo)
{
	sem_unlink(SEM_FORKS_TABLE);
	sem_unlink(SEM_PRINT_LOCK);
	sem_unlink(SEM_FORK_LOCK);
	sem_unlink(SEM_DEAD_LOCK);
	sem_unlink(SEM_MEALS_LOCK);
	sem_close(philo.forks_on_table);
	sem_close(philo.print_lock);
	sem_close(philo.fork_lock);
	sem_close(philo.dead_lock);
	sem_close(philo.meals_lock);
	free(philo.data);
	usleep(1000);
}
