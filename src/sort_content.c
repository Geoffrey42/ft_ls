/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:30:06 by ggane             #+#    #+#             */
/*   Updated: 2016/06/23 17:46:29 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_btree		*sort_files(t_data *meta_data, t_btree *tree)
{
	int		(*cmpf)(void *, void *);

	cmpf = choose_compare_file_function(meta_data, 0);
	tree = insert_files(meta_data, cmpf);
	return (tree);
}

t_applyf	choose_apply_function(t_info *info_line)
{
	void	(*applyf)(void *);

	if (info_line->flags & UPP_R_FLAG)
		return (applyf = &cb_recursive_applyf);
	else
		return (applyf = &cb_non_recursive_applyf);
}

void		sort_content(t_info *info_line, t_btree *directories)
{
	void	(*applyf)(void *);

	applyf = choose_apply_function(info_line);
	directories = choose_traversal_function(info_line, directories);
	erase_directories_tree(&directories);
}
