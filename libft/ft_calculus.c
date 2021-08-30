/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:57:15 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 14:03:07 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_funny(t_pft *one)
{
	if (one->pres2neg)
		return (-one->pres2);
	else
		return (one->pres2);
}

void	ft_calculus(t_pft *one)
{
	int	cp;
	int	p2;

	cp = ft_strlen(one->result) - one->resultneg + one->null;
	p2 = ft_funny(one);
	if (one->pres2neg == 1)
		one->pres2 = 0;
	if (cp < one->pres1 || cp < one->pres2)
	{
		if (one->pres1 > 0)
			one->pres1 -= one->resultneg;
		if (p2 > 0)
		{
			one->pres2 -= cp;
			if (one->pres2 < 0)
				one->pres1 += one->pres2;
		}
		one->pres1 -= one->pres2 + cp;
	}
	else
	{
		one->pres1 = 0;
		one->pres2 = 0;
	}
}
