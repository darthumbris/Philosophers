/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_state_philo.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:24:42 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 14:58:55 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*check_state_philo(void *arg)
{
	t_philos	*philo;
	long		current_time;

	philo = (t_philos *)arg;
	while (1)
	{
		current_time = get_time_in_ms();
		if ((current_time - philo->time_since_meal) > philo->data->time_to_die)
		{
			sem_wait(philo->print_lock);
			printf
				(DEAD, current_time - philo->data->start_time, philo->phil_nbr);
			sem_post(philo->dead_lock);
			return (NULL);
		}
	}
	return (NULL);
}
