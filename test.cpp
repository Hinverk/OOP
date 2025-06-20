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
  int maximumScore(vector<int> &nums, int k) {

    int max_i = 0, max_j = k;
    int max_score = -1;
    for (int i = 0; i <= k; i++) {
      for (int j = k; j < nums.size(); j++) {
        int score = *std::min_element(nums.begin() + i, nums.begin() + j + 1) *
                    (j - i + 1);
        if (max_score < score) {
          max_i = i;
          max_j = j;
          max_score = score;
        }
      }
    }
    return max_score;
  }
};

class Solution2 {
public:
  int maximumScore(vector<int> &nums, int k) {
    int numsSize = nums.Size();
    int l = k, r = k;
    int min = nums[k];
    int ans = min;
    while (min > 0) {
      int left_num = (l > 0) ? nums[l - 1] : 0;
      int right_num = (r < numsSize - 1) ? nums[r + 1] : 0;
      if (left_num > right_num) {
        if (min > left_num)
          min = left_num;
        l--;
      } else {
        if (min > right_num)
          min = right_num;
        r++;
      }
      if (min * (r - l + 1) > ans)
        ans = min * (r - l + 1);
    }
    return ans;
  };

  ////////////////////////////// Main Function //////////////////////////////
  int main(int argc, char *argv[]) {
    fastIO();

    // int n;
    // cin >> n;
    // debug(n);

    // arr_sort(n);

    vector<int> nums = {1, 4, 3, 7, 4, 5};
    int k = 3;

    debug(nums.size());
    Solution sol;
    debug(sol.maximumScore(nums, k));

    return 0;
  }
