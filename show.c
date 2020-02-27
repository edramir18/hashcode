/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:03:45 by edramire          #+#    #+#             */
/*   Updated: 2020/02/27 02:42:31 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode.h"

void	show(t_library *lib, int *books, int days)
{
	int l = 0;
	int score = 0;
	int prev = 0;
	int i = 0;
	while(i < days)
	{
		prev = score;
		if (i > lib->signup)
		{
			for(int j = 0; j < lib->ship_by_day && l < lib->books; j++)
			{
				score += books[lib->list[l++]];
			}
			if (prev == score)
				break ;
		} 
		++i;
	}
	lib->score = ((float)score * days / (i * i));
	lib->days = i;
	lib->points = score;
}