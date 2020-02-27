/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_libraries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:36:58 by edramire          #+#    #+#             */
/*   Updated: 2020/02/27 02:57:13 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode.h"

void	sort_libraries(t_facility *fac)
{
	int change = 1;
	int last;

	for (int i = 0; i < fac->libraries && change > 0; i++)
	{
		change = 0;
		last = fac->libraries - i - 1;
		for (int j = 0; j < last; j++)
		{
			if (fac->list[j].score < fac->list[j + 1].score)
			{
				t_library aux = fac->list[j];
				fac->list[j] = fac->list[j + 1];
				fac->list[j + 1] = aux;
				++change;
			}
		}
	}
}