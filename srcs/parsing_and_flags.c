/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:19:03 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/06 20:19:03 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_t_width(va_list vl, t_flags *fl, const char *restrict *format)
{
	if (**format == '*')
	{
		fl->width = (int)va_arg(vl, int);
		if (fl->width < 0)
		{
			fl->width *= -1;
			fl->minus = 1;
		}
		return ;
	}
	else
		fl->width = ft_atoi(*format);
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	make_t_precision(va_list vl, t_flags *fl, const char *restrict *format)
{
	(*format)++;
	if (**format == '*')
	{
		fl->precision = (int)va_arg(vl, int);
		(*format)++;
	}
	else
		fl->precision = ft_atoi(*format);
	if (fl->precision == -1)
		fl->precision = 0;
	while ((**format) >= '0' && (**format) <= '9')
		(*format)++;
	(*format)--;
}

void	preparcing3(va_list vl, t_flags *fl, const char *restrict *format)
{
	if ((**format) == ' ' && !fl->plus)
		fl->space = 1;
	if ((**format) == '#')
		fl->dash = 1;
	if ((**format) == '-')
	{
		fl->minus = 1;
		fl->zero = 0;
	}
	if ((**format) == '+')
	{
		fl->plus = 1;
		fl->space = 0;
	}
	if ((**format) == '0' && !fl->minus)
		fl->zero = 1;
	if (((**format) > '0' && (**format) <= '9') || (**format) == '*')
		make_t_width(vl, fl, format);
	if ((**format) == '.')
		make_t_precision(vl, fl, format);
	if ((**format) == 'l' && fl->l < 2)
		fl->l++;
	if ((**format) == 'j' && fl->l < 1)
		fl->l++;
}

void	preparcing2(va_list vl, t_flags *fl, const char *restrict *format)
{
	preparcing3(vl, fl, format);
	if ((**format) == 'h' && !fl->l && fl->h < 2)
		fl->h++;
	if ((**format) == 'L' && !fl->l && fl->h < 2)
		fl->ll++;
	(*format)++;
}

void	preparcing(va_list vl, t_buf **buf, t_flags *fl, \
const char *restrict *format)
{
	while ((**format) == ' ' || (**format) == '-' || (**format) == '+' || \
	((**format) >= '0' && (**format) <= '9') || (**format) == '#' || \
	(**format) == '.' || (**format) == 'h' || (**format) == 'l' || \
	(**format) == 'L' || (**format) == '*')
	{
		preparcing2(vl, fl, format);
	}
	if ((**format) == '%')
		percentage(buf, *fl);
}
