#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int height;
    struct node* lchild,*rchild;
}; //}*root=NULL;
struct node* root=NULL;

//final avl tree by abu sayed

int nodeheight(struct node* p)
{
    int hl,hr;

    hl=p&&p->lchild ?p->lchild->height:0;
    hr=p&&p->rchild ?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int balancefactor(struct node* p)
{
    int hl,hr;
    hl=p&& p->lchild ?p->lchild->height:0;
    hr=p&& p->rchild ?p->rchild->height:0;

    return hl-hr;
}

struct node* LLRotation(struct node* p)
{
    struct node* pl=p->lchild;
    struct node* plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=nodeheight(p);
    pl->height=nodeheight(pl);

    if(root==p)
        root=pl;
    return pl;
}

struct node* LRRotation(struct node* p)
{
    struct node* pl=p->lchild;
    struct node* plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    plr->height=nodeheight(plr);

    if(root==p)
        root=plr;
    return plr;

}
struct node* RRRotation(struct node* p)
{
    struct node* pr=p->rchild;
    struct node* prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=nodeheight(p);
    pr->height=nodeheight(pr);

    if(root==p)
        root=pr;
    return pr;
}
struct node* RLRotation(struct node* p)
{
    struct node* pr=p->rchild;
    struct node* prl=pr->lchild;

    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->rchild=pr;
    prl->lchild=p;

    pr->height=nodeheight(pr);
    p->height=nodeheight(p);
    prl->height=nodeheight(prl);

    if(root==p)
        root=prl;
    return prl;


}

struct node* RInsert(struct node* p,int key)
{
    struct node* t=NULL;
    if(p==NULL)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }else{
        p->rchild=RInsert(p->rchild,key);
    }

    p->height=nodeheight(p);

    if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
        return LLRotation(p);
    else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
        return LRRotation(p);
    else if(balancefactor(p)==-2 &&balancefactor(p->rchild)==-1)
        return RRRotation(p);
    else if(balancefactor(p)==-2 && balancefactor(p->rchild)==1)
        return RLRotation(p);

    return p;
}

struct node* deleteAVL(struct node* root,int data)
{
    struct node* temp;

    if(root==NULL)
        cout<<"there is no such node exists."<<endl;
    else if(root->data >data)
        root->lchild=deleteAVL(root->lchild,data);
    else if(root->data <data)
        root->rchild=deleteAVL(root->rchild,data);
    else{
           


    }
    return root;
}


void preorder(struct node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int menu()
{
    int n;
    cout<<endl<<"1.for insert node at AVL Tree.";
    cout<<endl<<"0.for exit.";
    cout<<endl<<"Enter your choice."<<endl;
    cin>>n;
    return n;
}

int main()
{
    while(1)
    {
        switch(menu())
        {
            case 1:

                root=RInsert(root,30);
                RInsert(root,20);
                RInsert(root,40);
                RInsert(root,10);
                preorder(root);
                break;

            case 0:
                exit(0);
                break;
            default:
                cout<<"invalid input"<<endl;
                break;
        }
    }
    return 0;
}

