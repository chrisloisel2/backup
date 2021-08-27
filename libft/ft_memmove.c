/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:12:19 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/27 03:38:31 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*cpy;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	cpy = malloc(sizeof(char) * (n + 1));
	s2 = (unsigned char *)src;
	s1 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cpy[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s1[i] = cpy[i];
		i++;
	}
	return (dest);
}
