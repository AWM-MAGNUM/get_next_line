/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:16 by bel-kase          #+#    #+#             */
/*   Updated: 2022/12/03 19:28:26 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);
char	*ft_the_reader(int fd, char *unreal);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buff);
int		ft_strlen(char *s);
char	*ft_extracteur_the_line(char *BIG_LINE);
char	*ft_update_42(char *META);
#endif
