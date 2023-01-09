#include "MyChess.h"

void Chess(int i, const char* p)
{

	if (i == WHITE)
	{
		printf("○");
	}
	if (i == BLACK)
	{
		printf("●");
	}
	if (i == BLANK)
	{
		printf("%s", p);
	}

}

void Chess_borad(int a[MAX_ROW][MAX_COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		if (i == 0)
		{
			printf("0");
			for (j = 0; j < col; j++)
			{
				if (j == 0)
				{
					Chess(a[i][j], "┌ ");
				}
				else if (j == col - 1)
				{
					Chess(a[i][j], "┐");
				}
				else
				{
					Chess(a[i][j], "┬ ");
				}
			}
			printf("\n");
		}
		else if (i == row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j == 0)
				{
					Chess(a[i][j], "└ ");
				}
				else if (j == col - 1)
				{
					Chess(a[i][j], "┘ ");
				}
				else
				{
					Chess(a[i][j], "┴ ");
				}
			}
			printf("\n");
		}
		else
		{
			for (j = 0; j < col; j++)
			{
				if (j == 0)
				{
					Chess(a[i][j], "├ ");
				}
				else if (j == col - 1)
				{
					Chess(a[i][j], "┤");
				}
				else
				{
					Chess(a[i][j], "┼ ");
				}
			}
			printf("\n");
		}
		if (i < 9)
		{
			printf("%d", i + 1);
		}
		if (i == 9)
		{
			printf("A");
		}
		if (i == 10)
		{
			printf("B");
		}
		if (i == 11)
		{
			printf("C");
		}
		if (i == 12)
		{
			printf("D");
		}
		if (i == 13)
		{
			printf("E");
		}
	}

	for (int k = 0; k < MAX_ROW; k++)
	{
		if (k == 0)
		{
			printf(" %d", k);
		}
		if (k < 10 && k > 0)
		{
			printf(" %d", k);

		}
		if (k == 10)
		{
			printf(" A");
		}
		if (k == 11)
		{
			printf(" B");
		}
		if (k == 12)
		{
			printf(" C");
		}
		if (k == 13)
		{
			printf(" D");
		}
		if (k == 14)
		{
			printf(" E");
		}

	}
	printf("\n\n\n");
}



int Win_Judge(int a[MAX_ROW][MAX_COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (a[i][j] == BLANK)
			{
				continue;
			}
			if (i < row - 4)
			{
				if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && a[i][j] == a[i + 4][j]) {
					return a[i][j];
				}
			}
			if (j < col - 4)
			{
				if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4]) {
					return a[i][j];
				}
			}
			if (i < row - 4 && j < col - 4)
			{
				if (a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i + 2][j + 2] && a[i][j] == a[i + 3][j + 3] && a[i][j] == a[i + 4][j + 4]) {
					return a[i][j];
				}
			}
			if (i < row - 4 && j > 3)
			{
				if (a[i][j] == a[i + 1][j - 1] && a[i][j] == a[i + 2][j - 2] && a[i][j] == a[i + 3][j - 3] && a[i][j] == a[i + 4][j - 4]) {
					return a[i][j];
				}
			}
		}

	}

	return BLANK;

}



