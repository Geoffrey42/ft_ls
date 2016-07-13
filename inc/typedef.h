/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:14:28 by ggane             #+#    #+#             */
/*   Updated: 2016/07/13 18:15:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct		s_info
{
	int				flags;
	int				argc;
	int				directory_presence;
	int				directory_position;
	int				position;
	int				nb_directories;
}					t_info;

typedef struct		s_data
{
	char			*file_name;
	char			*pathname;
	int				flags;
	int				is_dir;
	int				nb_directories;
	int				position;
	long long int	total_size;
}					t_data;

typedef int			(*t_cmpf)(void *, void *);
typedef void		(*t_applyf)(void *);

#endif
