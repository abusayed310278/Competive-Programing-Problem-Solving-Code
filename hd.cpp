int nodeheight(Node* p)
{
    int hl,hr;

    hl=p&&p->left ?0-p->left->height:0;
    hr=p&&p->right ?0+p->right->height:0;

    return hl>hr?hl+1:hr+1;
}