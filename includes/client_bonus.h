/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:20:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/20 01:08:50 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	convert_binary(int server_pid, unsigned char c);
void	send_msg(int pid, char *msg);
int		ft_atoi(const char *str);

#endif
