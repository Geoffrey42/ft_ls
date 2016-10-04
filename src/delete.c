/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:23:39 by ggane             #+#    #+#             */
/*   Updated: 2016/09/30 11:37:56 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	delete_content(void *to_delete, size_t size)
{
	t_data	*data;

	data = (t_data *)to_delete;
	free(data->name);
	free(data->pathname);
	free(data);
	data = NULL;
	to_delete = NULL;
	size = 0;
}

void	erase_list(t_list **directories)
{
	void	(*del)(void *, size_t);

	del = &delete_content;
	ft_lstdel(directories, del);
}
