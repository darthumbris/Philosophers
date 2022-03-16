/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_philos.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 12:35:55 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 11:26:07 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	new_philo(t_philos *philo, t_data *data, int id)
{
	philo->meals_remaining = data->amount_of_meals;
	philo->time_since_meal = get_time_in_ms();
	philo->data = data;
	philo->phil_nbr = id;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % data->philo_count;
	philo->state_philo = EATING;
	if (pthread_create(&philo->thread, NULL, philos_routine, philo) != 0)
		perror("Failed to create thread");
}

static void	init_locks(t_data *data)
{
	int	i;

	if (data && data->fork_locks)
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (pthread_mutex_init(&data->fork_locks[i], NULL) != 0)
				perror("Error: Mutex failed to init");
			i++;
		}
	}
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
		perror("Error: Mutex failed to init");
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		perror("Error: Mutex failed to init");
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
		perror("Error: Mutex failed to init");
}

void	create_philos(t_data *data)
{
	int	i;

	data->fork_locks = ft_calloc(data->philo_count, sizeof(pthread_mutex_t));
	if (data->fork_locks == NULL)
		free_data_and_philos(data);
	init_locks(data);
	data->philos = ft_calloc(data->philo_count, sizeof(t_philos));
	if (data->philos == NULL)
		free_data_and_philos(data);
	data->state_main = ACTIVE;
	i = 0;
	while (i < data->philo_count)
	{
		new_philo(&data->philos[i], data, i);
		i++;
	}
}
