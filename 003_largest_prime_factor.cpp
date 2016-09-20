// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <set>

using namespace std;

int main()
{
  long long N = 600851475143;
  set<long long> factors;

  for (long long i = 2; i <= N; i++)
  {
    while(1)
    {
      if(!(N % i))
      {
        N /= i;
        factors.insert(i);
      }
      else
        break;
    }
  }

  // print out all factors of N
  /*
  set<long long>::iterator it;
  for(it = factors.begin(); it != factors.end(); ++it)
  {
    cout << *it << endl;
  }
  */

  // print out largest factor of N
  cout << *(factors.rbegin()) << endl;

  return 0;
}
