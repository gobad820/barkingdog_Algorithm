#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
const int MAX = 1000005;
char dat[MAX];
int pre[MAX], nxt[MAX];
int unused = 1;

void insert(int addr, char item);
void erase(int addr);
void traverse();

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int cursor = 0;
  for (auto c : s) {
    insert(cursor, c);
    cursor++;
  }
  int q;
  cin >> q;
  while (q--) {
    char comm;
    cin >> comm;
    if (comm == 'P') {
      char add;
      cin >> add;
      insert(cursor, add);
      if (nxt[cursor] != 0) cursor = nxt[cursor];
    } else if (comm == 'B') {
      if (pre[cursor] != 0) {
        erase(cursor);
        cursor = pre[cursor];
      }
    } else if (comm == 'D') {
      if (nxt[cursor] != 0) cursor = nxt[cursor];
    } else {  // L
      if (cursor != 0) cursor = pre[cursor];
    }
    cout << cursor << endl;
    traverse();
  }
  traverse();
  return 0;
}
void insert(int addr, char item) {
  dat[unused] = item;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if (nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

void erase(int addr) {
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
  int cur = nxt[0];
  while (cur != 0) {
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << endl;
}