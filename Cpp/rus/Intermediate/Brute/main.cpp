/* Как писать стрессы:
1. Придумать брут
2. Написать константы
3. Написать генератор
4. Написать брут решение
5. Написать обёртку stress. Вызывает brute() и solve(). Сверяем ответ.
   Если неправильный ответ, то выводим тест и возвращаем false.
   Иначе говорим, что прошли тест, возвращаем true.
6. Переписываем слегка main(), чтобы переключать поведение с помощью
   константных флагов BSOLVE и BCHECK. Дёргаем флаги и смотрим где валится.
   Получаем тест на котором не работает, отлаживаем основное решение.
*/
// Ставим прагму O0, чтобы дебаггер корректно работал
// Когда будешь отсылать, то не забудь сделать O3 вместо O0
#pragma GCC optimize("O0")
#include <bits/stdc++.h>

/*
Решаем задачу Двоичный дек:
https://codeforces.com/group/U86Pj3Hohe/contest/1692/problem/E
*/

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
#define double ld

#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)

const auto boostIO = []() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(12);
  return 0;
}();

// Константы для брута
// Можно только праые границы использовать (максимумы),
// но в ограничения в этот момент посмотреть обязательно
const int MIN_N = 1, MAX_N = 10;
const int MIN_S = 1, MAX_S = 7;
// Проверяем ли мы брутом "правильное" решение
const bool BCHECK = true;
// Проверяем ли мы сам брут
const bool BSOLVE = false;

int n, s;
vector<int> arr;
int ans;

void read() {
  cin >> n >> s;
  arr.resize(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
}

void write() {
  cout << ans << '\n';
}

// Это жадное, неправильное решение.
// Мы смотрим слева или справа проще удалить единичку и удаляем.
void solve() {
  int sum = accumulate(all(arr), 0);
  if (sum < s) {
    ans = -1;
    return;
  }
  deque<int> cur(all(arr));
  int p1 = -1, p2 = -1;
  ans = 0;
  while (sum > s) {
    // Если слева не знаем где единица, то находим её
    if (p1 == -1) {
      p1 = 0;
      while (cur[p1] == 0) {
        ++p1;
      }
    }
    // Аналогично справа
    if (p2 == -1) {
      p2 = (int)cur.size() - 1;
      while (cur[p2] == 0) {
        --p2;
      }
    }
    // Считаем стоимости и вычисляем где выгоднее удалить
    // на текущем шаге и честно удаляем элементы из дека.
    int cost_left = p1 + 1;
    int cost_right = (int)cur.size() - p2;
    if (cost_left < cost_right) {
      ans += cost_left;
      for (int i = 0; i < cost_left; ++i) {
        cur.pop_front();
      }
      p2 -= p1 + 1;
      p1 = -1;
    } else {
      ans += cost_right;
      for (int i = 0; i < cost_right; ++i) {
        cur.pop_back();
      }
      p2 = -1;
    }
    --sum;
  }
}

// Придумываем любой сид (как в майнкрафте - один и тот же
// сид даёт один и тот же мир)
const int SEED = 42;
// Вихрь Мерсена
mt19937 RNG(SEED); // Если нужны большие числа, то используй mt19937_64
// f - откуда t - до куда
int rint(int f, int t) {
  // Равномерное целочисленное распределение типа int
  uniform_int_distribution<int> d(f, t);
  return d(RNG);
}

void gen() {
  n = rint(MIN_N, MAX_N);
  s = rint(MIN_S, MAX_S);
  arr.resize(n);
  for (int i = 0; i < n; ++i) {
    arr[i] = rint(0, 1);
  }
}

// Брут-решение. Напишем максимально глупое.
// Оно будет просто перебирать сколько элементов удалили
// слева и справа и проверять, что оставшаяся сумма равна s
void brute() {
  int sum = accumulate(all(arr), 0);
  if (sum < s) {
    ans = -1;
    return;
  }
  ans = n;
  for (int rem_left = 0; rem_left <= n; ++rem_left) {
    for (int rem_right = 0; rem_left + rem_right <= n; ++rem_right) {
      int have = 0;
      for (int i = rem_left; i < n - rem_right; ++i) {
        have += arr[i];
      }
      if (have == s) {
        ans = min(ans, rem_left + rem_right);
      }
    }
  }
}

bool stress() {
  // Номер теста. Он не меняется от вызова функции к вызову
  static int cnt = 1;
  solve();
  int mya = ans;
  brute();
  int cora = ans;
  if (mya != cora) {
    cout << "WA test #" << cnt << '\n';
    cout << n << ' ' << s << '\n';
    for (int i = 0; i < n; ++i) {
      cout << (i ? " " : "") << arr[i];
    }
    cout << '\n';
    cout << "Mya  = " << mya << '\n';
    cout << "Cora = " << cora << '\n';
    return false;
  }
  cout << "Passed test #" << cnt++ << endl;
  return true;
}

signed main() {
  if (BCHECK) {
    do {
      gen();
    } while (stress());
  } else {
    int tests = 1;
    while (tests --> 0) {
      read();
//      if (BSOLVE) {
//        brute();
//      } else {
//        solve();
//      }
      (BSOLVE ? brute() : solve());
      write();
    }
  }
  cout.flush();
  return 0;
}
