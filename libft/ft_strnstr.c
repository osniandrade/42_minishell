/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:17:39 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 15:19:22 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the NUL-terminated string 'lit' in
** string 'big', where no more than 'n' characters are searched. Characters
** after a '\0' are not searched.
*/

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	unsigned int	i;
	unsigned int	chksize;

	chksize = ft_strlen(lit);
	if (!chksize)
		return ((char *)big);
	i = 0;
	while (i < len)
	{
		if ((ft_strncmp((char *)&big[i], (char *)lit, chksize)) == 0)
		{
			if ((chksize + i) > len)
				return (0);
			return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
