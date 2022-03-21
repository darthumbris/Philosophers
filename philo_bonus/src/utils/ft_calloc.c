/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 11:09:03 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/15 12:21:30 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	memset(temp, 0, count * size);
	return (temp);
}
