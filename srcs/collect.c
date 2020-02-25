/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:27:38 by kmills            #+#    #+#             */
/*   Updated: 2019/09/19 19:08:10 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collector.h"

t_coll	*init_collector(void)
{
	t_coll	*col;

	col = (t_coll *)malloc(sizeof(t_coll));
	col->next = NULL;
	col->rub = NULL;
	return (col);
}

t_coll	*collector(void)
{
	static t_coll	*col;
	static int		n = 0;

	if (!n)
	{
		col = init_collector();
		n++;
	}
	return (col);
}

void	*c_malloc(size_t size)
{
	t_coll	*tmp;
	void	*data;

	tmp = collector();
	data = malloc(size);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = init_collector();
	tmp->next->rub = data;
	return (data);
}

void	garbage_free_this(void *data)
{
	t_coll	*tmp;

	tmp = collector();
	while (tmp && tmp->rub != data)
		tmp = tmp->next;
	if (tmp && tmp->rub == data)
	{
		free(tmp->rub);
		tmp->rub = NULL;
	}
}

void	garbage_free_all(void)
{
	t_coll	*tmp;
	t_coll	*head;

	head = collector();
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->rub)
			free(tmp->rub);
		free(tmp);
	}
}
