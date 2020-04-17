# include <cstring>
# include <iostream>
# include <queue>

using namespace std;

const int N = 112345;

int h[N], e[N], d[N], idx, ne[N];
int n, m, q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    
    queue<int>Q;
    Q.push(1);
    memset(d, -1, sizeof(d));
    d[1] = 0;
    while (!Q.empty()) {
        int temp = Q.front();
        Q.pop();
        for (int i = h[temp];i != -1;i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[temp] + 1;
                Q.push(j);
            }
        }
    }

    
    
    return d[n]; //! 返回最后一个搜到的点的距离
}

int main(void)
{
    scanf("%d %d", &n, &m);

    memset(h, -1, sizeof h);

    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d %d", &a, &b);
        add(a, b);
    }
    int res = bfs();
    printf("%d\n", res);
}
