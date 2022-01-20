/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:22:45 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/20 23:06:58 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	if (*s == '\0')
		return (0);
	while (*s++ != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t n)
{
	char	*start;

	start = b;
	while (n--)
		*start++ = c;
	return (b);
}

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	if (!s && !d)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

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

char	**ft_setarray(char *temp, char ch)
{
	int		words;
	int		i;
	int		size;

	i = 0;
	words = 0;
	size = (temp) ? ft_strlen(temp) : 0;
	while (temp[i] != '\0' && i < size)
	{
		if (temp[i] != ch)
		{
			words++;
			while (temp[i] != ch && temp[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return ((char **)malloc(sizeof(char *) * (words + 1)));
}

int		*ft_setdelim(char *temp, char ch)
{
	int		i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == ch)
			temp[i] = '\0';
		i++;
	}
	return (0);
}

int		*ft_setnull(int *i)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*temp;
	int		i[3];

	temp = (s) ? ft_strdup(s) : NULL;
	if (!s || !c || !temp || !(result = ft_setarray(temp, c)))
		return (NULL);
	ft_setnull(i);
	i[0] = (temp) ? ft_strlen(temp) : 0;
	ft_setdelim(temp, c);
	while (i[2] < i[0])
	{
		if (temp[i[2]] == '\0')
			i[2]++;
		else
		{
			if (!(result[i[1]] = ft_strdup(&temp[i[2]])))
				return (NULL);
			i[1]++;
			i[2] += ft_strlen(&temp[i[2]]);
		}
	}
	result[i[1]] = NULL;
	free(temp);
	return (result);
}

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

int		ft_strcat(char *dst, const char *src)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*temp;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	size = i + j + 1;
	temp = malloc(sizeof(char) * size);
	ft_strlcpy(temp, dst, ft_strlen(dst) + 1);
	j = 0;
	while (i < size)
	{
		temp[i] = src[j];
		i++;
		j++;
	}
	ft_strlcpy(dst, temp, ft_strlen(temp) + 1);
	free(temp);
	return(TRUE);
}