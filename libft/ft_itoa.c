/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:21:46 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/03/03 13:14:32 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts an integer value to a string and returns
** a pointer to the resulting string.
*/

static char	*ft_strrev(char *num)
{
	char	digit;
	int		i;
	int		size;

	i = 0;
	size = (num) ? (ft_strlen(num) - 1) : 0;
	while (i <= (size / 2))
	{
		digit = num[i];
		num[i] = num[size - i];
		num[size - i] = digit;
		i++;
	}
	return (num);
}

static char	*ft_setzero(char *num)
{
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static int	ft_count(int n)
{
	int i;

	i = 1;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int			i;
	int			sign;
	long int	ln;
	char		*num;

	ln = n;
	if (!(num = malloc(ft_count(n))))
		return (NULL);
	if (ln == 0)
		return (ft_setzero(num));
	i = 0;
	if ((sign = ln) < 0)
		ln *= -1;
	while (ln > 0)
	{
		num[i++] = (ln % 10) + '0';
		ln /= 10;
	}
	if (sign < 0)
		num[i++] = '-';
	num[i] = '\0';
	ft_strrev(num);
	return (num);
}
