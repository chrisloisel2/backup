/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 00:28:25 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 14:36:44 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_star(const char *s, va_list *ap, t_pft *one)
{
	one->star = 1;
	ft_get_all(s, ap, one);
	if (one->pres1neg == 0)
	{
		while (one->pres1-- > 0)
			ft_putchar(' ', one);
		if (one->flag != 0)
			ft_flag(one);
		if (one->resaff == 0)
			ft_putstr_pf(one->result + one->decal, one);
	}
	else
	{
		if (one->flag != 0)
			ft_flag(one);
		if (one->resaff == 0)
			ft_putstr_pf(one->result + one->decal, one);
		while (one->pres1-- > 0)
			ft_putchar(' ', one);
	}
	free(one->result);
}

void	ft_varum(const char *s, va_list *ap, t_pft *one)
{
	if (s[one->index] == 'p')
		ft_point(va_arg(*ap, unsigned long), one);
	if (s[one->index] == 'd')
		ft_putnbr(va_arg(*ap, int), one);
	if (s[one->index] == 'i')
		ft_putnbr(va_arg(*ap, unsigned int), one);
	if (s[one->index] == 's')
		ft_putstr_pf(va_arg(*ap, char *), one);
	if (s[one->index] == 'c')
		ft_putchar(va_arg(*ap, int), one);
	if (s[one->index] == '%')
		ft_putchar('%', one);
	if (s[one->index] == '*')
		ft_star(s, ap, one);
	if (s[one->index] == '.')
		ft_dot(s, ap, one);
	if (s[one->index] == '-')
		ft_minus(s, ap, one);
	if (s[one->index] == '0')
		ft_zero(s, ap, one);
	if (ft_alpha(s[one->index]))
		ft_star(s, ap, one);
	if (s[one->index] == '\0')
		one->index--;
}
