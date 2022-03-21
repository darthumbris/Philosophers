/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 10:35:00 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 16:10:28 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

static bool	init_semaphores(t_philos *philo)
{
	sem_unlink(SEM_FORK_LOCK);
	sem_unlink(SEM_PRINT_LOCK);
	sem_unlink(SEM_FORKS_TABLE);
	sem_unlink(SEM_DEAD_LOCK);
	sem_unlink(SEM_MEALS_LOCK);
	philo->fork_lock = sem_open(SEM_FORK_LOCK, O_CREAT, 0644, 1);
	philo->print_lock = sem_open(SEM_PRINT_LOCK, O_CREAT, 0644, 1);
	philo->forks_on_table = sem_open
		(SEM_FORKS_TABLE, O_CREAT, 0644, philo->data->philo_count);
	philo->dead_lock = sem_open(SEM_DEAD_LOCK, O_CREAT, 0644, 0);
	philo->meals_lock = sem_open(SEM_MEALS_LOCK, O_CREAT, 0644, 0);
	if (philo->fork_lock == SEM_FAILED || philo->print_lock == SEM_FAILED || \
		philo->forks_on_table == SEM_FAILED || \
		philo->dead_lock == SEM_FAILED || \
		philo->meals_lock == SEM_FAILED)
		return (false);
	return (true);
}

bool	init_philo(t_data *data, t_philos *philo)
{
	philo->data = data;
	return (init_semaphores(philo));
}
