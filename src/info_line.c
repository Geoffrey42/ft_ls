/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:22:42 by ggane             #+#    #+#             */
/*   Updated: 2016/09/25 19:33:48 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	**copy_av(int ac, char **av)
{
	char	**copy;
	int		i;

	i = 0;
	copy = NULL;
	if (!(copy = (char **)malloc(sizeof(char *) * ac)))
		return (NULL);
	while (i < ac - 1)
	{
		copy[i] = ft_strdup(av[i + 1]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

t_data	*initialize_info_line(int ac, char **av)
{
	t_data	*info_line;

	info_line = NULL;
	if (!(info_line = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	info_line->av = copy_av(ac, av);
	info_line->ac = ac - 1;
	info_line->flags = 0;
	info_line->nb_dir = 0;
	info_line->nb_sub_dir = 0;
	info_line->dir_pos = -1;
	return (info_line);
}
