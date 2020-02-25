/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:19:08 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/06 20:19:08 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_precision(t_double *dd, t_buf **buf, t_flags *fl)
{
	while (fl->precision-- && dd->mantissa[dd->i])
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	while (fl->precision-- >= 0)
		put_char_to_buf(buf, '0');
}

void	double_zero(t_double *dd, t_buf **buf, t_flags *fl)
{
	if (dd->sign)
		put_char_to_buf(buf, '-');
	else if (fl->plus)
		put_char_to_buf(buf, '+');
	else if (fl->space)
		put_char_to_buf(buf, ' ');
	dd->i = 0;
	while (dd->i < dd->dot - 1 && dd->mantissa[dd->i] == '0')
		dd->i++;
	while (fl->width-- > 0)
		put_char_to_buf(buf, '0');
	while (dd->i < dd->dot)
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	if ((fl->dash && !fl->precision) || fl->precision)
		put_char_to_buf(buf, '.');
	ft_put_precision(dd, buf, fl);
}

void	double_just(t_double *dd, t_buf **buf, t_flags *fl)
{
	while (fl->width-- > 0)
		put_char_to_buf(buf, ' ');
	if (dd->sign)
		put_char_to_buf(buf, '-');
	else if (fl->plus)
		put_char_to_buf(buf, '+');
	else if (fl->space)
		put_char_to_buf(buf, ' ');
	dd->i = 0;
	while (dd->i < dd->dot - 1 && dd->mantissa[dd->i] == '0')
		dd->i++;
	while (dd->i < dd->dot)
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	if ((fl->dash && !fl->precision) || fl->precision)
		put_char_to_buf(buf, '.');
	ft_put_precision(dd, buf, fl);
}

void	double_minus(t_double *dd, t_buf **buf, t_flags *fl)
{
	if (dd->sign)
		put_char_to_buf(buf, '-');
	else if (fl->plus)
		put_char_to_buf(buf, '+');
	else if (fl->space)
		put_char_to_buf(buf, ' ');
	dd->i = 0;
	while (dd->i < dd->dot - 1 && dd->mantissa[dd->i] == '0')
		dd->i++;
	while (dd->i < dd->dot)
		put_char_to_buf(buf, dd->mantissa[dd->i++]);
	if ((fl->dash && !fl->precision) || fl->precision)
		put_char_to_buf(buf, '.');
	ft_put_precision(dd, buf, fl);
	while (fl->width-- > 0)
		put_char_to_buf(buf, ' ');
}

void	f_flag(va_list vl, t_buf **buf, t_flags fl)
{
	if (fl.ll)
		long_double_flag(vl, buf, fl);
	else
		double_flag(vl, buf, fl);
}
