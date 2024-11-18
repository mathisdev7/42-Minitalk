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

void	send_char(pid_t server_pid, unsigned char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i++;
	}
}
/*
int main(int argc, char **argv) {
    if (argc != 3) {
        write(2, "Usage: ./client <server_pid> <message>\n", 39);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];

    for (int i = 0; message[i]; i++) {
        send_char(server_pid, message[i]);
    }

    return 0;
}
*/
