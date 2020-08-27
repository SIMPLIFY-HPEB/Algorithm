/*Red and Black*/
#include<stdio.h>

int dfs(int x, int y);

int w, h, s_x, s_y, step;
char room[20][20 + 1];

int main()
{
	for (scanf("%d %d", &w, &h); w * h != 0;printf("\n"), scanf("%d %d", &w, &h)) {
		step = 1;
		for (int y = 0; y < h; y++) {
			scanf("%s", room[y]);
			for (int x = 0; x < w; x++) {
				if (room[y][x] == '@')
					s_x = x, s_y = y;
			}
		}
		printf("%d", dfs(s_x, s_y, step));
	}
}

int dfs(int x, int y)
{
	if (x - 1 >= 0 && room[y][x - 1] == '.') {
		room[y][x - 1] = '#';
		step++;
		dfs(x - 1, y);
	}
	if (y + 1 < h && room[y + 1][x] == '.') {
		room[y + 1][x] = '#';
		step++;
		dfs(x, y + 1);
	}
	if (x + 1 < w && room[y][x + 1] == '.') {
		room[y][x + 1] = '#';
		step++;
		dfs(x + 1, y);
	}
	if (y - 1 >= 0 && room[y - 1][x] == '.') {
		room[y - 1][x] = '#';
		step++;
		dfs(x, y - 1);
	}
	return step;
}