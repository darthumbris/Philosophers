/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 11:15:15 by shoogenb      #+#    #+#                 */
/*   Updated: 2022/03/15 12:00:56 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);

#endif