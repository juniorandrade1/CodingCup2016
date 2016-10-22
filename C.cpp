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


int n;
vector< string > vet;
char s[1234567];

string pleaseSolveThisProblem(string str) {
  for(int i = 0; i < n; ++i) {
    std::size_t found = str.find(vet[i]);
    if(found != std::string::npos) {
      string aux = "";
      for(int j = 0; j < str.size(); ++j) {
        if(j < found || j >= found + vet[i].size()) aux.pb(str[j]);
      }
      return pleaseSolveThisProblem(aux);
    }
  }
  return str;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    vet.pb((string)s);
  }
  scanf(" %s", s);
  cout << pleaseSolveThisProblem((string)s) << endl;
  return 0;
}