/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_state_meals.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:31:41 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:29:01 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*
 * This function will lock the semaphore
 * for the meals and only after
 * the sem_post in the eating routine
 * has reached the amount_of_meals
 * will this than reach the second
 * if statement where it will
 * lock the print and dead locks
 * it will then print a message
 * to indicate all the philosophers
 * have eaten their meals.
 */
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
		printf(MEALS_DONE);
	}
	return (NULL);
}
