/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:30:23 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 21:19:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char *tcstr;
	char tcc;

	tcstr = (char*)str;
	tcc = (char)c;
	while (*tcstr && *tcstr != tcc)
	{
		tcstr++;
	}
	if (*tcstr == tcc)
		return (tcstr);
	return (0);
}
