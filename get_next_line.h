/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 10:57:42 by alisharu          #+#    #+#             */
/*   Updated: 2025-05-11 10:57:42 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_cut_str(char *line);
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strchr(char *s, int c);
char	*new_line(char *line);
char	*future_next_line(char *line);
void	ft_get_line(int fd, char **line);
size_t	ft_strlen(char *s);

#endif
