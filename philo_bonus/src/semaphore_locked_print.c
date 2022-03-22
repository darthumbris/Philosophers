/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   semaphore_locked_print.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:06:42 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:45:50 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*
 * This is function
 * will first lock the print semaphore
 * so other philos cant print when the current
 * one tries to print. This makes it that
 * messages can't be printed out of order.
 * It will then print the message and 
 * unlock the print_lock again.
 */
void	semaphore_locked_print(t_philos *philo, char *msg)
{
	long	current_time;

	sem_wait(philo->print_lock);
	current_time = get_time_in_ms() - philo->data->start_time;
	printf(msg, current_time, philo->phil_nbr);
	sem_post(philo->print_lock);
}
