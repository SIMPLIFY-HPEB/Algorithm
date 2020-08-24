/*Curling 2.0*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dfs(int x, int y, int step);

int s_x, s_y, width, height, minimum_step, board[20][20];

int main()
{
	for (scanf("%d %d", &width, &height); width * height != 0; printf("\n"), scanf("%d %d", &width, &height)) {
		minimum_step = 11;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				scanf("%d", &board[y][x]);
				if (board[y][x] == 2) {
					board[y][x] = 0;
					s_x = x, s_y = y;
				}
			}
		}
		dfs(s_x, s_y, 0);
		if (minimum_step == 11)
			minimum_step = -1;
		printf("%d", minimum_step);
	}
}

int dfs(int x, int y, int step)
{
	if (step > 10)
		return -1;
	for (int i = 1;x + i < width && board[y][x + i] != 1; i++) {
		if (board[y][x + i] == 3) {
			minimum_step = minimum_step > step + 1 ? step + 1 : minimum_step;
			return minimum_step;
		}
		if (x + i + 1 < width && board[y][x + i + 1] == 1) {
			board[y][x + i + 1] = 0;
			dfs(x + i, y, step + 1);
			board[y][x + i + 1] = 1;
		}
	}
	for (int i = 1; x - i >= 0 && board[y][x - i] != 1; i++) {
		if (board[y][x - i] == 3) {
			minimum_step = minimum_step > step + 1 ? step + 1 : minimum_step;
			return minimum_step;
		}
		if (x - i - 1 >= 0 && board[y][x - i - 1] == 1) {
			board[y][x - i - 1] = 0;
			dfs(x - i, y, step + 1);
			board[y][x - i - 1] = 1;
		}
	}
	for (int i = 1; y + i < height; i++) {
		if (board[y + i][x] == 3) {
			minimum_step = minimum_step > step + 1 ? step + 1 : minimum_step;
			return minimum_step;
		}
		if (y + i + 1 < height && board[y + i + 1][x] == 1) {
			board[y + i + 1][x] = 0;
			dfs(x, y + i, step + 1);
			board[y + i + 1][x] = 1;
		}
	}
	for (int i = 1; y - i >= 0; i++) {
		if (board[y - i][x] == 3) {
			minimum_step = minimum_step > step + 1 ? step + 1 : minimum_step;
			return minimum_step;
		}
		if (y - i - 1 >= 0 && board[y - i - 1][x] == 1) {
			board[y - i - 1][x] = 0;
			dfs(x, y - i, step + 1);
			board[y - i - 1][x] = 1;
		}
	}
}