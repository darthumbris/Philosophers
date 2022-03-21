/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleep_ms.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:03:41 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/21 10:03:46 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	sleep_ms(long ms)
{
	long	current_time_ms;

	current_time_ms = get_time_in_ms();
	while ((get_time_in_ms() - current_time_ms) < ms)
		usleep(125);
}
