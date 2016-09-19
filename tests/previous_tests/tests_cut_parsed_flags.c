/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_cut_parsed_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:35:22 by ggane             #+#    #+#             */
/*   Updated: 2016/06/07 18:51:53 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"

int		calcule_nb_flags(int ac, char **av)
{
	int		i;
	int		nb_flags;

	i = 1;
	nb_flags = 0;
	while (i <= ac - 1)
	{
		if (av[i][0] == '-')
			nb_flags++;
		i++;
	}
	printf("nb_flags : %d\n", nb_flags);
	return (nb_flags);
}

void	parcours_line(int fin, char **av)
{
	int		i;

	i = 0;
	while (i < fin)
	{
		printf("[%s] ", av[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		nb_flags;

	nb_flags = calcule_nb_flags(ac, av);
	printf("before the cut : ");
	parcours_line(ac, av);
	printf("\n");
	printf("after the cut : ");
	if (check_if_directories(ac, av))
		av = cut_parsed_flags(av);
	parcours_line(ac - nb_flags, av);
	printf("\n");
	return (0);
}
