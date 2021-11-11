/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:02:45 by ocarlos-          #+#    #+#             */
/*   Updated: 2020/02/27 16:08:06 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list ’lst’ and applies the function ’f’ to the content of each
** element.  Creates a new list resulting of the successive applications of
** the function ’f’.  The ’del’ function is used to delete the content of an
** element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*mov;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		if (!(mov = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, mov);
		lst = lst->next;
	}
	return (head);
}
