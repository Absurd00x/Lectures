// This library contains the sort() function
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  // An array is a controllable sequence of values.
  // The elements are arranges as you like it in a sequence.
  // Elements are indexed (same as numbered) from zero.
  // For example, the first element will have an index of 0,
  // the second one will have an index of 1 and so on
  // Arrays are declared like this:
  // vector<data_type> array_name(number_of_elements, initial_value);
  vector<int> arr(10, -1);
  // Please, do not use anything other than vector for now.
  // Arrays work well with 'for' cycles
  for (int i = 0; i < 10; ++i) {
    // In order to get i-th element, use:
    // array_name[i]
    // This expression can be viewed as a single value
    arr[i] = 123;
  }
  // Initial number of elements can be any non-negative number
  // even if you don't know in when compiling.
  // If you don't explicitly state initial value it will be set to 0
  int n;
  cin >> n;
  vector<int> brr(n);
  // You can read n numbers from the input like this:
  for (int i = 0; i < n; ++i) {
    // Notice that the variable i was already declared, but it has been
    // only visible in the previous 'for' cycle. It's gone afterwards.
    cin >> brr[i];
  }
  // You can reassign vectors just like integers
  arr = brr;

  // A function (in programming) is a callable code block.
  // Vector has functions to work with it.
  // Functions that work with specific object are called methods.
  // In our case, this is a vector object.
  // Method .size(), for instance, tells the current array size:
  cout << "Array size is " << arr.size() << endl;
  // .back() method gets you the last element in vector.
  // Which is equivalent to arr[arr.size() - 1]
  int last = arr.back();
  // .pop_back() method deletes the last element in the array.
  arr.pop_back();
  // .push_back() method adds an element to the end of the array.
  arr.push_back(last);
  last = 123;
  // arr is not changed after all those operations.

  // If you imagine an array as a street, then in iterator will be
  // a particular address on this street. For example "221B Baker Street"
  // is an iterator of the Baker Street.
  // There is a method to get an iterator to the beginning of an array.
  // The element which has index 0.
  vector<int>::iterator difficult = arr.begin();
  // You can use auto "data type", and the compiler will guess what you mean.
  // This is a direct instruction to the compiler "guess it yourself".
  auto it = arr.begin();
  // .end() method returns an iteretor to an element right after the last one,
  // which does not exist.
  // Any part of the 'for' cycle can be neglected:
  for (; it != arr.end(); ++it) {
    // An iterator can be "dereferenced",
    // which means we get the value it points to
    // It's like asking "What house there is at 221B Baker Street?"
    cout << *it << ' ';
    // ' ' => is a space character (is a char)
  }
  cout << endl;
  // Iterators of ARRAYS are linear.
  // That means, that if you have a house with an address of "x",
  // then you can easily understand, that after "y" houses, there
  // is a house with address "x + y".
  // So, we get an address of the beginning of the "arr" array,
  // increase it by 3 and then dereference it.
  // This is equivalent to arr[3]
  cout << *(arr.begin() + 3) << endl;

  // Iterators are needed mostly becase the standard library uses them
  // The sort() function, for instance:
  sort(arr.begin(), arr.end());
  auto elem = find(arr.begin(), arr.end(), 123);
  auto maximum = max_element(arr.begin(), arr.end());
  auto minimum = min_element(arr.begin(), arr.end());
  // etc.

  // You can subtract one LINEAR iterator from the other, which makes sence:
  // 221 Baker Street - 123 Baker Street = 98
  // But the difference between two addresses from different streets does not:
  // 221 Baker Street - 58 Paddington Street = ???

  // If you want to get an index instead of an iterator use:
  int index = maximum - arr.begin();

  // There also are reversed iterators. They are the same as the regular ones,
  // except that increasing them, will decrese the address number.
  // They go backwards in other words

  //        .begin()             .end()
  //          |                   |
  //          v ---->             v
  //        | 0 | 1 | 2 | 3 | 4 |
  // arr     123 456  0  -12  32
  //      ^             <---- ^
  //      |                   |
  //    .rend()            .rbegin()

  // string is the same as vector<char>
  // It has all methods that vector does, but it's more convenient.
  // You can directly use it with 'cout'
  // Both vectors ands strings can be compared with themselves using
  // lexicographic order or dictionary order. E.g.
  // "father" goes before "fruit"
  // and "123" goes before "5"
  // but if we compare them as numbers, the result will be different
  string s = "123";
  string t = "5";
  if (s < t) {
    cout << s << " < " << t << endl;
  } else {
    cout << s << " >= " << t << endl;
  }

  // You must state string's initial value
  string str(12, '0');
  // or do not state anything at all
  string example;
  // This is really convenient
  cin >> str;
  cout << str << endl;

  // Multidimensional arrays are just arrays that contain
  // other arrays as their data type.
  // Two-dimesional vectors are declared as follows:
  // vector<vector<data_type>> name(n.o. rows, vector<data_type>(n.o. columns, initial_value));
  vector<vector<int>> mat(3, vector<int>(3, -3));
  for (int i = 0; i < 3; ++i) {
    // mat[i] is the i-th array inside of the matrix "mat".
    // i-th row in other words.
    for (int j = 0; j < 3; ++j) {
      // mat[i][j] is j-th element inside i-th array in matrix "mat".
      // Or, a matrix element in i-th row and j-th column.
      cout << mat[i][j] << ' ';
    }
    cout << endl;
  }
  // You can go with as many dimensions as you like,
  // as long as it fits in memory.
  vector<vector<vector<int>>> tensor(3, vector<vector<int>>(3, vector<int>(3, 2)));
  return 0;
}

/* Vector methods and their time complexities (Big O):
arr.push_back(elem)    | Adds "elem" to the end of "arr"                             | O(1)
arr.pop_back()         | Removes an element from the end of "arr"                    | O(1)
arr.back()             | Access the element at the beginning of "arr"                | O(1)
arr.front()            | Access the element at the end of "arr"                      | O(1)
arr.size()             | Number of elements present in "arr"                         | O(1)
arr.empty()            | Whether if "arr" is empty or not                            | O(1)
arr.erase(iter)        | Remove an element from "arr", which is pointed by "iter"    | O(n) if deleted from the beginning
arr.insert(iter, elem) | Add an alement to "arr" to the position specified by "iter" | O(n) if added to the beginning
arr[i]                 | Access the element with index i                             | O(1)
arr.clear()            | Remove all elements from "arr"                              | O(n)
arr.assign(cnt, elem)  | Replace "arr" with "cnt" elements equal to "elem"           | O(n)
arr.begin()            | Iterator to the first element of "arr"                      | O(1)
arr.end()              | Iterator to the element that comes after the last one       | O(1)
arr.rbegin()           | Iterator to the last element of                             | O(1)
arr.rend()             | Iterator to the element that comes before the first one     | O(1)
+num to an iterator    | Increase iterator by num                                    | O(1)
*/
