#include<stdio.h>
#include<string.h>

int board[20][20], exist_row[20], exist_line[20];
int width, height, minimu_moves;
int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, -1, 0, 1 };

void dfs(int y, int x, int moves);

int main()
{
	int x, y, s_x, s_y;
	for (scanf("%d %d", &width, &height); width * height != 0; printf("\n"), scanf("%d %d", &width, &height)) {
		minimu_moves = 11;
		memset(exist_row, 0, sizeof(exist_row));
		memset(exist_line, 0, sizeof(exist_line));
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				scanf("%d", &board[y][x]);
				if (board[y][x] == 1 || board[y][x] == 3) {
					exist_row[y] += 1;
					exist_line[x] += 1;
				}
				if (board[y][x] == 2) {
					s_x = x;
					s_y = y;
				}
			}
		}
		dfs(s_y, s_x, 1);
		printf("%d", minimu_moves == 11 ? -1 : minimu_moves);
	}

}
void dfs(int y, int x, int moves)
{
	int i, j, n_x, n_y, * e_p;
	if (moves == 11) {
		return;
	}
	for (i = 0; i < 4; i++) {
		n_x = x;
		n_y = y;
		e_p = n_x + next_x[i] == x ? &exist_line[x] : &exist_row[y];
		if (*e_p == 0) {
			continue;
		}
		while (n_x + next_x[i] >= 0 && n_x + next_x[i] < width && n_y + next_y[i] >= 0 && n_y + next_y[i] < height && board[n_y + next_y[i]][n_x + next_x[i]] == 0) {
			n_x += next_x[i];
			n_y += next_y[i];
		}
		if (n_x + next_x[i] >= 0 && n_x + next_x[i] < width && n_y + next_y[i] >= 0 && n_y + next_y[i] < height) {
			if (board[n_y + next_y[i]][n_x + next_x[i]] == 1 && (n_x != x || n_y != y)) {
				board[n_y + next_y[i]][n_x + next_x[i]] = 0;
				*e_p -= 1;
				dfs(n_y, n_x, ++moves);
				board[n_y + next_y[i]][n_x + next_x[i]] = 1;
				*e_p += 1;
			}
			if (board[n_y + next_y[i]][n_x + next_x[i]] == 3) {
				minimu_moves = minimu_moves < moves ? minimu_moves : moves;
			}
		}
	}
}