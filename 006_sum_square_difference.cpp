// Sum square difference
// Problem 6

// The sum of the squares of the first ten natural numbers is,
// 12 + 22 + ... + 102 = 385
//
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)2 = 552 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>

int main()
{
  int n = 100;

  int sumofsquares = 0;
  for(int i = 1; i <= n; ++i)
  {
    sumofsquares += i*i;
  }

  int sums = 0;
  for(int i = 1; i <= n; ++i)
  {
    sums += i;
  }

  int squareofsums;
  squareofsums = sums*sums;

  std::cout << squareofsums - sumofsquares << std::endl;

}
