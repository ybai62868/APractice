# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

# define MAX 512

int n, m;
int g[MAX][MAX];
int dist[MAX];
bool st[MAX];

int prim()
{
	memset(dist, 0x3f, sizeof(dist));
	int res = 0;
	for (int i = 0;i < n;i++) {
		int t = -1;
		for (int j = 1;j <= n;j++) {
			if (!st[j] &&(t==-1||dist[j] < dist[t])) {
				t = j;
			}
		}
		if (i && dist[t]==0x3f3f3f3f) {
			return 0x3f3f3f3f;
		} 
		if (i) {
			res += dist[t];
		}
		for (int j = 1;j <= n;j++) {
			dist[j] = min(dist[j], g[t][j]);
		}


		st[t] = true;
	}
	return res;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	memset(g, 0x3f, sizeof(g));
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);

	}
	int res = prim();
	if (res >= 0x3f3f3f) {
		puts("impossible");
	} else {
		printf("%d\n", res);
	}


	return 0;
}