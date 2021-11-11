/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:14:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/12 00:03:24 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Allocates sufficient memory for a copy of the string 's1', does the
** copy and returns a pointer to it.
*/

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		size;

	size = ft_strlen(s1);
	if (!(dst = malloc(size + 1)))
		return (NULL);
	ft_memcpy(dst, s1, size);
	dst[size] = '\0';
	return (dst);
}
