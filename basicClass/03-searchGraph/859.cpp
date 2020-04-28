# include <cstdio>
# include <iostream>
# include <algorithm>

using namespace std;

# define MAX 112345

int n, m;
int p[MAX];

struct Edge
{
    int a, b, w;
    bool operator< (const Edge &W) const {
        return w < W.w;
    }
}edges[MAX << 1];

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}


int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0;i < m;i++) {
        int a, b, w; scanf("%d %d %d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    sort(edges, edges+m);
    for (int i = 1;i <= n;i++) {
        p[i] = i;
    }
    int res = 0, cnt = 0;
    for (int i = 0;i < m;i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;
        a = find(a), b = find(b);
        if (a!=b) {
            res+=w, cnt+=1;
            p[a] = b;
        }
    }
    if (cnt < n-1) {
        puts("impossible");
    } else {
        printf("%d\n",res);
    }

    
    return 0;
}