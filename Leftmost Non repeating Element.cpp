#include<bits/stdc++.h>
using namespace std;


/*

=>find leftmost non-repeating characters
=>return index otherwise return -1(if all char is distinct)

*/

// Tc:O(n^2)

int NaiveApporach(string &str) {


	for (int i = 0; i < str.length(); i++) {

		bool flag = false;

		for (int j = 0; j < str.length(); j++) {

			if (i != j && str[i] == str[j]) {
				flag = true;
				break;
			}

		}

		if (flag == false) {
			return i;
		}
	}

}






int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s1; cin >> s1;

	cout << NaiveApporach(s1) << endl;

	return 0;
}

/*
geeksforgeeks
abcd

*/