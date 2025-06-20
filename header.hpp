#ifndef HEADER_HPP
#define HEADER_HPP

#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple> // make_tuple, tie
#include <vector>

// Macro for Debugging
#define LOCAL
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

// constant definition
const int INF = 1e9;
const int MOD = 1e9 + 7;

// operator << overloading
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

// IO Optimization
// sync with stdio : true
// cin and cout tied

void fastIO();

// function definition
void arr_sort(int n);

#endif
