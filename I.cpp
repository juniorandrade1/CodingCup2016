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

const int N = 440;
ll pd[N][N];
ll v[N];
int n;

ll func(int l, int r) {
  if(l == r) return 0;
  if(pd[l][r] != -1) return pd[l][r];
  ll sol = LINF;
  for(int i = l; i < r; ++i) sol = min(sol, func(l, i) + func(i + 1, r) + v[l - 1] * v[i] * v[r]);
  return pd[l][r] = sol;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i <= n; ++i) scanf("%lld", v + i);
  memset(pd, -1, sizeof pd);
  printf("%lld\n", func(1, n));
  return 0;
}