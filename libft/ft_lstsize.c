/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:10:49 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/17 16:48:20 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the number of elements in a list.
*/

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*node;

	i = 1;
	if (!(node = lst))
		return (0);
	while (node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}
