/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_philos.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 12:35:55 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/18 09:54:51 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

static bool	new_philo(t_philos *philo, t_data *data, int id)
{
	philo->meals_remaining = data->amount_of_meals;
	philo->time_since_meal = get_time_in_ms();
	philo->data = data;
	philo->phil_nbr = id;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % data->philo_count;
	if (pthread_create(&philo->thread, NULL, &philos_routine, philo) != 0)
		return (error_msg(ERROR_THREAD));
	return (true);
}

static bool	init_locks(t_data *data)
{
	int	i;

	if (data && data->fork_locks)
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (pthread_mutex_init(&(data->fork_locks[i]), NULL) != 0)
				return (error_msg(ERROR_MUTEX));
			i++;
		}
	}
	if (pthread_mutex_init(&(data->print_lock), NULL) != 0)
		return (error_msg(ERROR_MUTEX));
	if (pthread_mutex_init(&(data->meal_lock), NULL) != 0)
		return (error_msg(ERROR_MUTEX));
	return (true);
}

bool	create_philos(t_data *data)
{
	int	i;

	data->fork_locks = ft_calloc(data->philo_count, sizeof(pthread_mutex_t));
	if (data->fork_locks == NULL)
		return (error_msg(ERROR_MALLOC));
	init_locks(data);
	data->philos = ft_calloc(data->philo_count, sizeof(t_philos));
	if (data->philos == NULL)
		return (error_msg(ERROR_MALLOC));
	data->state_main = ACTIVE;
	i = 0;
	while (i < data->philo_count)
	{
		if (!new_philo(&data->philos[i], data, i))
			return (false);
		i++;
	}
	return (true);
}
