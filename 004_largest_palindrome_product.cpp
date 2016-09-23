// Largest palindrome product
// Problem 4

// A palindromic number reads the same both ways. The largest
// palindrome made from the product of two 2-digit numbers is
// 9009 = 91 × 99.

// Find the largest palindrome made from the product of two
// 3-digit numbers.

#include <iostream>
#include <vector>
#include <cmath>


int main()
{
  // int n1 = 999;
  // int n2 = 999;

  for(int n1 = 999; n1 > 900; --n1) // guessing I'll be able to find something
  {                                 // in the range 900-999 - if not, adjust

    for(int n2 = 999; n2 > 900; --n2)
    {
      int product = n1 * n2;
      int num_digits = log10(product);

      int* digits = new int[num_digits];
      int temp = product;
      for(int j = num_digits; j >= 0; --j)
      {
        digits[j] = temp % 10;
        temp /= 10;
        // std::cout << digits[num_digits] << ' ';
      }
      // std::cout << std::endl;
      for(int i = 0; i <= (num_digits / 2); ++i)
      {
        // std::cout << "got here";
        if(digits[i] != digits[num_digits - i])
        {
          // std::cout << "for product " << product << " digit " << digits[i]
                    // << " is not equal to " << digits[num_digits - i] << std::endl;
          break;
        }
        if(i >= (num_digits / 2))
        {
          std::cout << product << "\t(" << n1 << " x " << n2 << ")" << std::endl;
          return 0;
        }
      }

      delete[] digits;
    }
  }
}
