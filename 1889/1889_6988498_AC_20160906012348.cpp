#include <iostream>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <hash_map>
#include <vector>
#include <string>
using namespace std;
hash_map<string, int> dict;
vector<int> num, mark;
int main() {
	int n, unknown = -2;
	bool ok = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		hash_map<string, int>::iterator it = dict.find(str);
		if (it == dict.end()) {
			if (str == "unknown")unknown = dict.size();
			num.push_back(dict.size());
			dict.insert(pair<string, int>(str, dict.size()));
			mark.push_back(0);
		}
		else {
			num.push_back(it->second);
		}
	}
	for (int i = n; i >= 1; i--) {
		if (n%i != 0)continue;
		for (int j = 0; j < n; j += i) {
			int lang = -1;
			for (int k = 0; k < i; k++) {
				if (num[j + k] == unknown)continue;
				if (lang == -1)lang = num[j + k];
				else if (lang != num[j + k]) goto nxt;
			}
			if (lang == -1)continue;
			if (mark[lang] == i)goto nxt;
			mark[lang] = i;
		}
		cout << n / i << " ";
		ok = true;
	nxt:;
	}
	if (!ok)cout << "Igor is wrong." << endl;
	return 0;
}
