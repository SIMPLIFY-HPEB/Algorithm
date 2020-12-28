#include<stdio.h>
#include<math.h>
#include<string.h>
#define INF 99999;
#pragma warning(disable : 4996);

int input, f[5], s[5], f_c[120], s_c[120];
int input_len, first_len, second_len, f_s, s_s, f_c_s, s_c_s;
int* m, m_s, * c, * c_s;

int permutation();
void dfs();

int main()
{
	int line, i;
	char c;
	scanf("%d", &line);
	getchar();
	while (line != 0 && (c = getchar())) {
		if (c == ' ') {
			continue;
		}
		if (c == '\n') {
			first_len = input_len - input_len / 2;
			second_len = input_len / 2;
			printf("%d\n", permutation());
			input = input_len = 0;
			--line;
		}
		else {
			input |= 1 << (c - 48);
			input_len++;
		}
	}
}

int permutation()
{
	int i, j, n;
	int k = 0;
	int l = input_len;
	int min = INF;
	for (i = input_len - 1; i > input_len - first_len ; i--) {
		l *= i;
	}
	for (i = first_len; i > 1; i--) {
		l /= i;
	}
	l /= 2;
	for (i = 0; i <= input; i++) {
		if ((i & input) != i) {
			continue;
		}
		f_s = s_s = 0;
		n = input;
		for (j = 0; 1 << j <= i; j++) {
			if (1 << j & i) {
				f[f_s++] = j;
				n &= ~(1 << j);
			}
		}
		if (f_s == first_len) {
			if (first_len == second_len && ++k > l) {
				break;
			}
			for (j = 0; 1 << j <= n; j++) {
				if (1 << j & n) {
					s[s_s++] = j;

				}
			}
			m = f;
			m_s = f_s;
			c = f_c;
			c_s = &f_c_s;
			dfs(0);
			m = s;
			m_s = s_s;
			c = s_c;
			c_s = &s_c_s;
			dfs(0);
			for (j = 0; j < f_c_s; j++) {
				for (n = 0; n < s_c_s; n++) {
					min = min < abs(f_c[j] - s_c[n]) ? min : abs(f_c[j] - s_c[n]);
				}
			}
			f_c_s = 0;
			s_c_s = 0;
		}
	}
	return min;
}

void dfs(int pre)
{
	int i;
	int j;
	int a_p[5];
	if (m_s == 0) {
		if (pre == 0) {
			c[*c_s] = 0;
		}
		(*c_s)++;
	}
	for (i = 0; i < m_s; i++) {
		if (pre == 0 && m[i] == 0) {
			if (m_s == 1) {
				c[(*c_s)++] = 0;
				return;
			}
			continue;
		}
		c[*c_s] = m[i] * pow(10, m_s - 1) + pre;
		memcpy(a_p, m, m_s * sizeof(int));
		for (j = i; j < m_s - 1; j++) {
			m[j] = m[j + 1];
		}
		m_s--;
		dfs(c[*c_s]);
		m_s++;
		memcpy(m, a_p, m_s * sizeof(int));
	}
}