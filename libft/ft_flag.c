/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 02:08:25 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 14:07:34 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag(t_pft *one)
{
	if (one->flag == '.')
	{
		if (one->pres2neg == 0)
		{
			if (one->resultneg == 1 && one->resaff == 0)
				ft_cast_min(one);
			if (one->point == 1)
				ft_putstr_pf("0x", one);
			while (one->pres2-- > 0 && one->pres2neg == 0)
				ft_putchar('0', one);
		}
	}
	if (one->flag == '-')
		ft_minus_flag(one);
}

int	ft_checkflag(char c)
{
	if (c == '.')
		return (1);
	if (c == '0')
		return (1);
	if (c == '-')
		return (1);
	return (0);
}

int	ft_checkdisplay(char c)
{
	if (c == 'c')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

void	ft_minus_flag(t_pft *one)
{
	if (one->pres2neg == 0)
	{
		if (one->resultneg == 1 && one->resaff == 0)
		{
			ft_cast_min(one);
			one->pres2--;
		}
		ft_putstr_pf(one->result + one->decal, one);
		one->resaff = 1;
		while (one->pres2-- > 0 && one->pres2neg == 0)
			ft_putchar(' ', one);
	}
}
