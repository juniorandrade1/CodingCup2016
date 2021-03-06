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

const int N = 10001;

ll pd[N];
int n, r;
int a[N];

int main() {
  scanf("%d %d", &n, &r);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  pd[0] = 1;
  for(int i = 0; i < n; ++i) {
    for(int j = a[i]; j <= r; j++) {
      pd[j] += pd[j - a[i]];
    }
  }
  printf("%lld\n", pd[r]);
  return 0;
}