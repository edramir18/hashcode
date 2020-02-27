#ifndef HASHCODE_H
# define HASHCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_library
{
	int		books;
	int		id;
	int		*list;
	int		ship_by_day;
	int		signup;
	float	score;
	int		points;
	int		days;
	int		registered;
	int		shipped;
}				t_library;

typedef struct	s_facility
{
	int			days;
	int			books;
	int			libraries;
	int			signup;
	int			*points;
	t_library	*list;
}				t_facility;

void	calculate_score(t_library *lib, int *books, int days);
void	sort_books(t_library *lib, int *books);
void	sort_libraries(t_facility *fac);

#endif