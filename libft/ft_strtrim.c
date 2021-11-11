/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:45:11 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/03/03 15:59:06 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a copy of ’s1’ with the characters specified in
** ’set’ removed from the beginning and the end of the string.
*/

static int	ft_chkchar(char const ch, char const *set)
{
	int		i;

	i = 0;
	if (!ch || !set)
		return (0);
	while (set[i] != '\0')
	{
		if (set[i] == ch)
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i[2];
	int		s1size;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	s1size = ft_strlen(s1);
	if (*set == '\0' || s1size == 0)
		return (ft_strdup(s1));
	i[0] = 0;
	i[1] = s1size;
	while (!(ft_chkchar(s1[i[0]], set)) && i[0] < s1size)
		i[0]++;
	while (!(ft_chkchar(s1[i[1]], set)) && i[1] != 0)
		i[1]--;
	if (i[1] <= 0 && i[0] >= s1size)
		return (ft_strdup(""));
	i[1] = s1size - i[1];
	result = ft_substr(s1, i[0], (s1size - i[1] - i[0] + 1));
	return (result);
}
