// A Sample Knapsack Problem
// http://www.lindo.com/doc/online_help/lingo15_0/a_sample_knapsack_problem.htm
//
// As an example, suppose you are planning a picnic. You've constructed a list of
// items you would like to carry with you on the picnic. Each item has a weight
// associated with it and your knapsack is limited to carrying no more than 15
// pounds. You have also come up with a 1 to 10 rating for each item, which
// indicates how strongly you want to include the particular item in the knapsack
// for the picnic. This information is listed in the table below.
//
// Item            Weight  Rating
// Ant Repellent   1       2
// Beer            3       9
// Blanket         4       3
// Bratwurst       3       8
// Brownies        3       10
// Frisbee         1       6
// Salad           5       4
// Watermelon      10      10

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
  string name;
  int weight;
  int value;
  Item(string n, int w, int v) : name(n), weight(w), value(v) { ; }
  void print() { cout << name << ", weight: " << weight << ", value: " << value << endl; }
};


int main(int argc, char** argv)
{
  // set up data:
  vector<string> names {"Ant Repellent", "Beer", "Blanket", "Bratwurst", "Brownies", "Frisbee", "Salad", "Watermelon"};
  vector<int> weights {1, 3, 4, 3, 3, 1, 5, 10};
  vector<int> values {2, 9, 3, 8, 10, 6, 4, 10};
  vector<Item> items;
  for(int i = 0; i < names.size(); ++i) {
    items.push_back(Item(names[i], weights[i], values[i]));
    items[i].print();
  }

  // initialize matrix:
  int knapsack_capacity = 15;
  vector< vector<int> > dp(items.size(), vector<int>(knapsack_capacity, 0));

  // DP time:
  for(int m = 0; m < dp.size(); ++m) {
    for(int n = 0; n < dp[0].size(); ++n) {
      if((items[m].weight > n+1) && (m-1 >= 0)) {
        dp[m][n] = dp[m-1][n];
      }
      else {
        int upcost = 0;
        int dpcost = 0;
        if(m-1 >= 0) {
          upcost = dp[m-1][n];
          if(n-items[m].weight >= 0) { dpcost = dp[m-1][n-items[m].weight]; }
        }
        dp[m][n] = max(upcost, dpcost+items[m].value);
      }
    }
  }

  // print out full matrix:
  cout << "\nAFTER:" << endl;
  for(int m = 0; m < dp.size(); ++m) {
    for(int n = 0; n < dp[0].size(); ++n) {
      cout << dp[m][n] << ", ";
    }
    cout << endl;
  }

  cout << "FINAL ANSWER: " << dp.back().back() << endl;
  return 0;
}
