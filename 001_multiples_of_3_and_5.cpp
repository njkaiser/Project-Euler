// Multiples of 3 and 5
// Problem 1

// If we list all the natural numbers below 10 that are
// multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of
// these multiples is 23.

// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include <set>

int main ()
{
  int N = 1000;
  int n1 = 3;
  int n2 = 5;

  std::set<int> myset;

  for(int i = n1; i < N; i += n1)
  {
    std::cout << "Inserting: " << i << std::endl;
    myset.insert(i);
  }

  for(int i = n2; i < N; i += n2)
  {
    if(i % n1)
    {
      std::cout << "Inserting: " << i << std::endl;
      myset.insert(i);
    }
    else
    {
      std::cout << "Value " << i << " already in set." << std::endl;
    }
  }

  long long sum = 0;
  std::set<int>::iterator it;
  for(it = myset.begin(); it != myset.end(); ++it)
  {
    sum += *it;
  }

  std::cout << sum << std::endl;

  return 0;
}
