/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:53:29 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 13:38:33 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares byte string 's2' against byte string 's1'. Both strings
** are assumed to be 'n' bytes long. Returns '0' if strings are identical,
** otherwise returns '-1' if 's1' is greater than 's2' or '1' if 's2' is
** greater than 's1'.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*d;
	const unsigned char	*s;

	d = s1;
	s = s2;
	while (n-- > 0)
		if (*d++ != *s++)
			return (d[-1] - s[-1]);
	return (0);
}
