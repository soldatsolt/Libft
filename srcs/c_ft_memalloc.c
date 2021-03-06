/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ft_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:56:15 by kmills            #+#    #+#             */
/*   Updated: 2018/12/08 18:56:15 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*c_ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = c_malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
