#include "sandpiles.h"

/**
 * grid_addition - ajoute 2 grilles
 * @grid1: première matrice
 * @grid2: deuxième matrice
 */

void grid_addition(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * grid_print - affiche une grille
 * @grid: matrice
 */

void grid_print(int grid[3][3])
{
	int i = 0;
	int j = 0;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_is_ok - vérifie si une grille est correcte
 * @grid: matrice
 * Return: 1 si c'est correct, 0 sinon
 */

int grid_is_ok(int grid[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3) /* si une cellule est supérieure à 3 */
				return (0);		/* la grille n'est pas ok */
		}
	}
	return (1); /* la grille est ok */
}

/**
 * grid_change - change la valeur d'une grille
 * @grid1: matrice
 */

void grid_change(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int gridx[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			gridx[i][j] = 0; /* initialise gridx à 0 */
	}

	for (i = 0; i < 3; i++) /* parcourt les lignes de grid1 */
	{
		for (j = 0; j < 3; j++) /* parcourt les colonnes de grid1 */
		{
			if (grid1[i][j] > 3) /* si une cellule est supérieure à 3 */
			{
				grid1[i][j] = grid1[i][j] - 4;	 /* soustrait 4 à la cellule */
				if ((i - 1) >= 0 && (i - 1) < 3) /*si une cellule est dans la grille*/
					gridx[i - 1][j] += 1;		 /* ajoute 1 à la cellule au-dessus */
				if ((j - 1) >= 0 && (j - 1) < 3)
					gridx[i][j - 1] += 1; /* ajoute 1 à la cellule à gauche */
				if ((i + 1) >= 0 && (i + 1) < 3)
					gridx[i + 1][j] += 1; /* ajoute 1 à la cellule en dessous */
				if ((j + 1) >= 0 && (j + 1) < 3)
					gridx[i][j + 1] += 1; /* ajoute 1 à la cellule à droite */
			}
		}
	}
	grid_addition(grid1, gridx); /* grid1 = grid1 + gridx */
}

/**
 * sandpiles_sum - additionne 2 tas de sable
 * @grid1: première matrice
 * @grid2: deuxième matrice
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_addition(grid1, grid2); /* grid1 = grid1 + grid2 */
	while (!grid_is_ok(grid1))	 /* tant que grid1 n'est pas correcte */
	{
		grid_print(grid1);
		grid_change(grid1);
	}
}
