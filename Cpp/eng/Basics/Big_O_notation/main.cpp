// Includes all the libraries there is in c++ standard library:
#include <bits/stdc++.h>
// This is just a file in "bits" directory that has many-many other includes.
// You can check it out yourself by following this link:
// https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h
// In order to use this with Visual studio, go to
// visual studio -> VS edition -> VC -> tools -> MSVC -> ver -> include
// Create a folder named "bits" and place stdc++.h file here.

using namespace std;

// A function in mathimatics is a dependency of one variable of the other.
// y = f(x) = k*x + b
// You can say that a function is a mapping of one values into others.

// A function in programming is a callable block of code.
// In the contrast to mathimatics, a function in programming
// does not have to return anything.
// Such functions are sometimes called procedures.

// Functions have the following usage:
// 1. Reuse written code multiple times;
// 2. Decompose the program (break it into logically completed parts);
// 3. Use code that is already written for you like sort() function.

// You can declare your own functions as follows:
// returning_data_type function_name(arguments) {**code**}
// Arguments is a list of variablse that function needs to run.
// Different functions have either different names or argument types.
// Returning data type does not tell compiler that functions are different
// if the names and the argument lists are the same in those functions.

int square(int x) {
  int res = x * x;
  return res;
}

// There is a special data type "void"
// It suggests that the function does not return anything.
// In fact it literally does return nothing.
void print(string something) {
  cout << something << endl;
  // You may use return statement if you want.
  // return;
}

// Asymptotics, complexity, "big O" of something is a function of "something",
// that depends on size of input, that is not less than "something" if it's
// multiplied by a constant factor. Usually they trying to find the
// smallest such function.
// O(n^2) time complexity means that the time algorithm spends working
// is not greater than n^2, multiplied by a constant factor.

// Time complexity is proportional to the number of iterations that our
// program does. If we calculate asymptotics of the number of iterations,
// then we will be able to estimate the time complexity of an algorithm.
// We consider all simple operations to be constant in time.
// Such operations are addition, multiplication, getting a value by its index.
// dereferencing and so on.

// Thit means that in order to calculate asymptotics, we need to:
// 1. Calculate total number of iterations;
//    (in whole program, in a function or in a block of code);
// 2. Break into terms like this; (n*(n-1)/2 = n*n/2 - n/2)
// 3. Choose the biggest term; (n^2 > n)
// 4. Remove all constant factors. (n^2/2 = n^2,
//    n^2 = n^2, because 2 is a notation and not a constant)
// O(n*(n-1)/2) = O(n*n/2 - n/2) = O(n*n/2) = O(n*n) = O(n^2)

// To know ahead if your solution will pass on time, pick the biggest
// numbers from the input and substitute what you have in O(..).
// 3*10^7 fits in one second and 6*10^7 fits in two in C++.
// O(n^2), n = 2*10^5;
// (2*10^5)^2 = 4*10^10.

