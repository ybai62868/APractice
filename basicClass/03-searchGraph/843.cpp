# include <cstdio>
# include <iostream>

using namespace std;

# define MAX 123


int n;
char grid[MAX][MAX];
bool col[MAX], left_dia[MAX], right_dia[MAX];

void dfs(int step)
{
	if (step == n) {
		for (int i = 0;i < n;i++) {
			puts(grid[i]);
		}
		puts("");
		return;
	}

	for (int i = 0;i < n;i++) {
		if (!col[i] && !left_dia[step+i] && !right_dia[i-step+n]) {
			grid[step][i] = 'Q';
			col[i] = left_dia[step+i] = right_dia[i-step+n] = true;
			dfs(step+1);
			col[i] = left_dia[step+i] = right_dia[i-step+n] = false;
			grid[step][i] = '.';

		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			grid[i][j] = '.';
		}
	}
	dfs(0);

	return 0;
}