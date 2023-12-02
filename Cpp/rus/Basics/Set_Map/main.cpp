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
  // Множество - упорядоченный набор значений.
  // В нём элементы по умолчанию будут располагаться от меньшего к большему.
  // У множества нет индексов, но есть итераторы.
  // В множестве каждый элемент хранится один раз.
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
  // Можно посчитать количество элементов num методом .count(num).
  // Звучит глупо, потому что либо элемент есть, либо нет,
  // так что получим либо 1, либо 0.
  cout << "There are " << st.count(1337) << " elems in set equal to 1337" << endl;
  // Можно попробовать найти конкретный элемент в множестве методом .find().
  // Он вернёт итератор на найденный элемент, а если не нашел его, то
  // итератор будет равен st.end().
  auto iter = st.find(1337);
  if (iter == st.end()) {
    cout << "1337 not found" << endl << endl;
  }
  // Не путай метод .find() с функцией find().

  // Мапу (отображение) можно понимать двумя способами:
  // 1. Это бесконечный массив, где индексы могут быть всем, что можно сравнивать.
  // 2. Это сет, у которого есть дополнительное поле для данных.
  // Объявляется так:
  // map<тип_ключа, тип_значения> название_мапы;
  map<int, int> counts;
  // Индексы в мапе называются "ключами"
  // Если ключа, который написали в [] нет, то он создаётся и будет
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
  pair<char, int> example = {'a', 0};
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
  // Никогда не пытайся удалять элементы из сета/мапы, когда по ним проходишься.
  // Это повлечёт за собой неопределённое поведение.
  // Делай так только если ты уверен, что то, что ты делаешь норм.
  for (int elem : arr) {
    // Чтобы удалить элемент из мапы, нужно указать его ключ.
    // Значение указывать не нужно.
    counts.erase(elem);
  }
  // .insert(), .erase(), .find(), .count() и [] работают за O(log(n)) по времени.
  // За сетом, мапой и мультисетом скрывается красно-чёрное дерево:
  // красно-чёрное дерево (КЧД): https://ru.wikipedia.org/wiki/Красно-чёрное_дерево

  // Мультимножество это множество,
  // где каждый элемнет может храниться несколько раз.
  multiset<int> ms;
  for (int i = 0; i < 10; ++i) {
    ms.insert(0);
  }
  cout << "Initial multiset size = " << ms.size() << endl;
  // .count() в мультисете работает за O(max(log(n), результат)) операций.

  // Когда удаляешь элемент из мультисета, то есть два случая:
  // 1. Ты удаляешь один элемент, тогда передаёшь итератор на него:
  ms.erase(ms.begin());
  // Внимание!!! Если попробуешь удалить итератор .end(), то получишь
  // неопределённое поведение!
  cout << "Multiset size after .begin() erased = " << ms.size() << endl;
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
  // При этом прибавление единицы будет работать за O(log(n)), но
  // прибавление числа работает за O(max(log(n), расстояние)).

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

// .count(elem) в сете работает за O(log(n))
// .count(elem) в мультисете работает за O(max(log(n), n))
// .insert(elem) добавляет элемент в сет/мультисет за O(log(n))
// Квадратные скобки [] у мапы работают за O(log(n))
