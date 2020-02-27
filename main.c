/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:06:37 by edramire          #+#    #+#             */
/*   Updated: 2020/02/27 02:58:02 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode.h"

void	load_facility(t_facility *f, FILE *fd)
{
	fscanf(fd, "%d %d %d ", &f->books, &f->libraries, &f->days);
	f->points = malloc(sizeof(int) * f->books);
	if (f->points == NULL)
		exit(1);
	for (int i = 0; i < f->books; i++)
		fscanf(fd, "%d", f->points + i);
}

void	load_library(t_library *lib, FILE *fd)
{
	fscanf(fd, "%d %d %d", &lib->books, &lib->signup, &lib->ship_by_day);
	lib->list = malloc(sizeof(int) * lib->books);
	if (lib->list == NULL)
		exit(1);
	for (int j=0; j < lib->books; j++)
		fscanf(fd, "%d", lib->list + j);
}

void		clear_facility(t_facility *f)
{
	t_library *l;

	for(int i = 0; i < f->libraries; i++)
	{
		l = f->list + i;
		free(l->list);
	}
	free(f->list);
	free(f->points);
}

void	print_library(t_library *lib, int index)
{
	printf("%6d %6d %6d %6d %10.2f %6d %6d", index, lib->books, lib->signup, lib->ship_by_day, lib->score, lib->points, lib->days);
	/*
	for (int i = 0; i < lib->books; i++)
	{
		printf(" %d", lib->list[i]);
	}
	*/
	printf("\n");
}

int main(int n, char **args)
{
	if (n != 2)
		return (0);
	FILE *f = fopen(args[1], "r");
	if (f == NULL)
		return (0);
	int books, libraries, days;

	t_facility fact;
	bzero(&fact, sizeof(t_facility));
	load_facility(&fact, f);
	fact.list = malloc(sizeof(t_library) * fact.libraries);
	bzero(fact.list, sizeof(t_library) * fact.libraries);
	if (fact.list == NULL)
		exit(1);
	for (int i = 0; i < fact.libraries; i++)
	{
		load_library(fact.list + i, f);
		sort_books(fact.list + i, fact.points);
	}
	for (int i = 0; i < fact.libraries; i++)
		show(fact.list + i, fact.points, fact.days);
	sort_libraries(&fact);
	for (int i = 0; i < fact.libraries; i++)
		print_library(fact.list + i, i);
	fclose(f);
	clear_facility(&fact);
}