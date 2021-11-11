/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:02:24 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/03/02 18:46:11 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of 'c' in the string pointed to by 's'.
** The terminating null character is considered to be part of the string -
** therefore, if 'ch' is '\0', the function locates the terminatting '\0'.
** Returns a pointer to the located character or NULL if not found.
*/

char	*ft_strchr(const char *s, int c)
{
	char			*sfer;

	sfer = (char *)s;
	while (*sfer != '\0')
		if (*sfer++ == (char)c)
			return (--sfer);
	if ((c == '\0') && (*sfer == '\0'))
		return (sfer);
	return (0);
}
