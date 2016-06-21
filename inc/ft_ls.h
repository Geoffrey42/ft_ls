/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:00:39 by ggane             #+#    #+#             */
/*   Updated: 2016/06/21 22:42:27 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# define FLAGS_SIZE 255
# define LOW_A_FLAG 1
# define LOW_T_FLAG 2
# define LOW_L_FLAG 4
# define LOW_R_FLAG 8
# define UPP_R_FLAG 16

typedef struct	s_info
{
	int			flags;
	int			argc;
	int			directory_presence;
	int			directory_position;
	int			nb_directories;
}				t_info;

/* info_line.c */
t_info			*set_directories_info(t_info *info_line, int ac, char **av);
t_info			*initialize_info_line(t_info *info_line);

/* parser.c */
int				add_flags(char *to_check, t_info *info_line, int i);
int				check_authorized_flags(char *to_check, t_info *info_line);
int				walkthrough_command_line(int ac, char **av, t_info *info_line);
int				parse_flags(int ac, char **av, t_info *info_line);

/* display.c */
void			display_flags_error_msg(char bad_option);

/* sort_directories.c */
t_btree			*insert_data
				(t_info *info_line, int (*cmpf)(void *, void *), char **av);
t_btree			*put_directories_in_a_tree
				(t_info *info_line, t_btree *sorted_dir, char **av);
t_btree			*put_current_directory_in_a_tree(t_btree *root);
t_btree			*sort_directories
				(t_info *info_line, char **av, t_btree *sorted_dir);

/* call_back_functions.c */
void			cb_ft_putendl(void *str);
int				cb_ft_timecmp(void *item1, void *item2);
int				cb_ft_strcmp(void *s1, void *s2);

#endif
