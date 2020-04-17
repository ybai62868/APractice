# include <cstdio>
# include <iostream>

using namespace std;

# define MAX 123


int n;
char grid[MAX][MAX];
bool row[MAX];
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

void dfs2(int x, int y, int s)
{
	if ( y==n ) {
		x++, y = 0;
	}
	if ( x==n ) {
		if ( s==n ) {
			for (int i = 0;i < n;i++) {
				puts(grid[i]);
			}
			puts("");
		}
		return;
	}
	dfs2(x, y+1, s);
	if (!row[x] && !col[y] && !left_dia[x+y] && !right_dia[x-y+n]) {
		grid[x][y] = 'Q';
		row[x] = col[y] = left_dia[x+y] = right_dia[x-y+n] = true;
		dfs2(x, y+1, s+1);
		grid[x][y] = '.';
		row[x] = col[y] = left_dia[x+y] = right_dia[x-y+n] = false;

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
	// dfs(0);
	dfs2(0, 0, 0);

	return 0;
}