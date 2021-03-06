/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 16:28:43 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:38:57 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <signal.h>
#include <stdlib.h>

static int	check_int(char *nbr_str)
{
	long long	temp_nbr;
	int			min;
	int			i;

	i = 0;
	temp_nbr = 0;
	min = 1;
	while (nbr_str[i] == ' ')
		i++;
	if (nbr_str[i] == '-')
		min = -1;
	if (nbr_str[i] == '+' || nbr_str[i] == '-')
		i++;
	while (ft_isdigit(nbr_str[i]))
	{
		temp_nbr = temp_nbr * 10 + (nbr_str[i] - 48);
		if ((temp_nbr * min) > 2147483647 || (temp_nbr * min) < -2147483648)
			return (0);
		i++;
	}
	if (nbr_str[i] && !ft_isdigit(nbr_str[i]))
		return (0);
	return (temp_nbr * min);
}

static	bool	is_valid(t_data *data)
{
	if (data->philo_count <= 0 || data->time_to_die <= 0 || \
		data->time_to_eat <= 0 || data->time_to_sleep <= 0 || \
		data->amount_of_meals == 0)
	{
		ft_putendl_fd("invalid input for arguments", 2);
		return (false);
	}
	if (data->philo_count > 200)
	{
		ft_putendl_fd("too many philosophors", 2);
		return (false);
	}
	if (data->philo_count == 1)
	{
		printf("[%d]\t1\e[0;35m has taken a fork\n\e[0m[%ld]\t1\e[0;31m died\n\e[0m", \
		0, data->time_to_die + 1);
		return (false);
	}
	return (true);
}

/*
 * This function will check the input for the
 * arguments and set the data to them and 
 * then checks if they are valid. If valid it 
 * will then contiue on with creating the philo
 * and processes.
 */
void	parse_input(char **argv, int argc, t_data *data)
{
	t_philos	philo;

	data->philo_count = check_int(argv[1]);
	data->time_to_die = (long)check_int(argv[2]);
	data->time_to_eat = (long)check_int(argv[3]);
	data->time_to_sleep = (long)check_int(argv[4]);
	if (argc == 6)
	{
		data->amount_of_meals = check_int(argv[5]);
		if (data->amount_of_meals <= 0)
			data->amount_of_meals = 0;
	}
	if (is_valid(data))
	{
		if (!init_philo(data, &philo))
			return (unlink_and_close_semaphores(philo));
		init_processes(&philo);
		unlink_and_close_semaphores(philo);
	}
	else
		free(data);
}
