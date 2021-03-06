/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 12:18:53 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/15 12:23:35 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	get_time_in_ms(void)
{
	long			ms;
	struct timeval	timev;

	gettimeofday(&timev, NULL);
	ms = timev.tv_sec * 1000;
	ms += timev.tv_usec / 1000;
	return (ms);
}
