/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:00:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/08/27 09:23:30 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * n + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
