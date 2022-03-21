/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex_locked_print.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 14:52:59 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/18 09:42:30 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_locked_printf(t_philos *philo, char *msg)
{
	long	current_time_ms;

	current_time_ms = get_time_in_ms() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->data->state_main == ACTIVE)
		printf(msg, current_time_ms, philo->phil_nbr + 1);
	pthread_mutex_unlock(&philo->data->print_lock);
}
