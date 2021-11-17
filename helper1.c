/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:21:04 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/17 23:25:53 by ocarlos-         ###   ########.fr       */
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

/*
** Appends string 'src' to the end of 'dst'. Will NUL-terminate unless
** 'size' is 0 or the original 'dst' string was incorrect.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dstsize;

	i = 0;
	j = 0;
	dstsize = 0;
	while (src[dstsize] != '\0')
		dstsize++;
	while (dst[i] && (i < size))
		i++;
	while (src[j] && ((i + j + 1) < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = '\0';
	return (i + dstsize);
}

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

/*
** Computes the length of the string 's' and returns it as an integer.
*/

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	if (*s == '\0')
		return (0);
	while (*s++ != '\0')
		i++;
	return (i);
}

/*
** Compares no more than 'n' characters of string 's2' to 's1'.
** Characters after a '\0' are not compared.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;

	i = 0;
	while (!((s1[i] == '\0') && (s2[i] == '\0')) && (i < n))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
