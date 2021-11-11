/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:16:07 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 13:39:44 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'n' bytes from string 'src' to string 'dest'. The copy
** is always non-destructive. Returns the original value of 'dest'.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*lasts;
	char		*lastd;

	d = dest;
	s = src;
	if (!s && !d)
		return (NULL);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		lasts = (char *)s + (n - 1);
		lastd = d + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
