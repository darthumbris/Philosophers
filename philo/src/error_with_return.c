/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_with_return.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:34:34 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/16 11:35:57 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

bool	error_msg(char *msg)
{
	perror(msg);
	return (false);
}
