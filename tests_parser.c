/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:29:27 by ggane             #+#    #+#             */
/*   Updated: 2016/06/20 17:31:31 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"

void	affiche_flags(int *flags)
{
	if (flags)
	{
		printf("option -a : ");
		printf((flags['a']) ? "set\n" : "unset\n");
		printf("option -r : ");
		printf((flags['r']) ? "set\n" : "unset\n");
		printf("option -l : ");
		printf((flags['l']) ? "set\n" : "unset\n");
		printf("option -R : ");
		printf((flags['R']) ? "set\n" : "unset\n");
		printf("option -t : ");
		printf((flags['t']) ? "set\n" : "unset\n");
	}
}

int		main(int ac, char **av)
{
	t_info	*info_line;

	ft_putendl("start main");
	info_line = NULL;
	info_line = parse_flags(ac, av, info_line);
	ft_putendl("parse ok");
	affiche_flags(info_line->flags);
	ft_putendl("end main");
	//free(flags);
	return (0);
}
