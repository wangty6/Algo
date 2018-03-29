#include <bits/stdc++.h>
using namespace std;
const int N = 8001000;
typedef long long LL;
struct Treap
{
    int cnt;
    int L[N] , R[N] , sz[N];
    bool rev[N];
    char val[N];
    void clear() {
        cnt = 0;
    }
    Treap () {clear();}
    bool hey(int A , int B) {
        return (LL)rand() * (sz[A] + sz[B]) < (LL)sz[A] * RAND_MAX;
    }
    int newnode(char x) {
        ++ cnt , L[cnt] = R[cnt] = 0;
        sz[cnt] = 1 , val[cnt] = x, rev[cnt] = false;
        return cnt;
    }
    int copynode(int A) {
        if (!A) return 0;
        ++ cnt , L[cnt] = L[A] , R[cnt] = R[A];
        sz[cnt] = sz[A] , val[cnt] = val[A], rev[cnt] = rev[A];
        return cnt;
    }    
	void pushup(int x) {
        sz[x] = 1;
        if (L[x]) sz[x] += sz[L[x]];
        if (R[x]) sz[x] += sz[R[x]];
    }
    void pushdown(int x)
    {
    	if (rev[x])
    	{
    		int t = copynode(x);
    		L[x] = R[x] = 0;
    		if (L[t])
    		{
    			R[x] = copynode(L[t]);
    			rev[R[x]] ^= 1;
			}
			if (R[t])
			{
				L[x] = copynode(R[t]);
				rev[L[x]] ^= 1;
			}
			rev[x] = false;
		}
	}
				

    void merge(int& t , int x , int y) {
    	if (x) pushdown(x);
    	if (y) pushdown(y);
        if (!x || !y) {
            t = 0;
            if (x) t = copynode(x);
            if (y) t = copynode(y);
        }
        else if ( hey(x , y) ) {
            t = copynode(x);
            merge(R[t] , R[x] , y) , pushup(t);
        }
        else {
            t = copynode(y);
            merge(L[t] , x , L[y]) , pushup(t);
        }
    }
    void split(int t , int& x , int& y , int size) {
    	if (t) pushdown(t);
        if (!size) {
             x = 0 , y = copynode(t);
             return;
        }
        if (sz[L[t]] >= size) {
            y = copynode(t);
            split(L[t] , x , L[y] , size) , pushup(y);
        }
        else {
            x = copynode(t);
            split(R[t] , R[x] , y , size - sz[L[t]] - 1) , pushup(x);
        }
    }
    void build(char *A , int& t , int l , int r) {
        int mid = (l + r) >> 1;
        t = newnode(A[mid]);
        if (l < mid) build(A , L[t] , l , mid - 1);
        if (mid < r) build(A , R[t] , mid + 1 , r);
        pushup(t);
    }
    void print(int t) {
    	pushdown(t);
        if (L[t]) print(L[t]);
        putchar(val[t]);
        if (R[t]) print(R[t]);
    }
    char a[201000];
    int ac;
    void gather(int t) {
    	pushdown(t);
        if (L[t]) gather(L[t]);
        a[ac++] = val[t];
        if (R[t]) gather(R[t]);
    }
    void refactor(int& rt)
    {
    	ac = 0;
    	gather(rt);
    	clear();
    	build(a, rt, 0, ac - 1);
    }
};
Treap T;
int n, m;
char str[201000];
int main()
{
	//freopen("h6.in", "r", stdin);
	
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	int rt;
	T.build(str, rt, 0, n - 1);
	int K = 1;
	for (int i = 0; i < m; i ++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r) continue;
		int mid = (l + r) >> 1;
		if ((r - l + 1) & 1)
		{
			int l1, l2, o, r2, r1, t1, t2, t3;
			T.split(rt, l1, t1, l - 1);
			T.split(t1, l2, t2, mid - l);
			T.split(t2, o, t3, 1);
			T.split(t3, r2, r1, r - mid);
			r2 = T.copynode(l2);
			T.rev[r2] ^= 1; 
			T.merge(t1, l1, l2);
			T.merge(t2, t1, o);
			T.merge(t3, t2, r2);
			T.merge(rt, t3, r1);
		} else
		{
			int l1, l2, r2, r1, t1, t2;
			T.split(rt, l1, t1, l - 1);
			T.split(t1, l2, t2, mid - l + 1);
			T.split(t2, r2, r1, r - mid);
			r2 = T.copynode(l2);
			T.rev[r2] ^= 1; 
			T.merge(t1, l1, l2);
			T.merge(t2, t1, r2);
			T.merge(rt, t2, r1);
		}
		//T.print(rt);puts("");
		if (i % 1000 == 0)
			T.refactor(rt);
	}
	T.print(rt);puts("");
	return 0;
}
