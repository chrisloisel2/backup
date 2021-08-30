/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 01:20:23 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 13:54:03 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus(const char *s, va_list *ap, t_pft *one)
{
	one->minus = 1;
	one->index++;
	ft_get_all(s, ap, one);
	if (one->display == 's')
	{
		ft_putstr_pf(one->result + one->decal, one);
		one->resaff = 1;
	}
	if (one->flag != 0)
		ft_flag(one);
	if (one->resaff == 0)
		ft_putstr_pf(one->result + one->decal, one);
	while (one->pres1-- > 0)
		ft_putchar(' ', one);
	free(one->result);
}

void	ft_cast_min(t_pft *one)
{
	ft_putchar('-', one);
	one->decal = 1;
	one->resultneg = 0;
}

void	ft_fixstr2(t_pft *one)
{
	if (one->flag != 0)
	{
		one->truepres2 = 0;
		one->pres2 = 0;
		one->p2 = 0;
	}
	else
		one->pres1 = 0;
}

void	ft_fixstr(t_pft *one)
{
	int	i;

	if (one->flag != 0)
		i = one->pres2;
	else
		i = one->pres1;
	if (one->flag != 0 && one->pres2neg == 1)
		return ;
	if (one->flag == 0 && one->pres1neg == 1)
		return ;
	if (one->minus == 1 && one->flag == 0)
		return ;
	if (one->display == 's' && one->zero == 0)
	{
		if (one->flag == 0 && one->star == 1)
			return ;
		while (one->result[i] != '\0')
			one->result[i++] = '\0';
		ft_fixstr2(one);
	}
}
