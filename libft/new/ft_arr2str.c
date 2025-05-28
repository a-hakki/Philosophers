/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:45:34 by ahakki            #+#    #+#             */
/*   Updated: 2025/05/11 22:50:32 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_arr2str(char **arr, char sp)
{
	int		i;
	int		j;
	int		c;
	char	*str;

	ft_init(3, &i, &j, &c);
	if (!arr || !*arr)
		return (NULL);
	while (arr[i])
		c += ft_strlen(arr[i++]) + 1;
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	ft_init(2, &i, &c);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			str[c++] = arr[i][j++];
		str[c++] = sp;
		i++;
	}
	str[c - 1] = '\0';
	return (str);
}
// int main(int ac, char **av, char **envp)
// {c
// 	(void)av;
// 	(void)ac;
// 	char *str;
// 	str = ft_arr2str(envp, '@');
// 	printf("%s\n", str);
// }
