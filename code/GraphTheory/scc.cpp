
const int N = 101000;
int key[N], next[N], head[N], cnt;
int dfn[N], stk[N], top, low[N], tmct, scc_c, scc[N];
bool instk[N];
bool in[N], out[N];
int n, m, no_in, no_out;
void init() {
	clr(dfn);
	clr(low);
	clr(scc);
	clr(instk);
	clr(stk);
	scc_c = top = tmct = cnt = 0;
	memset (head, -1, sizeof head);
	no_in = no_out = 0;
	clr(in);
	clr(out);
}
void DFS(int u) {
	dfn[u] = low[u] = ++ tmct;
	stk[++ top] = u;
	instk[u] = true;
	for (int i = head[u]; ~ i; i = next[i]) {
		int v = key[i];
		if (!dfn[v]) {
			DFS(v);
			low[u] = min(low[u], low[v]);
		} else if (instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		++ scc_c;
		int now;
		do {
			now = stk[top --];
			scc[now] = scc_c;
			instk[now] = false;
		} while(now != u);
	}
}
void add(int x, int y) {
	key[cnt] = y;
	next[cnt] = head[x];
	head[x] = cnt++;
}

int solve() {
	n = read(), m = read();
	rep(i, 1, m) {
		int x = read(), y = read();
		add(x, y);
	}
	rep(i, 1, n)
		if (dfn[i] == 0)
			DFS(i);
	rep(u, 1, n) edg(j, u) {
		int v = key[j];
		if (scc[u] == scc[v]) continue;
		in[scc[v]] = true;
		out[scc[u]] = true;
	}
	rep(i, 1, scc_c) if (in[i] == false) no_in++;
	rep(i, 1, scc_c) if (out[i] == false) no_out++;
	if (scc_c == 1) return 0;
	return max(no_in, no_out);
}

int main() {
	int T = read();
	rep(i, 1, T) {
		init();
		printf("%d\n", solve());
	}
	return 0;
}
