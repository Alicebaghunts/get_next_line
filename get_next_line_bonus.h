/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 10:58:13 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-11 10:58:13 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_cut_str(char *line);
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strchr(char *s, int c);
char	*new_line(char *line);
char	*future_next_line(char *line);
void	ft_get_line(int fd, char **line);
size_t	ft_strlen(char *s);

#endif
