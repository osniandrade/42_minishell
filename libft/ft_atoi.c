/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:28:32 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 13:40:50 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a string representing the integer
** received as an argument. Handles negative numbers.
*/

static int		ft_tstspc(const char ch)
{
	if ((ch == ' ') || (ch == '\f') || (ch == '\n') ||
		(ch == '\r') || (ch == '\t') || (ch == '\v'))
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		signal;
	int		num;

	signal = 1;
	num = 0;
	while (ft_tstspc(*str))
		str++;
	if ((*str == '+') || (*str == '-'))
		if (*str++ == '-')
			signal *= -1;
	if (!(ft_isdigit(*str)))
		return (0);
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - 48);
	return (num * signal);
}
