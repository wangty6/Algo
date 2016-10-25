const int N = 201000, M = 2001000;
int n, m, T;
LL ans;
struct Q {
	int x, y, w;
	void scan() {
		scanf("%d%d%d", &x, &y, &w);
	}
	bool operator < (const Q& a) const {
		return w < a.w;
	}
}e[M];
void init() {
	ans = 0;
}
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void solve() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) e[i].scan();
	rep(i, 1, n) fa[i] = i;
	sort(e + 1, e + 1 + m);
	rep(i, 1, m)
		if (find(e[i].x) != find(e[i].y)) {
			fa[fa[e[i].x]] = fa[e[i].y];
			ans += e[i].w;
		}
	cout << ans;
}
int main() {
	scanf("%d", &T);
	rep(i, 1, T) {
		init();
		solve();
	}
	return 0;
}
