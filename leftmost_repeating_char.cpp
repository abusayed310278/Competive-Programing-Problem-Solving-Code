#include<bits/stdc++.h>
using namespace std;


/*

=>find leftmost repeating characters
=>return index otherwise return -1(if all char is distinct)

*/
int mineApporach(string &str) {
	//index,frequency
	map<char, pair<int, int>>m;

	for (int i = 0; i < str.size(); i++) {
		m[str[i]].first = i;
		(m[str[i]].second)++;
	}

	int index = 0;
	for (int i = 0; i < m.size(); i++) {

		if (m[i].second >= 2) {
			index = m[i].first;
			break;
		}

	}

	return index;

}

int NaiveApporach(string &str) {

	for (int i = 0; i < str.length(); i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] == str[j]) {
				return i;
			}
		}
	}
	return -1;
}

const int CHAR = 256;
int BetterApporach(string &str) {

	int count[CHAR] = {0};
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++;
	}

	for (int i = 0; i < str.length(); i++) {
		if (count[str[i]] > 1) {
			return i;
		}
	}

	return -1;
}

// Tc:O(n),Sc:O(CHAR)
int efficientApporach_1(string &str) {

	int fIndex[CHAR];
	fill(fIndex, fIndex + CHAR, -1);
	int res = INT_MAX;

	for (int i = 0; i < str.length(); i++) {
		// int fi=fIndex[str[i]];

		if (fIndex[str[i]] == -1) {
			fIndex[str[i]] = i; //fIndex[str[i]]=fi;
		} else {
			res = min(res, fIndex[str[i]]);
		}
	}
	return (res == INT_MAX) ? -1 : res;
}

int efficientApporach_2(string &str) {

	bool visited[CHAR];
	fill(visited, visited + CHAR, false);
	int res = -1;

	for (int i = str.length()-1; i >= 0; i--) {
		// int fi=fIndex[str[i]];

		if (visited[str[i]] ) {
			res = i;
		} else {
			visited[str[i]] = true;
		}
	}
	return res;
}



int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s1; cin >> s1;
	// cout << mineApporach(s1)<<endl;
	// cout << NaiveApporach(s1) << endl;
	// cout << BetterApporach(s1) << endl;
	// cout << efficientApporach_1(s1) << endl;
	cout << efficientApporach_2(s1) << endl;

	return 0;
}

/*
geeksforgeeks
abcd

*/