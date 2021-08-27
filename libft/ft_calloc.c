/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:23:45 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/27 03:27:57 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		total;
	char	*c;
	void	*pt;
	void	*start;

	total = count * size;
	pt = malloc(total);
	start = pt;
	while (total--)
	{
		c = (char *)pt;
		*c = 0;
		pt++;
	}
	return (start);
}
