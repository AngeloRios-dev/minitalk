/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:06:42 by angrios           #+#    #+#             */
/*   Updated: 2025/09/01 18:18:30 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		ft_printf("ERROR: memory allocation failed (01)!");
		exit(EXIT_FAILURE);
	}
	temp = ft_strjoin(g_message, str);
	if (!temp)
	{
		ft_printf("ERROR: memory allocation failed (02)!");
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
