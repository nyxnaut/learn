#include "concat.h"

#include <vector>
#include <string>

#include "max_width.h"

using std::vector;
using std::string;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
  vector<string> ret = top;
  for(vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter) {
    ret.push_back(*iter);
  }
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
