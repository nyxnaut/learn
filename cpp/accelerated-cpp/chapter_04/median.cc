#include "median.h"

#include <stdexcept>
#include <vector>
#include <algorithm>

using std::domain_error;
using std::vector;
using std::sort;

// calling this function copies the entire vector and attempts to sort the copy
// even if sorted
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}
