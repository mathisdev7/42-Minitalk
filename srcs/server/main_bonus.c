/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:30 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/07 15:04:28 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server_bonus.h"
#include "../../printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	pid = 0;
	static char	c = 0;
	static int	i = 0;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	bin_to_char(signum, &c);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			kill(pid, SIGUSR1);
			pid = 0;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

void	print_server_pid(void)
{
	int		fd;
	char	*line;
	int		flag;

	flag = 0;
	fd = open("minitalk.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		flag++;
		if (flag % 2)
			ft_printf("\033[32m%s\033[0m", line);
		else
			ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("\033[32mServer PID: %d\033[0m\n", getpid());
	ft_printf("\033[32m[\033[0mBONUS MODE\033[32m]\033[0m\n");
}

int	main(void)
{
	struct sigaction	sa;

	print_server_pid();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up signal handlers\n");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
