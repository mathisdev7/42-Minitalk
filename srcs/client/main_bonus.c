/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:08:45 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/20 00:45:12 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"
#include "../../printf/ft_printf.h"

void	convert_binary(int server_pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
		{
			kill(server_pid, SIGUSR1);
		}
		else
			kill(server_pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		convert_binary(pid, *msg);
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
	send_msg(ft_atoi(argv[1]), argv[2]);
	send_msg(ft_atoi(argv[1]), "\n");
	if (argv[1][i] == '\0')
		ft_printf("\033[32mMessage sent!\033[0m\n");
	return (0);
}
