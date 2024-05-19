/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:55:02 by sebiko            #+#    #+#             */
/*   Updated: 2024/05/19 19:13:56 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char *s1 = "abc";
    char *s2 = "Zbc";
    // printf("strncmp:%d\n", strncmp(s1, s2, 3));
    // printf("strncmp:%d\n", strncmp(s1, NULL, 3)); // segfault
    // printf("strncmp:%d\n", strncmp(NULL, s2, 3)); // segfault
    // printf("strncmp:%d\n", strncmp(NULL, NULL, 3)); // segfault
    return (0);
}
*/
