/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal_stage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:30:38 by ggane             #+#    #+#             */
/*   Updated: 2016/09/15 16:40:02 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_and_delete(void *item)
{
	t_data	*data;

	data = (t_data *)item;
	ft_putendl(data->name);
}

t_list		*traversal_stage(t_list *directories)
{
	t_data	*tmp;
	void	(*applyf)(void *);

	applyf = &display_and_delete;
	while (directories)
	{
		tmp = (t_data *)directories->content;
		choose_infix_traversal(tmp->flags, tmp->files, applyf);
		directories = directories->next;
	}
	return (directories);
}
