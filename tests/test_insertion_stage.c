/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insertion_stage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:04:37 by ggane             #+#    #+#             */
/*   Updated: 2016/09/21 23:31:57 by ggane            ###   ########.fr       */
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
	directories = put_content_in_trees(directories);
	/*directories = insertion_stage(directories);
	print_list(directories);
	directories = traversal_stage(directories);*/
	//display_trees(directories);
	return (0);
}
