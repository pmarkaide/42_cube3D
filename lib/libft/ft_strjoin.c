/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:17:38 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/09/03 10:38:10 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arg_str(char **s1, char **s2, int mode)
{
	if (mode == 0)
		return ;
	else if (mode == 1)
		ft_free((void **)s1);
	else if (mode == 2)
		ft_free((void **)s2);
	else if (mode == 3)
	{
		ft_free((void **)s1);
		ft_free((void **)s2);
	}
}

char	*ft_strjoin(char *s1, char *s2, char *delim, int mode)
{
	int		total_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	total_len = 0;
	total_len += ft_strlen(s1);
	total_len += ft_strlen(s2);
	if (delim)
		total_len += ft_strlen(delim);
	res = (char *)malloc((total_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, s1);
	if (delim)
		res = ft_strcat(res, delim);
	res = ft_strcat(res, s2);
	free_arg_str(&s1, &s2, mode);
	return (res);
}