int AI_Judge(int a[MAX_ROW][MAX_COL], int x, int y, int row, int col, int TYPE, int O_TYPE, int N, int* R_X, int* R_Y, int* blank, int Defend)
{
	int BL = 0;
	int mx = 0, my = 0;
	int key = 1, num = 1;
	int compare = 0;
	int remx = x, remy = y, tx = x, ty = y;
	int final_x = 0, final_y = 0, q = 0;
	while (tx < row && ty < col && num <= 4)
	{
		tx++;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx - 1][ty] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}
		}
		num++;
	}

	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	key = 1;
	num = 1;
	tx = x;
	ty = y;
	q = 0;

	while (tx >= 0 && ty < col && num <= 4)
	{
		tx--;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx + 1][ty] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}
		}
		num++;
	}


	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	key = 1;
	num = 1;
	tx = x;
	ty = y;
	q = 0;

	while (tx < row && ty < col && num <= 4)
	{
		ty++;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx][ty - 1] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}
		}
		num++;
	}

	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	key = 1;
	num = 1;
	tx = x;
	ty = y;
	q = 0;

	while (tx < row && ty >= 0 && num <= 4)
	{
		ty--;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx][ty + 1] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	key = 1;
	num = 1;
	tx = x;
	ty = y;
	q = 0;

	while (tx < row && ty < col && num <= 4)
	{
		tx++;
		ty++;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx - 1][ty - 1] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	key = 1;
	num = 1;
	tx = x;
	ty = y;
	q = 0;

	while (tx >= 0 && ty >= 0 && num <= 4)
	{
		tx--;
		ty--;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx + 1][ty + 1] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	key = 1;
	num = 1;
	tx = x;
	ty = y;
	q = 0;

	while (tx < row && ty >= 0 && num <= 4)
	{
		tx++;
		ty--;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx - 1][ty + 1] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	key = 1;
	num = 1;
	tx = x;
	ty = y;
	q = 0;

	while (tx >= 0 && ty < col && num <= 4)
	{
		tx--;
		ty++;
		if (a[tx][ty] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[tx][ty] == a[tx + 1][ty - 1] || a[tx][ty] == a[remx][remy]) && a[tx][ty] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
		final_x = tx;
		final_y = ty;
	}

	mx = final_x - x;
	my = final_y - y;
	tx = x;
	ty = y;

	if (mx > 0 && my == 0)
	{
		if (a[tx - 1][ty] == BLANK)
		{
			*blank = 1;
		}
		while (tx <= final_x)
		{

			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}

			}
			tx++;
		}

	}

	tx = x;
	ty = y;

	if (mx < 0 && my == 0)
	{
		if (a[tx + 1][ty] == BLANK)
		{
			*blank = 1;
		}
		while (tx >= final_x)
		{
			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}
			}
			tx--;
		}

	}

	tx = x;
	ty = y;

	if (mx == 0 && my > 0)
	{
		if (a[tx][ty - 1] == BLANK)
		{
			*blank = 1;
		}
		while (ty <= final_y)
		{
			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}
			}

			ty++;
		}
	}

	tx = x;
	ty = y;

	if (mx == 0 && my < 0)
	{
		if (a[tx][ty + 1] == BLANK)
		{
			*blank = 1;
		}
		while (ty >= final_y)
		{
			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}
			}
			ty--;
		}
	}

	tx = x;
	ty = y;

	if (mx > 0 && my > 0)
	{
		if (a[tx - 1][ty - 1] == BLANK)
		{
			*blank = 1;
		}
		while (tx <= final_x && ty <= final_y)
		{
			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}
			}

			ty++;
			tx++;
		}
	}

	tx = x;
	ty = y;

	if (mx < 0 && my < 0)
	{
		if (a[tx + 1][ty + 1] == BLANK)
		{
			*blank = 1;
		}
		while (tx >= final_x && ty >= final_y)
		{
			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}
			}
			ty--;
			tx--;
		}
	}

	tx = x;
	ty = y;

	if (mx < 0 && my > 0)
	{
		if (a[tx + 1][ty - 1] == BLANK)
		{
			*blank = 1;
		}
		while (tx >= final_x && ty <= final_y)
		{
			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}
			}

			ty++;
			tx--;
		}
	}

	tx = x;
	ty = y;

	if (mx > 0 && my < 0)
	{
		if (a[tx - 1][ty + 1] == BLANK)
		{
			*blank = 1;
		}
		while (tx <= final_x && ty >= final_y)
		{
			if (a[tx][ty] == BLANK)
			{
				if (Defend == 1 && *blank == 1)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					*blank = 0;
					return 1;
				}
				if (Defend == 0)
				{
					a[tx][ty] = N;
					*R_X = tx;
					*R_Y = ty;
					return 2;
				}
			}

			ty--;
			tx++;
		}
	}

}

