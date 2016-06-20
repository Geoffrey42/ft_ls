/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:29:27 by ggane             #+#    #+#             */
/*   Updated: 2016/06/20 19:17:28 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"

void	affiche_flags(int flags)
{
	if (flags)
	{
		printf("option -a : ");
		printf((flags & LOW_A_FLAG) ? "set\n" : "unset\n");
		printf("option -r : ");
		printf((flags & LOW_R_FLAG) ? "set\n" : "unset\n");
		printf("option -l : ");
		printf((flags & LOW_L_FLAG) ? "set\n" : "unset\n");
		printf("option -R : ");
		printf((flags & UPP_R_FLAG) ? "set\n" : "unset\n");
		printf("option -t : ");
		printf((flags & LOW_T_FLAG) ? "set\n" : "unset\n");
	}
}

int		main(int ac, char **av)
{
	t_info	info_line;

	if (parse_flags(ac, av, &info_line))
		return (1);
	affiche_flags(info_line.flags);
	return (0);
}
