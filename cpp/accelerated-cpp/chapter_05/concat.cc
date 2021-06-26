#include "concat.h"

#include <vector>
#include <string>

#include "max_width.h"

using std::vector;
using std::string;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
  // copy all of top into ret
  vector<string> ret = top;

  // append bottom to the end of ret
  //  Equivalent to:
  //  for(vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter) {
  //    ret.push_back(*iter);
  //  }
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
  vector<string> ret;
  string::size_type width1 = max_width(left) + 1;
  vector<string>::size_type i = 0, j = 0;

  while(i != left.size() || j != right.size()) {
    string s;
    if (i != left.size())
      s = left[i++];
    s += string(width1 - s.size(), ' ');

    if (j != right.size())
      s = right[j++];

    ret.push_back(s);
  }

  return ret;
}
