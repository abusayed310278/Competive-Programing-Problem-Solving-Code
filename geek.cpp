
int nodeheight(Node* p)
{
    int hl,hr;

    hl=p&&p->left ?p->left->height:0;
    hr=p&&p->right ?p->right->height:0;

    return hl>hr?hl+1:hr+1;
}

int balancefactor(Node* p)
{
    int hl,hr;
    hl=p&& p->left ?p->left->height:0;
    hr=p&& p->right ?p->right->height:0;

    return hl-hr;
}

Node* LLRotation(Node* p,Node* root)
{
    Node* pl=p->left;
    Node* plr=pl->right;

    pl->right=p;
    p->left=plr;

    p->height=nodeheight(p);
    pl->height=nodeheight(pl);

    if(root==p)
        root=pl;
    return pl;
}

Node* LRRotation(Node* p,Node* root)
{
    Node* pl=p->left;
    Node* plr=pl->right;

    pl->right=plr->left;
    p->left=plr->right;

    plr->left=pl;
    plr->right=p;

    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    plr->height=nodeheight(plr);

    if(root==p)
        root=plr;
    return plr;

}
Node* RRRotation(Node* p,Node* root)
{
    Node* pr=p->right;
    Node* prl=pr->left;

    pr->left=p;
    p->right=prl;

    p->height=nodeheight(p);
    pr->height=nodeheight(pr);

    if(root==p)
        root=pr;
    return pr;
}
Node* RLRotation(Node* p,Node* root)
{
    Node* pr=p->right;
    Node* prl=pr->left;

    pr->left=prl->right;
    p->right=prl->left;

    prl->right=pr;
    prl->left=p;

    pr->height=nodeheight(pr);
    p->height=nodeheight(p);
    prl->height=nodeheight(prl);

    if(root==p)
        root=prl;
    return prl;


}

Node* insertToAVL(Node* root,int data)
{
    Node *p=root;
    Node* t=NULL;
    if(p==NULL)
    {
        t=(Node*)malloc(sizeof(struct node));
        t->data=data;
        t->height=1;
        t->left=t->right=NULL;
        return t;
    }
    if(data < p->data)
    {
        p->left=RInsert(p->left,data);
    }else{
        p->right=RInsert(p->right,data);
    }

    p->height=nodeheight(p);

    if(balancefactor(p)==2 && balancefactor(p->left)==1)
        return LLRotation(p,root);
    else if(balancefactor(p)==2 && balancefactor(p->left)==-1)
        return LRRotation(p,root);
    else if(balancefactor(p)==-2 &&balancefactor(p->right)==-1)
        return RRRotation(p,root);
    else if(balancefactor(p)==-2 && balancefactor(p->right)==1)
        return RLRotation(p,root);

    return p;
}




