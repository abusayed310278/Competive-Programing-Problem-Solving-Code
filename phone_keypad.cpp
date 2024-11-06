#include<bits/stdc++.h>
using namespace std;

string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WZYZ"};

void phoneKeypad(string input,string output,int i=0)
{
	//base case
	if(input[i]=='\0')
	{
		cout<<output<<endl;
		return;
	}

	//for keypad 1,2 digit
	int cur_digit=input[i]-'0';
	if(cur_digit==0 or cur_digit==1){
		phoneKeypad(input,output,i+1);
	}

	//main keypad code for 2,3,4,5,6,7,8,9 digit
	for(int k=0; k < keypad[cur_digit].size();k++){
		phoneKeypad(input,output+keypad[cur_digit][k],i+1);
	}

	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	string input,output;
	cin>>input;

	phoneKeypad(input,output);


	return 0;
}

/*

23

output:
AD
AE
AF
BD
BE
BF
CD
CE
CF


*/