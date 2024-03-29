// В этой библиотеке лежит функция sort()
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  // Массив - набор значений, расположенных в заданном порядке.
  // Элементы в массиве индексируются (то же самое, что нумеруются) с нуля.
  // Например, первый элемент будет иметь индекс 0,
  // второй элемент будет иметь индекс 1 и так далее.
  // Массивы объявляется так:
  // vector<тип_элеметов> название_массива(количество_элементов, чем_заполнен);
  vector<int> arr(10, 0);
  // Пожалуйста, не пользуйтесь ничем, кроме векторов пока.
  // Массивы хорошо работают с циклами for.
  for (int i = 0; i < 10; ++i) {
    // Чтобы обратиться к i-му (читаю как "Итому") элементу, пишешь
    // название_массива[i]
    // Эту конструкцию можно рассматривать как одну переменную.
    arr[i] = 123;
  }
  // Массив можно объявить на произвольное количество значений.
  // Даже на то, которое мы не знаем на момент написания кода.
  // Если явно не указать чем заполнен массив, то он будет заполнен нулями.
  int n;
  cin >> n;
  vector<int> brr(n);
  // Прочитать n чисел из ввода можно, например, так:
  for (int i = 0; i < n; ++i) {
    // Заметь, переменную i уже объявляли раньше в программе, но
    // она видна только в цикле и при выходе из цикла она "пропадёт".
    cin >> brr[i];
  }
  // Массивы можно переприсваивать как и целые числа:
  arr = brr;
  // Функция (в программировании) - вызываемый участок кода.
  // У вектора есть функции для работы с ним.
  // Функции, которые работают с каким-то объектом (в этом случае с вектором)
  // называют методами. Их пишут через символ точки '.'.
  // Например, метод .size() говорит текущий размер массива.
  cout << "Array size is " << arr.size() << endl;
  // Метод .back() говорит значение последнего элемента в массиве.
  // Это эквивалентно arr[arr.size() - 1]:
  int last = arr.back();
  // Метод .pop_back() удаляет последний элемент массива:
  arr.pop_back();
  // Метод .push_back() добавляет элемент в конец массива:
  arr.push_back(last);
  last = 123;
  // arr от этого присвоения не поменяется.

  // Итератор - адрес в памяти компьютера.
  // Если представить массив, как улицу, то итератор будет являться
  // конкретным адресом на ней. Например "улица Ленина 123" - это
  // итератор на улицу Ленина.
  // Есть метод, который возвращает итератор на начало массива.
  // То есть на элемент с индексом 0.
  vector<int>::iterator difficult = arr.begin();
  // Можно использовать "тип" auto, компилятор догадается что ты имеешь в виду.
  // Это прямая инструкция компилятору "догадайся сам какой там тип".
  auto it = arr.begin();
  // Итераторы нельзя сравнивать между собой на меньше/больше.
  // Метод .end() возвращает итератор на элемент следующий за последним.
  // Любую часть for можно не писать, но ставить ';' обязательно:
  for (; it != arr.end(); ++it) {
    // Итератор можно "разыменовать", чтобы получить значение,
    // на которое он указывает.
    // Всё равно что обратиться по индексу, только с помощью итератора.
    // Это как спросить "а какой дом находится по адресу Ленина 123?"
    cout << (*it) << ' ';
    // ' ' => это символ пробела (типа char)
  }
  cout << endl;
  // Итераторы массивов ЛИНЕЙНЫ.
  // Это означает, что если у тебя есть дом с номером "x",
  // то ты можешь сразу понять, что через "y" домов будет дом с номером "x + y".
  // Мы получаем адрес начала массива "arr", увеличивая его на 3,
  // а затем разыменовывая его. Это эквивалентно arr[3].
  cout << *(arr.begin() + 3) << endl;

  // Итераторы нужны в большей степени из-за того, что их использует
  // стандартная библиотека.
  // Например, функция сортировки sort():
  sort(arr.begin(), arr.end());
  // Поиск минимального элемента в массиве:
  auto minimum = min_element(arr.begin(), arr.end());
  // Поиск максимального элемента в массиве:
  auto maximum = max_element(arr.begin(), arr.end());
  // ...и многие другие.

  // Можно вычитать один ЛИНЕЙНЫЙ итератор из другого.
  // Это имеет под собой смысл - количество домов между двумя адресами:
  // Ленина 123 - Ленина 0 = 123
  // Ленина 50 - Ленина 25 = 25
  // Но разность между адресами на две разные улицы смысл не имеет:
  // Ленина 123 - Каруселина 2 = ???

  // Если хочешь найти индекс максимального элемента, то используй:
  int index = maximum - arr.begin();

  // Также существуют "перевёрнутые", (reversed) итераторы.
  // Они ведут себя также, как и обычные, но если их увеличивать, то
  // адрес будет уменьшаться.
  // Они как бы идут задом-наперёд.

  //            .begin()             .end()
  //              |                   |
  //              v ---->             v
  // иднекс |   | 0 | 1 | 2 | 3 | 4 |   |
  // элемент     123 456  0  -12  32
  //          ^             <---- ^
  //          |                   |
  //        .rend()            .rbegin()

  // Например, если передать в функцию sort() перевёрнутые
  // итераторы, то она отсортирует по убыванию, а не по возрастанию:
  sort(arr.rbegin(), arr.rend());

  // Строчка string - это то же самое, что vector<char>, только лучше.
  // Она имеет все методы массива, но более удобна.
  // Её можно напрямую вывести в 'cout'.
  // Её можно напрямую считать из 'cin'.
  // Вектора можно сравнивать с векторами и строки можно сравнивать со строками
  // "лексикографически", то есть в алфавитном порядке, как в словаре.
  // Например, слово "пальма" стоит в словаре раньше, чем слово "папа".
  // "123" стоит раньше, чем "5", но если их сравнивать как числа,
  // то результат будет другой.
  string s = "123";
  string t = "5";
  if (s < t) {
    cout << s << " < " << t << endl;
  } else {
    cout << s << " >= " << t << endl;
  }

  // У строчки либо ничего не указываешь
  string example;
  // Или указываешь и количество элементво и чем заполнена:
  string str(12, '0');
  // В любом случае ты всегда можешь прочитать строку независимо от размера:
  cin >> str;
  cout << str << endl;

  // Многомерные массивы - это массивы, которые содержат массивы внутри себя.
  // Двумерные объявляются таким образом:
  // vector<vector<тип>> название(кол-во_строк, vector<тип>(кол-во_столбцов, начальное_значение));
  vector<vector<int>> mat(3, vector<int>(3, -3));
  for (int i = 0; i < 3; ++i) {
    // mat[i] - i-й (Итый) массив внутри матрицы "mat".
    // то есть i-я строчка.
    for (int j = 0; j < 3; ++j) {
      // mat[i][j] - j-й (Житый) элемент внутри i-го (Итого) массива матрицы "mat".
      // Или элемент матрицы в i-й строчке и j-м столбце
      cout << mat[i][j] << ' ';
    }
    cout << endl;
  }
  // Можно делать столько измерений сколько хватит фантазии и памяти:
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
arr.erase(iter)        | Удалить элемент из arr, на который указывает iter  | O(кол-во сдвинутых)
arr.insert(iter, elem) | Добавить элемент elem в arr на позицию iter        | O(кол-во сдвинутых)
arr[i]                 | Элемент с индексом i                               | O(1)
arr.clear()            | Очистить содержимое arr                            | O(n)
arr.assign(cnt, elem)  | Меняет содержимое arr на cnt элементов равных elem | O(n)
arr.begin()            | Итератор на начало массива                         | O(1)
arr.end()              | Итератор на элемент после последнего               | O(1)
arr.rbegin()           | Итератор на последний элемент                      | O(1)
arr.rend()             | Итератор на элемент перед первым                   | O(1)
+num к итератору       | Увеличить итератор на num                          | O(1)
*/

/* !!!
Однако нельзя удалять и вставлять перевёрнутые итераторы.
.erase(rbegin()) и .insert(rbegin()) не сработают.
Нужно для этого с помощью арифметики итераторов найти обычный
итератор, который указывает на этот же самый элемент,
что и перевёрнутый.
*/
