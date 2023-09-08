#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  long long x;
  cin >> n >> x;
  vector<int> arr(n);
  for (int &elem : arr) {
    cin >> elem;
  }
  bool ans = false;
  const int M = 1 << n;
  for (int mask = 0; mask < M; ++mask) {
    long long sum = 0;
    for (int bit = 0; bit < n; ++bit) {
      if ((mask >> bit) & 1) {
        sum += arr[bit];
      }
    }
    if (sum == x) {
      ans = true;
      break;
    }
  }
  if (ans) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main() {
  /* Полином (многочлен) - это выражение вида
   * a_n * x^n + a_(n-1) * x^(n-1) + ... + a_1 * x^1 + a_0 * x^0
   * x называется основанием многочлена
   * числа a_i называются коэффициентами многочлена
   * Например, квадратное уравнение является полиномом:
   * x^2 - 2x + 1
   * Числа можно представлять в виде многочленов. Например,
   * десятичные числа можно представлять в виде многочленов с
   * основанием 10 следующим образом:
   * 123 = 1 * 10^2 + 2 * 10^1 + 3
   * А двоичные числа можно представить в виде многочленов с
   * основанием 2 точно таким же образом:
   * 6543210
   * 1111011 = 2^6 + 2^5 + 2^4 + 2^3 + 2^1 + 2^0
   * Когда в задаче идёт речь про битовые операции, то почти
   * полезно представлять числа в двоичном виде, но не всегда.
   * Чтобы явно представить число в двоичном виде, можно
   * использовать bitset, но чаще всего это не нужно делать в задаче.
   * Основные битовые операции:
   * '&' '|' '^' - И, ИЛИ, ИСКЛЮЧАЮЩЕЕ ИЛИ (XOR)
   * '>>' '<<' - побитовый сдвиг вправо и влево соответственно
   */
  const int N = 8;
  const int ONE = 240;
  const int TWO = 204;
  const int THREE = 170;
  // Функция И равна 1, если ВСЕ операнды равны 1
  cout << "ONE   = " << bitset<N>(ONE) << endl;
  cout << "TWO   = " << bitset<N>(TWO) << endl;
  cout << "THREE = " << bitset<N>(THREE) << endl;
  cout << "AND   = " << bitset<N>(ONE & TWO & THREE) << endl;
  cout << endl;
  // Функция ИЛИ равна 1, если ХОТЯ БЫ ОДИН операнд равен 1
  cout << "ONE   = " << bitset<N>(ONE) << endl;
  cout << "TWO   = " << bitset<N>(TWO) << endl;
  cout << "THREE = " << bitset<N>(THREE) << endl;
  cout << "OR    = " << bitset<N>(ONE | TWO | THREE) << endl;
  cout << endl;
  // Функция XOR равна 1, если сумма операндов нечётна
  cout << "ONE   = " << bitset<N>(ONE) << endl;
  cout << "TWO   = " << bitset<N>(TWO) << endl;
  cout << "THREE = " << bitset<N>(THREE) << endl;
  cout << "XOR   = " << bitset<N>(ONE ^ TWO ^ THREE) << endl;
  cout << endl;
  /* Таблица значений (называется таблица истинности):
   *  x1  x2  x3 AND  OR XOR
   *  0   0   0   0   0   0
   *  0   0   1   0   1   1
   *  0   1   0   0   1   1
   *  0   1   1   0   1   0
   *  1   0   0   0   1   1
   *  1   0   1   0   1   0
   *  1   1   0   0   1   0
   *  1   1   1   1   1   1
   */
  // Если в начале числа написать 0b, то можно его записать
  // сразу в двоичном виде прямо в коде:
  int cur = 0b1101;
  /* Ключевой операцией является побитовый сдвиг.
   * Побитовый сдвиг влево на k эквивалентен умножению на 2^k.
   * Действительно, посмотрим что будет проиходить с числом.
   */
  for (int i = 0; i <= 4; ++i) {
    cout << bitset<N>(cur) << " << " << i << " = " << bitset<N>(cur << i);
    cout << " = " << (cur << i) << endl;
  }
  cout << endl;
  /* Из этого следует, что (1 << k) = 2^k
   * Внимание! Тип результата у оператора << зависит от левого операнда.
   * Поэтому выражение (1 << k) имеет тип int!!!
   * Если хочешь, чтобы оно имело тип long long, нужно, чтобы левый
   * операнд был типа long long. Если хочешь, чтобы константное значение
   * имело тип long long, то нужно использовать литералы. В данном случае
   * суффикс LL вот так:
   * pow2 = 1LL << k;
   * Не используй функцию pow! Она возвращает дробное число!
   */
  for (int i = 0; i < 8; ++i) {
    cout << "1 << " << i << " = " << bitset<N>(1 << i) << ' ' << (1 << i) << endl;
  }
  cout << endl;
  // Аналогично, побитовый сдвиг вправо на k (почти) эквивалентен делению на 2^k
  cur = 0b11010010;
  for (int i = 0; i < 8; ++i) {
    cout << bitset<N>(cur) << " >> " << i << " = " << bitset<N>(cur >> i);
    cout << " = " << (cur >> i) << endl;
  }
  cout << endl;
  /* После сдвига на k позиций вправо, k-й бит оказывается на 0 позиции
   * Из этого следует, что можно получить значение k-го бита следующим кодом:
   * bit = (cur >> k) & 1
   * бит может быть равен 0 или 1 в этом случае. Так и должно быть.
   */
  /* Число, двоичное представление которого необходимо для выбора определённых
   * битов называется маской.
   * Понятие маскирования встречается в сетях для определения адреса
   * сети и адреса узла. Есть ip адрес. Первые сколько-то бит в нём
   * обозначают адрес сети, остальные - адрес узла. Пользуются маской сети,
   * чтобы получить адрес сети из ip адреса.
   * Например:
   * 192.168.5.130/24. Эта запись обозначает, что чтобы получить адрес сети,
   * нужно воспользовать 32х битной маской, где 24 самых больших бита равны 1.
   * Конкретно, если сделать побитовое И адреса с маской, то получится
   * адрес сети. Оставшиеся 32 - 24 = 8 бит будут отвечать за адрес узла.
   * 11000000.10101000.00000101.10000010 = 192.168.5.130
   * 11111111.11111111.11111111.00000000 = маска сети
   * 11000000.10101000.00000101.00000000 = адрес сети
   * 00000000.00000000.00000000.10000010 = адрес узла
   *
   * Как это применять? Например, хотим выбрать биты с 8го до 15го включительно.
   * Тогда потребуется такая маска (точки здесь ради удобства):
   * 00000000.00000000.11111111.00000000
   * Как получить такое число? Например, вычислить 2^16 - 2^8
   * 00000000.00000001.00000000.00000000 = 2^16
   * 00000000.00000000.00000001.00000000 = 2^8
   * 00000000.00000000.11111111.00000000 = необходимая маска
   *
   * Также существуют понятия подмаски и надмаски.
   * Число B называется подмаской числа A, если A & B = B
   * Иначе говоря, B - подмаска A, если все единичные биты B присутствуют в A
   * Также число A в этом случае называется надмаской или супермаской.
   * Например:
   * A = 10010110
   * B = 00010100
   * B - подмаска A
   * A - надмаска (супермаска) B
   * В спортивном программировании говорят о переборе масок, когда хотят
   * перебрать все способы выбрать подмножество элементов.
   * Например, такая задача.
   * Даны два числа n и x. Дано n целых чисел.
   * Нужно сказать, можно ли выбрать какие-то из них так, чтобы сумма
   * была равна в точности x. Она решается следующим образом.
   * Переберём все маски длины n (то есть все числа на промежутке [0, 2^n).
   * Скажем для каждой маски, что если в ней на позиции i стоит единичный бит,
   * то мы берём это число, суммируем. Иначе не берём, оставляем.
   * Таким образом мы переберём все 2^n способов взять какое-то подмножество
   * чисел. Код сверху.
   */
  /* Отрицательные числа представляются следующим образом в памяти компьютера:
   * Есть положительное число. Инвертируем все биты  (0 заменяем на 1,
   * 1 заменяем на 0) и добавляем единицу к получившемуся числу.
   * Унарный оператор '-' именно это и делает. Можно проверить:
   */
  const int I = 32;
  int num = 1e9;
  cout << bitset<I>(num) << " = num" << endl;
  // Унарнрый оператор '~' инвертирует все биты в числе.
  cout << bitset<I>(~num) << " = ~num" << endl;
  cout << bitset<I>(~num + 1) << " = ~num + 1" << endl;
  cout << bitset<I>(-num) << " = -num" << endl;
  cout << bitset<I>(num&-num) << " = num&-num" << endl;
  cout << endl;
  /* Ещё одна популярная операция с битами - убрать из числа все биты,
   * кроме наименьшего. Иначе говоря, получить 2^(наименьший единичный бит).
   * Она делается так:
   * num&-num
   * Ничего не взрывается, если num=0
   */
  for (int i = 0; i < 16; ++i) {
    cout << bitset<N / 2>(i) << ' ' << bitset<N / 2>(i&-i) << endl;
  }
  cout << endl;
  /* Наконец, существуют операции с двоичными числами, которые присущи
   * лишь компилятору gcc, а компилятор visual studio не знает их:
   * __lg(num) - получить индекс самого старшего бита. Если число равно 0, то
   *             поведение не определено. То есть результат произвольный.
   *
   * __builtin_popcount(num)   - посчитать количество единичных битов
   * __builtin_popcountll(num) - отдельная функция для типа long long
   *                             popcount = population count
   *
   * __builtin_clz(num)   - count leading zeros, посчитать количество нулей
   *                        СЛЕВА, то есть количество незначащих нулей
   * __builtin_clzll(num) - аналогичная версия для типа long long.
   *                        Если num = 0, то неопределённое поведение
   *
   * __builtin_ctz(num)   - count trailing zeros, посчитать количество нулей
   *                        СПРАВА
   * __builtin_ctzll(num) - аналогичная версия для типа long long
   *                        Если num = 0, то неопределённое поведение
   *
   * Они работают за O(количество бит) по-хорошему, но ощущаются как O(1).
   * А если в начале программы написать
   * pragma GCC optimize("O3")
   * pragma GCC target("popcnt")
   * То эти операции станут работать сильно быстрее.
   */
  return 0;
}
