/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:30:05 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 15:27:12 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		data = init_data();
		if (!data)
		{
			ft_putendl_fd(ERROR_MALLOC, 2);
			return (1);
		}
		parse_input(argv, argc, data);
	}
	else
	{
		ft_putendl_fd("ERROR: not correct amount of arguments", 2);
		ft_putendl_fd
		("Program accepts 4 or 5 arguments in the following way:", 2);
		ft_putendl_fd
		("[# philos] [time_to_die] [time_to_eat] [time_to_sleep] (# meals)", 2);
		ft_putendl_fd("with the time in ms", 2);
		return (1);
	}
	return (0);
}
