/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:50:32 by ggane             #+#    #+#             */
/*   Updated: 2016/09/11 19:37:36 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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
