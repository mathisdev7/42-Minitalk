/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:27:49 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/18 16:27:49 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"
#include "../../printf/ft_printf.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int						bit_count = 0;
	static unsigned char			character = 0;

	(void) context;
	(void) info;
	character |= (signal == SIGUSR2) << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		if (character == '\0')
			write(1, "\033[0m\n", 5);
		else
			ft_printf("\033[34m%c\033[0m", character);
		bit_count = 0;
		character = 0;
	}
}
/*
int main() {
    struct sigaction sa;

    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    ft_printf("\033[32mServer PID: %d\033[0m\n", getpid());

    while (1) {
        pause();
    }
    return 0;
}
*/
