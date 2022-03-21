/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleep_ms.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 15:18:02 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/18 09:43:30 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	sleep_ms(long ms)
{
	long	current_time_ms;

	current_time_ms = get_time_in_ms();
	while ((get_time_in_ms() - current_time_ms) < ms)
		usleep(125);
}
