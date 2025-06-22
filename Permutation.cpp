#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <tuple> // make_tuple, tie
#include <vector>

#include "header.cpp"
#include "header.hpp"

class Solution1 {
public:
  int count = 0, used[10];
  char str[10];

  int perm(int n, int k, int i) {
    if (i == n) {
      count++;
      if (count == k)
        return 1;
      return 0;
    }
    // we are filling str[i]
    for (int j = 1; j <= n; j++) {
      if (!used[j]) {
        used[j] = 1; // mark j used
        str[i] = j + '0';
        int ret = perm(n, k, i + 1);
        if (ret)
          return 1;
        used[j] = 0; // unmark j }
      }
    }
    return 0;
  }

  char *getPermutation(int n, int k) {
    for (int i = 1; i <= n; i++)
      used[i] = 0;
    count = 0;
    perm(n, k, 0);
    str[n] = 0;
    return str;
  }
};

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> nums;
    for (int i = 1; i <= n; i++)
      nums.push_back(i);

    int fact = 1;
    for (int i = 2; i < n; i++)
      fact *= i; // (n-1)!

    k--; // 0-indexed
    string res;

    while (!nums.empty()) {
      int idx = k / fact;
      res += to_string(nums[idx]);
      nums.erase(nums.begin() + idx);
      if (nums.empty())
        break;

      k %= fact;
      fact /= nums.size(); // 다음 자리수 기준 갱신
    }

    return res;
  }
};

////////////////////////////// Main Function //////////////////////////////
int main(int argc, char *argv[]) {
  fastIO();

  return 0;
}
