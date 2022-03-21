/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:14:33 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 14:54:01 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	grab_forks(t_philos *philo)
{
	sem_wait(philo->fork_lock);
	sem_wait(philo->forks_on_table);
	sem_wait(philo->forks_on_table);
	semaphore_locked_print(philo, GRABBING);
	semaphore_locked_print(philo, GRABBING);
}

void	drop_forks(t_philos *philo)
{
	sem_post(philo->forks_on_table);
	sem_post(philo->forks_on_table);
}
