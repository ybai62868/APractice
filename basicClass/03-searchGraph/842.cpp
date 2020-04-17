# include <cstdio>
# include <iostream>

using namespace std;

# define MAX 112345

int path[MAX];
bool book[MAX];
int n;

void dfs(int step)
{
	if (step == n) {
		for (int i = 0;i < n;i++) {
			printf("%d ", path[i]);
		}
		puts("");
		return;
	}

	for (int i = 1;i <= n;i++) {
		if (!book[i]) {
			path[step] = i;
			book[i] = true;
			dfs(step+1);
			book[i] = false;
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	dfs(0);

	return 0;
}