void Compare_1(int a[MAX_ROW][MAX_COL], int* x, int* y, int* x_1, int* y_1, int O_TYPE, int TYPE)
{
	int tx = 0, mx = 0, cx = 0;
	int ty = 0, my = 0, cy = 0;
	int compare = 0;
	int m = 1, t = 0;

	tx = *x + 1;
	ty = *y;

	if (a[tx][ty] == BLANK)
	{
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{
			if (tx + m < MAX_ROW)
			{
				if (a[tx + m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx + m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - m >= 0)
			{
				if (a[tx - m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx - m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (ty + m < MAX_COL)
			{
				if (a[tx][ty + m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty + m] == O_TYPE)
				{
					t--;
				}
			}
			if (ty - m >= 0)
			{
				if (a[tx][ty - m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty - m] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty - 1 >= 0)
			{
				if (a[tx - 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty + 1 < MAX_COL)
			{
				if (a[tx + 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty + 1 < MAX_COL)
			{
				if (a[tx - 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty - 1 >= 0)
			{
				if (a[tx + 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	tx = *x - 1;
	ty = *y;
	m = 1;

	if (a[tx][ty] == BLANK)
	{
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{
			if (tx + m < MAX_ROW)
			{
				if (a[tx + m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx + m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - m >= 0)
			{
				if (a[tx - m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx - m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (ty + m < MAX_COL)
			{
				if (a[tx][ty + m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty + m] == O_TYPE)
				{
					t--;
				}
			}
			if (ty - m >= 0)
			{
				if (a[tx][ty - m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty - m] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty - 1 >= 0)
			{
				if (a[tx - 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty + 1 < MAX_COL)
			{
				if (a[tx + 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty + 1 < MAX_COL)
			{
				if (a[tx - 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty - 1 >= 0)
			{
				if (a[tx + 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	tx = *x;
	ty = *y + 1;
	m = 1;

	if (a[tx][ty] == BLANK)
	{
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{
			if (tx + m < MAX_ROW)
			{
				if (a[tx + m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx + m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - m >= 0)
			{
				if (a[tx - m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx - m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (ty + m < MAX_COL)
			{
				if (a[tx][ty + m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty + m] == O_TYPE)
				{
					t--;
				}
			}
			if (ty - m >= 0)
			{
				if (a[tx][ty - m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty - m] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty - 1 >= 0)
			{
				if (a[tx - 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty + 1 < MAX_COL)
			{
				if (a[tx + 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty + 1 < MAX_COL)
			{
				if (a[tx - 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty - 1 >= 0)
			{
				if (a[tx + 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	tx = *x;
	ty = *y - 1;
	m = 1;

	if (a[tx][ty] == BLANK) {
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{
			if (tx + m < MAX_ROW)
			{
				if (a[tx + m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx + m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - m >= 0)
			{
				if (a[tx - m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx - m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (ty + m < MAX_COL)
			{
				if (a[tx][ty + m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty + m] == O_TYPE)
				{
					t--;
				}
			}
			if (ty - m >= 0)
			{
				if (a[tx][ty - m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty - m] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty - 1 >= 0)
			{
				if (a[tx - 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty + 1 < MAX_COL)
			{
				if (a[tx + 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty + 1 < MAX_COL)
			{
				if (a[tx - 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty - 1 >= 0)
			{
				if (a[tx + 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	tx = *x + 1;
	ty = *y + 1;
	m = 1;

	if (a[tx][ty] == BLANK)
	{
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{
			if (tx + m < MAX_ROW) {
				if (a[tx + m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx + m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - m >= 0)
			{
				if (a[tx - m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx - m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (ty + m < MAX_COL)
			{
				if (a[tx][ty + m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty + m] == O_TYPE)
				{
					t--;
				}
			}
			if (ty - m >= 0)
			{
				if (a[tx][ty - m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty - m] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty - 1 >= 0)
			{
				if (a[tx - 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty + 1 < MAX_COL)
			{
				if (a[tx + 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty + 1 < MAX_COL)
			{
				if (a[tx - 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty - 1 >= 0)
			{
				if (a[tx + 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	tx = *x + 1;
	ty = *y + 1;
	m = 1;

	if (a[tx][ty] == BLANK)
	{
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{
			if (tx + m < MAX_ROW)
			{
				if (a[tx + m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx + m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - m >= 0)
			{
				if (a[tx - m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx - m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (ty + m < MAX_COL)
			{
				if (a[tx][ty + m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty + m] == O_TYPE)
				{
					t--;
				}
			}
			if (ty - m >= 0)
			{
				if (a[tx][ty - m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty - m] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty - 1 >= 0)
			{
				if (a[tx - 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty + 1 < MAX_COL)
			{
				if (a[tx + 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty + 1 < MAX_COL)
			{
				if (a[tx - 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty - 1 >= 0)
			{
				if (a[tx + 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	tx = *x - 1;
	ty = *y + 1;
	m = 1;

	if (a[tx][ty] == BLANK)
	{
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{
			if (tx + m < MAX_ROW)
			{
				if (a[tx + m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx + m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - m >= 0)
			{
				if (a[tx - m][ty] == TYPE)
				{
					t++;
				}
				else if (a[tx - m][ty] == O_TYPE)
				{
					t--;
				}
			}
			if (ty + m < MAX_COL)
			{
				if (a[tx][ty + m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty + m] == O_TYPE)
				{
					t--;
				}
			}
			if (ty - m >= 0)
			{
				if (a[tx][ty - m] == TYPE)
				{
					t++;
				}
				else if (a[tx][ty - m] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && ty - 1 >= 0)
			{
				if (a[tx - 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty + 1 < MAX_COL)
			{
				if (a[tx + 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx - 1 >= 0 && tx + 1 < MAX_ROW)
			{
				if (a[tx - 1][ty + 1] == TYPE)
				{
					t++;
				}
				else if (a[tx - 1][ty + 1] == O_TYPE)
				{
					t--;
				}
			}
			if (tx + 1 < MAX_ROW && ty - 1 >= 0)
			{
				if (a[tx + 1][ty - 1] == TYPE)
				{
					t++;
				}
				else if (a[tx + 1][ty - 1] == O_TYPE)
				{
					t--;
				}
			}
			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	tx = *x + 1;
	ty = *y - 1;
	m = 1;

	if (a[tx][ty] == BLANK)
	{
		while (tx < MAX_ROW && ty < MAX_COL && tx >= 0 && ty >= 0 && m <= 2)
		{

			if (a[tx + m][ty] == TYPE)
			{
				t++;
			}
			else if (a[tx + m][ty] == O_TYPE)
			{
				t--;
			}

			if (a[tx - m][ty] == TYPE)
			{
				t++;
			}
			else if (a[tx - m][ty] == O_TYPE)
			{
				t--;
			}

			if (a[tx][ty + m] == TYPE)
			{
				t++;
			}
			else if (a[tx][ty + m] == O_TYPE)
			{
				t--;
			}

			if (a[tx][ty - m] == TYPE)
			{
				t++;
			}
			else if (a[tx][ty - m] == O_TYPE)
			{
				t--;
			}

			if (a[tx - 1][ty - 1] == TYPE)
			{
				t++;
			}
			else if (a[tx - 1][ty - 1] == O_TYPE)
			{
				t--;
			}

			if (a[tx + 1][ty + 1] == TYPE)
			{
				t++;
			}
			else if (a[tx + 1][ty + 1] == O_TYPE)
			{
				t--;
			}

			if (a[tx - 1][ty + 1] == TYPE)
			{
				t++;
			}
			else if (a[tx - 1][ty + 1] == O_TYPE)
			{
				t--;
			}

			if (a[tx + 1][ty - 1] == TYPE)
			{
				t++;
			}
			else if (a[tx + 1][ty - 1] == O_TYPE)
			{
				t--;
			}

			if (t > compare)
			{
				compare = t;
				cx = tx;
				cy = ty;
			}

			m++;
		}
	}

	*x_1 = cx;
	*y_1 = cy;

}


void AI_Chess(int a[MAX_ROW][MAX_COL], int x, int y, int compare, int O_TYPE, int TYPE, int* R_X, int* R_Y)
{
	int blankey = 0;
	int* blankey_t = &blankey;
	int q = 0;
	int kx = 1, ky = 2;
	int* k_x = &kx;
	int* k_y = &ky;
	if (compare == 0)
	{
		for (int i = 0; i < MAX_ROW; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				if (a[i][j] == BLANK)
				{
					a[i][j] = TYPE;
					q = 1;
					*R_X = i;
					*R_Y = j;
					break;
				}
			}
			if (q == 1)
			{
				break;
			}

		}
	}
	if (compare == 1)
	{
		for (int i = 0; i < MAX_ROW; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				if (a[i][j] == TYPE)
				{
					Compare_1(a, &i, &j, k_x, k_y, O_TYPE, TYPE);
				}
			}

		}

		*R_X = *k_x;
		*R_Y = *k_y;
		a[*k_x][*k_y] = TYPE;

	}
	else
	{
		AI_Judge(a, x, y, MAX_ROW, MAX_COL, TYPE, O_TYPE, TYPE, R_X, R_Y, blankey_t, 0);
	}

}


int AI_Deepth(int a[MAX_ROW][MAX_COL], int m, int n, int num, int row, int col, int TYPE, int O_TYPE)
{
	int q = 0;
	int key = 1;
	int remx = m, remy = n, compare = 0;
	while (m < row && n < col && num <= 4)
	{
		m++;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[m][n] == a[m - 1][n] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1 || m == row)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
	}

	key = 1;
	num = 1;
	m = remx;
	n = remy;
	q = 0;

	while (m >= 0 && n < col && num <= 4)
	{
		m--;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[m][n] == a[m + 1][n] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1 || m < 0)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
	}

	key = 1;
	num = 1;
	m = remx;
	n = remy;
	q = 0;

	while (m < row && n < col && num <= 4)
	{
		n++;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{

			if ((a[m][n] == a[m][n - 1] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}
		}
		num++;
	}

	if (q == 1 || n == col)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
	}

	key = 1;
	num = 1;
	m = remx;
	n = remy;
	q = 0;

	while (m < row && n >= 0 && num <= 4)
	{
		n--;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{

			if ((a[m][n] == a[m][n + 1] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1 || n < 0)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
	}

	key = 1;
	num = 1;
	m = remx;
	n = remy;
	q = 0;

	while (m < row && n < col && num <= 4)
	{
		m++;
		n++;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[m][n] == a[m - 1][n - 1] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1 || m == row)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
	}

	key = 1;
	num = 1;
	m = remx;
	n = remy;
	q = 0;

	while (m >= 0 && n >= 0 && num <= 4)
	{
		m--;
		n--;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[m][n] == a[m + 1][n + 1] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1 || m < 0)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;
	}

	key = 1;
	num = 1;
	m = remx;
	n = remy;
	q = 0;

	while (m < row && n >= 0 && num <= 4)
	{
		m++;
		n--;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[m][n] == a[m - 1][n + 1] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1 || m == row)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;

	}

	key = 1;
	num = 1;
	m = remx;
	n = remy;
	q = 0;

	while (m >= 0 && n < col && num <= 4)
	{
		m--;
		n++;
		if (a[m][n] == O_TYPE)
		{
			q = 1;
			break;
		}
		else
		{
			if ((a[m][n] == a[m + 1][n - 1] || a[m][n] == a[remx][remy]) && a[m][n] == TYPE)
			{
				key++;
			}
			if (key == 4)
			{
				key = 100;
			}

		}
		num++;
	}

	if (q == 1 || m < 0)
	{
		key = -1;
	}

	if (key > compare)
	{
		compare = key;

	}

	return compare;
}


int DFS_5(int a[MAX_ROW][MAX_COL], int i, int j, int  O_TYPE, int TYPE, int t, int forward_x, int forward_y, int B)
{

	if (forward_x > 0 && forward_y > 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i - 1, j - 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i - 1, j - 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	if (forward_x > 0 && forward_y == 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i - 1, j, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i - 1, j, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	if (forward_x > 0 && forward_y < 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i - 1, j + 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i - 1, j + 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	if (forward_x == 0 && forward_y > 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i, j - 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i, j - 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	if (forward_x == 0 && forward_y < 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i, j + 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i, j + 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	if (forward_x < 0 && forward_y > 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i + 1, j - 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i + 1, j - 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	if (forward_x < 0 && forward_y == 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i + 1, j, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i + 1, j, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	if (forward_x < 0 && forward_y < 0)
	{
		if (i == MAX_ROW - 1 || j == MAX_COL - 1 || i == 0 || j == 0)
		{
			return 0;
		}
		if (t == 4 && a[i][j] == TYPE)
		{
			return 1;
		}
		else if (t == 4 && (a[i][j] == BLANK || a[i][j] == O_TYPE))
		{
			return 0;
		}

		if (t <= 3 && a[i][j] == O_TYPE)
		{
			return -100;
		}
		else if (t <= 3 && a[i][j] == BLANK)
		{
			B = B + 1;
			if (B == 2 && t <= 3)
			{
				return 0;
			}
			return DFS_5(a, i + 1, j + 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}
		else
		{
			return 1 + DFS_5(a, i + 1, j + 1, O_TYPE, TYPE, t + 1, forward_x, forward_y, B);
		}

	}

	return 0;
}

bool Second_Search(int a[MAX_ROW][MAX_COL], int O_TYPE, int TYPE)
{
	int count = 0;
	int dx = 0, dy = 0;
	int dm[8] = { 0 };
	int im = 0;
	int forward = 0;
	int n = 0, m = 0;
	int top = 0, base = 0, comp = 0;

	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			if (a[i][j] == BLANK)
			{
				for (int x = i - 1; x <= i + 1; x++)
				{
					if (x == i - 1 || x == i + 1) {
						for (int y = j - 1; y <= j + 1; y++)
						{
							if (y == j - 1 || y == j + 1)
							{
								if (x > 0 && y > 0 && x < MAX_ROW && y < MAX_ROW)
								{
									if (a[x][y] == TYPE)
									{
										count++;
										if (count == 3)
										{
											a[i][j] = O_TYPE;
											return true;
										}

									}
								}
							}

						}
					}
				}

				count = 0;

				for (im = 0; im < 8; im++)
				{
					dm[im] = 0;
				}

				im = 0;

				for (dx = i - 1; dx <= i + 1; dx++)
				{
					for (dy = j - 1; dy <= j + 1; dy++)
					{
						if (dx == i && dy == j)
						{
							continue;
						}

						if (dx >= 0 && dy >= 0 && dx < MAX_ROW && dy < MAX_COL && im < 8)
						{
							n = i - dx;
							m = j - dy;

							dm[im] = DFS_5(a, dx, dy, O_TYPE, TYPE, 1, n, m, 0);
							im++;

						}

					}
				}

				for (base = 0, comp = 7; base < 7 && comp >= 0; base++, comp--)
				{

					if (dm[base] == 1)
					{
						if (dm[comp] < 0)
						{
							continue;
						}

						if (dm[comp] == 1)
						{
							for (top = base + 1; top < 8; top++)
							{
								if (dm[top] >= 2)
								{
									if (top == comp)
									{
										continue;
									}
									a[i][j] = O_TYPE;
									return true;
								}
							}
						}

					}

					if (dm[base] >= 2)
					{
						if (dm[comp] < 0)
						{
							continue;
						}

						for (top = base + 1; top < 8; top++)
						{
							if (top == comp)
							{
								continue;
							}
							if (dm[top] >= 2)
							{
								a[i][j] = O_TYPE;
								return true;
							}
						}

					}

				}


			}

		}

	}

	return false;

}


void Com1(int a[MAX_ROW][MAX_COL], int row, int col, int adjustment, int q, int* px, int* py, int* t)
{
	int me = 0, blankey = 0;
	int AS_D = 0;
	int* ak = &AS_D, * blankey_t = &blankey;
	int i = 0, j = 0, k = 0;
	int mx = 0, my = 0;
	int zx = 0, zy = 0;
	int c_x = 0, c_y = 0;
	int n1 = 0, n2 = 0, num = 1, n3 = 0, n4 = 0;
	int eq1 = 0, eq2 = 0, eq1_m = 0, eq2_m = 0;
	if (adjustment == BLACK)
	{
		if (q == 1)
		{
			a[7][7] = BLACK;
			*px = 7;
			*py = 7;
		}
		else
		{
			for (i = 0; i < MAX_ROW; i++)
			{
				for (j = 0; j < MAX_COL; j++)
				{
					if (a[i][j] == WHITE)
					{
						n1 = AI_Deepth(a, i, j, num, row, col, WHITE, BLACK);
						if (n1 > n2)
						{
							n2 = n1;
							mx = i;
							my = j;
						}

						if (n1 == n2 && n1 >= 3 && *t < 1)
						{
							c_x = i;
							c_y = j;
							eq1 = c_x - mx;
							eq2 = c_y - my;
							eq1_m = abs(eq1);
							eq2_m = abs(eq2);
							if (eq1_m <= 4 && eq2_m <= 4) {
								if ((eq1_m == 0 || eq2_m == 0) || (eq1_m == eq2_m))
								{
									if (eq1_m == 0 && eq2_m == 0)
									{
										continue;
									}
									*t = *t + 1;
								}
							}
						}

						if (n2 >= 3 && *t == 0)
						{
							*t = -1;
						}

					}

				}
			}

			for (i = 0; i < MAX_ROW; i++)
			{
				for (j = 0; j < MAX_COL; j++)
				{
					if (a[i][j] == BLACK)
					{
						n3 = AI_Deepth(a, i, j, num, row, col, BLACK, WHITE);
						if (n3 > n4)
						{
							n4 = n3;
							zx = i;
							zy = j;
						}
					}

				}
			}

			if (n2 == 100)
			{
				AI_Judge(a, mx, my, row, col, WHITE, BLACK, BLACK, px, py, blankey_t, 0);
				return;
			}

			if (Second_Search(a, BLACK, WHITE) == true)
			{
				return;
			}

			if (n2 > n4 && n2 >= 3 && *t == 1)
			{
				*t = 0;
				AI_Judge(a, mx, my, row, col, WHITE, BLACK, BLACK, px, py, blankey_t, 0);
				return;
			}

			if (n2 > n4 && *t == -1)
			{
				*t = 0;
				if (AI_Judge(a, mx, my, row, col, WHITE, BLACK, BLACK, px, py, blankey_t, 1) == 1)
				{
					return;
				}
				return;
			}

			AI_Chess(a, zx, zy, n4, WHITE, BLACK, px, py);
			return;

		}

	}
	else
	{
		if (q == 1)
		{
			for (i = 0; i < MAX_ROW; i++)
			{
				for (j = 0; j < MAX_COL; j++)
				{
					if (a[i][j] == BLACK)
					{
						me = 1;
						if (i < 7 && j < 7)
						{
							a[i + 1][j + 1] = WHITE;
						}

						if (i >= 7 && j < 7)
						{
							a[i - 1][j + 1] = WHITE;
						}

						if (i < 7 && j >= 7)
						{
							a[i + 1][j - 1] = WHITE;
						}

						if (i >= 7 && j >= 7)
						{
							a[i - 1][j - 1] = WHITE;
						}

					}
					if (me == 1)
					{
						break;
					}
				}
				if (me == 1)
				{
					break;
				}
			}
		}
		else
		{
			for (i = 0; i < MAX_ROW; i++)
			{
				for (j = 0; j < MAX_COL; j++)
				{
					if (a[i][j] == BLACK)
					{
						n1 = AI_Deepth(a, i, j, num, row, col, BLACK, WHITE);
						if (n1 > n2)
						{
							n2 = n1;
							mx = i;
							my = j;
						}

						if (n1 == n2 && n1 >= 3 && *t < 1)
						{
							c_x = i;
							c_y = j;
							eq1 = c_x - mx;
							eq2 = c_y - my;
							eq1_m = abs(eq1);
							eq2_m = abs(eq2);
							if (eq1_m <= 4 && eq2_m <= 4) {
								if ((eq1_m == 0 || eq2_m == 0) || (eq1_m == eq2_m))
								{
									if (eq1_m == 0 && eq2_m == 0)
									{
										continue;
									}

									*t = *t + 1;
								}
							}
						}

						if (n2 >= 3 && *t == 0)
						{
							*t = -1;
						}

					}

				}
			}

			for (i = 0; i < MAX_ROW; i++)
			{
				for (j = 0; j < MAX_COL; j++)
				{
					if (a[i][j] == WHITE)
					{
						n3 = AI_Deepth(a, i, j, num, row, col, WHITE, BLACK);
						if (n3 > n4)
						{
							n4 = n3;
							zx = i;
							zy = j;
						}
					}

				}
			}

			if (n2 == 100)
			{
				AI_Judge(a, mx, my, row, col, BLACK, WHITE, WHITE, px, py, blankey_t, 0);
				return;
			}

			if (Second_Search(a, WHITE, BLACK) == true)
			{
				return;
			}

			if (n2 > n4 && n2 >= 3 && *t == 1)
			{
				*t = 0;
				AI_Judge(a, mx, my, row, col, BLACK, WHITE, WHITE, px, py, blankey_t, 0);
				return;
			}

			if (n4 < n2 && *t == -1)
			{
				*t = 0;
				if (AI_Judge(a, mx, my, row, col, BLACK, WHITE, WHITE, px, py, blankey_t, 1) == 1)
				{
					return;
				}
			}

			AI_Chess(a, zx, zy, n4, BLACK, WHITE, px, py);
			return;

		}
	}

}

void Per_Vs_Com1(int a[MAX_ROW][MAX_COL], int row, int col)
{

	int mem = 0;
	int i = 0, j = 0;
	int step = 1;
	int q = 1;
	int akd = 0, akc = 0, akt = 0;
	int* px = &akd;
	int* py = &akc;
	int* t = &akt;
	int ix = 0, iy = 0;
	while (1)
	{
		printf("请选择你的先手或后手：\n\n");
		printf("1.你是后手\n");
		printf("2.你是先手\n");
		scanf_s("%d", &mem);
		if (mem < 1 || mem > 2)
		{
			printf("错误输入，重新输入");
		}
		else
		{
			break;
		}
	}
	system("cls");
	for (step = 1; step <= MAX_ROW * MAX_COL; step++)
	{
		if (step % 2 != 0)
		{
			if (mem == 1)
			{
				Chess_borad(a, MAX_ROW, MAX_COL);
				printf("请等待电脑做出决策，大约2秒\n");

				printf("\n");
				Sleep(2000);
				if (q == 1) {
					Com1(a, MAX_ROW, MAX_COL, BLACK, q, px, py, t);
					q = 0;
				}
				else
				{
					Com1(a, MAX_ROW, MAX_COL, BLACK, q, px, py, t);
				}
				if (Win_Judge(a, row, col) == BLACK)
				{
					system("cls");
					Chess_borad(a, row, col);
					printf("黑棋胜利\n");
					exit(0);
				}
				system("cls");
				ix = *px;
				iy = *py;
			}
			else
			{
				printf("黑棋落子\n\n");
				while (1)
				{
					printf("白棋的落子位置如下：\n");
					printf("横坐标:%d\n", iy);
					printf("纵坐标:%d\n", ix);
					printf("请输入你的黑棋坐标:\n");
					Chess_borad(a, row, col);
					printf("横坐标: \n");
					scanf_s("%d", &j);
					printf("纵坐标: \n");
					scanf_s("%d", &i);
					if (a[i][j] != BLANK)
					{
						printf("这个位置是不合法的输入，请重新输入\n\n");
						continue;
					}
					if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
					{
						printf("超出棋盘范围了\n\n");
						continue;
					}
					break;
				}
				a[i][j] = BLACK;
				system("cls");
				if (Win_Judge(a, row, col) == BLACK)
				{
					Chess_borad(a, row, col);
					printf("黑棋胜利\n");
					exit(0);
				}
				system("cls");
			}
		}
		else
		{
			if (mem == 1)
			{
				printf("白棋落子\n\n");
				while (1)
				{
					printf("黑棋的落子位置如下：\n");
					printf("横坐标:%d\n", iy);
					printf("纵坐标:%d\n", ix);
					printf("请输入你的白棋坐标:\n");
					Chess_borad(a, row, col);
					printf("横坐标: \n");
					scanf_s("%d", &j);
					printf("纵坐标: \n");
					scanf_s("%d", &i);
					if (a[i][j] != BLANK)
					{
						printf("这个位置是不合法的输入，请重新输入\n\n");
						continue;
					}
					if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
					{
						printf("超出棋盘范围了\n\n");
						continue;
					}
					break;
				}
				a[i][j] = WHITE;
				system("cls");
				if (Win_Judge(a, row, col) == WHITE)
				{
					Chess_borad(a, row, col);
					printf("白棋胜利\n");
					exit(0);
				}
				system("cls");
			}
			else
			{
				Chess_borad(a, MAX_ROW, MAX_COL);
				printf("请等待电脑做出决策，大约2秒\n");
				printf("\n");
				Sleep(2000);
				if (q == 1) {
					Com1(a, MAX_ROW, MAX_COL, WHITE, q, px, py, t);
					q = 0;
				}
				else
				{
					Com1(a, MAX_ROW, MAX_COL, WHITE, q, px, py, t);
				}
				if (Win_Judge(a, row, col) == WHITE)
				{
					system("cls");
					Chess_borad(a, row, col);
					printf("白棋胜利\n");
					exit(0);
				}
				system("cls");
				ix = *px;
				iy = *py;
			}
		}
	}
	printf("棋盘已满,本次对局为和棋！3秒后自动退出\n\n");
	Sleep(3000);

}

void Com_Vs_Com(int a[MAX_ROW][MAX_COL], int row, int col)
{
	int akd = 0, akc = 0, akt = 0, q = 1, z = 1;
	int* px = &akd;
	int* py = &akc;
	int* t = &akt;
	int step = 0;
	printf("4秒后开始演示\n");
	Sleep(4000);
	system("cls");
	for (step = 1; step <= MAX_ROW * MAX_COL; step++)
	{
		if (step % 2 != 0)
		{
			Chess_borad(a, MAX_ROW, MAX_COL);

			printf("\n");
			Sleep(500);
			if (q == 1) {
				Com1(a, MAX_ROW, MAX_COL, BLACK, q, px, py, t);
				q = 0;
			}
			else
			{
				Com1(a, MAX_ROW, MAX_COL, BLACK, q, px, py, t);
			}

			if (Win_Judge(a, row, col) == BLACK)
			{
				system("cls");
				Chess_borad(a, row, col);
				printf("黑棋胜利\n");
				exit(0);
			}
			system("cls");
		}
		else
		{
			Chess_borad(a, MAX_ROW, MAX_COL);
			printf("\n");
			Sleep(500);
			if (z == 1) {
				Com1(a, MAX_ROW, MAX_COL, WHITE, z, px, py, t);
				z = 0;
			}
			else
			{
				Com1(a, MAX_ROW, MAX_COL, WHITE, z, px, py, t);

			}

			if (Win_Judge(a, row, col) == WHITE)
			{
				system("cls");
				Chess_borad(a, row, col);
				printf("白棋胜利\n");
				exit(0);
			}
			system("cls");

		}
	}

	printf("棋盘已满,本次对局为和棋！3秒后自动退出\n\n");
	Sleep(3000);

}

void Per_Vs_Per(int a[MAX_ROW][MAX_COL], int row, int col)
{
	int q = 0, z = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int i = 0, j = 0;
	int step = 1;
	for (step = 1; step <= MAX_ROW * MAX_COL; step++)
	{
		if (step % 2 != 0)
		{
			if (q == 1) {
				printf("白棋的落子情况如下:\n");
				printf("白棋的横坐标是:%d\n", x2);
				printf("白棋的纵坐标是:%d\n", y2);
				printf("\n");
			}
			else {
				q = 1;
			}
			printf("黑棋落子\n\n");
			while (1)
			{
				printf("请输入你的黑棋坐标:\n");
				Chess_borad(a, row, col);
				printf("横坐标: \n");
				scanf_s("%d", &j);
				printf("纵坐标: \n");
				scanf_s("%d", &i);
				x1 = j;
				y1 = i;
				if (a[i][j] != BLANK)
				{
					printf("这里已经有棋子了\n\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("超出棋盘范围了\n\n");
					continue;
				}
				break;
			}
			a[i][j] = BLACK;
			system("cls");
			if (Win_Judge(a, row, col) == BLACK)
			{
				Chess_borad(a, row, col);
				printf("黑棋胜利\n");
				exit(0);
			}
		}
		else
		{
			if (z == 1) {
				printf("黑棋的落子情况如下:\n");
				printf("黑棋的横坐标是:%d\n", x1);
				printf("黑棋的纵坐标是:%d\n", y1);
				printf("\n");
			}
			else {
				z = 1;
			}
			printf("白棋落子\n\n");
			while (1)
			{
				printf("请输入你的白棋坐标:\n");
				Chess_borad(a, row, col);
				printf("横坐标: \n");
				scanf_s("%d", &j);
				printf("纵坐标: \n");
				scanf_s("%d", &i);
				x2 = j;
				y2 = i;
				if (a[i][j] != BLANK)
				{
					printf("这里已经有棋子了\n\n");
					continue;
				}
				if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0)
				{
					printf("超出棋盘范围了\n\n");
					continue;
				}
				break;
			}
			a[i][j] = WHITE;
			system("cls");
			if (Win_Judge(a, row, col) == WHITE)
			{
				Chess_borad(a, row, col);
				printf("白棋胜利\n");
				exit(0);
			}
			system("cls");
		}

	}
	printf("棋盘已满,本次对局为和棋！3秒后自动退出\n\n");
	Sleep(3000);
}

void menu()
{
	printf("---------------------------------------------\n");
	printf("---------------------------------------------\n");
	printf("------- 欢迎进入QC的五子棋游戏系统 -------------\n");
	printf("--------- 请选择你想要的操作 ------------------\n");
	printf("------- 1. 玩家 VS 玩家 ----------------------\n");
	printf("------- 2. 玩家 VS 电脑 ----------------------\n");
	printf("------- 3. 电脑 VS 电脑 ----------------------\n");
	printf("------- 4. 退出系统 --------------------------\n");
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n");
}

int main()
{
	int choice = 0;
	int che[MAX_ROW][MAX_COL] = { 0 };
	menu();

	while (1)
	{
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			system("cls");
			Per_Vs_Per(che, MAX_ROW, MAX_COL);
			break;
		case 2:
			system("cls");
			Per_Vs_Com1(che, MAX_ROW, MAX_COL);
			break;
		case 3:
			system("cls");
			Com_Vs_Com(che, MAX_ROW, MAX_COL);
			break;
		case 4:
			printf("期待下次使用！\n");
			break;
		default:
			printf("未知的输入，请重新尝试\n");
			break;
		}

		if (choice == 4)
		{
			break;
		}

	}

	return 0;
}