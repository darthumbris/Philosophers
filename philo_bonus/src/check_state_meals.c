/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_state_meals.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:31:41 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 15:24:32 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*check_state_meals(void *arg)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)arg;
	i = philo->data->philo_count - 1;
	if (philo->data->amount_of_meals != -1)
	{
		while (i > 0)
		{
			sem_wait(philo->meals_lock);
			i--;
		}
	}
	if (philo->data->amount_of_meals != -1)
	{
		sem_wait(philo->print_lock);
		sem_post(philo->dead_lock);
		printf("\e[0;32mAll philosophers have eaten their meals\e[0m\n");
	}
	return (arg);
}
