// Прагмы - инструкции для компилятора
// Они вообще должны ускорять работу программы обычно
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
// define - это инструкция комплятору вида "замени X на Y"
// когда компилятор производит эти замены, он игнорирует то,
// что перед ним код. Даже if(false){#define} будет исполнен
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)

namespace nums {
  const double PI = acos(-1.0L);
}

// Нужно позже для разделителей:
struct i_love_timus : ctype<char> {
  i_love_timus() : ctype<char>(get_table()) {}
  static mask const* get_table()
  {
    static mask rc[table_size];
    static const char delims[] = " \n.,-:!?";
    for (char delim : delims) {
      rc[(int)delim] = ctype_base::space;
    }
    return &rc[0];
  }
};

// cin.imbue(locale(cin.getloc(), new i_love_timus));

signed main() {
  /* Существует такое понятие как пространство имён. Например,
   * std namespace. Можно создавать свои namespace'ы
   * Область видимости, пространство имён и namespace это одно и то же
   */
  cout << nums::PI << endl;
  /* Каждый раз, когда пишешь '{', то создаёшь новую область
   * видимости. Например, в цикле for
   */
  for (int i = 0; i < 10; ++i) {
    // Компилятор ругается, что я не использовал эту переменную
    int kek = 123;
    cout << i << ' ';
  }
  cout << endl;
  /* Тут kek уже недоступен, он не находится в текущей области
   * видимости. Нельзя сейчас написать "cout << kek << endl;"
   * Можно создавать свои области видимости просто напечатав {}
   * без всего. Например:
   */
  {
    int kek = 123;
    cout << kek << endl;
  }
  /* Снова нельзя использовать kek. Мы не в той области видимости.
   * Бывает удобно декомпозировать программу с помощью анонимных
   * namespace'ов. Вот так:
   */
  { // Тут я сортирую массив подсчётом
    // ...
  }
  { // Теперь вывожу отсортированный
    // ...
  }
  // Самой полезной вещью в 17м стандарте c++ было введение структурных
  // привязок. Они упрощают работу с парами и кортежами (tuple). Аналогичны
  // распаковке в питоне. Например:
  {
    // Объявили пару интов
    pair<int, int> example(1, 2);
    // Создали копии и записали в a и b соответственно
    auto [a, b] = example;
    // Создали ссылки на элементы пары. Как будно имена дали этим элементам.
    auto &[c, d] = example;
    a = 3, b = 4;
    cout << example.first << ' ' << example.second << endl;
    c = 5, d = 6;
    cout << example.first << ' ' << example.second << endl;
  }
  { // Кортежи
    // Можно сделать структуру из нескольких элементов.
    // Тройку, четвёрку пятёрку и так далее
    tuple<int, int, int> triple;
    tuple<bool, string, float, long long> quad;
    tuple<vector<int>, pair<int, char>, char, int, int> quint;
    // Их можно также распаковывать с помощью структурных привязок
    auto &[a, b, c, d] = quad;
    // Если хочется взять только один элемент кортежа, то нужно
    // использовать особую функцию get<N>(tuple)
    int last = get<4>(quint);
    // Это менее удобно, но так можно делать.
    // ВНИМАНИЕ! Число в треугольных скобочках должно быть константным.
    // Либо число, либо константная переменная.
  }
  { // Ещё структурные привязки можно использовать в попсовых фориках так:
    vector<int> arr;
    vector<pair<int, int>> brr;
    for (int num : arr) {}
    for (auto &[a, b] : brr) {}
    // Знак & обозначает, что копирования нет и ты работаешь с элементами
    // массива. Если его убрать, то будешь работать с копиями.
    // Добавлять в вектор можно функцией .emplace_back. Например:
    brr.emplace_back(5, 10);
    // С push_back'ом пришлось бы сначала создать пару, а потом добавить её
    brr.push_back(pair<int, int>(10, 15));
    // Или можно просто фигурные скобки дописать
    brr.push_back({3, 17});
  }
  { // Можно создавать функции внутри функции и вызывать их.
    // Такие функции называют лямбда-функциями или анонимными функциям
    // У функции очень странное объявление. Формально тип функции это:
    // function<возвращаемый тип(тип первого аргумента, второго, третьего)>
    function<int(int, int, int)> calc_ap = [&](int start, int finish, int cnt) {
      return (start + finish) * cnt / 2;
    };
    // Теперь её можно вызывать в коде
    cout << calc_ap(1, 5, 5) << endl;
    // В квадратных скобочках можно указывать какие переменные видит функция
    // из ранее написанного кода. Если указать [&], то будут доступны все
    // ранее используемые переменные.
    // Можно использовать auto, чтобы не писать этот страшный тип:
    auto digital_root = [](int num) {
      while (num > 9) {
        int next = 0;
        while (num > 0) {
          next += num % 10;
          num /= 10;
        }
        num = next;
      }
      return num;
    };
    // Однако с рекурсивными лямбдами придётся целиком писать тип:
    // Функция должна иметь ссылку на саму себя, так как она рекурсивная
    // и заранее знать свой тип
    function<int(int)> fib = [&](int num) {
      if (num == 0 || num == 1) {
        return int(1);
      }
      return fib(num - 1) + fib(num - 2);
    };
  }
  {
    // На самом деле лямбда-функции очень удобные, если нужно её аккуратненько
    // куда-то вставить. Например, в функцию сортировки:
    vector<int> arr = {7, 1, 4, 5, 3, 6};
    cout << "Before:" << '\n';
    for (int num : arr) {
      cout << num << ' ';
    }
    cout << '\n';
    // Хочу, чтобы сначала были чётные по возрастанию, а потом нечётные по
    // убыванию. Делаю так:
    /* Да, у сортировки есть третий аргумент. Он называется компаратором.
     * Компаратор - это функция, которая должна говорить "правда ли, что a < b".
     * Если элементы равны, то она должна вернуть false
     */
    sort(arr.begin(), arr.end(), [](int a, int b) {
      if (a % 2 != b % 2) {
        return a % 2 == 0;
      }
      if (a % 2 == 0) {
        return a < b;
      }
      return a > b;
    });
    cout << "After:" << '\n';
    for (int num : arr) {
      cout << num << ' ';
    }
    cout << endl;
  }
  {
    // Существуют встроенные функции бинарного поиска. Это следующие:

    // Вернуть итератор на первый элемент >= num
    // lower_bound(arr.begin(), arr.end(), num)
    // Вернёт arr.end(), если не найдёт

    // Вернуть итератор на первый элемент > num
    // upper_bound(arr.begin(), arr.end(), num)
    // Аналогично вернёт arr.end(), если не найдёт

    // Попробовать найти число:
    // binary_search(arr.begin(), arr.end(), num)
    // Вернёт true, если найдёт
    // Во все эти функции можно передавать свой компаратор 4м аргументом.
    vector<int> arr = {1, 2, 3, 3, 4, 5};
    cout << "\nTesting lower bound\n";
    for (int num : arr) {
      cout << num << ' ';
    }
    cout << '\n';
    {
      auto it = lower_bound(arr.begin(), arr.end(), 3);
      // Можно получить индекс из итератора массива
      int ind = it - arr.begin();
      cout << "lower_bound: " << ind << endl;
    }
    {
      auto it = upper_bound(arr.begin(), arr.end(), 3);
      int ind = it - arr.begin();
      cout << "upper_bound: " << ind << endl;
    }
  }
  {
    // Может пригодиться техника "сжатия координат".
    // Мы начнём работать не самими числами, а с их рангами
    cout << "\nTesting compression\n";
    vector<int> arr = {4, 1, 5, 2, 5, 5, 3, 3};
    cout << "Initial array:" << endl;
    for (int num : arr) {
      cout << num << ' ';
    }
    cout << endl;
    // Для этого мы сначала сортируем массив
    sort(arr.begin(), arr.end());
    // Затем вызываем функцию unique. Обычно она сочетается с методом erase
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    // функция unique выпишет в массив все уникальные элементы и
    // вернёт итератор на первый дубликат. Работает за O(n)
    for (int num : arr) {
      cout << num << ' ';
    }
    cout << endl;
    // Теперь можно работать не с числами, а с их рангами. Иногда пригождается.
    // Это очень известный приём.
  }
  {
    // Какие-то операции происходят во время исполнения программы, а какие-то
    // во время компиляции. Выделение памяти под настоящий массив (не вектор)
    // происходит на компиляции, если он в глобальной области видимости.
    // То есть до мейна
    // Важно отметить, что swap для векторов работает за O(1), программа
    // просто поменяет две ссылки. А вот с честным массивом так не получится.
    // swap отработает за O(количество свапнутых элементов)
    // Честные массивы можно объявить так:
    int kek[10];
    int cheburek[10];
    // Или так:
    array<int, 10> lol;
    // На самом деле есть отличия у многомерного вектора и массива.
    // обращение по индексу и создание быстрее у обычного массива
    // Потому что обычный массив как бы ты не старался останется сплошной
    // полосочкой в памяти. Покажу на доске.
  }
  { // Существуют следущие полезные структуры данных:
    deque<int> dq;
    // У дека есть методы .pop_front() и .push_front(), которые работают за O(1)
    queue<int> q;
    // У очереди есть методы .front(), .push(), .pop()
    // Это как очередь в пятёрочке. Кто приходит - становится в конец очереди
    // Первого в очереди обслуживают
    stack<int> st;
    // Стек это плохой вектор. Вектор работает точно так же.
  }
  {
    // Поток ввода
    ifstream in("input.txt");
    // Поток вывода
    ofstream out("output.txt");
    string message;
    in >> message;
    out << message + "-" + message << endl;
  }
  { // чтение до конца ввода
    int sum = 0;
    int next;
    // чтобы прервать этот цикл ты должен ввести ctrl+d
    while (cin >> next) {
      sum += next;
    }
    cout << sum << endl;
  }
  // Вот такая копипаста позволяет раздеять по тем символам, по которым
  // Смотри копипасту в начале файла --^

  // Есть массив
  int dp[10][20][30];
  // Хотим забить его очень большими значениями
  // Для этого ты используешь функцию memset:
  memset(dp, 0x7F, sizeof(dp));
  cout << dp[0][0][0] << endl;
  signed sdp[10][20];
  memset(sdp, 0x7F, sizeof(sdp));
  cout << sdp[0][0] << endl;
  // Также рабоает с 0 и с -1
  return 0;
}
