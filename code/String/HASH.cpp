pw[0] = 1;
for (int i = 1; i < 2001; i ++)
{
	pw[i] = pw[i - 1] * MAGIC;
}
h[ls] = 0;
for (int i = ls - 1; i >= 0; i --)
{
	h[i] = h[i + 1] * MAGIC + s[i];
}

const int N = 2100;
LL pw[N], h[N];
const LL MAGIC = 131;

LL hash(int i, int l)
{
	return h[i] - h[i + l] * pw[l];
}
