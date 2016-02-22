#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int size = 4;
char characters[4] = {'A', 'C', 'G', 'T'};

struct node {
	string pattern;
	bool isword;
	bool issuffix;
	int nodes;
	unordered_map <char, node*> map;

	node() { isword = issuffix = false; pattern = ""; nodes = 0; }

	node(string pattern, bool isword, bool issuffix, unordered_map<char, node*> & map, int nodes) {
		this->pattern = pattern;
		this->isword = isword;
		this->issuffix = issuffix;
		this->map = map;
		this->nodes = nodes;
	}

	void insert(string word, int i, bool isword) {
		if (i < word.length()) {
			if (nodes == 0) pattern = word.substr(i, word.length()-i);
			else {
				int j;
				for (j = 0; i < word.length() && j < pattern.length() && word[i] == pattern[j]; i++, j++);
				if (j == pattern.length()) {
					if (i < word.length()) {
						if (!map.count(word[i])) map.insert(pair<char, node*>(word[i], new node()));
						map[word[i]]->insert(word, i, isword);
					}
				} else {
					unordered_map <char, node*> aux = map;
					map = unordered_map <char, node*>();
					map.insert(pair<char, node*>(pattern[j], new node(pattern.substr(j, pattern.length()-j), this->isword, issuffix, aux, nodes)));
					pattern = pattern.substr(0, j);
					issuffix = false;
					this->isword = false;
					if (i < word.length()) {
						map.insert(pair<char, node*>(word[i], new node()));
						map[word[i]]->insert(word, i, isword);
					}
				}
				//if (!map.count(word[i])) map.insert(pair<char, node*>(word[i], new node(, isword, issuffix, map)));
				//else map[word[i]]->insert(word, i+1, isword);
			}
			if (i >= word.length() || nodes == 0) {
				issuffix  = true;
				this->isword |= isword;
			}
			nodes++;
		}
	}
	
	int search(string word, int i) {
		int j;
		for (j = 0; i < word.length() && j < pattern.length() && word[i] == pattern[j]; i++, j++);
		if (j == pattern.length()) {
			if (i == word.length()) return isword? 2: issuffix? 1: 0;
			else {
				if (i >= word.length() || !map.count(word[i])) return 0;
				return map[word[i]]->search(word, i);
			}
		} else return 0;
	}

	void print(int i){
		cout << i << "p:" << pattern << endl;
		for (auto it = map.begin(); it != map.end(); ++it) it->second->print(i+1);
	}

	pair<string, int> lrs() {
		pair<string, int> res = pair<string, int>("", 0);
		if (map.empty()) return res;
		for (int i = 0; i < size; i++) {
			if (map.count(characters[i])) {
				pair<string, int> t = map[characters[i]]->lrs();
				if (pattern.length() + t.first.length() > res.first.length()) {
					res = t;
					res.first = pattern + res.first;
					if (res.second == 0) res.second = nodes;
				}
			}
		}
		return res;
	}
};

struct suffixtree {
	node* root;

	suffixtree() { root = new node(); }

	~suffixtree() { delete root; }

	void insert(string word) {
		for (int j = word.length() - 1; j >= 0; j--) {
			if (j == 0) root->insert(word, j, true);
			else root->insert(word, j, false);
		}
	}

	int search(string word) { return root->search(word, 0); }

	void clear() { delete root; root = new node(); }

	void print() { root->print(0); }

	pair<string, int> lrs() {
		return root->lrs();
	}
};

int main() {
	suffixtree tree;
	string word;
	int N;
	cin >> N;
	while (N--) {
		cin >> word;
		tree.insert(word);
		pair<string, int> res = tree.lrs();
		if (res.second >= 2) cout << res.first << " " << res.second << '\n';
		else printf("No repetitions found!\n");
		tree.clear();
	}
	return 0;
}