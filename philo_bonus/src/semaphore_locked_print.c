/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   semaphore_locked_print.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:06:42 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 14:12:11 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	semaphore_locked_print(t_philos *philo, char *msg)
{
	long	current_time;

	sem_wait(philo->print_lock);
	current_time = get_time_in_ms() - philo->data->start_time;
	printf(msg, current_time, philo->phil_nbr);
	sem_post(philo->print_lock);
}
