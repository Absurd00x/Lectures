// https://www.youtube.com/watch?v=6zw8y5RvatI
// https://drive.google.com/file/d/14ZW3_Vhpiv420JxrMmR2ziXrDDSh1djQ/view?usp=sharing
// подключает все библиотеки, которые есть в стандартной библиотеке std
#include <bits/stdc++.h>

using namespace std;

// ты знаешь что такое функция?
// в математике функция - это зависимость одной переменной от другой (других)
// y = f(x) = k*x + b
// функция (опять в математике) - это отображение одних значений в другие

// в программировании функция - это вызываемый участок кода
// в отличии от математики, функция в программировании не обязана что-то возвращать
// такие функции называются процедурами (в основном в паскале)

// функции в программировании нужны, чтобы
// 1. Не плодить одинаковый код
// 2. Декомпозировать программу (разбивать её на логически законченные части)
// 3. Использовать уже написанный за тебя код (функция sort)

// можно объявлять свои функции следующим образом:
// возвращаемый_тип название_функции(аргументы) {}
// аргументы - перечисление переменных, которые нужны функции, чтобы исполниться
// функции различаются как названиями, так и списком аргументов, но не
// возвращаемым типом

int square(int x) {
  int res = x * x;
  // функция обязательно должна что-то вернуть
  return res;
}
// существует особый тип данных void
// он говорит, что функция ничего не возвращает
// на самом деле она всё равно возвращает "ничего", просто
// вы с компилятором договариваетесь это проигнорировать
void print(string something) {
  cout << something << endl;
  // return;
}

// Асимптотика (количества итераций) - пропорционально какой функции ты совершишь
// количество итераций в зависимости от входных данных.
// Как посчитать асимтотику:
// 1. Считаешь общее количество итераций
//    (во всей программе, в функции, в блоке кода, где нужно);
// 2. Разбиваешь на слагаемые n*(n-1)/2 = n*n/2 - n/2;
// 3. Выбираешь самое большое слагаемое; (n^2 > n)
// 4. Убираешь все константы. (10*n = n,
//    n^2 = n^2, 2 - не константа, а форма записи)
// Например
// O(n*(n-1)/2) = O(n*n/2 - n/2) = O(n*n/2) = O(n*n) = O(n^2)
// 5. Подставляем значения, узнаём конкретное число. Смотрим
// самые большие числа из условия. Обычно n <= 2*10^5.
// O(n^2), n = 2*10^5;
// (2*10^5)^2 = 4*10^10.
// 6. В одну секунду влезает примерно 3*10^7 на c++. В две
// секунды соотственно в два раза больше: 6*10^7
// 7. Если мы насчитали меньше, чем влезает, то можно писать код.
// 8. Если хочешь поточнее узнать влезет ли решение, то не
// убираешь константы, но это уже не асимптотика, а количество итераций.
// Все обычно пользуются асимптотикой.

