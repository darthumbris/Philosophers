/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data_and_philos.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 12:08:30 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 11:26:15 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	free_data_and_philos(t_data *data)
{
	if (data)
	{
		if (data->fork_locks)
			free(data->fork_locks);
		if (data->philos)
			free(data->philos);
		free(data);
		data = NULL;
	}
}
