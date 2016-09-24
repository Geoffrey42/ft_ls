/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:57:08 by ggane             #+#    #+#             */
/*   Updated: 2016/09/24 12:11:43 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	switcher(int *switcher, int flags)
{
	if (flags & LOW_A_FLAG)
	{
		ft_putstr("-a ");
		*switcher = 1;
	}
	if (flags & LOW_T_FLAG)
	{
		ft_putstr("-t ");
		*switcher = 1;
	}
	if (flags & LOW_L_FLAG)
	{
		ft_putstr("-l ");
		*switcher = 1;
	}
	if (flags & LOW_R_FLAG)
	{
		ft_putstr("-r ");
		*switcher = 1;
	}
	if (flags & UPP_R_FLAG)
	{
		ft_putstr("-R ");
		*switcher = 1;
	}
}

void	print_flags(int flags)
{
	int		switcher_v;

	switcher_v = 0;
	ft_putstr("flags ");
	switcher(&switcher_v, flags);
	if (switcher_v)
		ft_putendl(" activated\n");
	else
		ft_putendl(" not activated\n");
}
