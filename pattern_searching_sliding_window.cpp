#include<bits/stdc++.h>
#define p 1e7+7;;
using namespace std;

vector<int>roll;

bool match(string s, int len, int size, string &ans) {

	unordered_map<int, vector<int>>m; //key->hashValue...->starting index of substring
	int hash = 0; //curr window hash
	for (int i = 0; i < size; ++i)hash = (hash * 26 + (s[i] - 'a')) % p;

	m[hash].push_back(0);

	//rolling hash (sliding window)

	for (int j = size; j < len; ++j) {

		hash = ((hash - roll[size - 1] * (s[j - size] - 'a')) % p + p) % p;
		hash = (hash * 26 + (s[j] - 'a')) % p;

		if (m.find(hash) != m.end()) {

			for (auto start : m[hash]) {
				string temp = s.substr(start, size);
				string curr = s.substr(j - size + 1, size);

				if (temp.compare(curr) == 0) {
					ans = temp;
					return true;
				}
			}
		}
		m[hash].push_back(j - size + 1);
	}

	return false;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s="geeksforgeeks",pat="geeks";

	int len=s.size();

	string temp="";
	bool flag=match(s,len,mid,pat);


	return 0;
}
