/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:27:38 by kmills            #+#    #+#             */
/*   Updated: 2019/09/19 19:08:10 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTOR_H
# define COLLECTOR_H

# include "libft.h"

t_coll	*init_collector(void);
t_coll	*collector(void);
void	*c_malloc(size_t size);
void	garbage_free_all(void);
void	garbage_free_this(void *data);

#endif
