#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <set>
#include <utility>
using namespace std;

int size = 4;
char characters[4] = {'a', 'c', 'g', 't'};

struct node {
	string pattern;
	bool isword;
	bool issuffix;
	int nodes;
	unordered_map <char, node*> map;
    int words;
    int lastword;

	node() { isword = issuffix = false; pattern = ""; nodes = 0; words = 0; lastword = -1;}

	node(string pattern, bool isword, bool issuffix, unordered_map<char, node*> & map, int nodes, int words, int lastword) {
		this->pattern = pattern;
		this->isword = isword;
		this->issuffix = issuffix;
		this->map = map;
		this->nodes = nodes;
        this->words = words;
        this->lastword = lastword;
	}

	void insert(string word, int i, bool isword, int wordId) {
		if (i < word.length()) {
			if (nodes == 0) pattern = word.substr(i, word.length()-i);
			else {
				int j;
				for (j = 0; i < word.length() && j < pattern.length() && word[i] == pattern[j]; i++, j++);
				if (j == pattern.length()) {
					if (i < word.length()) {
						if (!map.count(word[i])) map.insert(pair<char, node*>(word[i], new node()));
						map[word[i]]->insert(word, i, isword, wordId);
					}
				} else {
					unordered_map <char, node*> aux = map;
					map = unordered_map <char, node*>();
					map.insert(pair<char, node*>(pattern[j], new node(pattern.substr(j, pattern.length()-j), this->isword, issuffix, aux, nodes, words, lastword)));
					pattern = pattern.substr(0, j);
					issuffix = false;
					this->isword = false;
					if (i < word.length()) {
						map.insert(pair<char, node*>(word[i], new node()));
						map[word[i]]->insert(word, i, isword, wordId);
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
            if (wordId > lastword) lastword = wordId, words++;
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
		//cout << i << "p:" << pattern << endl;
        printf("%d p: %s w: %d n: %d\n", i, pattern.c_str(), words, nodes);
		for (auto it = map.begin(); it != map.end(); ++it) it->second->print(i+1);
	}

	set<string>* lrs(int & l, int insertedWords) {
		if (words != insertedWords) { l = 0; return NULL; }
		set<string>* res = new set<string>();
		l = pattern.length();
		res->insert(pattern);
		if (!map.empty()) {
			for (int i = 0; i < size; i++) {
				if (map.count(characters[i])) {
					int rl;
					set<string>* auxi = map[characters[i]]->lrs(rl, insertedWords);
					if (auxi != NULL) {
						if (pattern.length() + rl > l) { l = pattern.length() + rl; res->clear(); }
						if (pattern.length() + rl == l) {
							for (auto it = auxi->begin(); it != auxi->end(); ++it) {
								res->insert(pattern + (*it));
							}
						}
						delete auxi;
					}
				}
			}
		}
		return res;
	}
};

struct suffixtree {
	node* root;
    int words;

	suffixtree() { root = new node(); words = 0; }

	~suffixtree() { delete root; }

	void insert(string word) {
		for (int j = word.length() - 1; j >= 0; j--)
            root->insert(word, j, j == 0, words);
        words++;
	}

	int search(string word) { return root->search(word, 0); }

	void clear() { delete root; root = new node(); words = 0; }

	void print() { root->print(0); }

	set<string>* lrs(int & l) {
		return root->lrs(l, words);
	}
};

int main() {
	suffixtree tree;
	string s1, s2;
    bool first = false;
	while (cin >> s1 >> s2) {
        if (first) printf("\n");
        else first = true;
		tree.insert(s1);
        tree.insert(s2);
        int l = 0;
		set<string>* sol = tree.lrs(l);
        if (sol == NULL || l == 0) printf("No common sequence.\n");
        else for (auto it = sol->begin(); it != sol->end(); ++it) printf("%s\n", (*it).c_str());
		delete sol;
		tree.clear();
	}
	return 0;
}
