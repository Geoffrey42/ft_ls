/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:27:39 by ggane             #+#    #+#             */
/*   Updated: 2016/09/11 18:02:37 by ggane            ###   ########.fr       */
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
	sort_content(&directories, info_line);
	print_content(directories, info_line);
	erase_list(&directories);
	return (0);
}
