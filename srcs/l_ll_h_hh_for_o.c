/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_ll_h_hh_for_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:18:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/06 20:18:27 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_str_with_precision_for_hho(t_flags fl, u_int8_t k)
{
	char	*s;
	int		i;
	char	*str;

	if (fl.precision == 0 && k == 0 && !fl.dash)
		return (ft_strdup(""));
	str = ft_itoa_base_small_hh(k, 8);
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - (int)ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_ho(t_flags fl, unsigned short k)
{
	char	*s;
	int		i;
	char	*str;

	if (fl.precision == 0 && k == 0 && !fl.dash)
		return (ft_strdup(""));
	str = ft_itoa_base_small_h(k, 8);
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - (int)ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_llo(t_flags fl, unsigned long long k)
{
	char	*s;
	int		i;
	char	*str;

	if (fl.precision == 0 && k == 0 && !fl.dash)
		return (ft_strdup(""));
	str = ft_itoa_base_small_ll(k, 8);
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - (int)ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}

char	*make_str_with_precision_for_lo(t_flags fl, unsigned long k)
{
	char	*s;
	int		i;
	char	*str;

	if (fl.precision == 0 && k == 0 && !fl.dash)
		return (ft_strdup(""));
	str = ft_itoa_base_small_l(k, 8);
	if (fl.precision != -1 && (((int)ft_strlen(str) <= fl.precision)))
	{
		i = 0;
		s = ft_strnew(sizeof(char) * (fl.precision + 1));
		while (i < fl.precision - (int)ft_strlen(str))
		{
			s[i] = '0';
			i++;
		}
		s = ft_strcpy(&(s[i]), str);
		s = s - i;
		free(str);
		str = NULL;
		s[fl.precision] = '\0';
	}
	else
		s = str;
	return (s);
}
