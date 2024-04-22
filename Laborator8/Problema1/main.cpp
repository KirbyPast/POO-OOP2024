#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
using namespace std;
ifstream fin("input.in");


class Compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second) {
			return true;
		}
		else if (p1.second > p2.second) {
			return false;
		}
		else return p1.first > p2.first;
	}
};

int main() {
	string prop;
	string word;
	map<string, int> map_freq;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare > queue;

	getline(fin, prop);
	word.clear();
	for (int i = 0; i < prop.size(); i++) {
		if (prop[i] == ' ' || prop[i] == ',' || prop[i] == '?' || prop[i] == '!' || prop[i] == '.') {
			if (word.empty() == false) {
				for (int j = 0; j < word.size(); j++) {
					word[j] = tolower(word[j]);
				}
				map_freq[word]++;
				word.clear();
			}
		}
		else {
			word += prop[i];
		}
	}

	if (!word.empty()) {
		for (int j = 0; j < word.size(); j++) {
			word[j] = tolower(word[j]);
		}
		map_freq[word]++;
		word.clear();
	}

	map<string, int>::iterator it;
	for (it = map_freq.begin(); it != map_freq.end(); it++) {
		queue.push(make_pair(it->first, it->second));
	}

	while (!queue.empty()) {
		printf("%s => %d \n", queue.top().first.c_str(), queue.top().second);
		queue.pop();
	}
	return 0;
}