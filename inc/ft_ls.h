/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:28:09 by ggane             #+#    #+#             */
/*   Updated: 2016/09/22 14:22:00 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# define LOW_A_FLAG 1
# define LOW_T_FLAG 2
# define LOW_L_FLAG 4
# define LOW_R_FLAG 8
# define UPP_R_FLAG 16

typedef struct	s_info
{
	char		**av;
	int			ac;
	int			flags;
	int			nb_dir;
	int			dir_pos;
}				t_info;

typedef struct	s_data
{
	char		*name;
	char		*pathname;
	int			error;
	int			flags;
	int			is_dir;
	t_btree		*file;
}				t_data;

typedef int		(*t_cmpf)(void *, void *);

//recursive_flag.c

void			create_new_dir_list(t_data *old_data, t_list **new_dir);
void			reverse_recursive_infix(int flags, t_btree *root, t_list **new_dir);
void			regular_recursive_infix(int flags, t_btree *root, t_list **new_dir);
t_list			*choose_recursive_infix_traversal(t_list *list, t_list *new_dir);
//t_list			*recursive_traversal_stage(t_list *directories);
void			recursive_traversal_stage(t_list *directories);
//traversal_stage.c

void			choose_infix_traversal(int flags, t_btree *tree,
				void (*applyf)(void *));
void			display_content(void *item);
//t_list			*traversal_stage(t_list *directories);
void			traversal_stage(t_list *directories);
void			display_dir_title(char *name);

//insertion_stage.c

t_cmpf			choose_compare_tree_function(t_data *data);
t_btree			*insert_data_in_tree(t_data *data, t_btree *content,
				char *file_name, int (*cmpf)(void *, void *));
t_btree			*insert_content(t_list *directories,
				int (*cmpf)(void *, void *));
t_list			*open_directory(t_list *directories);
t_list			*insertion_stage(t_list *directories);
t_list			*put_content_in_trees(t_list *directories);

//compare_list_data.c

int				choose_compare_list_function(t_list *item1, t_list *item2);
int				check_nanoseconds(char *str1, char *str2);
int				cb_timecmp_list(char *str1, char *str2);
int				cb_timecmp_tree(void *item1, void *item2);
int				cb_strcmp_tree(void *item1, void *item2);
int				check_nanoseconds_tree(void *item1, void *item2);

//create_data_dir.c

int				check_if_error_dir(char *name);
char			*create_pathname(char *parent, char *son);
t_data			*initialize_data_dir(char *name, char *parent, int flags);
t_data			*initialize_data_dir_first_call
				(char *name, char *parent, int flags);

//merge_sort.c

t_list			*merge_lists(t_list *a, t_list *b);
void			partition(t_list *head, t_list **front, t_list **back);
void			merge_sort(t_list **source);

//list_directories.c

t_list			*insert_current_directory(int flags);
t_list			*insert_several_directories(t_info *info_line);
t_list			*check_and_insert_data
				(t_list *directories, char *name, int flags);
t_list			*create_directories_list(t_info *info_line);
t_list			*list_and_sort_directories(t_info *info_line);

//parser_flags.c

void			check_binary_mask(t_info *info_line, char *to_check, int j);
void			check_authorized_flags(t_info *info_line, char *to_check);
void			parse_flags(t_info *info_line);

//parser_directories.c

void			check_dir_position(t_info *info_line);
void			check_nb_directories(t_info *info_line);
void			parse_directories(t_info *info_line);

//parser.c

char			**copy_av(int ac, char **av);
t_info			*initialize_info_line(int ac, char **av);
t_info			*parse_prompt(int ac, char **av);

//display_errors.c

void			display_flag_error_msg(char bad_option);

//test_functions.c

void			display_data(t_list *list);
void			print_list(t_list *list);
void			print_flags(int flags);
void			cb_ft_putendl(void *item);
void			display_content_tree(t_data *content);
void			display_trees(t_list *list);

#endif
