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

const int N = 100000101;




bool isPrime(int x) {
  for(int i = 2; i * i <= x; ++i) if(x % i == 0) return false;
  return true;
}

bool isAdd(int x) {
  int sum = 0;
  while(x) {
    sum += (x % 10);
    x /= 10;
  }
  return isPrime(sum);
}

int main() {
  int x; scanf("%d", &x);
  for(int i = x; ; ++i) {
    if(isPrime(i) && isAdd(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}