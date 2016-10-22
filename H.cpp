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

const int N = 500000;

int pset[N];

int fnd(int i){ return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }
void uni(int i, int j){ pset[fnd(i)] = fnd(pset[j]); }

int main() {
  for(int i = 1; i < N; ++i) pset[i] = i;
  int n, q; scanf("%d %d", &n, &q);
  while(q--) {
    int a, b; scanf("%d %d", &a, &b);
    uni(a, b);
  }
  set<int>s;
  for(int i = 1; i <= n; ++i) if(fnd(i) != i) s.insert(fnd(i));
  printf("David pode participar de %d guildas\n", (int)s.size());
  return 0;
}