// покажу несколько алгоритмов сортировки
// ДОСКА!!!!!!!!!!
// Пузырьковая сортировка
void bubble_sort(vector<int> &arr) {
  // очень важен символ '&' перед названием переменной
  // если его не ставить, то мы будем работать не с тем массивом,
  // а с его копией.
  // если не используешь этот символ, то говорят, что ты
  // "передаёшь аргумент по значению"
  // если используешь, то говорят, что ты
  // "передаёшь по ссылке"

  // тут явно преобразую тип к int, т.к. arr.size() имеет
  // беззнаковый тип unsigned int
  int n = (int)arr.size();

  // один цикл сделает n - 0 = n итераций
  for (int i = 0; i < n; ++i) { // [0, n)
    // второй цикл сделает n - 1 итерацию
    for (int j = 1; j < n; ++j) { // [1, n)
      // если два подряд идущих элемента идут не по-порядку
      // например: 3, 2
      if (arr[j] < arr[j - 1]) {
        // то меняем их местами
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // так как один цикл вложен в другой, то перемножаем
  // их количество итераций
  // O(n) * O(n - 1) = O(n^2 - n) = O(n^2)
  // итоговая асимптотика времени работы функции O(n^2)
  // итоговая асимптотика дополнительно использованной памяти O(1)
  // так как мы не использовали дополнительную память пропорционально n
}

// "быстрая" пузырьковая сортировка
void fast_bubble_sort(vector<int> &arr) {
  int n = (int)arr.size();

  // первый цикл сделает n - 1 - 0 = n - 1 итерацию
  for (int i = 0; i < n - 1; ++i) {
    // второй цикл сделает сначала n - 0 - 1 = n - 1 итерацию
    // потом n - 1 - 1 = n - 2 итерации
    for (int j = 1; j < (n - i); ++j) {
      if (arr[j] < arr[j - 1]) {
        // то меняем их местами
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // считаем суммарное количество итераций:
  // (n - 1) + (n - 2) + ... + 1
  // 1 + 2 + ... + (n - 1)
  // первый элемент суммы равен 1
  // последний элемент суммы равен (n - 1)
  // все слагаемые находятся в полуинтервале [1, n)
  // значит, их количество равно n - 1
  // общая сумма равна (первый + последний) * количество / 2, получается
  // (1 + (n - 1)) * (n - 1) / 2 = n * (n - 1) / 2
  // n * (n - 1) / 2 = n * n / 2 - n / 2
  // O(n * n / 2 - n / 2) = O(n * n / 2) = O(n * n) = O(n^2)
  // итоговая асимптотика времени работы функции O(n^2)
  // итоговая асимптотика дополнительно использованной памяти O(1)
  // так как мы не использовали дополнительную память пропорционально n
}

// обезьянья сортировка
void bogo_sort(vector<int> &arr) {
  int n = (int)arr.size();
  bool sorted = false; // говорим, что массив не отсортирован
  // O(n!)
  while (!sorted) { // пока он не отсортирован
    // перемешиваем в нём элементы случайным образом
    // для этого идём по массиву с конца
    // O(n)
    for (int i = n - 1; i > 0; --i) {
      // функция rand() возвращает случайное число
      // из отрезка [0, RAND_MAX], где RAND_MAX - константа,
      // для каждого компьютера своя
      // это ПЛОХАЯ функция для генерации случайных чисел,
      // но достаточно простая для примера
      // выбираем случайный индекс j, находя остаток от деления
      // случайного числа на i
      // тогда j находится на промежутке [0, i)

      // так как само число, которое мы получили было случайным,
      // то и остаток будет случайным
      int j = rand() % i;
      swap(arr[i], arr[j]);
    }
    // говорим, что массив теперь отсортирован
    sorted = true;
    // проверяем, что наговорили
    // O(n)
    for (int i = 1; i < n; ++i) {
      if (arr[i] > arr[i - 1]) {
        sorted = false;
      }
    }
  }
  // всего существует n! возможных перестановок массива arr
  // на каждой итерации цикла while мы получаем случайную из них
  // затем, внутри цикла мы перемешиваем элементы и проверяем
  // массив на упорядоченность
  // n! * ((n - 1) + (n - 1)) = n! * (2n - 2)
  // O(n! * (2n - 2)) = O(n! * n)
  // итоговая асимптотика времени работы функции O(n!*n)
  // итоговая асимптотика дополнительно использованной памяти O(1)
  // так как мы не использовали дополнительную память пропорционально n
}

// ДОСКА !!!!!!!!!!
// рекурсия - это когда функция вызывает саму себя
// это вспомогательная функци для алгоритма сортировки слиянием
// функции необходимо объявлять до того, как их вызвали в коде
// функция принимает ссылку на массив, индекс на начало и на конец
// отсортированного полуинтервала, который нужно слить
vector<int> merge(vector<int> &arr, int start, int finish) {
  vector<int> res; // результат слияния
  if (finish - start == 1) { // если нужно слить 1 элемент
    res.push_back(arr[start]); // то добавляем его в результат
    return res; // и выходим из функции
  }
  // вычисляем середину полуинтервала [start, finish)
  int mid = start + (finish - start) / 2;
  // решаем задачу отдельно для левой половины
  vector<int> left = merge(arr, start, mid);
  // и для правой
  vector<int> right = merge(arr, mid, finish);
  // теперь есть две отсортированные половины - left и right
  // p1, p2 - элементы, который мы хотим добавить из первой
  // и из второй половины соответственно
  int p1 = 0, p2 = 0;
  // записываем размеры половин в int
  // это как признак хорошего тона
  // ну, и чтобы компилятор не ругался
  int n_left = (int)left.size();
  int n_right = (int)right.size();
  // пока есть элемент в левой и в правой половине
  while (p1 < n_left && p2 < n_right) {
    // добавляем меньший из них (при равенстве - берём из левой половины)
    // увеличиваем соответствующий индекс p1 или p2
    if (left[p1] <= right[p2]) {
      res.push_back(left[p1]);
      ++p1;
    } else {
      res.push_back(right[p2]);
      ++p2;
    }
  }
  // если остались элементы в левой половине, то добавляем их
  while (p1 < n_left) {
    res.push_back(left[p1]);
    ++p1;
  }
  // аналогично с правой
  while (p2 < n_right) {
    res.push_back(right[p2]);
    ++p2;
  }
  // на каждой итерации рекурсии количество элементов уменьшается в два раза
  // то есть количество элементов на глубине 1 равно n
  // на глубине 2 равно n / 2, на глубине 3 равно n / 4
  // на глубине k равно n / 2^k
  // меньше одного элемента быть не может
  // прикинем максимальную глубину:
  // n / 2^k = 1
  // n = 2^k
  // log(n) = k
  // k = log(n)
  // значит, глубина рекурсии не превышает log(n)
  // на каждом слиянии мы тратим O(n) операций на слияние

  // итоговая асимптотика времени работы функции O(n*log(n))
  // итоговая асимптотика дополнительно использованной памяти O(n*log(n))
  // так на каждой итерации рекурсии мы объявляем новый массив и каждый
  // раз забиваем его числами, а потом выбрасываем
  // то есть по сути храним каждый элемент исходного массива логарифм раз
  // ну, на каждом шаге рекурсии
  return res;
}

// а тут просто вызываем
void merge_sort(vector<int> &arr) {
  // заметь - это единственная сортировка, которая не трогает исходный массив
  // она "вычисляет" отсортированный и возвращает его тебе
  // я не буду его тут возвращать, но ты имей в виду
  arr = merge(arr, 0, (int)arr.size());
}

// "сортировка" подсчётом
// не совсем сортировка, потому что она не пользуется сравнением элементов
// так ещё и использует то, что даны целые числа (неотрицательные)
// а не строчки, например
void count_sort(vector<int> &arr) {
  // находим максимум в массиве стандартной функцией
  int max = *max_element(arr.begin(), arr.end());
  // готовимся посчитать количество каждого элемента
  vector<int> counts(max + 1, 0);
  // считаем
  for (int i = 0; i < (int)arr.size(); ++i) {
    ++counts[arr[i]];
  }
  // очищаем исходный массив
  arr.clear();
  // смотрим сколько было каждого элемента
  for (int i = 0; i <= max; ++i) {
    // и добавляем i столько раз в массив, сколько до этого его посчитали
    for (int j = 0; j < counts[i]; ++j) {
      arr.push_back(i);
    }
  }
  // итоговая асимптотика времени работы функции O(n + max_element) = O(max(n, max_element))
  // n + max так и остаётся, потому что не понятно что из этого больше
  // итоговая асимптотика дополнительно использованной памяти O(max_element)
  // так как мы объявили дополнительный массив counts пропорционально
  // максимальному элементу в массиве
}

// всё это конечно круто и здорово, но в c++ есть стандартная сортировка
// sort(arr.begin(), arr.end());
// которая работает за O(nlog(n))
// конкретно в GCC написана "интроспективная сортировка"
// https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_algo.h#L1948
// https://ru.wikipedia.org/wiki/Introsort

// отношения O():
// 1 < log < log^2 < sqrt < n < n*log < n*log^2 < n*sqrt(n) < n^2 < 2^n < n! < n^n

// бонус
// статические переменные
void static_count_sort(vector<int> &arr) {
  // эта переменная не будет заново создаваться при каждом
  // последующем вызове функции
  static vector<int> counts;
  int max = *max_element(arr.begin(), arr.end());
  // поменяем размер массива counts
  counts.resize(max + 1);
  // остальное аналогично
  for (int i = 0; i < (int)arr.size(); ++i) {
    ++counts[arr[i]];
  }
  arr.clear();
  for (int i = 0; i <= max; ++i) {
    for (int j = 0; j < counts[i]; ++j) {
      arr.push_back(i);
    }
    // но не забываем очистить массив counts
    // так как будем его потом использовать
    counts[i] = 0;
  }
  // асимптотика не поменяется просто будет чуть-чуть быстрее, так
  // как не нужно будет каждый раз новый массив объявлять
}

// не обращай внимания, просто получаю массив случайных чисел
vector<int> get_random_array(int size, mt19937 rngesus) {
  vector<int> res(size);
  iota(res.begin(), res.end(), 0);
  shuffle(res.begin(), res.end(), rngesus);
  return res;
}

// функции можно передавать как аргумент
// auto можно писать как тип аргумента, ничего не сломается
void test_sort(int n, int tests, int seed, auto f, string name) {
  mt19937 rngesus(seed);
  cout << "Testing " << name << endl;
  clock_t start = clock();
  for (int test = 0; test < tests; ++test) {
    vector<int> arr = get_random_array(n, rngesus);
    f(arr);
  }
  clock_t finish = clock();
  double diff = double(finish - start);
  cout << diff / (CLOCKS_PER_SEC * tests) << "s per single test" << endl;
  cout << diff / CLOCKS_PER_SEC << "s total" << endl;
  cout << "===========================================================" << endl;
}

int main() {
  const int SEED = 42;
  cout << fixed << setprecision(8);
  int n = 10, tests = 10;
  cout << "n = " << n << "; tests = " << tests << endl << endl;
  test_sort(10, 10, SEED, bogo_sort, "bogo sort");
  cout << endl;

  n = 1000, tests = 100;
  cout << "n = " << n << "; tests = " << tests << endl << endl;
  test_sort(n, tests, SEED, bubble_sort, "bubble sort");
  test_sort(n, tests, SEED, fast_bubble_sort, "fast bubble sort");
  test_sort(n, tests, SEED, merge_sort, "merge sort");
  test_sort(n, tests, SEED, count_sort, "count sort");
  test_sort(n, tests, SEED, static_count_sort, "static count sort");
  cout << endl;

  // ' <= это разделитель, ни на что не влияет
  // появился в c++14
  n = 10'000, tests = 100;
  cout << "n = " << n << "; tests = " << tests << endl << endl;
  test_sort(n, tests, SEED, bubble_sort, "bubble sort");
  test_sort(n, tests, SEED, fast_bubble_sort, "fast bubble sort");
  test_sort(n, tests, SEED, merge_sort, "merge sort");
  test_sort(n, tests, SEED, count_sort, "count sort");
  test_sort(n, tests, SEED, static_count_sort, "static count sort");
  cout << endl;
  return 0;
}

/*

результаты были получены на ОС
Linux userpc 5.13.0-39-generic #44~20.04.1-Ubuntu SMP Thu Mar 24 16:43:35 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux

с процессором
Intel(R) Core(TM) i5-3450 CPU @ 3.10GHz

с компилятором
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0

с флагами компиляции
-O2 -fconcepts

результаты:

n = 10; tests = 10

Testing bogo sort
1.10456510s per single test
11.04565100s total
===========================================================

n = 1000; tests = 100

Testing bubble sort
0.00998971s per single test
0.99897100s total
===========================================================
Testing fast bubble sort
0.00728111s per single test
0.72811100s total
===========================================================
Testing merge sort
0.00106512s per single test
0.10651200s total
===========================================================
Testing count sort
0.00011819s per single test
0.01181900s total
===========================================================
Testing static count sort
0.00011803s per single test
0.01180300s total
===========================================================

n = 10000; tests = 100

Testing bubble sort
1.01583518s per single test
101.58351800s total
===========================================================
Testing fast bubble sort
0.74302695s per single test
74.30269500s total
===========================================================
Testing merge sort
0.01229034s per single test
1.22903400s total
===========================================================
Testing count sort
0.00121320s per single test
0.12132000s total
===========================================================
Testing static count sort
0.00120476s per single test
0.12047600s total
===========================================================
*/
