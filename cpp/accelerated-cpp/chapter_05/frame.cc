#include "frame.h"

#include <vector>
#include <string>

#include "max_width.h"

using std::vector;
using std::string;

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = max_width(v);
	string border(maxlen + 4, '*');

	ret.push_back(border);
	for (string s : v) {
		ret.push_back("* " + s + string(maxlen - s.size(), ' ') + " *");
	}
	ret.push_back(border);
	return ret;
}
