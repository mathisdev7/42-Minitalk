/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:27:49 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/19 14:56:33 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line.h"
#include "../../includes/server.h"
#include "../../printf/ft_printf.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;

	(void)context;
	if (signal == SIGUSR2)
		character |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	show_pid(void)
{
	char	*line;
	int		fd;
	int		flag;

	flag = 0;
	fd = open("minitalk.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Could not open file\n");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		flag++;
		if (flag % 2)
			ft_printf("\033[32m%s\033[0m", line);
		else
			ft_printf("%s", line);
		free(line);
	}
	ft_printf("\033[32mServer PID: %d\033[0m\n", getpid());
	return (0);
}

int	main(void)
{
	struct sigaction	sa;

	system("clear");
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (show_pid() == 1)
		return (1);
	ft_printf("\033[32m[\033[0mBONUS VERSION\033[32m]\033[0m\n");
	while (1)
		pause();
	return (0);
}
