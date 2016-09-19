/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insertion_stage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:04:37 by ggane             #+#    #+#             */
/*   Updated: 2016/09/19 16:38:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ft_ls.h"

int		main(int ac, char **av)
{
	t_info	*info_line;
	t_list	*directories;

	directories = NULL;
	info_line = parse_prompt(ac, av);
	directories = list_and_sort_directories(info_line);
	directories = insertion_stage(directories);
	display_trees(directories);
	return (0);
}
