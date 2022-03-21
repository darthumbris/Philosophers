/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 10:36:10 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 13:25:36 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_data	*init_data(void)
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
	return (new);
}
