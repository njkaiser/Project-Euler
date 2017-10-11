#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;


class FibWithMemoization {
public:
  unordered_map< int, int > memotable;

  int fib(int n) {
    if(n <= 0) { return 0; }
    if(n == 1) { return 1; }

    if(memotable.find(n) != memotable.end()) {
      // cout << "n: " << n << " solution found, using memo" << endl;
      return memotable.find(n)->second;
    }
    else {
      // cout << "n: " << n << " solution not found, adding" << endl;
      int f = fib(n-1) + fib(n-2);
      memotable[n] = f;
      return f;
    }
  }
};



int main(int argc, char** argv)
{
  int n = 50;
  FibWithMemoization fwm;

  // int i = 5;
  for(int i = 0; i <= n; ++i) {
    cout << "[" << i << "]: " << fwm.fib(i) << endl;
  }

  return 0;
}
