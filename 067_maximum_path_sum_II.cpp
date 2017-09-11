// By starting at the top of the triangle below and moving to
// adjacent numbers on the row below, the maximum total from
// top to bottom is 23.
//
// 3
// 7 4
// 2 4 6
// 8 5 9 3
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom in triangle.txt (right
// click and 'Save Link/Target As...'), a 15K text file containing a
// triangle with one-hundred rows.
//
// NOTE: This is a much more difficult version of Problem 18. It is
// not possible to try every route to solve this problem, as there
// are 299 altogether! If you could check one trillion (1012) routes
// every second it would take over twenty billion years to check
// them all. There is an efficient algorithm to solve it. ;o)


#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h> // exit()

using namespace std;


void init_triangle(vector<vector<int> > &triangle);
void print_triangle(const vector<vector<int> > &triangle);


int main(int argc, char const *argv[])
{
  // create triangle
  vector<vector<int> > triangle;
  init_triangle(triangle);
  print_triangle(triangle);

  // now do stuff to it
  for(int i = triangle.size() - 2; i >= 0; --i) {
    for(int j = 0; j <= i; ++j) {
      int m = max(triangle[i+1][j], triangle[i+1][j+1]);
      // cout << "[" << i << "][" << j << "] (val = " << triangle[i][j] << "): " << m << endl;
      triangle[i][j] += m;
    }
  }

  print_triangle(triangle);
  cout << "MAXIMUM PATH VALUE IS " << triangle[0][0] << endl;
  return 0;
}



void init_triangle(vector<vector<int> > &triangle) {
  // set up triangle size
  int size = 100;
  triangle.resize(size);

  // open file
  ifstream f;
  f.open("067_triangle.txt");
  if(!f) {
    cerr << "Unable to open file datafile.txt" << endl;
    exit(1);
  }

  // pack file contents into triangle
  int x;
  int i = 0, j = 0;
  while(f >> x) {
    triangle[i].push_back(x);
    if(j == i) {
      j = 0; // reset j to 0
      i++; // next row
    }
    else {
      j++; // next column
    }
  }
  cout << endl;

  // clean up
  f.close();
}


void print_triangle(const vector<vector<int> > &triangle) {
  for(int i = 0; i < triangle.size(); ++i) {
    for(int j = 0; j <= i; ++j) {
      cout << triangle[i][j] << ", " ;
    }
    cout << endl;
  }
}
