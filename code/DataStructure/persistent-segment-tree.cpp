#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define length(x) (int(x.size())
#define db(x) cout << #x << "=" << x << endl;
#define all(x) x.begin(), x.end()
typedef long long LL;
#define ls L[idx]
#define rs R[idx]
#define lson l, mid, ls
#define rson mid + 1, r, rs
const int N = 201000;
int nc, L[N * 20], R[N * 20], sum[N * 20];
int n, m, a[N], rt[N];
int newnode(int val, int l, int r)
{
	++nc;
	sum[nc] = val;
	L[nc] = l;
	R[nc] = r;
	return nc;
}
void update(int l, int r, int idx, int &nidx, int pos)
{
	nidx = newnode(sum[idx] + 1, ls, rs);
	if (l == r)
	{
		return ;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(lson, L[nidx], pos);
	if (pos > mid) update(rson, R[nidx], pos);
}
int query(int l, int r, int K)
{
	int st = 1, ed = n;
	int x = rt[l - 1], y = rt[r];
	while(st != ed)
	{
		if (sum[y] - sum[x] < K) return 0;
		int mid = (st + ed) >> 1;
		int a = sum[L[y]] - sum[L[x]];
		if (a >= K)
		{
			x = L[x];
			y = L[y];
			ed = mid;
		} else if (sum[R[y]] - sum[R[x]] >= K - a)
		{
			K -= a;
			x = R[x];
			y = R[y];
			st = mid + 1;
		} else return 0;
	}
	return st;
}
int main()
{
	scanf("%d%d", &n, &m);
	vector<int> vec;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		vec.push_back(a[i]);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	for (int i = 1; i <= n; i ++)
	{
		int x = lower_bound(all(vec), a[i]) - vec.begin() + 1;
		update(1, n, rt[i - 1], rt[i], x);
	}
	for (int i = 1; i <= m; i ++)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", vec[query(l, r, k) - 1]);
	}
	return 0;
} 
