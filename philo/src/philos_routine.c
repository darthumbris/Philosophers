/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos_routine.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 13:48:31 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/18 09:45:25 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat_routine(t_philos *philo)
{
	attempt_grab_forks(philo);
	mutex_locked_printf(philo, EATING);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->time_since_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->data->meal_lock);
	sleep_ms(philo->data->time_to_eat);
	drop_forks(philo);
	if (philo->meals_remaining > 0)
		philo->meals_remaining--;
}

static void	sleep_routine(t_philos *philo)
{
	mutex_locked_printf(philo, SLEEPING);
	sleep_ms(philo->data->time_to_sleep);
}

static void	think_routine(t_philos *philo)
{
	mutex_locked_printf(philo, THINKING);
}

void	*philos_routine(void *arg)
{
	t_philos	*philo;

	philo = arg;
	sleep_ms((philo->phil_nbr % 2) * philo->data->time_to_eat / 2);
	while (philo->meals_remaining != 0 && philo->data->state_main == ACTIVE)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		if (philo->data->state_main == FINISHED)
			return (NULL);
		pthread_mutex_unlock(&philo->data->print_lock);
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
