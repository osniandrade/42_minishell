/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:25:23 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 15:20:14 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the last occurrence of 'c' in string pointed by 'str'. The
** terminating null character is considered to be part of the string (if 'c'
** is '\0', the function locates the terminating '\0'). Returns a pointer to
** the located character or NULL if not found.
*/

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	size;

	size = ft_strlen(s);
	while ((s[size] != (char)c) && size > 0)
		size--;
	if ((s[size] != (char)c) && size == 0)
		return (NULL);
	return ((char *)&s[size]);
}
