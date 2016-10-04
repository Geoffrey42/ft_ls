/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_stage_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 20:29:41 by ggane             #+#    #+#             */
/*   Updated: 2016/09/30 11:47:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initialize_first_call(t_list *list)
{
	t_list	*tmp;
	t_data	*content;

	tmp = list;
	content = NULL;
	while (tmp)
	{
		content = (t_data *)tmp->content;
		content->first_call = 1;
		tmp = tmp->next;
	}
}

int			recall_sub_dir_number(t_list *recursive)
{
	t_list	*tmp;
	int		i;

	tmp = recursive;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		recursive_call(t_list *recursive)
{
	t_data	*content;

	content = (t_data *)recursive->content;
	content->first_call = 1;
	if ((content->flags & UPP_R_FLAG))
	{
		merge_sort(&recursive);
		content->nb_sub_dir = recall_sub_dir_number(recursive);
		recursive = put_content_in_trees(recursive);
	}
	erase_list(&recursive);
}
