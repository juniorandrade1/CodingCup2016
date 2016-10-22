#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define Pi 2*acos(0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

const int N = 200010;
const int M = 20;

int n;
int tr[4 * N];
vi g[N];

void build(int no, int l, int r) {
  tr[no] = 1;
  if(l == r) return;
  int nxt = (no << 1), mid = (l + r) >> 1;
  build(nxt, l, mid);
  build(nxt + 1, mid + 1, r);
}

void update(int no, int l, int r, int i, int val) {
  if(l == r) {
    tr[no] = val;
    return;
  }
  int nxt = (no << 1), mid = (l + r) >> 1;
  if(i <= mid) update(nxt, l, mid, i, val);
  else update(nxt + 1, mid + 1, r, i, val);
  tr[no] = min(tr[nxt], tr[nxt + 1]);
}

int query(int no, int l, int r, int i, int j) {
  if(r < i || l > j) return 1;
  if(l >= i && r <= j) return tr[no];
  int nxt = (no << 1), mid = (l + r) >> 1;
  return min(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

int query(int l, int r) {
  assert(l <= r);
  return query(1, 1, n, l, r);
}

void update(int x, int p) {
  update(1, 1, n, x, p);
}

int subSize[N], idChain[N], posInBase[N];
int counterBase = 0;
int lca[N][M], h[N];

void dfs(int x, int ult) {
  subSize[x] = 1;
  lca[x][0] = ult;
  for(int i = 1; i < M; ++i) lca[x][i] = lca[lca[x][i - 1]][i - 1];
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    h[y] = h[x] + 1;
    dfs(y, x);
    subSize[x] += subSize[y];
  }
}

int getLca(int a, int b) {
  if(h[a] < h[b]) swap(a, b);
  int d = h[a] - h[b];
  for(int i = M - 1; i >= 0; --i) if((d >> i) & 1) a = lca[a][i];
  if(a == b) return a;
  for(int i = M - 1; i >= 0; --i) if(lca[a][i] != lca[b][i]) a = lca[a][i], b = lca[b][i];
  return lca[a][0];
}

void hld(int x, int chain) {
  idChain[x] = chain;
  posInBase[x] = ++counterBase;
  debug("x = %d = %d %d\n", x, idChain[x], posInBase[x]);
  int idx = -1;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(idx == -1 || subSize[idx] < subSize[y]) idx = y;
  }
  if(idx != -1) hld(idx, chain);
  for(int i = 0; i < g[x].size(); ++i) {
    if(g[x][i] == idx) continue;
    hld(g[x][i], g[x][i]);
  }
}

int queryUp(int a, int b) {
  int chainA = idChain[a], chainB = idChain[b];
  int ans = 1;
  while(chainA != chainB) {
    ans = min(ans, query(posInBase[chainB], posInBase[b]));
    b = lca[chainB][0];
    chainB = idChain[b];
  }
  ans = min(ans, query(posInBase[a], posInBase[b]));
  return ans;
}

int solve(int a, int b) {
  int lca = getLca(a, b);
  return min(queryUp(lca, a), queryUp(lca, b));
}

int main() {
  scanf("%d", &n);
  assert(n >= 1 && n <= 100000);
  for(int i = 2; i <= n; ++i) {
    int p; scanf("%d", &p);
    assert(p < i);
    g[p].pb(i);
  }
  build(1, 1, n);
  dfs(1, 1);
  hld(1, 1);
  assert(counterBase <= n);
  int q; scanf("%d", &q);
  while(q--) {
    char op; scanf(" %c", &op);
    if(op == '?') {
      //debug("NEED ANS\n");
      int x, y; scanf("%d %d", &x, &y);
      assert(x <= n && x >= 1 && y <= n && y >= 1);
      puts(solve(x, y) ? "Y" : "N");
    }
    else if(op == '+') {
      //debug("TURN ON\n");
      int x; scanf("%d", &x);
      assert(x >= 1 && x <= n);
      update(posInBase[x], 1);
    }
    else {
      //debug("TURN OFF\n");
      int x; scanf("%d", &x);
      assert(x >= 1 && x <= n);
      update(posInBase[x], 0);
    }
  }
  return 0;
}