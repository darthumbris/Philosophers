/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleep_ms.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 15:18:02 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 09:44:02 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	sleep_ms(long ms)
{
	long	current_time_ms;

	current_time_ms = get_time_in_ms();
	//printf("ms: %ld\n", ms);
	//printf("current: %ld\n", current_time_ms);
	while ((get_time_in_ms() - current_time_ms) < ms)
		usleep(50);
}
