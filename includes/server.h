/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/07 14:38:30 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

extern char	*g_str;

char		*ft_strjoin_mod(char *s1, char *s2);
void		ft_listening_data(int sig, siginfo_t *info, void *context);
char		*get_next_line(int fd);

#endif
