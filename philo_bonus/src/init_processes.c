/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_processes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 09:49:30 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:31:53 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>
#include <signal.h>

static bool	fork_processes(t_philos *philo, int *pid)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_count)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			ft_putendl_fd(ERROR_FORK, 2);
			return (false);
		}
		else if (pid[i] == 0)
		{
			philo->phil_nbr = i + 1;
			routine_child_process(philo);
		}
		i++;
	}
	return (true);
}

static void	kill_processes(t_philos *philo, int *pid)
{
	int		i;

	i = 0;
	while (i < philo->data->philo_count)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
}

/*
 * This function will unlock the meals lock
 * in case a philosopher dies before
 * all the meals have been eaten 
 * (this is only needed if the optional argument
 * is used)
 */
static void	unlock_meals_lock(t_philos *philo)
{
	int			i;
	int			meals_to_eat;

	i = 0;
	meals_to_eat = philo->data->amount_of_meals;
	philo->data->amount_of_meals = -1;
	while (i < meals_to_eat)
	{
		sem_post(philo->meals_lock);
		i++;
	}
}

/*
 * This function will start a thread that will
 * check the amount of meals eaten using the
 * semaphore meals_lock
 * it will then create all the processes
 * and each process will start a thread to
 * check if that philospher needs to die
 * if a philosopher dies or all philosophers
 * have eaten their meals it will kill all
 * the processes because the dead_lock will
 * then be unlocked.
 * In case a philosopher dies before they
 * have eaten all their meals
 * the sem_post after the kill processes
 * will ensure that the meals_lock will
 * be unlocked
 */
void	init_processes(t_philos *philo)
{
	pid_t		*pid;
	pthread_t	thread_meals;

	pid = ft_calloc(philo->data->philo_count, sizeof(pid_t));
	if (!pid)
		return (ft_putendl_fd(ERROR_MALLOC, 2));
	pthread_create(&thread_meals, NULL, &check_state_meals, philo);
	pthread_detach(thread_meals);
	if (!fork_processes(philo, pid))
		return (free(pid));
	sem_wait(philo->dead_lock);
	kill_processes(philo, pid);
	unlock_meals_lock(philo);
	free(pid);
}
