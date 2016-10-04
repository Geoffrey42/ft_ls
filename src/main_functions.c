/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:28:52 by ggane             #+#    #+#             */
/*   Updated: 2016/09/30 11:45:04 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*parse_prompt(int ac, char **av)
{
	t_data	*info_line;

	info_line = initialize_info_line(ac, av);
	parse_flags(info_line);
	parse_directories(info_line);
	return (info_line);
}

t_list	*list_and_sort_directories(t_data *info_line)
{
	t_list	*directories;

	directories = create_directories_list(info_line);
	merge_sort(&directories);
	return (directories);
}

t_list	*put_content_in_trees(t_list *directories)
{
	t_data			*data;

	data = (t_data *)directories->content;
	directories = insertion_stage(directories);
	traversal_stage(directories);
	return (directories);
}
