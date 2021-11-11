/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:48:19 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/03/04 17:27:08 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a substring from the string 's'. The substring
** begins at index 'start' and is of maximum size 'n'.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((slen == 0) || (start > (slen - len)) || (len > slen))
		return (ft_strdup(""));
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}
