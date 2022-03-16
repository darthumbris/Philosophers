/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex_locked_print.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 14:52:59 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 12:11:39 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_locked_printf(t_philos *philo)
{
	long	current_time_ms;

	current_time_ms = get_time_in_ms() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->data->state_main == ACTIVE)
	{
		if (philo->state_philo == EATING)
			printf("[%ld]\t%d\e[1;34m is eating\n\e[0m", \
			current_time_ms, philo->phil_nbr + 1);
		if (philo->state_philo == SLEEPING)
			printf("[%ld]\t%d\e[0;32m is sleeping\n\e[0m", \
			current_time_ms, philo->phil_nbr + 1);
		if (philo->state_philo == THINKING)
			printf("[%ld]\t%d\e[0;33m is thinking\n\e[0m", \
			current_time_ms, philo->phil_nbr + 1);
		if (philo->state_philo == GRABBING)
			printf("[%ld]\t%d\e[0;35m has taken a fork\n\e[0m", \
			current_time_ms, philo->phil_nbr + 1);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}
