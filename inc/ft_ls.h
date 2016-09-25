/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:28:09 by ggane             #+#    #+#             */
/*   Updated: 2016/09/25 21:15:44 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include "../libft/libft.h"

# define LOW_A_FLAG 1
# define LOW_T_FLAG 2
# define LOW_L_FLAG 4
# define LOW_R_FLAG 8
# define UPP_R_FLAG 16

typedef struct	s_data
{
	char		**av;
	int			ac;
	int			flags;
	int			nb_dir;
	int			nb_sub_dir;
	int			dir_pos;
	char		*name;
	char		*pathname;
	int			error;
	int			first_call;
	t_btree		*file;
}				t_data;

typedef int		(*t_cmpf)(void *, void *);

//long_format_flag_3.c

void			display_size(struct stat file_stat);
void			print_total_size(size_t size);
size_t			sum_file_sizes(t_data *directory, struct dirent *file);
void			display_total_size(t_data *directory);

//long_format_flag_2.c

void			display_total_size(t_data *directory);
void			display_type_file(struct stat file_stat);
void			display_rights(struct stat file_stat);
void			display_links(struct stat file_stat);
void			display_id(struct stat file_stat);

//long_format_flag_1.c

void			display_file_mode(struct stat file_stat);
void			display_size(struct stat file_stat);
char			*keep_necessary_timedata(char *long_time);
void			display_date(struct stat file_stat);
void			display_long_format(t_data *data);

//display.c

void			display_new_line(t_list *list);
void			display_dir_title(t_data *content);
void			display_short_format(t_data *data);
void			choose_format_to_display(t_data *data);
void			display_content(void *item);

//main_functions.c

t_data			*parse_prompt(int ac, char **av);
t_list			*list_and_sort_directories(t_data *info_line);
t_list			*put_content_in_trees(t_list *directories);

//delete.c

void			delete_content(void *to_delete, size_t size);
void			erase_list(t_list **directories);

//recursive_flag.c

void			create_new_dir_list(t_data *old_data, t_list **new_dir);
void			reverse_recursive_infix
				(int flags, t_btree *root, t_list **new_dir);
void			regular_recursive_infix
				(int flags, t_btree *root, t_list **new_dir);
t_list			*choose_recursive_infix_traversal
				(t_list *list, t_list *new_dir);
void			recursive_traversal_stage(t_list *directories);

//traversal_stage.c

int				recall_sub_dir_number(t_list *recursive);
void			recursive_call(t_list *recursive);
void			files_list(t_list *files);
t_list			*display_only_directories(t_list *directories);
t_list			*directories_list(t_list *directories);
void			choose_infix_traversal(int flags, t_btree *tree,
				void (*applyf)(void *));
void			traversal_stage(t_list *directories);

//insertion_stage.c

t_cmpf			choose_compare_tree_function(t_data *data);
t_btree			*insert_data_in_tree(t_data *data, t_btree *content,
				char *file_name, int (*cmpf)(void *, void *));
t_btree			*insert_content(t_list *directories,
				int (*cmpf)(void *, void *));
t_list			*open_directory(t_list *directories);
t_list			*insertion_stage(t_list *directories);

//compare_tree_data.c

int				cb_timecmp_tree(void *item1, void *item2);
int				cb_strcmp_tree(void *item1, void *item2);
int				check_nanoseconds_tree(void *item1, void *item2);

//compare_list_data.c

int				choose_compare_list_function(t_list *item1, t_list *item2);
int				check_nanoseconds_list(char *str1, char *str2);
int				cb_timecmp_list(char *str1, char *str2);

//create_data_dir.c

int				check_if_error_dir(char *name);
char			*create_pathname(char *parent, char *son);
t_data			*init_rec_data(char *name, char *parent, t_list *list);
t_data			*initialize_data_dir(char *name, char *parent, t_data *info);
t_data			*initialize_data_dir_first_call
				(char *name, char *parent, t_data *info);

//merge_sort.c

t_list			*merge_lists(t_list *a, t_list *b);
void			partition(t_list *head, t_list **front, t_list **back);
void			merge_sort(t_list **source);

//create_directories_list.c

t_list			*insert_current_directory(t_data *info_line);
t_list			*insert_several_directories(t_data *info_line);
t_list			*insert_data_in_list
				(t_list *directories, char *name, t_data *info_line);
t_list			*create_directories_list(t_data *info_line);

//parser_flags.c

int				check_flags_for_new_line(t_data *content);
void			check_binary_mask(t_data *info_line, char *to_check, int j);
void			check_authorized_flags(t_data *info_line, char *to_check);
void			parse_flags(t_data *info_line);

//parser_directories.c

void			check_dir_position(t_data *info_line);
void			check_nb_directories(t_data *info_line);
void			parse_directories(t_data *info_line);

//info_line.c

char			**copy_av(int ac, char **av);
t_data			*initialize_info_line(int ac, char **av);

//errors_traversal.c

void			zero_flags(t_list *error);
void			display_error_list(t_list *error);
void			display_unknow_files(t_list *files);

//display_errors.c

void			display_permission_denied(t_data *content);
void			display_unknow_error_msg(char *file);
void			display_flag_error_msg(char bad_option);

//test_functions_2.c

void			switcher(int *switcher, int flags);
void			print_flags(int flags);

//test_functions_1.c

void			display_data(t_list *list);
void			print_list(t_list *list);
void			display_content_tree(t_data *content);
void			display_trees(t_list *list);
void			cb_ft_putendl(void *item);

#endif
