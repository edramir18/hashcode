/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_books.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:36:58 by edramire          #+#    #+#             */
/*   Updated: 2020/02/27 23:59:49 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode.h"
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (t_library *lib, int *books, int low, int high) 
{ 
    int pivot = books[lib->list[high]];    // pivot 
    int i = (low - 1);  // Index of smaller element
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (books[lib->list[j]] > pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(lib->list + i, lib->list + j);
        } 
    } 
    swap(lib->list + i + 1, lib->list + high); 
    return (i + 1); 
}

void quickSort(t_library *lib, int *books, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(lib, books, low, high); 
        quickSort(lib, books, low, pi - 1); 
        quickSort(lib, books, pi + 1, high); 
    } 
}
void	sort_books(t_library *lib, int *books)
{
	quickSort(lib, books, lib->shipped, lib->books - 1);
	/*printf("%d: ", lib->id);
	for (int i = 0; i < lib->books; i++)
		printf("%d[%d] ", books[lib->list[i]], lib->list[i]);
	printf("\n");*/
}
/*{
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
}*/