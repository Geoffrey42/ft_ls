/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:29:27 by ggane             #+#    #+#             */
/*   Updated: 2016/06/21 14:16:33 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"

void	check_dir(t_info *info_line)
{
	printf("Il y a t'il des dossiers ?\n");
	printf((info_line->directory_presence) ? "oui\n" : "non\n");
	printf("Quelle est la position du 1er dossier ?\n");
	printf((info_line->directory_position == -1) ? "Il n'y en a pas !\n" : "C'est : ");
	if (info_line->directory_presence)
	{
		printf("%d\n", info_line->directory_position);
		printf("Combien il y en a ?\nIl y en a %d\n", info_line->nb_directories);
	}
}

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
	check_dir(&info_line);
	return (0);
}
