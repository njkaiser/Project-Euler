// Permuted multiples
// Problem 52

// It can be seen that the number, 125874, and its double,
// 251748, contain exactly the same digits, but in a
// different order.

// Find the smallest positive integer, x, such that 2x, 3x,
// 4x, 5x, and 6x, contain the same digits.

#include <iostream>
#include <vector>
#include <algorithm> // std::sort
#include <cmath> // log10

int main ()
{
  long long num = 10; //single digit numbers won't work, so start at 10
  long long prefix_max = 17; // 10/6 = 16.666, so anything that starts with 17 or greater will contain 1 more digit than the orig number and won't work
  long long prefix_counter = 1;
  long long answer;

  std::vector<int> vec1;
  std::vector<int> vec2(6, 0);
  std::vector<int> vec3(6, 0);
  std::vector<int> vec4(6, 0);
  std::vector<int> vec5(6, 0);
  std::vector<int> vec6(6, 0);

  while(1)
  {
    for(int i = num; i < prefix_max * prefix_counter; ++i)
    {
      // std::cout << i << ' ';
      int digits = log10(static_cast<double>(num));
      int tmp = i;
      for(int w = 0; w <= digits; ++w)
      {
        vec1.push_back(tmp % 10);
        // std::cout << tmp % 10 << ' ';
        tmp /= 10;
      }
      // std::cout << std::endl;

      tmp = 2 * i;
      for(int w = 0; w <= digits; ++w)
      {
        vec2.push_back(tmp % 10);
        // std::cout << tmp % 10 << ' ';
        tmp /= 10;
      }
      // std::cout << std::endl;

      tmp = 3 * i;
      for(int w = 0; w <= digits; ++w)
      {
        vec3.push_back(tmp % 10);
        // std::cout << tmp % 10 << ' ';
        tmp /= 10;
      }
      // std::cout << std::endl;

      tmp = 4 * i;
      for(int w = 0; w <= digits; ++w)
      {
        vec4.push_back(tmp % 10);
        // std::cout << tmp % 10 << ' ';
        tmp /= 10;
      }
      // std::cout << std::endl;

      tmp = 5 * i;
      for(int w = 0; w <= digits; ++w)
      {
        vec5.push_back(tmp % 10);
        // std::cout << tmp % 10 << ' ';
        tmp /= 10;
      }
      // std::cout << std::endl;

      tmp = 6 * i;
      for(int w = 0; w <= digits; ++w)
      {
        vec6.push_back(tmp % 10);
        // std::cout << tmp % 10 << ' ';
        tmp /= 10;
      }
      // std::cout << std::endl;

      std::sort(vec1.begin(), vec1.end());
      std::sort(vec2.begin(), vec2.end());
      std::sort(vec3.begin(), vec3.end());
      std::sort(vec4.begin(), vec4.end());
      std::sort(vec5.begin(), vec5.end());
      std::sort(vec6.begin(), vec6.end());

      if(vec1 == vec2)
        if(vec2 == vec3)
          if(vec3 == vec4)
            if(vec4 == vec5)
              if(vec5 == vec6)
              {
                // WTF do I do here?
                answer = i;
                break;
              }
    }
    std::cout << "still working, currently at " << num << std::endl;
    prefix_counter *= 10;
    num *= 10;
    // std::cout << std::endl;
    if(num > 150000)
      break;

    vec1.clear();
    vec2.clear();
    vec3.clear();
    vec4.clear();
    vec5.clear();
    vec6.clear();
  }

  std::cout << answer << std::endl;

  return 0;
}
