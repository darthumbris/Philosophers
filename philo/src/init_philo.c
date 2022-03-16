/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 11:02:27 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 11:24:08 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

t_data	*init_philo(void)
{
	t_data	*new;

	new = ft_calloc(1, sizeof(t_data));
	if (!new)
		return (NULL);
	new->amount_of_meals = -1;
	new->time_to_die = 0;
	new->time_to_eat = 0;
	new->time_to_sleep = 0;
	new->philo_count = 0;
	new->start_time = get_time_in_ms();
	new->fork_locks = NULL;
	new->philos = NULL;
	return (new);
}
