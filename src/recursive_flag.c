/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:36:09 by ggane             #+#    #+#             */
/*   Updated: 2016/09/21 22:00:08 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list	*choose_recursive_infix_traversal(t_list *list)
{
	t_data	*data;

	data = (t_data *)list->content;
	if ((data->flags & LOW_R_FLAG) != 0)
		return (list = reverse_recursive_infix(list));
	else
		return (list = regular_recursive_infix(list));
}

t_list	*recursive_flag_traversal(t_list *directories)
{
	t_list	*new_dir;
	t_list	*tmp;

	tmp = directories;
	while (tmp)
	{
		new_dir = choose_recursive_infix_traversal(tmp);
		tmp = tmp->next;
	}
	return (directories);
}
