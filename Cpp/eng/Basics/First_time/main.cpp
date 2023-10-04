// A comments starts with two '/' slash characters
// Comments do not interfere with code
// Plug in input output c++ library
#include <iostream> // input-output stream
// Saying we are going to use standard function's names
using namespace std;

// Starting point of a program
int main() {
  // A variable is like a box which contains something.
  // This box has "data type"
  // Data type tells us of what kind of entity is within the box

  // C++ standard states that:
  // short <= int <= long long

  // Data types are:
  // Integer numbers
  // [-2^15; 2^15)
  short short_integer = 0;
  // [-2^31; 2^31)
  // 2 * 10 ^ 9 fits
  int integer = 0;
  // [-2^63; 2^63)
  // 9 * 10 ^ 18 fits
  long long long_integer = 0;
  // Most of the time you should use long long type

  // Fractional numbers
  // 1.23e-4 = 1.23 * 10^(-4)
  // This kind of writing is called "scientific notation"

  // min stands for a value that is the closest to zero
  // lowest => -3.40282e+38
  // min    => 1.17549e-38
  // max    => 3.40282e+38
  float floating_point_number = 3.14;

  // lowest => -1.79769e+308
  // min    => 2.22507e-308
  // max    => 1.79769e+308
  double double_precision = 3.1415;
  // Use this one

  // lowest => -1.18973e+4932
  // min    => 3.3621e-4932
  // max    => 1.18973e+4932
  long double long_double_precision = 3.1415926535;
  // Or this one
  // Visual c++ compiler thinks it's the same as double

  // [-2^7; 2^7)
  char character = 'a';

  // All mentioned above types may have prefix "signed" or "unsigned",
  // If you don't specify either signed or unsigned, then
  // the compiler thinks it's signed.
  // If you use unsigned, then you will be unable to properly store
  // negative numbers, but will have twice as much space for positives
  // For instance, int values will shift like this:
  // [-2^31; 2^31) => [0, 2^32)

  // [false, true]
  bool boolean = true;
  // Curiously enough, this type takes 1 byte of memory,
  // however it only uses a single bit of it.
  // This happens because a bit does not have an address in memory,
  // where every byte does.

  // If you perform an operation with two different data types, then
  // a type with less precision converts (casts) to a type with higer
  // precision without you participating.
  // Such casts are called implicit, because the compiler does
  // everything on itself using strict rules.
  // There is an exception, however. Any operations with the "char" type
  // will result in "int" type.
  // Signed and unsigned types will be cast to unsigned!

  // If you want to tell the compiler what type you should use, then
  // use explicit casting like this:
  int o = 15;
  long long m = (long long)o;
  // or this:
  double k = double(o);

  string s = "kappa";

  // input/output
  // "cout << something;" - prints something in the console
  // endl prints end-of-line character
  cout << "Hello, World!" << endl;
  // "cin >> somewhere;" - reads something from the console
  cin >> integer;

  // Arithmetic operations are just like in math:
  // Binary (using two operands):
  // '+' '-' '*' '/' '%' - addition, subtraction, multiplication, division
  // and remainder. The only one that is different from regular math is
  // the remainder.
  int one = 9, other = 3;
  cout << "one   = " << one << endl;
  cout << "other = " << other << endl;
  cout << "one + other = " << (one + other) << endl;
  cout << "one - other = " << (one - other) << endl;
  cout << "one * other = " << (one * other) << endl;
  cout << "one / other = " << (one / other) << endl;
  cout << "one % other = " << (one % other) << endl;
  // Unary '-'
  cout << "-one = " << (-one) << endl;
  cout << endl;

  // Logical operations:
  // '&&' '||' - logical И and ИЛИ
  // and   or  - you can just use 'and' and 'or'
  bool student = false;
  bool smart = true;
  cout << "student = " << student << endl;
  cout << "smart   = " << smart << endl;
  cout << "student AND smart = " << (student and smart) << endl;
  cout << "student OR smart = " << (student or smart) << endl;

  // '!' - inversion, logical negation:
  cout << "NOT student = " << (!student) << endl;
  cout << "NOT smart = " << (!smart) << endl;
  cout << endl;

  // Operations of comparison:
  // '<', '>', '<=', '>=', '==', '!=' - are respectively
  // less, greater, less or equal, greater or equal, equal, inequale
  // These operations will always result in the 'bool' type (true/false)
  cout << "one   = " << one << endl;
  cout << "other = " << other << endl;
  cout << "one < other = " << (one < other) << endl;
  cout << "one > other = " << (one > other) << endl;
  cout << "one <= other = " << (one <= other) << endl;
  cout << "one >= other = " << (one >= other) << endl;
  cout << "one == other = " << (one == other) << endl;
  cout << "one != other = " << (one != other) << endl;
  cout << endl;

  // Conditional operation if
  int a = 123, b = 234;
  if (a < b) { // If this is true, then go to curly brackets {}
    a = b;
  } else if (a > b) { // If the first one failed, then check the other one
    b = a;
  } else { // If neither succeeded this executes
    // A block can be empty
  }

  // while cycle
  a = 0, b = 123; // a and b are already declared, no need to type 'int' again
  while (a < b) { // while this condition evaluates as true,
    a += 1; // increase a by 1
    // return to the beginning of the cycle, checking the condition
  }

  // for cycle
  // for (declaration of variables inside the cycle; condition; action after cycle)
  for (int i = 0; i < 123; ++i) {
    // Let i be an integer equal to 0
    // While it is less than 123
    a += a; // add 'a' to itself
    // action after cycle (++i) - increase i by 1
  }

  // Increment
  a = 0;
  // suffix increment
  int c = ++a; // a = 1, c = 1
  // prefix increment
  int d = a++; // d = 1, a = 2
  // chaining operations
  int e = a += 1; // a = 3, e = 3
  c = d = e = a;

  // main should return 0, if the program executed successfully
  return 0;
}
