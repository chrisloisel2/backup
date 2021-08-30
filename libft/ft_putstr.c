/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 02:06:43 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/30 13:46:27 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *s, t_pft *one)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr_pf("(null)", one);
	else
	{
		while (s[i] != '\0' || one->null == 1)
		{
			if (one->null == 1)
				one->null = 0;
			ft_putchar(s[i], one);
			i++;
		}
	}
}

void	ft_putchar(char c, t_pft *one)
{
	write(1, &c, 1);
	one->cpt++;
}

void	ft_point(unsigned long p, t_pft *one)
{
	ft_putstr_pf("0x", one);
	ft_puthexa(p, one);
}
