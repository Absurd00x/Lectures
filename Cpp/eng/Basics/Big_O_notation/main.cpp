// Includes all the libraries there is in c++ standard library
#include <bits/stdc++.h>
// This is just a file in bits directory that has many-many other includes
// You can check it out yourself by following this link:
// https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h
// In order to use this with Visual studio, go to
// visual studio -> VS edition -> VC -> tools -> MSVC -> ver -> include
// create a folder named "bits" and place stdc++.h file here

using namespace std;

// A function in mathimatics is a dependency of one variable of the other.
// y = f(x) = k*x + b
// You can say that a function is a mapping of one values into others.

// A function in programming is a callable block of code.
// In the contrast to mathimatics, a function in programming
// does not have to return anything.
// Such functions are called procedures.

// Functions have the following usage:
// 1. Reuse written code multiple times;
// 2. Decompose the program;
// 3. Use code that is already written for you like sort() function.

// You can declare your own functions as follows:
// returning_data_type function_name(arguments) {**code**}
// Arguments is a list of variablse that function needs to run.
// Different functions have either different names or argument types.
// But returning data type does not tell the compiler that functions
// are different (if name and argument list is the same)

int square(int x) {
  int res = x * x;
  return res;
}

// There is a special data type "void"
// It suggests that the function does not return anything.
// In fact it does return nothing.
void print(string something) {
  cout << something << endl;
  // You may use return statement if you want.
  // return;
}

// Asymptotics of something means how much does this something change if
// the input volume changes. This definition is neither formal, nor absolutely
// correct, but it captures the main idea.
// O(n^2) time complexity means that the time algorithm consumes is proportional
// to n^2. If n gets 10 times bigger, then the time needed for algorithm to
// finish will increase 100 times.

// Time complexity is proportional to the number of iterations a
// program does. So if we calculate number of iterations depending on the
// size of input, we will be able to estimate our program's time complexity.
// In order to calculate time complexity we need to:
// 1. Calculate the number of iterations proportionally to the input size.
// 2. Break down into terms: n*(n-1)/2 = n*n/2 - n/2;
// 3. Pick the biggest term; (n^2 > n)
// 4. Remove the constants. (10*n = n, n^2 = n^2, 2 is notation and not a value)
// Example:
// O(n*(n-1)/2) = O(n*n/2 - n/2) = O(n*n/2) = O(n*n) = O(n^2)

// Now on how to use it:
// 1. Replace n with the biggest numbers from the statement.
// Usually n <= 2*10^5.
// O(n^2), n = 2*10^5;
// (2*10^5)^2 = 4*10^10.
// 2. Roughly 3*10^7 fits in one second in c++.
// 6*10^7 fits in two seconds accordingly.
// 3. If it fits, you can implement your code.
// 4. If you are still uncertan, then don't remove constants and
// smaller terms, but it will no longer be "time complexity"
// Usually everyone uses asymptotics or big-O-notation or code complexity.
// This is all the same thing.

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

  // The first cycle does n iterations
  for (int i = 0; i < n; ++i) { // [0, n)
    // The second one always does n - 1 iterations
    // for each iteration of outer cycle.
    for (int j = 1; j < n; ++j) { // [1, n)
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // Two cycles are nested and dependent, so we can just multiply
  // their number of iterations
  // O(n * (n - 1)) = O(n^2 - n) = O(n^2)

  // Time complexity is O(n^2)
  // Space complexity is O(1)

  // Because we didn't use any additional space in proportion to n.
}

void fast_bubble_sort(vector<int> &arr) {
  int n = (int)arr.size();

  // The first cycle does n - 1 iterations
  for (int i = 0; i < n - 1; ++i) {
    // The second one does n-1, n-2, ..., 2, 1 iterations
    for (int j = 1; j < (n - i); ++j) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  // We need to calculate the cumulative number of iterations:
  // (n - 1) + (n - 2) + ... + 2 + 1
  // 1 + 2 + ... + (n - 2) + (n - 1)
  // The first element is 1, the last one is (n - 1)
  // Their sum is 1 + (n - 1) = n.
  // If we increase the first element by d, and decrease the last one by d,
  // then the sum won't change. 'd' is difference between two consecutive terms.
  // We repeat this process n times.
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
  // If there are n! possible permutations and for each of those
  // permutations (big O consideres the worst case) we shuffle and
  // check for being sorted. Assuming each time we get a different array,
  // which is not true in this example, total number of iterations is:
  // n! * ((n-1) + (n-1)) = n! * 2(n-1)
  // O(n! * 2(n - 1)) = O(n! * n)

  // Time complexity is O(n! * n)
  // Space complexity is O(1)
}

// Recursive function is a function that calls itself.
// This is a helper function, because its signature (argument list)
// is different from the others.
vector<int> merge(vector<int> &arr, int start, int finish) {
  vector<int> res;
  if (finish - start == 1) {
    // If there is a single element
    res.push_back(arr[start]);
    return res;
  }
  // Middle of [start, finish)
  int mid = start + (finish - start) / 2;
  // Sort left and right parts recursively
  vector<int> left = merge(arr, start, mid);
  vector<int> right = merge(arr, mid, finish);
  // "left" and "right" are sorted now.
  // p1 is a pointer to the "left"
  // p2 is a pointer to the "right" array
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
  // ...or in the right part:
  while (p2 < n_right) {
    res.push_back(right[p2]);
    ++p2;
  }
  // On each recursion step the number of elements remaining decreases
  // by a factor of 2. If initial depth is 0, then at depth k the length is
  // equal to n / 2^k
  // How many iterations are needed for recurtion to stop? When a single
  // element remains?
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
  return res;
}

// This is a function with proper argument list:
void merge_sort(vector<int> &arr) {
  arr = merge(arr, 0, (int)arr.size());
}

void count_sort(vector<int> &arr) {
  // This function is not exactly a sorting algorithm, because it uses the
  // fact that it given nonnegative integer numbers.
  int max = *max_element(arr.begin(), arr.end());
  // Just declare an array
  vector<int> counts(max + 1, 0);
  // And count how many times each number occures
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

// This is just an example on how to use big O notation. If you need a sorting
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
    // Don't forget to "clear" the "counts" array
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

  // ' <= this is a delimiter for numbers from c++14 an onwards
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
