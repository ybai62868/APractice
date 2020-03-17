# include <cstdio>
# include <iostream>
# include <algorithm>

using namespace std;

# define MAX 112345
int a[MAX];

int main(void)
{
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 0;i < n;i++) scanf("%d", &a[i]);
    while (q--) {
        int x; scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= x) r = mid;
            else {
                l = mid + 1;
            }
        }
        if (a[l] != x) {
            printf("-1 -1\n");
        } else {
            int ll = 0, rr = n - 1;
            while (ll < rr) {
                int mid2 = (ll + rr + 1) >> 1;
                if (a[mid2] <= x) ll = mid2;
                else rr = mid2 - 1;
            }
            printf("%d %d\n", l, rr);
        }
    }
    return 0;
}