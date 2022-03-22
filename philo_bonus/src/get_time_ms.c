/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time_ms.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 09:50:59 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/22 09:34:27 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

/*
 * This function returns the current
 * local time in ms
 */
long	get_time_in_ms(void)
{
	long			ms;
	struct timeval	timev;

	gettimeofday(&timev, NULL);
	ms = timev.tv_sec * 1000;
	ms += timev.tv_usec / 1000;
	return (ms);
}
