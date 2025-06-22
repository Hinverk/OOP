// https://leetcode.com/problems/perfect-squares/description/
// 279. Perfect Square

// Given an integer n, return the least number of perfect square vnumbers that
// sum to n.
// A perfect square is an integer that is the square of an integer; in other
// words, it is the product of some integer with itself. For example, 1, 4, 9,
// and 16 are perfect squares while 3 and 11 are not.

// Example 1:
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

// Example 2:
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

// Constraints: 1 <= n <= 104

#include <cmath>
#include <cstring> // memset
#include <ctime>

#include "header.cpp"
#include "header.hpp"

class Solution1 {
public:
  int arr[10001];
  int numSquares(int n) {
    arr[0] = 0;
    // Actually, you can reuse the array already filled. // But let's recompute
    // everything for simplicity.
    for (int i = 1; i <= n; i++)
      arr[i] = n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; i - j * j >= 0; j++)
        if (arr[i - j * j] + 1 < arr[i])
          arr[i] = arr[i - j * j] + 1;
    return arr[n];
  }
};

////////////////////////////// Main Function //////////////////////////////
int main(int argc, char *argv[]) {
  fastIO();

  return 0;
}
