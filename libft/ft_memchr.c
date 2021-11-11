/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:27:14 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 13:37:07 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of 'c' character in string 's'.
** Returns a pointer to the byte located or 'NULL' if no such byte
** exists within 'n' bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*b;

	b = (void *)s;
	while (n--)
		if (*b++ == (char)c)
			return (&b[-1]);
	return (NULL);
}
