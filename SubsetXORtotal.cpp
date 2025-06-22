// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

// 1863. Sum of All Subset XOR Totals

// The XOR total of an array is defined as the bitwise XOR of all its elements,
// or 0 if the array is empty.
// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of
// nums.
// Note: Subsets with the same elements should be counted multiple times.
// An array a is a subset of an array b if a can be obtained from b by deleting
// some (possibly zero) elements of b.

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

// OR (Given)
class Solution1 {
public:
  int subsetXORSum(vector<int> &nums) {
    int ans = 0;
    int numsSize = nums.size();
    for (int i = 0; i < numsSize; i++)
      ans |= nums[i];
    return ans << (numsSize - 1);
  }
};

class Solution2 {
public:
  int generate_subset(vector<int> nums, int numsSize, int i, int currentTotal) {
    if (i == numsSize)
      return currentTotal;
    // include nums[i]
    int total1 = generate_subset(nums, numsSize, i + 1, currentTotal ^ nums[i]);
    // exclude nums[i]
    int total2 = generate_subset(nums, numsSize, i + 1, currentTotal);
    return total1 + total2;
  }
  int subsetXORSum(vector<int> nums) {
    int numsSize = nums.size();
    return generate_subset(nums, numsSize, 0, 0);
  }
};

// Top-Down DP
class Solution3 {
public:
  int dp[21][1 << 13]; // 0 ≤ currentXor < 8192, 0 ≤ index < 21

  int dfs(vector<int> &nums, int index, int currentXor) {
    if (index == nums.size())
      return currentXor;
    if (dp[index][currentXor] != -1)
      return dp[index][currentXor];

    int include = dfs(nums, index + 1, currentXor ^ nums[index]);
    int exclude = dfs(nums, index + 1, currentXor);

    return dp[index][currentXor] = include + exclude;
  }

  int subsetXORSum(vector<int> &nums) {
    memset(dp, -1, sizeof(dp));
    return dfs(nums, 0, 0);
  }
};

////////////////////////////// Main Function //////////////////////////////
int main(int argc, char *argv[]) {
  fastIO();

  // int n;
  // cin >> n;
  // debug(n);

  // arr_sort(n);

  vector<int> nums = {1, 2, 3, 4, 5};

  Solution1 Solution1;
  Solution1.subsetXORSum(nums);
  return 0;
}