// Usually when peolpe study asymptotics, they are shown multiple
// sorting algorithms, so they get the idea of how to calculate it.
void bubble_sort(vector<int> &arr) {
  // '&' symbol shows that we get the value "by reference" and are
  // going to work with the variable from outer scope.
  // If we don't use this symbol, then the program will first
  // create a new variable and store a copy of what is given there.
  // So you will end up working with a copy. In this case they say
  // that we get the variable "by value".

  // Explicit cast to int type, becase .size() returns unsigned long long.
  int n = (int)arr.size();

  // The first cycle does n iterations.
  for (int i = 0; i < n; ++i) { // [0, n)
    // The second one always does n - 1 iterations
    // for each iteration of outer cycle.
    for (int j = 1; j < n; ++j) { // [1, n)
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // One cycle is nested into other and is independent of it,
  // so we can just multiply their number of iterations.
  // O(n * (n - 1)) = O(n^2 - n) = O(n^2)

  // Time complexity is O(n^2)
  // Space complexity is O(1)

  // Because we didn't use any additional space in proportion to n.
}

void fast_bubble_sort(vector<int> &arr) {
  int n = (int)arr.size();

  // The first cycle does n - 1 iterations.
  for (int i = 0; i < n - 1; ++i) {
    // The second one does n-1, n-2, ..., 2, 1 iterations.
    for (int j = 1; j < (n - i); ++j) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // We need to calculate the cumulative number of iterations:
  // (n - 1) + (n - 2) + ... + 2 + 1
  // 1 + 2 + ... + (n - 2) + (n - 1)
  // This is arithmetic progression.

  // Arithmetic progression is a sequence of numbers where difference between
  // two any consecutive terms is constant and equal to d.

  // The first element is 1. The last one is (n - 1).
  // Their sum is 1 + (n - 1) = n.
  // If we increase the first element by d=1, and decrease the last one by d=1,
  // then the sum won't change. 'd=1' is difference between two consecutive terms.
  // We repeat this process as many times, as there temrs in the sequence.
  // But each term is counted twice, so we should divide it by 2 and get:
  // sum = (first + last) * number_of_terms / 2
  // In our case:
  // (1 + (n-1)) * (n-1) / 2 = n * (n-1) / 2
  // O(n * (n-1) / 2) = O(n^2)

  // Time complexity is O(n^2)
  // Space complexity is O(1)
}

void bogo_sort(vector<int> &arr) {
  int n = (int)arr.size();
  // Consider array is not sorted
  bool sorted = false;
  while (!sorted) {
    // There are n! = n * (n-1) * (n-2) * ... * 2 * 1 possible permutations
    // of array of size n.

    // First, we shuffle the array
    for (int i = n - 1; i > 0; --i) {
      // rand() function returns a random value between [0, RAND_MAX]
      // RAND_MAX is hardware dependent.
      // You should not use this function for generating random numbers.
      // This is just an example.

      int j = rand() % i;
      swap(arr[i], arr[j]);
    }
    sorted = true;
    // Check if the array is sorted now
    for (int i = 1; i < n; ++i) {
      if (arr[i] > arr[i - 1]) {
        sorted = false;
      }
    }
  }
  // There are n! possible permutations and for each of those
  // permutations (big O consideres the worst case) we shuffle and
  // check for being sorted. Assuming each time we get a different array,
  // which is not true in general, total number of iterations is:
  // n! * ((n-1) + (n-1)) = n! * 2(n-1)
  // O(n! * 2(n-1)) = O(n! * n)

  // Time complexity is O(n! * n)
  // Space complexity is O(1)
}

// Recursive function is a function that calls itself.
// This is a helper function, because its signature (argument list)
// is different from the others.
vector<int> merge(vector<int> &arr, int start, int finish) {
  vector<int> res;
  if (finish - start == 1) {
    // If there is a single element:
    res.push_back(arr[start]);
    return res;
  }
  // Middle of [start, finish):
  int mid = start + (finish - start) / 2;
  // Sort left and right parts recursively
  vector<int> left = merge(arr, start, mid);
  vector<int> right = merge(arr, mid, finish);
  // "left" and "right" are sorted now.
  // p1 is a pointer to the left part.
  // p2 is a pointer to the right part.
  int p1 = 0, p2 = 0;
  // Explicit cast
  int n_left = (int)left.size();
  int n_right = (int)right.size();
  // While there are elements in both parts:
  while (p1 < n_left && p2 < n_right) {
    // We add the lesser of them.
    if (left[p1] <= right[p2]) {
      res.push_back(left[p1]);
      ++p1;
    } else {
      res.push_back(right[p2]);
      ++p2;
    }
  }
  // If there are elements remaining in the left part:
  while (p1 < n_left) {
    res.push_back(left[p1]);
    ++p1;
  }
  // Or in the right part:
  while (p2 < n_right) {
    res.push_back(right[p2]);
    ++p2;
  }
  // On each recursion step the number of elements remaining decreases
  // by a factor of 2. If initial depth is 0, then at depth k the length is
  // equal to n / 2^k
  // When only one element will remain the recursion will stop.
  // n / 2^k = 1
  // n = 2^k
  // log_2(n) = k
  // k = log_2(n)
  // That is the recursion depth does not exeed log_2(n)
  // At each recursion depth no elements are lost or gained.
  // That means that at each layer there are exactly n elements.
  // Merge operation is linear, because it looks through each element only once.
  // Therefore, we can just multiply n by log_2(n)

  // Time complexity is O(n*log(n))
  // Space complexity is O(n*log(n))

  // We do not specify logarithm base in big O, because we can transition
  // to any base using this formula:
  // log_b(n) = log_c(n) / log_c(b)
  // log_c(b) is a constant, so we can get rid of it. That means, we
  // can put any base we want and that will not contradict our definition
  // of big O. This is why we don't write any base in logarithm when using big O.

  // Because we need to save all intermediate merge results, our implementation
  // of merge sort takes O(n*log(n)) additional memory. There is an implementation,
  // which uses no more than O(n) additional memory.
  return res;
}

// This is a function with proper argument list:
void merge_sort(vector<int> &arr) {
  arr = merge(arr, 0, (int)arr.size());
}

void count_sort(vector<int> &arr) {
  // This is not exactly a sorting algorithm, because it uses the
  // fact that it given nonnegative integer numbers.
  int max = *max_element(arr.begin(), arr.end());
  // Just declare an array
  vector<int> counts(max + 1, 0);
  // Count how many times each number occures
  for (int i = 0; i < (int)arr.size(); ++i) {
    ++counts[arr[i]];
  }
  arr.clear();
  // For each element there could be
  for (int i = 0; i <= max; ++i) {
    // We add it as many times, as we have counted it previously
    for (int j = 0; j < counts[i]; ++j) {
      arr.push_back(i);
    }
  }
  // The nested cycle does n iteration through all iterations of the outer one.
  // Time complexity is O(n + max_element) = O(max(n, max_element))
  // Space complexity is O(max_element)
}

// This is just an example on how to calculate complexities. If you need a sorting
// function, you most likely need to use the standard one:
// sort(arr.begin(), arr.end());
// GCC compiler uses Introsort, which is a mix of quicksort and heapsort
// Time complexity is O(n*log(n))
// Space complexity is O(log(n)) due to recursive nature of quicksort
// https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_algo.h#L1948
// https://en.wikipedia.org/wiki/Introsort

// Big O relations:
// 1 < log < log^2 < sqrt < n < n*log < n*log^2 < n*sqrt(n) < n^2 < 2^n < n! < n^n

void static_count_sort(vector<int> &arr) {
  // Static variable remains after the function is finished.
  // So on the next call this array will remain the same as it was the last time.
  static vector<int> counts;
  int max = *max_element(arr.begin(), arr.end());
  counts.resize(max + 1);
  for (int i = 0; i < (int)arr.size(); ++i) {
    ++counts[arr[i]];
  }
  arr.clear();
  for (int i = 0; i <= max; ++i) {
    for (int j = 0; j < counts[i]; ++j) {
      arr.push_back(i);
    }
    // Don't forget to "clear" the "counts" array:
    counts[i] = 0;
  }
  // Big O is the same as in regular count_sort.
}

// Don't pay too much attention. Just generating a random permutation.
vector<int> get_random_array(int size, mt19937 rngesus) {
  vector<int> res(size);
  iota(res.begin(), res.end(), 0);
  shuffle(res.begin(), res.end(), rngesus);
  return res;
}

// You can pass a function as an argument and use
// auto instead of it's type and nothing will break.
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

  // ' <= this is a delimiter for numbers from C++14 an onwards.
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
Hardware specifications:
Linux userpc 5.13.0-39-generic #44~20.04.1-Ubuntu SMP Thu Mar 24 16:43:35 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
Intel(R) Core(TM) i5-3450 CPU @ 3.10GHz

Compiler specifications:
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
-O2 -fconcepts

Results:

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
