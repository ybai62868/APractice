# include <cstdio> 
# include <iostream>
# include <cstring>

using namespace std;

# define MAX 112345
int n;
int h[MAX], e[MAX*2], ne[MAX*2], idx;
bool st[MAX];
int ans = MAX;


void add(int a, int b) 
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
	st[u] = true;

	int sum = 1, res = 0;
	for (int i = h[u];i!=-1;i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return ans;
}


int main(void)
{
	scanf("%d", &n);
	memset(h, -1, sizeof(h));
	for (int i = 0;i < n-1;i++) {
		int a, b; scanf("%d %d", &a, &b);
		add(a, b), add(b, a);
	}
	ans = dfs(n);
	printf("%d\n", ans);

	return 0;
}