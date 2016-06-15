/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:00:39 by ggane             #+#    #+#             */
/*   Updated: 2016/06/15 20:17:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# define FLAGS_SIZE 255

/* parser.c */
int			*parse_flags(int ac, char **av);
int			check_authorized_flags(char *option, int *flags);

/* display.c */
void		display_flags_error_msg(char bad_option);

/* sort_directories.c */
t_btree		*put_directories_in_a_tree(int start, int ac, char **av);
int			check_directories_presence(int ac, char **av);
t_btree		*sort_directories(int ac, char **av);

/* call_back_functions.c */
int			cb_ft_strcmp(void *s1, void *s2);

#endif
