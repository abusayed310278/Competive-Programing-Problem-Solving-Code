#include<bits/stdc++.h>
using namespace std;

class Complex{
public:
    int a,b;

    void setData(int a,int b){
        this->a=a;
        this->b=b;
    }
    void showData(){
        cout<<a<<" "<<b<<endl;
    }
    friend void fun();
};
void fun(Complex ob){
    cout<<ob.a<<" "<<ob.b;
}
int main()
{
    Complex ob;
    ob.setData(4,5);
    ob.showData();
    fun(ob);
    return 0;
}
