/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/20 01:07:15 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	convert_binary(int server_pid, unsigned char c);
void	send_msg(int pid, char *msg);
int		ft_atoi(const char *str);

#endif
