#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;
void InsertLastNode()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* r;
    int data;
    cout<<"Enter your Node Value:"<<endl;
    cin>>temp->data;

    temp->next=NULL;
    if(start==NULL)
       start=temp;
    else{
        r=start;
        while(r->next!=NULL)
            r=r->next;

        r->next=temp;
    }

}
void DeleteFirstNode()
{
    struct node* r;
    if(start==NULL)
        cout<<"List is empty"<<endl;
    else{
         r=start;
         start=r->next;
         free(r);
    }

}
void deleteAnyListNode()
{
    cout<<"which node you want to delete:"<<endl;
    int data;
    cin>>data;
    struct node* a;
    a=start;
    if(start==NULL)
        cout<<"List is not exists."<<endl;
    else if(a->data==data){
        a->next=a->next;
        free(a);
    }else{
        cout<<data<<" is not exists."<<endl;
    }
}
void print()
{
    struct node* p;
    p=start;
    if(start==NULL)
        cout<<"list is empty"<<endl;
    else{
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }

}
void find_out()
{
    struct node* s;
    s=start;
    if(start==NULL)
        cout<<"list is empty"<<endl;
    else{
            cout<<"which node you want to search:"<<endl;
            int data;
            cin>>data;
        if(s->data==data){
            cout<<data<<"  is exists."<<endl;

        }else{
            cout<<data<<" is not exists."<<endl;
        }
    }
}
int menu()
{

    cout<<endl<<"1.for insert list.";
    cout<<endl<<"2.for deleteFirstNode list.";
    cout<<endl<<"3.for print list.";
    cout<<endl<<"4.for search a node from list.";
    cout<<endl<<"5.for delete Any node from list.";
    cout<<endl<<"0.for exit.";
    int n;
    cout<<endl<<"Enter your choice:"<<endl;
    cin>>n;
    return n;

}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while(1)
    {

       switch(menu())
       {


           case 1:InsertLastNode();break;
           case 2:DeleteFirstNode();break;
           case 3:print();break;
           case 4:find_out();break;
           case 5:deleteAnyListNode();break;
           case 0:exit(0);break;
           default:cout<<"invalid input."<<endl;break;

        }
    }
return 0;
}
