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

const int N = 100010;
const int M = 20;
int n;
vi g[N];

int lca[N][M], h[N];

void dfs(int x, int ult) {
  lca[x][0] = ult;
  for(int i = 1; i < M; ++i) lca[x][i] = lca[lca[x][i - 1]][i - 1];
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    h[y] = h[x] + 1;
    dfs(y, x);
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

int olocoTio[N];
int papai[N];

void solve(int x, int y) {
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    solve(y, x);
    olocoTio[x] += olocoTio[y];
  }
  olocoTio[x] %= 2;
}

int main() {
  scanf("%d", &n);
  for(int i = 2; i <= n; ++i) {
    int x; scanf("%d", &x);
    g[x].pb(i);
    papai[i] = x;
  }
  dfs(1, 0);
  int q; scanf("%d", &q);
  while(q--) {
    int a, b; scanf("%d %d", &a, &b);
    int l = getLca(a, b);
    olocoTio[a]++;
    olocoTio[b]++;
    olocoTio[l]--;
    olocoTio[lca[l][0]]--;
  }


  solve(1, 1);
  vii sol;
  for(int i = 2; i <= n; ++i) {
    olocoTio[i] %= 2;
    while(olocoTio[i] < 0) olocoTio[i] += 2;
    olocoTio[i] %= 2;
    if(olocoTio[i]) sol.pb(mp(i, papai[i]));
    else sol.pb(mp(papai[i], i));
  }
  sort(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); ++i) {
    printf("%lld %lld\n", sol[i].F, sol[i].S);
  }


  return 0;
}