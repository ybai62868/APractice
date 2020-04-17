# include <cstdio>
# include <iostream>
# include <queue>
# include <cstring>
# include <queue>

using namespace std;

# define MAX 123

int n, m;
int grid[MAX][MAX];
int d[MAX][MAX]; //每个点到起点的距离
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

typedef pair<int, int> PII;

PII q[MAX * MAX], father[MAX][MAX];

// int bfs(int x, int y)
// {
// 	int hh = 0, tt = 0;
// 	q[0] = {0, 0};
// 	memset(d, -1, sizeof(d));
// 	d[0][0] = 0;
// 	while (hh <= tt) {
// 		PII t = q[hh++];
// 		for (int i = 0;i < 4;i++) {
// 			int x = t.first + dx[i];
// 			int y = t.second + dy[i];
// 			if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && d[x][y] == -1) {
// 				d[x][y] = d[t.first][t.second] + 1;
//                 father[x][y] = t;
// 				q[++tt] = {x, y};

// 			}
// 		}
// 	}
	
// 	int v_x = n-1, v_y = m-1;
// 	while (v_x||v_y) {
// 	    printf("%d %d\n", v_x, v_y);
// 	    auto t = father[v_x][v_y];
// 	    v_x = t.first;
// 	    v_y = t.second;
// 	}
	
// 	return d[n-1][m-1];
// }

int bfs(int x, int y)
{
    queue<PII>Q;
    Q.push({0, 0});
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    while (!Q.empty()) {
        auto temp = Q.front();
        Q.pop();
        for (int i = 0;i < 4;i++) {
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];
            if ( x >=0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[temp.first][temp.second] + 1;
                father[x][y] = temp;
                Q.push({x, y});
            }
        }
    }
    // int v_x = n-1, v_y = m-1;
    // while (v_x || v_y) {
    //     printf("%d %d\n", v_x, v_y);
    //     auto t = father[v_x][v_y];
    //     v_x = t.first;
    //     v_y = t.second;
    // }
    return d[n-1][m-1];
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	int res = bfs(0, 0);
	printf("%d\n", res);

	return 0;
}