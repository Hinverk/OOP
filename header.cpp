#include "header.hpp"

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void arr_sort(int n) {
  // example of input processing
  // putting n inputs into arr(n)
  cout << "insert inputs array :" << endl;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  debug(arr);

  // sortion
  sort(arr.begin(), arr.end());

  cout << "sorted : " << endl;
  debug(arr);
  for (int x : arr)
    cout << x << ' ';
}
