/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:56 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 13:25:16 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes character 'ch' to file descriptor 'fd'.
*/

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	write(fd, &ch, 1);
}
