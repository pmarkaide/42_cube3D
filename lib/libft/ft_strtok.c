/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:47:36 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/08/18 10:57:31 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char *delim)
{
	static char	*current_position;
	char		*start_of_token;

	if (str)
		current_position = str;
	if (!current_position)
		return (NULL);
	while (*current_position && ft_strchr(delim, *current_position))
		current_position++;
	if (*current_position == '\0')
		return (NULL);
	start_of_token = current_position;
	while (*current_position && !ft_strchr(delim, *current_position))
		current_position++;
	if (*current_position)
	{
		*current_position = '\0';
		current_position++;
	}
	return (start_of_token);
}
