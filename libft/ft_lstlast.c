/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:49:49 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/17 16:52:25 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the last element of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!(node = lst))
		return (0);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
