// I feel like I'm missing something. I don't see the benefit of 'a function
// that reads words from an input stream and stores them in a vector' for this
// problem. Is that the point? That external functions are not always helpful?

#include <iostream>
#include <string>
#include <vector>

#include "read_words-4-5.cc"

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;
typedef vector<string>::size_type vec_sz;

int main() {
	vector<string> words;
	read_words(cin, words);

	vector<string> unique_words;
	vector<vec_sz> frequency;

	for(auto& word : words) {
		bool shouldGrow = true;
		for(vec_sz i = 0; i < unique_words.size(); i++) {
			if(unique_words[i] == word) {
				frequency[i]++;
				shouldGrow = false;
				break;
			}
		}
		if (shouldGrow) {
			unique_words.push_back(word);
			frequency.push_back(1);
		}
	}
	for(vec_sz i = 0; i < unique_words.size(); i++)
		cout << unique_words[i] << " " << frequency[i] << endl;
}
