/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:12:09 by ggane             #+#    #+#             */
/*   Updated: 2016/05/31 23:23:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <uuid/uuid.h>

char	*keep_necessary_timedata(char *long_time)
{
	char	*shorter_time;
	char	*ptr;

	shorter_time = (char *)malloc(sizeof(char) * 13);
	if (!shorter_time)
		return (NULL);
	ptr = long_time + 4;
	shorter_time = strncpy(shorter_time, ptr, 12);	
	shorter_time[12] = '\0';
	return (shorter_time);
}

int		inspect_file(char *file)
{
	struct stat		file_stat;
	struct passwd	*usr_id;
	struct group	*grp_id;
	char			*time;

	if (lstat(file, &file_stat) < 0)
		return (1);
	printf("Nom : %s\n", file);
	printf("Type : ");
	if (S_ISDIR(file_stat.st_mode))
		printf("dossier\n");
	else
		printf("fichier\n");
	printf("Mode : ");
	printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
	printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	printf("Nombre de liens : %d\n", file_stat.st_nlink);
	usr_id = getpwuid(file_stat.st_uid);
	printf("Proprietaire : %s\n", usr_id->pw_name);
	grp_id = getgrgid(file_stat.st_gid);
	printf("Groupe : %s\n", grp_id->gr_name);
	printf("Taille : %lld octets\n", file_stat.st_size);
	time = keep_necessary_timedata(ctime(&file_stat.st_mtime));
	printf("Date de derniere modification : %s\n", time);
	printf("Date de derniere modification : %ld\n", file_stat.st_mtime);
	return (0);
}

int		main(int ac, char **av)
{
	int		i = 1;
	int		ret;

	while (i <= ac - 1)
	{
		ret = inspect_file(av[i]);
		i++;
	}
	return (0);
}
