#include <bits/stdc++.h>

using namespace std;

void find_string() {
  int a; cin >> a;
  cin.ignore();
  string buff;
  getline(cin, buff);
  stringstream inp(buff);
  int n;
  vector<int> need;
  while (inp >> n) {
    need.push_back(n);
  }
  n = (int)need.size();
  vector<int> eq(n, -1);
  for (int i = 0; i < n; ++i) {
    if (need[i] != 0) {
      eq[i] = need[i] - 1;
    }
  }
  map<vector<int>, vector<int>> uni;
  vector<int> cur(n);
  function<void(int)> dfs = [&](int ind) {
    if (ind == n) {
      vector<int> pf(n);
      for (int bit = 1; bit < n; ++bit) {
        int j = pf[bit - 1];
        while (j > 0 && cur[j] != cur[bit]) {
          j = pf[j - 1];
        }
        j += cur[j] == cur[bit];
        pf[bit] = j;
      }
      if (uni.count(pf) == 0) {
        uni[pf] = cur;
      }
      return;
    }
    if (eq[ind] == -1) {
      for (int i = 0; i < a; ++i) {
        cur[ind] = i;
        dfs(ind + 1);
        cur[ind] = 0;
      }
    } else {
      cur[ind] = cur[eq[ind]];
      dfs(ind + 1);
    }
  };
  dfs(0);
  if (uni.count(need)) {
    vector<int> res = uni[need];
    for (int i = 0; i < n; ++i) {
      cout << char(res[i] + 'a');
    }
    cout << endl;
  }
}

void gen_pf() {
  int n;
  string s; cin >> s;
  n = (int)s.size();
  vector<int> pf(n);
  for (int i = 1; i < n; ++i) {
    int j = pf[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = pf[j - 1];
    }
    j += s[j] == s[i];
    pf[i] = j;
  }
  for (int i = 0; i < n; ++i) {
    cout << (i ? " " : "") << pf[i];
  }
  cout << endl;
}

int main() {
  gen_pf();
  return 0;
}
