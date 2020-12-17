#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma warning(disable:4996)

int solve();

int set[10];
int end;

int main()
{
	int line;
	char c;
	scanf("%d", &line);
	getchar();
	while (line > 0) {
		while ((c = getchar())) {
			if (c == ' ')
				continue;
			if (c == '\n') {
				printf("%d", solve());
				if (--line != 0)
					printf("\n");
				break;
			}
			set[end++] = c - 48;
		}
	}
}

int solve()
{
	int i;
	int m;
	int min_i;
	int min = 10;
	int first_n = 0;
	int second_n = 0;
	int first_min[5] = { 0 };
	int second_min[5] = { 0 };
	int f_m_size = 0;
	int s_m_size = 0;
	int first = end / 2 == end - end / 2 ? end / 2 : end - end / 2;
	int second = end - first;
	if(first != second)
		for(i = 0; i < end; i++)
			if (set[i] != 0) {
				first_min[f_m_size++] = set[i];
				set[i] = 0;
				while (i < end - 1) {
					set[i] = set[i + 1];
					i++;
				}
				end--;
				break;
			}
	if (set[0] == 0) {
		if (first_min[0] != 0) {
			first_min[f_m_size++] = 0;
			second_min[s_m_size++] = set[end - 1];
			for (i = 0; i < end - 2; i++)
				set[i] = set[i + 1];
			end -= 2;
		}
		else{
			first_min[f_m_size++] = set[2];
			first_min[f_m_size++] = 0;
			second_min[s_m_size++] = set[1];
			second_min[s_m_size++] = set[end - 1];
			for (i = 0; i < end - 4; i++)
				set[i] = set[i + 3];
			end -= 4;
		}
	}
	for (m = 0; m < second; m++) {
		for (i = 0; i < end - 1; i++) {
			min = min < set[i + 1] - set[i] ? min : (min_i = i), set[i + 1] - set[i];
			if (first_min[0] == 0) {
				first_min[f_m_size++] = set[end - 1];
				second_min[s_m_size++] = set[min_i];
			}
			else {
				first_min[f_m_size++] = set[min_i];
				second_min[s_m_size++] = set[end - 1];
			}
			while (min_i < end - 2) {
				set[min_i] = set[min_i + 1];
				min_i++;
			}
			end -= 2;
		}
	}
	for (i = 0; i < f_m_size; i++)
		first_n += first_min[i] * pow(10, f_m_size - i - 1);
	for (i = 0; i < s_m_size; i++)
		second_n += second_min[i] * pow(10, s_m_size - i - 1);
	return first_n - second_n;
}