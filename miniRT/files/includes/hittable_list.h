/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:59:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 20:59:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include "sphere.h"



typedef struct				s_hittable_list
{
	t_sphere				*obj;
	struct s_hittable_list	*next;
	bool					(*hit)(t_params_list*, struct s_hittable_list*);
}							t_hittable_list;


t_params_list		set_lstparam_values(
											t_ray r,
											double t_min,
											double t_max,
											t_hit_record *rec
										);
bool				hittable_list_hit(
										t_params_list *params,
										t_hittable_list *lst
									);
int					ft_lstsize(t_hittable_list *lst);
t_hittable_list		*ft_lstnew(void *content);
t_hittable_list		*ft_lstlast(t_hittable_list *lst);
void				ft_lstadd_back(t_hittable_list **lst, t_hittable_list *new);

#endif
