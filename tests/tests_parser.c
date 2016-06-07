/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:29:27 by ggane             #+#    #+#             */
/*   Updated: 2016/06/07 13:45:13 by ggane            ###   ########.fr       */
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
	int		*flags;

	flags = parse_flags(ac, av);
	affiche_flags((int *)flags);
	free(flags);
	return (0);
}
