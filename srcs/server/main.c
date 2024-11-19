/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:27:49 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/20 00:52:58 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line.h"
#include "../../includes/server.h"
#include "../../printf/ft_printf.h"

char	*g_str;

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[++i] != '\0')
		join[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i++] = '\0';
	free(s1);
	return (join);
}

void	ft_listening_data(int sig)
{
	static int	bit;
	static int	i;
	char		*c1;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		c1 = (char *)malloc(sizeof(char) * 2);
		if (!c1)
			return ;
		c1[0] = (char)i;
		c1[1] = '\0';
		g_str = ft_strjoin_mod(g_str, c1);
		if (c1[0] == '\n')
		{
			ft_putstr_fd(g_str, 1);
			free(g_str);
			g_str = NULL;
		}
		bit = 0;
		i = 0;
		free(c1);
	}
}

int	main(void)
{
	int		fd;
	char	*line;
	int		flag;

	flag = 0;
	fd = open("minitalk.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Could not open file\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		flag++;
		if (flag % 2)
			ft_printf("\033[32m%s\033[0m", line);
		else
			ft_printf("%s", line);
		free(line);
	}
	ft_printf("\033[32mServer PID: %d\033[0m\n\033[32m[\033[0mNO BONUS MODE\033[32m]\033[0m\n", getpid());
	signal(SIGUSR1, ft_listening_data);
	signal(SIGUSR2, ft_listening_data);
	while (1)
		pause();
}
