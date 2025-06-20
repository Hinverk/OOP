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

// Brute force style
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

// Two pointer style (given)
class Solution2 {
public:
  int maximumScore(vector<int> &nums, int k) {
    int numsSize = nums.size();
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
  }
};

// Monotonic stack
class Solution3 {
public:
  int maximumScore(vector<int> &nums, int k) {
    int n = nums.size();
    std::vector<int> left(n, -1);
    std::vector<int> right(n, n);
    std::stack<int> s;

    // 1. right array (Next Smaller Element)
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && nums[s.top()] > nums[i]) {
        right[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }

    // stack flush
    while (!s.empty())
      s.pop();

    // 2. left array (Previous Smaller Element)
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && nums[s.top()] > nums[i]) {
        left[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }

    int max_score = 0;
    // 3. maximum score
    for (int i = 0; i < n; ++i) {
      // check whether subarray which has min value i includes k
      if (left[i] < k && k < right[i]) {
        int width = right[i] - left[i] - 1;
        max_score = std::max(max_score, nums[i] * width);
      }
    }

    return max_score;
  }
};

////////////////////////////// Main Function //////////////////////////////
int main(int argc, char *argv[]) {
  fastIO();

  vector<int> nums = {1, 4, 3, 7, 4, 5};
  int k = 3;

  debug(nums.size());
  Solution1 Solution1;
  Solution2 Solution2;
  Solution3 Solution3;
  debug(Solution1.maximumScore(nums, k));
  debug(Solution2.maximumScore(nums, k));
  debug(Solution3.maximumScore(nums, k));

  return 0;
}
