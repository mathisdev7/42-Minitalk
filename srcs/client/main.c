/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:08:45 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/18 17:08:45 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"
#include "../../printf/ft_printf.h"
#include <locale.h>

void send_char(pid_t server_pid, unsigned char c)
{
    for (int i = 0; i < 8; i++)
    {
        if (c & (1 << i))
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);

        usleep(500);
    }
}

void send_message(pid_t server_pid, const char *message)
{
    int i = 0;

    while (message[i] != '\0')
    {
        unsigned char c = message[i];
        send_char(server_pid, c);
        i++;
    }
    send_char(server_pid, '\0');
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("\033[32mMessage received!\033[0m\n");
		exit(0);
	}
}

int	main(int argc, char **argv) {
	int		i;

	i = 0;
    if (argc != 3) {
        ft_printf("Usage: ./client <server_pid> <message>\n");
        return 1;
    }
	setlocale(LC_CTYPE, "en_US.UTF-8");

    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];

    signal(SIGUSR1, signal_handler);
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
	pause();
    return (0);
}
