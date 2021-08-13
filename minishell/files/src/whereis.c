/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whereis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	whereis_util(struct dirent **sd, DIR **dir, char *target[], int j)
{
	*dir = opendir(target[j]);
	if (*dir)
		*sd = readdir(*dir);
	else
		*sd = NULL;
}

void	ft_whereis(char **cmd[], char *target[])
{
	DIR				*dir;
	struct dirent	*sd;
	int				j;

	j = 0;
	while (target[j])
	{
		whereis_util(&sd, &dir, target, j);
		while (sd)
		{
			while (sd && ft_strcmp(sd->d_name, (*cmd)[0]))
				sd = readdir(dir);
			if (sd)
			{
				free((*cmd)[0]);
				(*cmd)[0] = ft_strjoin(ft_strdup(target[j]),
						ft_strdup(sd->d_name), '/');
				closedir(dir);
				return ;
			}
		}
		if (dir)
			closedir(dir);
		j++;
	}
}
