#include "max_width.h"

#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::max;

string::size_type max_width(const vector<string>& v) {
	string::size_type width = 0;
	for(string s : v)
		width = max(width, s.size());
	return width;
}
