/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:40:44 by ggane             #+#    #+#             */
/*   Updated: 2016/09/10 15:54:00 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int     check_if_error_dir(char *name)
{
    return (0);
}

char    *create_pathname(char *parent, char *son)
{
    parent = ft_strjoin(parent, "/");
    son = ft_strjoin(parent, son);
    return (son);
}

t_data  *initialize_data_dir(char *name)
{
    t_data  *data_dir;

    if (!(data_dir = (t_data *)malloc(sizeof(t_data))))
        return (NULL);
    data_dir->name = ft_strdup(name);
    data_dir->pathname = create_pathname(ft_strdup(""), name);
    data_dir->error = check_if_error_dir(name);
    return (data_dir);
}
