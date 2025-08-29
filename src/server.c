/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:06:42 by angrios           #+#    #+#             */
/*   Updated: 2025/08/29 20:19:07 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	store_message(char **msg, char new_char)
{
	char	*temp_msg;
	char	str[2];

	str[0] = new_char;
	str[1] = '\0';
	if (*msg == NULL)
		*msg = ft_strdup("");
	temp_msg = ft_strjoin(*msg, str);
	if (!temp_msg)
		return (1);
	free(*msg);
	*msg = temp_msg;
	return (0);
}

void	signal_handler(int signal)
{
	static char		chr = 0;
	static int		bit_counter = 0;
	static char		*msg = NULL;

	if (signal == SIGUSR1)
		chr = (chr << 1);
	if (signal == SIGUSR2)
		chr = (chr << 1) | 1;
	bit_counter++;
	if (bit_counter == 8)
	{
		if (store_message(&msg, chr) != 0)
			return ;
		if (chr == '\0')
		{
			write(STDOUT_FILENO, msg, ft_strlen(msg));
			write(STDOUT_FILENO, "\n", 1);
			free(msg);
			msg = NULL;
		}
		chr = 0;
		bit_counter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	ft_printf("Server PID: %d\n", getpid());
	sleep(1);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
*/

static char	*g_message = NULL;

static void	append_char(char chr)
{
	char	*temp;
	char	str[2];

	str[0] = chr;
	str[1] = '\0';
	if (!g_message)
		g_message = ft_strdup("");
	if (!g_message)
	{
		ft_printf("ERROR: memory allocation failed (append_char, !g_message)!");
		exit(EXIT_FAILURE);
	}
	temp = ft_strjoin(g_message, str);
	if (!temp)
	{
		ft_printf("ERROR: memory allocation failed (append_char, !temp)!");
		exit(EXIT_FAILURE);
	}
	free(g_message);
	g_message = temp;
}

static void	handle_char(char chr)
{
	if (chr == '\0')
	{
		ft_printf("%s\n", g_message);
		free(g_message);
		g_message = NULL;
	}
	else
		append_char(chr);
}

static void	signal_handler(int signal)
{
	static char	current_char = 0;
	static int	bit_counter = 0;

	if (signal == SIGUSR2)
		current_char |= (1 << bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		handle_char(current_char);
		current_char = 0;
		bit_counter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	g_message = NULL;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("ERROR: sigaction failed!\n");
		return (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (EXIT_SUCCESS);
}