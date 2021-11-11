/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:38:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 13:29:13 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes 'n' bytes of value 'c' to the string 'b'.
** Returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t n)
{
	char	*start;

	start = b;
	while (n--)
		*start++ = c;
	return (b);
}
