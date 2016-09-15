/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:50:32 by ggane             #+#    #+#             */
/*   Updated: 2016/09/15 16:38:14 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	cb_ft_putendl(void *item)
{
	t_data	*tmp;

	tmp = (t_data *)item;
	ft_putstr("name : ");
	ft_putendl(item->name);
	ft_putstr("pathname : ");
	ft_putendl(item->pathname);
}

void	display_content_tree(t_data *content)
{
	void	(applyf *)(void *);

	applyf = &cb_ft_putendl;
	btree_apply_infix(content->files, applyf);
}

void	display_trees(t_list *list)
{
	while (list)
	{
		ft_putendl((char *)list->content->name);
		display_content_tree((t_data *)list->content);
		list = list->next;
	}
}

void	display_data(t_list *list)
{
	t_data	*tmp;

	tmp = (t_data *)list->content;
	ft_putstr("name : ");
	ft_putendl(tmp->name);
	/*ft_putstr("pathname : ");
	ft_putendl(tmp->pathname);
	ft_putstr("error : ");
	ft_putnbr(tmp->error);
	ft_putchar('\n');
	print_flags(tmp->flags);
	ft_putchar('\n');*/
	ft_putstr("is_dir : ");
	ft_putnbr(tmp->is_dir);
	ft_putchar('\n');
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

void	print_flags(int flags)
{
	int		switcher;

	switcher = 0;
	ft_putstr("flags ");
	if (flags & LOW_A_FLAG)
	{
		ft_putstr("-a ");
		switcher = 1;
	}
	if (flags & LOW_T_FLAG)
	{
		ft_putstr("-t ");
		switcher = 1;
	}
	if (flags & LOW_L_FLAG)
	{
		ft_putstr("-l ");
		switcher = 1;
	}
	if (flags & LOW_R_FLAG)
	{
		ft_putstr("-r ");
		switcher = 1;
	}
	if (flags & UPP_R_FLAG)
	{
		ft_putstr("-R ");
		switcher = 1;
	}
	if (switcher)
		ft_putendl(" activated\n");
	else
		ft_putendl(" not activated\n");
}
