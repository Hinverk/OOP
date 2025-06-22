#include <cmath>
#include <cstring> // memset
#include <ctime>
#include <vector>

#include "header.cpp"
#include "header.hpp"

// given
class Solution1 {
  int arr[20001];
  bool canPartition(vector<int> nums) {
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; i++)
      total += nums[i];
    if (total % 2)
      return 0;
    for (int i = 0; i <= total / 2; i++)
      arr[i] = 0;
    arr[0] = 1;
    for (int i = 0; i < n; i++)
      for (int j = total / 2; j >= nums[i]; j--)
        if (arr[j - nums[i]])
          arr[j] = 1;
    return arr[total / 2];
  }
};

////////////////////////////// Main Function //////////////////////////////
int main(int argc, char *argv[]) {
  fastIO();

  return 0;
}
