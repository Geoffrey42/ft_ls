/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:53:12 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 14:06:16 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	display_content_tree(t_data *content)
{
	void	(*applyf)(void *);

	applyf = &cb_ft_putendl;
	btree_apply_infix(content->file, applyf);
}

void	display_trees(t_list *list)
{
	t_data	*tmp;

	ft_putendl("Affichage contenu des arbres");
	while (list)
	{
		tmp = (t_data *)list->content;
		ft_putendl(tmp->name);
		display_content_tree((tmp));
		list = list->next;
	}
}

void	display_data(t_list *list)
{
	t_data	*tmp;

	tmp = (t_data *)list->content;
	ft_putstr("name : ");
	ft_putendl(tmp->name);
	ft_putstr("pathname : ");
	ft_putendl(tmp->pathname);
	ft_putstr("error : ");
	ft_putnbr(tmp->error);
	ft_putchar('\n');
	print_flags(tmp->flags);
	ft_putendl("------");
}

void	print_list(t_list *list)
{
	while (list)
	{
		display_data(list);
		list = list->next;
	}
}

void	cb_ft_putendl(void *item)
{
	t_data	*tmp;

	tmp = (t_data *)item;
	ft_putstr("name : ");
	ft_putendl(tmp->name);
}
