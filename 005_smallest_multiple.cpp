// Smallest multiple
// Problem 5

// 2520 is the smallest number that can be divided by each of the numbers
// from 1 to 10 without any remainder.

// What is the smallest positive number that is evenly divisible by all
// of the numbers from 1 to 20?

#include <iostream>

int main()
{
  int n = 20;
  long long smallest = 116396280; // MUST be even for code to work
                                  // this is 2520 * all primes from 10 to 20
  long long max = 999999999;

  while(1)
  {
    for(int i = n; i >= 3; --i) // can stop at 3 since we only test evens
    {
      if(smallest % i)
      {
        break;
      }
      else
      {
        if(i == 3)
        {
          std::cout << "Smallest number is " << smallest << std::endl;
          return 0;
        }
      }
    }
    if(smallest > max)
    {
      std::cout << "No number found less than max iteration value of " << max << std::endl;
    }
    smallest += 2; // must be an even number, no point in incrementing by 1
  }
}
