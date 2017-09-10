#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 100000 + 10;
struct State {
    int suf, go[26], nxt;
    int val, cnt;
    State() :
        suf(0), val(0) {
            memset(go, 0, sizeof go);
        }
};
int root, last, cur, first[MAX_N];
State st[MAX_N * 2];

void init() {
    cur = 1;
    root = last = cur++;
}

void extend(int w) {
    int p = last, np = cur++;
    st[np].val = st[p].val + 1;
    st[np].cnt = 1;
    while (p && !st[p].go[w])
        st[p].go[w] = np, p = st[p].suf;
    if (!p)
        st[np].suf = root;
    else {
        int q = st[p].go[w];
        if (st[p].val + 1 == st[q].val) {
            st[np].suf = q;
        } else {
            int nq = cur++;
            memcpy(st[nq].go, st[q].go, sizeof st[q].go);
            st[nq].val = st[p].val + 1;
            st[nq].suf = st[q].suf;
            st[q].suf = nq;
            st[np].suf = nq;
            while (p && st[p].go[w] == q)
                st[p].go[w] = nq, p = st[p].suf;
        }
    }
    last = np;
}
char str[101000];
int main() {
    int T;
    scanf("%d", &T);
    while(T --)
    {
        init();
        memset (first, 0, sizeof first);
        int n;
        scanf("%d%s", &n, str);
        int L = strlen(str);
        for (int i = 0; i < L; ++i) {
            extend(str[i] - 'a');
        }
        for (int i = 1; i < cur; ++i)
            st[i].nxt = first[st[i].val], first[st[i].val] = i;
        for (int it = L; it >= 0; --it) {
            for (int i = first[it]; i; i = st[i].nxt)
                if (st[i].suf)
                    st[st[i].suf].cnt += st[i].cnt;
        }

        for (int i = 1; i < cur; ++i)
        {
            memset (st[i].go, 0, sizeof st[i].go);
            st[i].suf = st[i].nxt = st[i].val = st[i].cnt = 0;
        }
    }
    return 0;
}
