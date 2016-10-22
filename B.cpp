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



int main() {
  int ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
  int x, y; scanf("%d %d", &x, &y);
  int ok = 1;
  if(x >= ax && y >= ay && x <= bx && y >= by && x <= cx && y <= cy && x >= dx && y <= dy) ok = 1;
  else ok = 0;
  if(ok) puts("Estou dentro do quadrado");
  else puts("Estou fora do quadrado");
  return 0;
}