// в этой библиотеке лежит функция сортировки
#include <algorithm>
#include <iostream>
// подключу библиотеку для работы с массивами
#include <vector>
// для работы со строками
#include <string>

using namespace std;

// Главная (main) функция, точка входа в программу
int main() {
  // массив - контролируемый набор значений, как строй, рота
  // значит, как ты скажешь расположить там элементы, так они и будут распологаться
  // элементы в массиве нумеруются (то же самое, что индексируются) с нуля
  // например, первый элемент будет иметь номер (индекс) 0,
  // второй элемент будет иметь индекс 1 и так далее
  // объявляется так:
  // vector<тип_элеметов> название_массива(количество_элементов, чем_заполнен);
  vector<int> arr(10, -1);
  // массивы обычно идут вместе с циклами for
  for (int i = 0; i < 10; ++i) {
    // чтобы обратиться к i-му (читаю как "Итому") элементу, пишешь
    // название_массива[i]
    // теперь эту конструкцию можно рассматривать как обычную переменную
    arr[i] = 123;
  }
  // массив можно объявить на произвольное количество значений
  // даже на то, которое мы не знаем на момент написания кода
  // также можно не указывать чем изначально заполнени массив
  // тогда он будет заполнен нулями
  int n;
  cin >> n;
  vector<int> brr(n);
  // прочитать n чисел из ввода можно, например, так:
  for (int i = 0; i < n; ++i) {
    // заметь, переменную i уже объявляли раньше в программе, но
    // она видна только в цикле и при выходе из цикла она "пропадёт"
    cin >> brr[i];
  }
  // массивы можно переприсваивать
  arr = brr;
  // функция - вызываемый участок кода
  // у вектора есть функции для работы с ним
  // функции, которые присущи какому-то объекту (в этом случае вектору)
  // называют методами. Их пишут через символ точки '.'
  // например, метод .size() говорит текущий размер массива
  cout << "Array size is " << arr.size() << endl;
  // метод .back() говорит значение последнего элемента в массиве
  // эквивалентно arr[arr.size() - 1]
  int last = arr.back();
  // метод .pop_back() удаляет последний элемент массива
  arr.pop_back();
  // метод .push_back() добавляет элемент в конец массива
  arr.push_back(last);
  last = 123;
  // arr от этого присвоения не поменяется

  // если представить массив, как улицу, то итератор будет являться
  // конкретным адресом на ней. Например "улица Ленина 123"
  // объявляем итератор на начало массива
  // то есть на первый элемент (тот, у которого индекс 0)
  vector<int>::iterator difficult = arr.begin();
  // можно использовать "тип" auto, компилятор догадается
  // что ты имеешь в виду. На самом деле это не отдельный тип данных, а прямо
  // инструкция компилятору "догадайся сам какой там тип"
  auto it = arr.begin();
  // любую часть for можно не писать, но ставить ';' обязательно
  for (; it != arr.end(); ++it) {
    // итератор можно "разыменовать", чтобы получить значение,
    // на которое он указывает
    // это как спросить "а какой дом находится по адресу Ленина 123?"
    cout << (*it) << ' ';
    // ' ' => это символ (char) пробела
  }
  cout << endl;
  // итераторы МАССИВОВ линейны
  // это означает, что если у тебя есть дом с номером "x",
  // то ты можешь сразу понять, что через "y" домов будет дом с номером "x + y"
  cout << (*(arr.begin() + 3)) << endl;

  // итераторы нужны в большей степени из-за того, что в стандартной
  // библиотеке большинство фунций используют именно итераторы, а не индексы
  // например, сортировка:
  sort(arr.begin(), arr.end());
  // поиск элемента в массиве (отдельная функция, не метод)
  auto elem = find(arr.begin(), arr.end(), 123);
  // поиск максимального элемента в массиве
  auto maximum = max_element(arr.begin(), arr.end());
  // поиск минимального элемента в массиве
  auto minimum = min_element(arr.begin(), arr.end());
  // и многие другие

  // можно найти разность итераторов и получить число
  // Ленина 123 - Ленина 0 = 123
  // Ленина 50 - Ленина 25 = 25
  // Ленина 123 - Каруселина 2 = ???
  // Поэтому нельзя вычитать из итератора на один массив
  // итератор на другой массив.
  int index = maximum - arr.begin();

  // строчка string - это почти то же самое, что vector<char>
  // она имеет все методы массива, но объявляется по-другому
  // ещё можно выводить в cout и сравнивать с другими строчками "лексикографически"
  // одна строчка лексикографически меньше другой, если она стоит
  // раньше в словаре. Массивы тоже можно сравнивать лексикографически между собой.
  // например "123" < "5", т.к. '1' < '5'
  // хотя если их сравнивать как числа, то результат будет другой
  string s = "123";
  string t = "5";
  if (s < t) {
    cout << s << " < " << t << endl;
  } else {
    cout << s << " >= " << t << endl;
  }

  // у строчки обязательно указывать начальное значение
  // а у вектора было не обязательно
  string str(12, '0');
  // также строчки можно считывать
  // даже не задавая их размер
  cin >> str;
  cout << str << endl;

  // многомерные массивы
  // многомерные массивы - это просто массивы массивов
  // двумерные объявляются таким образом:
  // vector<vector<тип>> название(кол-во_строк, vector<тип>(кол-во_столбцов, начальное_значение));
  vector<vector<int>> mat(3, vector<int>(3, -1));
  for (int i = 0; i < 3; ++i) {
    // так как mat[i] - i-й (Итый) массив внутри матрицы mat
    // то есть i-я строчка
    for (int j = 0; j < 3; ++j) {
      // mat[i][j] - j-й (Житый) элемент внутри i-го (Итого) массива матрицы mat
      // или элемент матрицы в i-й строчке и j-м столбце
      cout << mat[i][j] << ' ';
    }
    // выведем конец строки после каждой строки матрицы
    cout << endl;
  }
  vector<vector<vector<int>>> tensor(3, vector<vector<int>>(3, vector<int>(3, 2)));
  return 0;
}

/* Методы вектора и их асимптотики:
arr.push_back(elem)    | Добавить элемент elem в конец arr                  | O(1)
arr.pop_back()         | Удалить элемент с конца arr                        | O(1)
arr.back()             | Элемент в конце arr                                | O(1)
arr.front()            | Элемент в начале arr                               | O(1)
arr.size()             | Количество элементов в arr                         | O(1)
arr.empty()            | Пустой ли arr                                      | O(1)
arr.erase(iter)        | Удалить элемент из arr, на который указывает iter  | O(n) если удаляешь из начала
arr.insert(iter, elem) | Добавить элемент elem в arr на позицию iter        | O(n) если добавляешь в начало
arr[i]                 | Элемент с индексом i                               | O(1)
arr.clear()            | Очистить содержимое arr                            | O(n)
arr.assign(cnt, elem)  | Меняет содержимое arr на cnt элементов равных elem | O(n)
arr.begin()            | Итератор на начало массива                         | O(1)
arr.end()              | Итератор на элемент, следующий за последним        | O(1)
arr.rbegin()           | Итератор на последний элемент                      | O(1)
arr.rend()             | Итератор на элемент, следующий за первым           | O(1)
+num к итератору       | Увеличить итератор на num                          | O(1)
*/