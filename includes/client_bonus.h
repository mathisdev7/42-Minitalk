/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:20:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/07 15:28:53 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	convert_binary(int server_pid, unsigned char c, char *pid_str);
void	send_msg(int pid, char *msg, char *pid_str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		calculate_delay(int len);
int		ft_strlen(const char *str);

#endif
