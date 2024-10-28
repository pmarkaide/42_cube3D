/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:07:27 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/08/18 12:47:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_split_args(char *str, char *delim)
{
	t_list	*tokens;
	t_list	*token;
	char	*token_start_pos;

	tokens = NULL;
	token_start_pos = ft_strtok(str, delim);
	while (token_start_pos)
	{
		token = ft_lstnew((void *)token_start_pos);
		if (!token)
		{
			ft_lstclear(&tokens, ft_del);
			return (NULL);
		}
		ft_lstadd_back(&tokens, token);
		token_start_pos = ft_strtok(NULL, delim);
	}
	return (tokens);
}
