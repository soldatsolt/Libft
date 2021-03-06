/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:47:04 by kmills            #+#    #+#             */
/*   Updated: 2018/10/23 16:17:22 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*c;

	c = dest;
	while (*src != '\0')
	{
		*dest = (char)*src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (c);
}
