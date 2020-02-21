#include <stdio.h>

typedef struct	s_library
{
	int		total;
	double	score;
	int		*books;
	int		ship_by_day;
	int		signup;
}				t_library;

typedef struct facility
{
	int		days;
	int		books;
	int		libraries;
	int		*weights;
};


int main(int n, char **args)
{
	if (n != 2)
		return (0);
	FILE *f = fopen(args[1], "r");
	if (f == NULL)
		return (0);
	int books, libraries, days;

	fscanf(f, "%d %d %d", &books, &libraries, &days);
	printf("%d %d %d\n", books, libraries, days);
	int book;
	for (int i =0 ; i < books; i++)
	{
		fscanf(f, "%d", &book);
		printf("%d ", book);
	}
	printf("\n");
	int lbooks, ldays, lship;
	for (int i = 0; i < libraries; i++)
	{
		fscanf(f, "%d %d %d", &lbooks, &ldays, &lship);
		printf("%d %d %d\n", lbooks, ldays, lship);
		for (int j=0; j < lbooks; j++)
		{
			fscanf(f, "%d", &book);
			printf("%d ", book);
		}
		printf("\n");
	}
	fclose(f);
}