# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
# include <queue>

using namespace std;
# define MAX 11234

int n,m;
int h[MAX], w[MAX], e[MAX], ne[MAX], idx;
int dist[MAX], cnt[MAX];
bool st[MAX];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa() {
    queue<int>q;
    for (int i = 1;i <= n;i++) {
        st[i] = true;
        q.push(i);
    }
    
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t];i!=-1;i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        
        }
    }
    return false;
}

int main(void)
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof(h));
    while(m--) {
        int a, b, c; scanf("%d %d %d",&a, &b, &c);
        add(a, b, c);
    }
    
    int flag = spfa();
    if (flag) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}