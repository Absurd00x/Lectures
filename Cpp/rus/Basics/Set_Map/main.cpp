#include <bits/stdc++.h>
// Библиотеки можно подключать дважды. Компилятор разберётся.
// Для работы с множествами:
#include <set>
// Для работы с отображениями:
#include <map>

using namespace std;

// O(n)
int get_position_in_multiset(multiset<int> &ms, auto iter) {
  int res = 0;
  while (iter != ms.begin()) {
    --iter;
    ++res;
  }
  return res;
}

int main() {
  // Множество - отсортированный набор значений.
  // В нём элементы по умолчанию будут располагаться от меньшего к большему.
  // У множества нет индексов, но есть итераторы.
  // В множестве каждый элемент хранится не больше одного раза.
  // Объявляется так:
  // set<тип_элементов> название_множества;

  set<int> st;
  // Можно присваивать переменные при помощи "списка инициализации":
  vector<int> arr = {2, 3, 1, 2, 3, 1};
  // В множество можно добавлять элементы, удалять из него элементы
  // и искать в нём элементы намного быстрее, чем в обычном массиве.
  for (int i = 0; i < (int)arr.size(); ++i) {
    // Добавить элемент в множество можно методом .insert().
    // Если в множестве уже был такой элемент, то ничего не произойдёт.
    st.insert(arr[i]);
  }
  // Чтобы пройтись по множеству, можно использовать итераторы:
  cout << "Set contents:" << endl;
  for (auto it = st.begin(); it != st.end(); ++it) {
    cout << (*it) << ' ';
  }
  cout << endl;
  // Или "питонячие" форики такого формата:
  // for (тип_элемента название_перемнной : массив) {
  // вместо типа_элемента можно писать auto.
  cout << "Set contents:" << endl;
  for (int elem : st) {
    cout << elem << ' ';
  }
  cout << endl << endl;
  for (int i = 0; i < (int)arr.size(); ++i) {
    // Из множества можно удалить элементы методом .erase().
    // Если элемента нет в множестве, то ничего не случится.
    st.erase(arr[i]);
  }
  // Можно попробовать найти конкретный элемент в множестве методом .find().
  // Он вернёт итератор на найденный элемент, а если не нашел его, то
  // итератор будет равен st.end().
  auto iter = st.find(1337);
  if (iter == st.end()) {
    cout << "1337 not found" << endl << endl;
  }
  // Не путай метод .find() с функцией find().

  // Мапу (отображение, не "карта") можно понимать двумя способами:
  // 1. Это сет, у которого есть дополнительное поле для данных.
  // 2. Это бесконечный массив, где индексы могут быть всем, что можно сравнивать.
  // Объявляется так:
  // map<тип_ключа, тип_значения> название_мапы;
  // Индексы в мапе называются "ключами"
  map<int, int> counts;
  // Если ключа, который написали в [] нет, то он создаётся и значение будет
  // равен чему-то "пустому". 0 для чисел и "" для строки.

  // Самое частое применение мапы - подсчёт.
  // В отличии от сортировки подсчётом, мапе не важно, что она считает
  // большие числа или не числа вовсе.
  for (int elem : arr) {
    ++counts[elem];
  }
  // Под капотом мапа состоит из пар.
  // Пара это просто два значения рядом друг с другом.
  // Объявляется так:
  // pair<тип_первого_элемента, тип_второго_элемента> имя_пары;
  pair<char, int> example('a', 0);
  // Обращение к первому и второму элементам пары:
  cout << "Pair contents:" << endl;
  cout << example.first << ' ' << example.second << endl << endl;
  // По мапе также можно пройтись с помощью итераторов:
  cout << "Map contents:" << endl;
  for (auto it = counts.begin(); it != counts.end(); ++it) {
    // Можно разыменовать итератор на мапу и получить пару.
    pair<int, int> elem = *it;
    // auto тоже работает.
    auto key_value = *it;
    cout << elem.first << ' ' << key_value.second << endl;
  }
  cout << "Map contents:" << endl;
  for (auto key_value : counts) {
    cout << key_value.first << ' ' << key_value.second << endl;
  }
  cout << endl;
  // Допустим, тебе надоели пары. Ты хочешь как-то удобнее обращаться к
  // первому и ко второму элементу пары.
  // Для тебя придумали структурные привязки. Это эквивалент "распаковки"
  // из питона.
  pair<int, int> point(2, 3);
  cout << "Pair contents:" << endl;
  // Обычное обращение:
  cout << point.first << ' ' << point.second << endl;

  // Если ты пишешь символ &, то изменение x и y затронет
  // саму пару. Если не пишешь, то будешь работать с копией point.first и
  // point.second.
  auto &[x, y] = point;
  cout << "Strutured binding:" << endl;
  cout << x << ' ' << y << endl;

  // Изменения x и y затрагивают саму пару.
  x = -123, y = 222;
  cout << "Changed x to -123 and y to 222" << endl;
  cout << "Pair contetns:" << endl;
  cout << point.first << ' ' << point.second << endl;
  // x и point.first это одно и то же. Аналогично y и point.second.
  cout << endl;

  // Делаем копирование, чтобы такого не было:
  auto [x0, y0] = point;
  // int x0 = point.first
  // int y0 = point.second
  cout << "Copied:" << endl;
  cout << x0 << ' ' << y0 << endl;
  // Создали копию, изменили копию. Значения пары не поменялись.
  x0 = 0, y0 = 0;
  cout << "Changed x0 to 0 and y0 to 0" << endl;
  cout << "Pair contetns:" << endl;
  cout << point.first << ' ' << point.second << endl;
  cout << endl;

  // С помощью структурных привязок можно очень удобно проходиться по мапе:
  cout << "Map contents:" << endl;
  for (auto &[key, value] : counts) {
    cout << key << ' ' << value << endl;
  }
  cout << endl;

  // Ошибкоопасные места!
  vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {5, 6}};
  // Делаем структурную привязку на последний элемент:
  auto &[a, b] = vec.back();
  // Удаляем последний элемент, на который ссылаются a и b.
  vec.pop_back();
  // Если обратиться к a и b, то будет неопределённое поведение.
  cout << "Undefined behavior:" << endl;
  cout << a << ' ' << b << endl;
  // В этом случае можешь воспользоваться копированием, не используй &
  cout << endl;

  // Никогда не пользуйся структурными привязками, когда собираешься добавлять
  // элементы в вектор! Пользуйся только копированием!
  auto &[p, q] = vec[1];
  cout << "Before adding elements: p = " << p << ", q = " << q << endl;
  // .emplace_back() позволяет удобно добавить пару в вектор
  vec.emplace_back(10, 10);
  vec.emplace_back(11, 11);
  // Думаем, что p и q указывают на вторую пару в векторе, но ничего подобного:
  cout << "After adding elements: p = " << p << ", q = " << q << endl;
  cout << "Changed p to 123 and q to 456" << endl;
  p = 123, q = 456;
  cout << "Pair in vector: ";
  cout << "first = " << vec[1].first << ", q = " << vec[1].second << endl;
  cout << endl;

  // Никогда не пытайся удалять элементы из сета/мапы, когда по ним проходишься.
  // Это тоже неопределённое поведение.
  for (int elem : arr) {
    // Чтобы удалить элемент из мапы, нужно указать его ключ.
    // Значение указывать не нужно.
    counts.erase(elem);
  }
  // .insert(), .erase(), .find() и [] работают за O(log(n)) по времени.
  // За сетом, мапой и мультисетом скрывается красно-чёрное дерево:
  // красно-чёрное дерево (КЧД): https://ru.wikipedia.org/wiki/Красно-чёрное_дерево

  // Мультимножество это множество,
  // где каждый элемнет может храниться несколько раз.
  multiset<int> ms;
  for (int i = 0; i < 10; ++i) {
    ms.insert(0);
  }
  cout << "Initial multiset size = " << ms.size() << endl;

  // Когда удаляешь элемент из мультисета, то есть два случая:
  // 1. Ты удаляешь один элемент, тогда передаёшь итератор на него:
  ms.erase(ms.begin());
  cout << "Multiset size after .begin() erased = " << ms.size() << endl;
  // Внимание!!! Если попробуешь удалить итератор .end(), то получишь
  // неопределённое поведение!
  // 2. Ты удаляешь все элементы равные какому-то значению.
  int val = *ms.begin();
  // Если значения нет в сете, то ничего страшного не происходит.
  ms.erase(val);
  cout << "Multiset size after smallest elements are erased = " << ms.size() << endl;
  cout << endl;

  // Как говорилось раньше, можно добавить число 'x' к итератору и получить
  // новый итератор, находящийся на 'x' позиций дальше.
  cout << "Element at index 3 equals to ";
  // Эквивалентно arr[3]:
  cout << (*(arr.begin() + 3)) << endl;
  // Такое прибавление работает за O(1) в векторе.
  // Но в сете/мапе/мультисете это займёт
  // O(max(log(n), расстояние)) итераций, потому что
  // нужно будет обходить красно-чёрное дерево.
  // Прибавление единицы будет работать за O(log(n)), но
  // прибавление числа работает за O(max(log(n), расстояние)).
  // Плюс, просто так ты число не добавишь к итератору на set/map/multiset.

  // У структур выше есть очень полезные методы
  // .lower_bound(num) и .upper_bound(num)
  // Они возвращают итераторы на первые элементы, которые:
  // .lower_bound(num): >= num
  // .upper_bound(num): > num
  ms = {1, 2, 3, 3, 4, 5};
  cout << "Multiset contents are:" << endl;
  for (int num : ms) {
    cout << num << ' ';
  }
  cout << endl << endl;
  auto it = ms.lower_bound(3);
  // Это простая функция, которая находит "индекс" элемента в мультимножестве:
  int pos = get_position_in_multiset(ms, it);
  cout << ".lower_bound(3) returns iterator at position " << pos << endl;
  cout << "which points at " << (*it) << endl << endl;
  it = ms.upper_bound(3);
  pos = get_position_in_multiset(ms, it);
  cout << ".upper_bound(3) returns iterator at position " << pos << endl;
  cout << "which points at " << (*it) << endl << endl;

  // Разберём как под капотом работает вектор.

  // arr = {2, 3, 1, 2, 3, 1}
  // В памяти компьютера эти элементы расположены подряд.
  // Когда вставляешь элемент, то чтобы последовательность не сломалась,
  // каждый элемент справа должен сдвинуться на единицу вправо, чтобы
  // освободить место новому элементу.
  // arr = {2, _, 3, 1, 2, 3, 1}
  // Это приводит к асимптотике O(кол-во_сдвинутых) за один вызов .insert()
  // Из-за этого метод .push_back() работает за O(1).
  // С методами .erase() и .pop_back() работает аналогично.
  cout << "Vector contents are:" << endl;
  for (int num : arr) {
    cout << num << ' ';
  }
  cout << endl << endl;
  cout << "Erasing element at index 3..." << endl;
  // arr[3]
  arr.erase(arr.begin() + 3);
  cout << "Now vector contents are:" << endl;
  for (int num : arr) {
    cout << num << ' ';
  }
  cout << endl << endl;
  cout << "Inserting 1337 at index 1..." << endl;
  // arr[1]
  arr.insert(arr.begin() + 1, 1337);
  cout << "Now vector contents are:" << endl;
  for (int num : arr) {
    cout << num << ' ';
  }
  cout << endl << endl;
  return 0;
}

/* Общие методы и их асимптотики:
.find(elem)       | Получает итератор на элемент равный elem                         | O(log(n))
.size()           | Количество элементов                                             | O(1)
.empty()          | Пустой ли контейнер, или нет                                     | O(1)
.erase(elem)      | Удалить все элементы равные "elem"                               | O(log(n))
.erase(iter)      | Удалить элемент, на который указывает "iter".                    | O(log(n))
                  | Если "iter" равен .end(), то происходит неопределённое поведение |
.clear()          | Удалить все элементы из контейнера                               | O(n)
.lower_bound(num) | Итератор на первый элемент >= "num"                              | O(log(n))
.upper_bound(num) | Итератор на первый элемент > "num"                               | O(log(n))
.begin()          | Итератор на первый элемент "arr"                                 | O(1)
.end()            | Итератор на элемент после последнего                             | O(1)
.rbegin()         | Итератор на последний элемент структуры                          | O(1)
.rend()           | Итератор на элемент перед первым                                 | O(1)
*/

// .insert(elem) добавляет элемент в сет/мультисет за O(log(n))
// Квадратные скобки [] у мапы работают за O(log(n))
