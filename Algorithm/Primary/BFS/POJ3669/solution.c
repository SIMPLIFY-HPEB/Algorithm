#include<stdio.h>
#pragma warning(disable : 4996)

int point[302][302];

struct {
	int x;
	int y; 
	int t;
}queue[4001];
int head;
int end;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs();

int main()
{
	int m, i, n, x, y, t;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &t);
		if (point[y][x] == 0 || point[y][x] > t)
			point[y][x] = t;
		for (n = 0; n < 4; n++)
			if (x + dx[n] >= 0 && x + dx[n] < 301 && y + dy[n] >= 0 && y + dy[n] < 301 &&
				(point[y + dy[n]][x + dx[n]] == 0 || t < point[y + dy[n]][x + dx[n]]))
				point[y + dy[n]][x + dx[n]] = t;
	}
	printf("%d", bfs());
}

int bfs()
{
	queue[head].x = 0;
	queue[head].y = 0;
	queue[head].t = 0;
	if (point[0][0] == 0)
		return 0;
	while (head <= end) {
		int i;
		for (i = 0; i < 4; i++)
			if (queue[head].x + dx[i] >= 0 && queue[head].x + dx[i] < 302 && queue[head].y + dy[i] >= 0 && queue[head].y + dy[i] < 302){
				if (point[queue[head].y + dy[i]][queue[head].x + dx[i]] == 0)
					return queue[head].t + 1;
				if (point[queue[head].y + dy[i]][queue[head].x + dx[i]] > queue[head].t + 1) {
					end++;
					queue[end].x = queue[head].x + dx[i];
					queue[end].y = queue[head].y + dy[i];
					queue[end].t = queue[head].t + 1;
				}
			}
		head++;
	}
	return -1;
}