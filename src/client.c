/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:08:58 by angrios           #+#    #+#             */
/*   Updated: 2025/08/29 20:19:17 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

static void	ft_usleep(int microseconds)
{
	struct timespec ts;

	ts.tv_sec = microseconds / 1000000;
	ts.tv_nsec = (microseconds % 1000000) * 1000;
	nanosleep(&ts, NULL);
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
	ft_usleep(500);
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

int main(int argc, char *argv[])
{
	int		i;
	char	*msg;
	int		server_pid;

	if (argc != 3)
	{
		ft_printf("USAGE: %s <server pid> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
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
