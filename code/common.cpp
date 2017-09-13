#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define edg(i, x) for (int i = head[x]; ~ i; i = next[i])
#define ctn(i, x) for (i = x.begin(); i != x.end(); i++)
#define clr(x) memset ((x), 0, sizeof (x))
#define SZ(x) (int)x.size()
#define next nxt
#define left lft
typedef unsigned long long LL;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x) {
    static int a[24];int n = 0;
    while(x > 0) {
        a[n++] = x % 10;
        x /= 10;
    }
    if (n == 0) a[n++] = 0;
    while(n--) putchar('0' + a[n]);
    putchar('\n');
}
void from(const char *s) {
    freopen(s, "r", stdin);
}
void to(const char *s) {
    freopen(s, "w", stdout);
}
template<class K, class V>
int getId(map<K, V> &mp, int &input_cnt, const string& name)
{
    if (mp.count(name) == 0)
    {
        mp[name] = ++input_cnt;
    }
    return mp[name];
}
