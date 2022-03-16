/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_state_philos.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 13:32:28 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 11:16:20 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	check_state_philos(t_data *data, t_philos *philos)
{
	int			i;
	long		time_waiting;

	while (data->state_main == ACTIVE)
	{
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_lock(&data->meal_lock);
			time_waiting = get_time_in_ms() - (philos[i].time_since_meal);
			if (time_waiting > data->time_to_die)
			{
				data->state_main = FINISHED;
				if (philos[i].meals_remaining)
					printf("%ld %d died\n", \
						get_time_in_ms() - (data->start_time), i + 1);
			}
			pthread_mutex_unlock(&data->meal_lock);
			if (data->state_main == FINISHED)
				return ;
			i++;
			usleep(50);
		}
	}
}
