/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:55:42 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/12 00:03:35 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Copies up to 'size' - 1 characters from string 'src' to 'dst',
** NUL-terminating the result if 'size' is not 0.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	int		old;

	i = -1;
	old = 0;
	if (!dst || !src)
		return (0);
	while (src[old] != '\0')
		old++;
	if (size == 0)
		return (old);
	if (size > 0)
		while ((src[++i] != '\0') && (i < (int)(size - 1)))
			dst[i] = src[i];
	dst[i] = '\0';
	return (old);
}
