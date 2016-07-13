/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_if_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 12:22:01 by ggane             #+#    #+#             */
/*   Updated: 2016/07/07 12:35:46 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_ls.h"

void	test_if_dir(char *to_check)
{
	int		res;

	res = check_if_dir(to_check);
	printf(res ? "%s dossier (%d)\n" : "%s fichier (%d)\n", to_check, res);
}

int		main(int ac, char **av)
{
	int		i = 1;

	while (i <= ac - 1)
		test_if_dir(av[i++]);
	return (0);
}
