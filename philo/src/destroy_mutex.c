/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_mutex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:07:12 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/18 09:52:05 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_destroy(&data->fork_locks[i]);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->meal_lock);
}
