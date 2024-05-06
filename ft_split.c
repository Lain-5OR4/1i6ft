/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:26:36 by sebiko            #+#    #+#             */
/*   Updated: 2024/05/03 19:47:21 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	det_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_str_arr(char **str_arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str_arr[i]);
	}
	free(str_arr);
}

static char	**splitter(char const *s, char c, char **str_arr, size_t word_num)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < word_num)
	{
		while (s[j] && s[j] == c)
			j++;
		str_arr[i] = ft_substr(s, j, det_word_len(&s[j], c));
		if (!str_arr[i])
		{
			free_str_arr(str_arr, i);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str_arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str_arr)
		return (NULL);
	str_arr = splitter(s, c, str_arr, words);
	return (str_arr);
}
