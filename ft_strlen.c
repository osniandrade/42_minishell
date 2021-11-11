/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:47:48 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/12 00:03:38 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
