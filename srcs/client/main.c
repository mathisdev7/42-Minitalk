/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:08:45 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/07 15:28:06 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"
#include "../../printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern int		calculate_delay(int len);

static int		g_receiver = 0;

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;

	(void)info;
	(void)context;
	g_receiver = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		i = 0;
}

int	char_to_bin(char c, int pid, int len)
{
	int	bit_index;
	int	itr;

	bit_index = 7;
	while (bit_index >= 0)
	{
		itr = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (itr == 50)
			{
				ft_printf("No response from server.\n");
				exit(EXIT_FAILURE);
			}
			itr++;
			usleep(calculate_delay(len) * 1000);
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					byte_index;
	int					pid;

	if (argc != 3)
		return (ft_printf("You need to pass 2 args\n"));
	pid = atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Invalid PID.\n"));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error setting up signal handlers.\n"));
	byte_index = 0;
	while (argv[2][byte_index] != '\0')
	{
		char_to_bin(argv[2][byte_index], pid, ft_strlen(ft_itoa(pid)));
		byte_index++;
	}
	return (char_to_bin('\0', pid, ft_strlen(ft_itoa(pid))));
}
