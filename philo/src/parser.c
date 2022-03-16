/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 16:28:43 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 12:13:57 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdbool.h>

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

void	parse_input(char **argv, int argc, t_data *data)
{
	data->philo_count = check_int(argv[1]);
	data->time_to_die = (long)check_int(argv[2]);
	data->time_to_eat = (long)check_int(argv[3]);
	data->time_to_sleep = (long)check_int(argv[4]);
	if (argc == 6)
		data->amount_of_meals = check_int(argv[5]);
	if (is_valid(data))
	{
		create_philos(data);
		check_state_philos(data, data->philos);
		join_threads(data);
		destroy_mutex(data);
		free_data_and_philos(data);
	}
	else
		free_data_and_philos(data);
}
