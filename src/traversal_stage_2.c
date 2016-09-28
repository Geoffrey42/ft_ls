/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_stage_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 20:29:41 by ggane             #+#    #+#             */
/*   Updated: 2016/09/28 20:29:52 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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
	if ((content->flags & UPP_R_FLAG))
	{
		merge_sort(&recursive);
		content->nb_sub_dir = recall_sub_dir_number(recursive);
		recursive = put_content_in_trees(recursive);
	}
	erase_list(&recursive);
}