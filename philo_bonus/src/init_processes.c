/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_processes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 09:49:30 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 16:13:53 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>
#include <signal.h>

bool	fork_processes(t_philos *philo, int *pid)
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

void	kill_processes(t_philos *philo, int *pid)
{
	int		i;

	i = 0;
	while (i < philo->data->philo_count)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
}

void	init_processes(t_philos *philo)
{
	int			i;
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
	i = philo->data->amount_of_meals - 1;
	philo->data->amount_of_meals = -1;
	while (i > 0)
	{
		sem_post(philo->meals_lock);
		i--;
	}
	free(pid);
}
