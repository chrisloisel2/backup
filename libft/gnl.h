/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 02:22:24 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/27 07:00:01 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <unistd.h>
# include "libft.h"
# include <string.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*ft_sub_str(char const *s, unsigned int start, size_t len);
int		ft_checkfile(char *line);
int		get_next_line(int fd, char **line);
void	ft_freenull(char **stat);
int		ft_supp_gnl(char *stat, char **line);
char	*ft_run_stat(char *stat);

#endif
