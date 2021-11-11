/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:51:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/21 13:44:45 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tests for any upcase or lowercase letter. Returns '0'
** if false or '1' if true.
*/

int		ft_isalpha(int c)
{
	if ((c < 65) || (c > 122))
		return (0);
	else if ((c > 90) && (c < 97))
		return (0);
	else
		return (1);
}
