#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *next;

}*start=NULL;

class Solution{
public:
	void insert(int x){

		Node *r=start;
		Node *n=(Node*)malloc(sizeof(Node));
		n->val=x;
		n->next=NULL;

		if(start==NULL)
			start=n;
		else{
			while(r->next!=NULL)
				r=r->next;
			r->next=n;
		}
	}
	void print(){
		Node *r=start;
		while(r->next!=NULL){
			cout<< r->val <<endl;
			r=r->next;
		}
		
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;cin>>n;
	Solution ob;
	while(n--){
		int x;cin>>x;
		ob.insert(x);
	}
	ob.print();

	return 0;
}