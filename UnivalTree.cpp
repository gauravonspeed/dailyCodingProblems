#include<iostream>
using namespace std;

class Tree_t{
    public:
        int val ;
        Tree_t* left;
        Tree_t* right;
        Tree_t(int x){val = x;}
};

bool countUnival(int &val, Tree_t* root)
{
    
    cout<<"countUnival:"<<val<<endl;
    if(root == NULL)
    {
        return true;
        cout<<"it is true"<<endl;
    }
    bool res = false;
    
    if(countUnival(val,root->left))
    {
        res = true;
        cout<<"at left"<<endl;
    }
    else
    res = false;
    if(countUnival(val,root->right))
    {
        res = true;
        cout<<"at right"<<root->val<<endl;
    }
    else
        res = false;
    
    if(res && (root->left == NULL || root->right == NULL)){
        cout<<"child NULL so leaf node"<<endl;
        val++;
    }
    else if(root->val == root->left->val && root->val == root->right->val && res)
    {
        cout<<"comapare"<<endl;
        val++;
    }
    else
    return false;
}

int main()
{
    Tree_t* root= new Tree_t(5);
    Tree_t* t1 = new Tree_t(1);
    Tree_t* t2= new Tree_t(5);
    Tree_t* t3 = new Tree_t(5);
    Tree_t* t4= new Tree_t(5);
    Tree_t* t5= new Tree_t(5);
    //Tree_t t6(5);
    //Tree_t t7(1);
    //Tree_t t8(5);
    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->right = t5;
    int val =0;
    bool result = countUnival(val,root);
    cout<<"count is :"<<val<<endl;
    return 0;
}
