/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:45:47 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/08/19 13:47:06 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_char(char *str, char c)
{
	int		i;
	int		j;
	int		len;
	char	*clean;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	clean = malloc(sizeof(char) * len + 1);
	if (!clean)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			clean[j] = str[i];
			j++;
		}
		i++;
	}
	clean[j] = '\0';
	return (clean);
}
