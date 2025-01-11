#include <bits/stdc++.h>

using namespace std;

// В подобных задачах копипаста ниже может
// замедлить программу в 3 раза потому что
// деление для лонгов сильно медленнее, чем для интов
// typedef long long ll;
// #define int ll
// Пруфы:
// https://codeforces.com/contest/1771/submission/184865500
// https://codeforces.com/contest/1771/submission/184865546

typedef pair<int, int> pii;

signed main() {
  // Число называется простым, если оно делится только на
  // 1 и на само себя. Например, 2, 3, 5, 7 - простые.
  // Иначе число называется составным. Например, 4, 6, 8, 10 - составные.
  // Числа 0 и 1 не простые и не составные.
  // Простые числа до n можно искать при помощи решета Эратосфена.
  // Алгоритм очень простой. Говорим, что все числа
  // простые, кроме 0 и 1. Проходимся по остальным.
  // Если находим простое число p, то говорим, что все числа
  // вида k * p (k > 1) являются составными.
  const int N = 100;
  // Все числа простые
  vector<bool> sieve(N + 1, true);
  // Кроме 0 и 1
  sieve[0] = sieve[1] = false;
  vector<int> primes;
  // Проходимся по числам
  for (int i = 2; i <= N; ++i) {
    // Если нашли простое
    if (sieve[i]) {
      primes.push_back(i);
      // Числа вида k * p (k > 1) - составные
      for (int j = i + i; j <= N; j += i) {
        sieve[j] = false;
      }
    }
  }
  cout << "Primes <= " << N << ":\n";
  for (int p : primes) {
    cout << p << ' ';
  }
  cout << endl;
  // Теперь можно за O(1) узнать простое ли число или нет до n
  // И мы явно выписали все простые до n.
  // Этот алгоритм работает за O(n*log(log(n)))
  // Докажем сначала что он работает за O(n*log(n)).
  // Пускай предположим, что мы на самом деле для каждого
  // числа перебираем числа j = k * p, а не только для простых.
  // Тогда количество итераций будет равно:
  // n/2 + n/3 + n/4 + ... + n/n
  // Вынесем n.
  // n * (1/2 + 1/3 + 1/4 + ... + 1/n)
  // Сумма справа называется суммой гармонического ряда.
  // Её асимптотика (приближение) равно O(log(n))
  // Это очень известный ряд. Его нужно запомнить.
  // Докажем, что сумма гармонического ряда не превосходит O(log(n))
  // Рассмотрим другой ряд (сумму чисел) и сравним с исходным:
  // 1/2 + 1/2 + 1/4 + 1/4 + 1/4 + 1/4 + 1/8 + 1/8 + ...
  // 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 + 1/9 + ...
  // Сумма первого ряда больше суммы второго, потому что
  // каждое слагаемое либо больше, либо равно слагаемому
  // гармонического ряда. Будем работать с первой суммой.
  // Видно, что слагаемые "схлопываются" в единицы.
  // 1/2 + 1/2 = 1
  // 1/4 + 1/4 + 1/4 + 1/4 = 1
  // Каждый раз нужно в два раза больше дробей, чтобы получить единицу.
  // Сколько единиц поместится в n?
  // 2 + 4 + 8 + ... + 2^k = n
  // Мы говорим, что у нас есть n слагаемых.
  // Сначала потратили 2, потом 4, потом 8 и так далее,
  // чтобы получать единицу и в итоге получили n.
  // Здесь k и будет равно количеству единиц.
  // 2 + 4 + 8 + ... + 2^k < 2^(k+1). Надеюсь, очевидно.
  // 2^(k+1) = n. Логарифмируем.
  // k+1 = log(n).
  // Наконец-то получили оценку на количество единиц.
  // Можно сказать, что сумма пропорциональна логарифму.
  // Что и требовалось доказать.
  // Однако мы брали вообще все числа. В то время как
  // алгоритм "пробегается" по решету только когда
  // встречает простое. Существует теорема о распределении простых чисел:
  // https://ru.wikipedia.org/wiki/Теорема_о_распределении_простых_чисел
  // Она гласит, что количество простых на отрезке [1; n] растёт с
  // увеличением n как n/ln(n).
  // Грубо говоря, это означает, что у случайно выбранного числа
  // от 1 до n вероятность оказаться простым равна 1/ln(n)
  // Это текст из википедии.
  // Из неё и следует оценка O(n*log(log(n))).
  // Я не буду это доказывать. Слишком сложно уже.

  // Теорема Евклида утверждает, что множество простых
  // чисел бесконечно. Докажем это от противного.
  // Пускай есть какое-то конечное простое число p.
  // Тогда перемножим все простые числа до p включительно
  // и прибавим один. Получим число, которое взаимнопросто
  // со всеми предыдущими простыми, то есть само является
  // простым. Противоречие.

  // Почему после прибавления единицы получим взаимнопростое?
  // Потому что любые два подряд идущих числа взаимнопросты.
  // Докажем это с помощью алгоритма Евклида.

  // Алгоритм Евклида ищет Наибольший Общий Делитель (НОД) двух чисел.
  // (GCD - Greatest Common Divisor)
  // Он основывается на таком наблюдении:
  // Если a и b (a > b) делятся на g, то
  // a - b тоже делится на g. Докажем.
  // a = g * a1, b = g * b1
  // a - b = g * a1 - g * b1 = g * (a1 - b1)
  // Очевидно, что разность всё ещё делится на g
  // Таким образом будем вычитать из большего меньшее
  // пока меньшее не станет равно нулю.
  function<int(int, int)> slow_gcd = [&](int a, int b) {
    if (b == 0) {
      return a;
    }
    if (a > b) {
      a -= b;
    } else {
      swap(a, b);
    }
    return slow_gcd(a, b);
  };
  // Однако вычитаний может быть очень много. Воспользуемся
  // вместо этого остатком от деления, ведь это то же самое
  // что и вычитание, только за одну операцию:
  function<int(int, int)> fast_gcd = [&](int a, int b) {
    if (b == 0) {
      return a;
    }
    return fast_gcd(b, a % b);
  };
  // Существует стандартная функция std::gcd(), которой лучше пользоваться.
  // Отсюда можно видеть свойства gcd:
  // gcd(a, b) = gcd(a - b, b) = gcd(b, a) = gcd(b, a % b)
  // К слову, gcd(0, n) = n и gcd(1, n) = 1

  // gcd работает за O(log(min(a, b))) потому что
  // за каждые две итерации меньшее из чисел точно
  // уменьшается хотя бы в два раза.
  // a, b. a > b
  // a1 = b, b1 = a % b
  // a2 = b1, b2 = b % (a % b)
  // Утверждается, что b2 уменьшится хотя бы в два раза.
  // Если a % b = b / 2, то так и будет.
  // Если остаток будет больше, то b уменьшится
  // Если остаток будет меньше, то b тоже уменьшится
  // То есть хотя бы в два раза оно уменьшится.
  // Что и требовалось доказать.

  // Вернёмся к утверждению, что два подряд идущих числа
  // взаимнопросты, то есть их gcd = 1
  // gcd(x + 1, x) = gcd(x + 1 - x, x) = gcd(1, x) = 1
  // Что и требовалось доказать.

  // Зачем мы вообще разбираем эти простые числа?
  // Всё дело в основной теореме арифметики.
  // Любое число можно представить с помощью произведения
  // простых чисел единственным образом, т.е. факторизовать его.
  // Сможешь доказать?

  // А зачем раскладывать на простые? Потому что можно
  // оперировать с числом с помощью теории множеств, а
  // не с помощью арифметики.
  // Например, 12 = {2, 2, 3}, 14 = {2 * 7}
  // Арифметическое умножение будет эквивалентно
  // совокупности множеств.
  // 12 * 14 = {2, 2, 2, 3, 7} = 168
  // Деление без остатка будет эквивалентно разности
  // двух множеств. 12 / 2 = {2, 2, 3} - {2} = {2, 3} = 6
  // gcd двух чисел будет эквивалентно пересечению множеств
  // gcd(12, 14) = {2, 2, 3} n {2 * 7} = {2} = 2.
  // Тут n - знак пересечения множеств
  // Сложение и вычитание работают не так гладко.

  // Как же факторизовать число? (разложить на простые множители)?
  // Можно просто пройтись по всем числам [2, n] и попробовать
  // поделить число на каждое из них. Это будет работать за O(n).
  // Заметим, что у числа не может быть двух множителей больше
  // корня из числа. Действительно, иначе бы их произведение
  // было бы больше, чем само число.
  // Значит, достаточно посмотреть числа на промежутке [2, sqrt(n)]
  // И если в конце число не будет равно 1, то добавить его в
  // факторизацию. Будем хранить факторизацию числа как список
  // пар вида {простое, степень}:
  auto my_root = [](int num) {
    int root = (int)sqrtl(num);
    while (root * root <= num) {
      ++root;
    }
    return root;
  };
  auto sqrt_factorize_all_nums = [&](int num) {
    int root = my_root(num);
    vector<pii> res;
    for (int i = 2; i < root; ++i) {
      if (num % i == 0) {
        int cnt = 0;
        while (num % i == 0) {
          ++cnt;
          num /= i;
        }
        res.emplace_back(i, cnt);
      }
    }
    if (num > 1) {
      res.emplace_back(num, 1);
    }
    return res;
  };
  {
    const int num = 54321;
    vector<pii> fact = sqrt_factorize_all_nums(num);
    cout << num << ':';
    for (auto &[p, cnt] : fact) {
      for (int i = 0; i < cnt; ++i) {
        cout << ' ' << p;
      }
    }
    cout << '\n';
  }
  // Можно заранее посчитать все простые числа и итерироваться только
  // по ним. Тогда факторизация будет работать за O(sqrt(n)/log(sqrt(n)))
  // Это побыстрее.
  auto sqrt_factorize_primes = [&](int num) {
    int root = my_root(num);
    vector<pii> res;
    for (int i = 0; i < (int)primes.size() && primes[i] < root; ++i) {
      int p = primes[i];
      if (num % p == 0) {
        int cnt = 0;
        while (num % p == 0) {
          ++cnt;
          num /= p;
        }
        res.emplace_back(p, cnt);
      }
    }
    if (num > 1) {
      res.emplace_back(num, 1);
    }
    return res;
  };
  {
    const int num = 4321;
    vector<pii> fact = sqrt_factorize_primes(num);
    cout << num << ':';
    for (auto &[p, cnt] : fact) {
      for (int i = 0; i < cnt; ++i) {
        cout << ' ' << p;
      }
    }
    cout << '\n';
  }
  // Можно находить все делители числа за корень примерно таким
  // же методом. Будем для каждого делителя искать частное.
  // Это "парный делитель"
  auto get_all_divisors = [&](int num) {
    int root = my_root(num);
    vector<int> res;
    for (int i = 1; i < root; ++i) {
      if (num % i == 0) {
        res.push_back(i);
        res.push_back(num / i);
      }
    }
    // В случае, когда число - квадрат какого-то числа
    // то корень не нужно дважды добавлять как делитель
    if (res.back() == res[res.size() - 2]) {
      res.pop_back();
    }
    return res;
  };
  {
    const int num = 36;
    vector<int> divs = get_all_divisors(num);
    cout << num << ':';
    for (int d : divs) {
      cout << ' ' << d;
    }
    cout << '\n';
  }
  // Зная факторизацию числа можно получить все делители
  // при помощи обычного dfs'а за O(ans)
  auto get_all_divisors_dfs = [&](int num) {
    vector<pii> fact = sqrt_factorize_primes(num);
    vector<int> res;
    function<void(int, int)> dfs = [&](int ind, int cur) {
      if (ind == (int)fact.size()) {
        res.push_back(cur);
        return;
      }
      auto &[p, cnt] = fact[ind];
      for (int i = 0; i < cnt; ++i) {
        dfs(ind + 1, cur);
        cur *= p;
      }
      dfs(ind + 1, cur);
    };
    dfs(0, 1);
    return res;
  };
  {
    const int num = 36;
    vector<int> divs = get_all_divisors_dfs(num);
    cout << num << ':';
    for (int d : divs) {
      cout << ' ' << d;
    }
    cout << '\n';
  }
  // Всего существует порядка кубического корня делителей числа.
  // Доказательство вроде такое: сгенерим и увидим. O(cbrt(n))

  // Последнее. Количество делителей можно найти по формуле.
  // Вот у нас есть пары вида {простое, степень}.
  // У делителя может быть любая степень от 0 до той, которая
  // в факторизации. Это (cnt + 1) возможных вариантов.
  // Перемножив эти количества и узнаем сколько делителей у числа.
  auto count_all_divisors = [&](int num) {
    vector<pii> fact = sqrt_factorize_primes(num);
    int res = 1;
    for (auto &[_, cnt] : fact) {
      res *= (cnt + 1);
    }
    return res;
  };
  for (int i = 2; i <= N; ++i) {
    cout << i << ": " << count_all_divisors(i) << endl;
  }
  // Можно факторизовать ещё быстрее с предподсчётом в O(n),
  // используя линейное решето, но это тема дополнительной лекции.
  return 0;
}
