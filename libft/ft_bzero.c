/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:28:24 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 15:11:51 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes n zeroed bytes to the string s.
** If n is zero, does nothing.
*/

void	*ft_bzero(void *s, size_t n)
{
	char	*start;

	start = s;
	while (n--)
		*start++ = 0;
	return (s);
}
