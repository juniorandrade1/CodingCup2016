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

const int N = 10;

int n;

inline int trueMod(int x) {
  x += n;
  return x % n;
}

map< string, int > idx;
map< int, string > idv;
char s[12345];
vector< string > vet;


int go = 1;
int pos = 0;
int qtdVez = 1;
char lstEspecial = -1;
bool pulaJog = false;



void reaction(char c) {
  qtdVez--;

  if(c == '?') {
    qtdVez++;
    printf("%s\n", idv[pos].c_str());
  }
  else if(c == 'P') {
    pulaJog = 1;
    lstEspecial = c;
  }
  else if(c == 'I') {
    go *= -1;
    lstEspecial = c;
  }
  else if(c == 'M') {
    scanf(" %s", s);
    pos = idx[(string)s];
    qtdVez = 1;
    pulaJog = false;
    lstEspecial = c;
    return;
  }
  else if(c == 'D') {
    qtdVez += 2;
    lstEspecial = c;
  }
  else if(c == 'R') {
    qtdVez++;
    debug("%c\n", lstEspecial);
    exit(0);
    reaction(lstEspecial);
  }

  if(qtdVez == 0) {
    pos += go;
    pos = trueMod(pos);
    if(pulaJog) {
      pos += go;
      pos = trueMod(pos);
    }
    pulaJog = false;
    qtdVez = 1;
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    vet.pb((string)s);
    idx[vet[i]] = i;
    idv[i] = vet[i];
  }
  char c;
  while(1) {
    scanf(" %c", &c);
    if(c == '!') {
      printf("%s\n", idv[pos].c_str());
      break;
    }
    reaction(c);
  }
  return 0;
}