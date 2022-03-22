/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleep_ms.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:03:41 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:47:05 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/*
 * this function will sleep the
 * amount of ms given as input
 * it will do it in steps of 125
 * microsecond because the usleep
 * has a tendency to overshoot 
 * because the input for usleep
 * is the minimum amount of time it will
 * sleep. So if you do it in smaller
 * steps it is less likely to overshoot
 * with a large margin.
 */
void	sleep_ms(long ms)
{
	long	current_time_ms;

	current_time_ms = get_time_in_ms();
	while ((get_time_in_ms() - current_time_ms) < ms)
		usleep(125);
}
