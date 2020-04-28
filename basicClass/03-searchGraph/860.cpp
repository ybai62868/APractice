# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;
# define MAX 112345
int n, m;
int h[MAX], e[MAX*2], ne[MAX*2], idx;
int color[MAX];

void add(int a, int b)
{
    e[idx] = b, ne[idx]= h[a], h[a] = idx++;
}


bool dfs(int u, int c) 
{
    color[u] = c;
    for (int i = h[u]; i!=-1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {
            if(!dfs(j, 3 - c)) return false;
        } else if (color[j] == c){
            return false;
        }
    }
    return true;
}

int main(void)
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof(h));
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b), add(b, a);
    }
    bool flag = true;
    for (int i = 1;i <= n;i++) {
        if (!color[i] ) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }
    
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}