#include <bits/stdc++.h>
// You may include libraries twice. Compiler will handle this.
#include <set>
#include <map>

using namespace std;

// O(n)
int get_index_in_multiset(multiset<int> &ms, auto iter) {
  int res = 0;
  while (iter != ms.begin()) {
    --iter;
    ++res;
  }
  return res;
}

int main() {
  // Set is uncontrollable. Its values are always sorted.
  // Set does not have indices, but has iterators
  // There can only exist one instance of each value at once
  // Declared like this:
  // set<data_type> set_name;

  set<int> st;
  // You can assign variables using list-initialization:
  vector<int> arr = {2, 3, 1, 2, 3, 1};
  // You can add elements into set, remove them, and try to find them
  // much faster than in regular array.
  for (int i = 0; i < (int)arr.size(); ++i) {
    // .insert() method adds an element to set.
    // If it already exists, nothing happens.
    st.insert(arr[i]);
  }
  // In order to iterate through elements of a set you can use iterators:
  cout << "Set contents:" << endl;
  for (auto it = st.begin(); it != st.end(); ++it) {
    cout << (*it) << ' ';
  }
  cout << endl;
  // Or "python-like" for cycles like this:
  // for (data_type variable_name : container) {
  // You can replace "data_type" with "auto".
  cout << "Set contents:" << endl;
  for (int elem : st) {
    cout << elem << ' ';
  }
  cout << endl << endl;
  for (int i = 0; i < (int)arr.size(); ++i) {
    // .erase() methon removes an element from set.
    // If there is no such element, nothing happens.
    st.erase(arr[i]);
  }
  // You can count the number of specific elements.
  // Sounds silly, because it's either present or not, so you will get 1 or 0.
  cout << "There are " << st.count(1337) << " elems in set equal to 1337" << endl;
  // You can try to find a specific element in set using .find() method.
  // If there is no such element .find() will return .end() iterator.
  auto iter = st.find(1337);
  if (iter == st.end()) {
    cout << "1337 not found" << endl << endl;
  }
  // Do not mix method .find() and function find().

  // You can think of a map in multiple two ways:
  // 1. It is an infinite array, where indices can be anything that is comparable.
  // 2. It is a set, that has an additional data field.
  // Declaration:
  // map<key_data_type, value_data_type> map_name;
  map<int, int> counts;
  // The indices in map are called "keys".
  // If the key you put in [] is not present, then it is created and
  // is assigned something "empty". 0 for numbers and "" for string.
  // The most frequent usage of a map is counting.
  // Unlike count sort, map does not care if the values are big or not integers.
  for (int elem : arr) {
    ++counts[elem];
  }
  // Under the hood elements of a map is a pair.
  // Pair is simply two values near each other.
  // Declared like this:
  // pair<first_data_type, second_data_type> pair_name;
  pair<char, int> example = {'a', 0};
  cout << "Pair contents:" << endl;
  // Access first and second element of a pair:
  cout << example.first << ' ' << example.second << endl << endl;
  // You can iterate through map using iterators.
  cout << "Map contents:" << endl;
  for (auto it = counts.begin(); it != counts.end(); ++it) {
    // If you dereference an iterator to map, it will return a pair.
    pair<int, int> elem = *it;
    // auto works aswell.
    auto key_value = *it;
    cout << elem.first << ' ' << key_value.second << endl;
  }
  cout << "Map contents:" << endl;
  for (auto key_value : counts) {
    cout << key_value.first << ' ' << key_value.second << endl;
  }
  cout << endl;
  // Never try to erase elements from set/map when you are itereting through them.
  // It will cause undefined behavior.
  // Do it only if you are sure what you are doing is ok.
  for (int elem : arr) {
    // In order to remove an element from map, you need to
    // specify its key. You don't need the value.
    counts.erase(elem);
  }
  // .insert(), .erase(), .find(), .count() and [] have time complexity O(log(n))
  // Behind set, map and multiset there is a red-black tree:
  // https://en.wikipedia.org/wiki/Red-black_tree

  // Multiset is a set, that can contain every element multiple times.
  multiset<int> ms;
  for (int i = 0; i < 10; ++i) {
    ms.insert(0);
  }
  cout << "Initial multiset size = " << ms.size() << endl;
  // .count() method will traverse entire tree resulting in
  // O(max(log(n), result)) time complexity per call.

  // When removing elements from multiset there are two possible situations.
  // 1. You want to remove a single instance of an element.
  // You need to pass an iterator to this instance.
  ms.erase(ms.begin());
  // Attention!!! If you try to erase iterator .end(), this will result in
  // undefined behavior!
  cout << "Multiset size after .begin() erased = " << ms.size() << endl;
  // 2. You want to remove all occurrences of an element.
  int val = *ms.begin();
  ms.erase(val);
  // If there is no such element, nothing bad happens.
  cout << "Multiset size after smallest elements are erased = " << ms.size() << endl;
  cout << endl;

  // As stated earlier, you can add a number 'x' to an iterator of a vector
  // and get a new iterator 'x' positions farther away.
  // Equivalent to arr[3]
  cout << "Element at index 3 equals to ";
  cout << *(arr.begin() + 3) << endl;
  // This has time complexity of O(1).
  // But in set/map/multiset this takes O(max(log(n), distance)) iterations, because
  // we will need to traverse the red-black tree to find other elements.
  // Incrementing will take O(log(n)) time, but adding a number
  // will take O(max(log(n), distance)).

  // These structures have very useful methods
  // .lower_bound(num) и .upper_bound(num)
  // They both return an iterator to the first element that:
  // .lower_bound(num): >= num
  // .upper_bound(num): > num
  ms = {1, 2, 3, 3, 4, 5};
  cout << "Multiset contents are:" << endl;
  for (int num : ms) {
    cout << num << ' ';
  }
  cout << endl << endl;
  auto it = ms.lower_bound(3);
  // This is a simple function that finds "index" of an element in multiset.
  int pos = get_index_in_multiset(ms, it);
  cout << ".lower_bound(3) returns iterator at position " << pos << endl;
  cout << "which points at " << (*it) << endl << endl;
  it = ms.upper_bound(3);
  pos = get_index_in_multiset(ms, it);
  cout << ".upper_bound(3) returns iterator at position " << pos << endl;
  cout << "which points at " << (*it) << endl << endl;

  // Let's investigate how does a vector work under the hood.

  // arr = {2, 3, 1, 2, 3, 1}
  // In computer memory they are allocated consecutively.
  // When you are inserting an element, in order for this sequence to
  // not break, every element to the right needs to be moved one element
  // to the right to free up space.
  // arr = {2, _, 3, 1, 2, 3, 1}
  // This leads to O(num_of_moved) time complexity on a single call of .insert() method,
  // Method .push_back() works in O(1), because of it.
  // It works the same way with .erase() and .pop_back() methods.
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

/* Common methods and their time complexities:
.find(elem)       | Gets an iterator to an element equal to elem                   | O(log(n))
.size()           | Number of elements present                                     | O(1)
.empty()          | Whether if container is empty or not                           | O(1)
.erase(elem)      | Remove all elements equal to "elem"                            | O(log(n))
.erase(iter)      | Remove an element pointed by "iter" from structure.            | O(log(n))
                  | If "iter" is equal to .end(), then undefined behavior occurres |
.clear()          | Remove all elements from the container                         | O(n)
.lower_bound(num) | Iterator to the first element >= "num"                         | O(log(n))
.upper_bound(num) | Iterator to the first element > "num"                          | O(log(n))
.begin()          | Iterator to the first element of "arr"                         | O(1)
.end()            | Iterator to the element that comes after the last one          | O(1)
.rbegin()         | Iterator to the last element of structure                      | O(1)
.rend()           | Iterator to the element that comes before the first one        | O(1)
*/

// .count(elem) in set works in O(log(n))
// .count(elem) in multiset works in O(max(log(n), n))
// .insert(elem) adds element to set/multiset O(log(n))
// map [] brackets work in O(log(n))
