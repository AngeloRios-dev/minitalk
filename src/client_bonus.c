/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:08:58 by angrios           #+#    #+#             */
/*   Updated: 2025/09/01 19:23:58 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int signal)
{
	(void)signal;
	g_ack_received = 1;
}

static void	send_bit(int server_pid, int bit)
{
	if (bit == 1)
	{
		if (kill(server_pid, SIGUSR2) == -1)
		{
			ft_printf("ERROR: could not send SIGUSR2 to PID %d\n", server_pid);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 0)
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			ft_printf("ERROR: could not send SIGUSR1 to PID %d\n", server_pid);
			exit(EXIT_FAILURE);
		}
	}
	while (g_ack_received == 0)
		;
	g_ack_received = 0;
}

static void	process_char(int server_pid, char chr)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(server_pid, (chr >> bit) & 1);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int					i;
	char				*msg;
	int					server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("USAGE: %s <server pid> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i])
	{
		process_char(server_pid, msg[i]);
		i++;
	}
	process_char(server_pid, '\0');
	ft_printf("\nMessage sent successfuly!\n");
	return (EXIT_SUCCESS);
}
