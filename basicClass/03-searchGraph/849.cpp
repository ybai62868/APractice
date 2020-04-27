# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

# define MAX 521
int n, m;
int g[MAX][MAX];
int dist[MAX];
bool st[MAX];

int dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	for (int i = 1;i <= n;i++) {
		int t = -1;
		for (int j = 1;j <= n;j++) {
			if (!st[j] && (t==-1||dist[t] > dist[j])) {
				t = j;
			}
		}
		st[t] = true;
		for(int j = 1;j <= n;j++) {
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
	}

	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main(void)
{
	scanf("%d %d", &n, &m);
	memset(g, 0x3f, sizeof(g));
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		g[a][b] = min(g[a][b], c);
	}
	int res = dijkstra();
	printf("%d\n", res);

	return 0;
}