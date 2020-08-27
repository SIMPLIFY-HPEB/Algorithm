#include<stdio.h>

int a[10], b[6], c[6], m;

int main() 
{
	for (scanf("%d", &m); m > 0; m--) {
		for (int n = 0; n < 10; n++)
			scanf("%d", &a[n]);
		dfs(a, b + 1, c + 1, 1);
		if (a[9] == 0)
			printf("YES\n");
		else
			printf("No\n");
	}
}

int dfs(int* a, int* b, int* c, int step)
{
	if (step > 10)
		return;
	if (*a > * (b - 1) && *(b + 5 - step) == 0) {
		*b = *a;
		*a = 0;
		dfs(a + 1, b + 1, c, step + 1);
		return;
	}
	if (*a > * (c - 1)) {
		*c = *a;
		*a = 0;
		dfs(a + 1, b, c + 1, step + 1);
		return;
	}
	return;
}