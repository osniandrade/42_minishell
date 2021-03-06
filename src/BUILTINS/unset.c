/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:39:44 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/05/19 21:05:28 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_data *data, int id)
{
	int		i;
	int		arg;

	arg = 1;
	while (data->argve[id][arg])
	{
		i = 0;
		while (data->envp[i])
		{
			if (!ft_strcmp(data->argve[id][arg], "PATH"))
				double_free((void ***)&data->command_path);
			if (!ft_strncmp(data->envp[i], data->argve[id][arg], \
				ft_strlen(data->argve[id][arg])))
			{
				free(data->envp[i]);
				move_ptrs_back(data->envp + i);
			}
			else
				i++;
		}
		delete_in_list(data->argve[id][arg++], &data->vars);
	}
}
