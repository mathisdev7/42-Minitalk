/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:08:45 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/24 16:25:45 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"
#include "../../printf/ft_printf.h"

void	convert_binary(int server_pid, unsigned char c, char *pid_str)
{
	int	bit;
	int	len;
	int	delay;

	bit = 0;
	len = ft_strlen(pid_str);
	delay = 15;
	if (len > 10000)
		delay = 35;
	if (len > 25000)
		delay = 60;
	if (len > 50000)
		delay = 100;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
		{
			kill(server_pid, SIGUSR1);
		}
		else
			kill(server_pid, SIGUSR2);
		usleep(delay);
		bit++;
	}
}

void	send_msg(int pid, char *msg, char *pid_str)
{
	while (*msg)
	{
		convert_binary(pid, *msg, pid_str);
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(write(1, "Error: Wrong format!", 20));
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit(write(1, "\033[31mERROR: PID invalid!\033[0m\n", 30));
		i++;
	}
	send_msg(ft_atoi(argv[1]), argv[2], argv[1]);
	send_msg(ft_atoi(argv[1]), "\n", argv[1]);
	if (argv[1][i] == '\0')
		ft_printf("\033[32mMessage sent!\033[0m\n");
	return (0);
}
