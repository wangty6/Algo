bool vis[N];
int pr[N];
void getpr() {
	int N = 1000000;
	for (int i = 1; i <= N; i ++)
		vis[i] = false;
	int cnt = 0;
	for (int i = 2; i <= N; i ++) {
		if (!vis[i])
			pr[++ cnt] = i;
		for (int j = 1; j <= cnt; j ++) {
			if (i * pr[j] > N) break;
			vis[i * pr[j]] = true;
			if (i % pr[j] == 0) break;
		}
	}
}