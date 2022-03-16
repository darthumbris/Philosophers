/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:09:05 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 11:09:24 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		pthread_join(data->philos[i].thread, NULL);
}
