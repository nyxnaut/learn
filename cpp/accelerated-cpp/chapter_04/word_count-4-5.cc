#include "read_words-4-5.h"

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

int main() {
	vector<string> words;
	read_words(cin, words);

	cout << "Number of words: " << words.size() << endl;
	return 0;
}
