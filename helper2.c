/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:22:15 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/17 23:22:48 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Copies 'n' bytes from memory area 'src' to memory area 'dest'.
** Returns a pointer to 'dest' memory area or 'NULL' if src is empty.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	if (!s && !d)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}
