/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_books.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:36:58 by edramire          #+#    #+#             */
/*   Updated: 2020/02/27 16:55:46 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode.h"

void	sort_books(t_library *lib, int *books)
{
	int change = 1;
	int last;
	int begin;

	begin = lib->shipped;
	for (int i = begin; i < lib->books && change > 0; i++)
	{
		change = 0;
		last = begin + lib->books - i - 1;
		for (int j = begin; j < last; j++)
		{
			if (books[lib->list[j]] < books[lib->list[j + 1]])
			{
				int aux = lib->list[j];
				lib->list[j] = lib->list[j + 1];
				lib->list[j + 1] = aux;
				++change;
			}
		}
	}
}