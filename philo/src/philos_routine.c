/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos_routine.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 13:48:31 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 10:44:32 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat_routine(t_philos *philo)
{
	attempt_grab_forks(philo);
	philo->state_philo = EATING;
	mutex_locked_printf(philo);
	philo->time_since_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->data->meal_lock);
	sleep_ms(philo->data->time_to_eat);
	if (philo->meals_remaining > 0)
		philo->meals_remaining--;
	drop_forks(philo);
}

static void	sleep_routine(t_philos *philo)
{
	philo->state_philo = SLEEPING;
	mutex_locked_printf(philo);
	sleep_ms(philo->data->time_to_sleep);
}

static void	think_routine(t_philos *philo)
{
	philo->state_philo = THINKING;
	mutex_locked_printf(philo);
}

void	*philos_routine(void *arg)
{
	t_philos	*philo;

	philo = arg;
	sleep_ms((philo->phil_nbr % 2) * philo->data->time_to_eat / 2);
	while (philo->data->state_main == ACTIVE && philo->meals_remaining != 0)
	{
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
