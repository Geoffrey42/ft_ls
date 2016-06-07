/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_parsed_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:15:17 by ggane             #+#    #+#             */
/*   Updated: 2016/06/07 18:51:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		check_if_directories(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-')
			return (1);
		i++;
	}
	return (0);
}

char	**cut_parsed_flags(char **av)
{
	av++;
	while (**av == '-' && av != NULL)
		av++;
	return (av);
}
