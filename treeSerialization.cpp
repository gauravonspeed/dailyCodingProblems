// Example program
#include <iostream>
#include <string>
#include<queue>
using namespace std;

class tree1{
    private:
        int value;
        tree1* left;
        tree1* right;
    public:
         void createTreeNode(int val)
         {
             this->value = val;
             this->left =NULL;
             this->right = NULL;
             return;
             }
        int getValue()
        {
            return this->value;
            }
        //void insert2tree()
        tree1* getLeftChild()
        {
            return this->left;
            }
            
        tree1* getRightChild()
        {
            return this->right;
            }
        void setLeftChild( tree1& child)
        {
            this->left = &child;
            }
            
        void setRightChild( tree1& child)
        {
            this->right = &child;
            }
    };
    

void serializeTree(tree1 &root)
{
    std::queue<tree1*> Qtree;
    Qtree.push(&root);
    while(!Qtree.empty())
    {
        tree1* temp = Qtree.front();
        Qtree.pop();
        cout<<temp->getValue()<<endl;
        Qtree.push(temp->getLeftChild());
        Qtree.push(temp->getRightChild());
        };
        return ;
    }
int main()
{
    
    tree1 root;
    root.createTreeNode(1);
    //cout<<root.getValue()<<endl;
    //cout<<root.getRightChild()<<endl;
    //cout<<root.getLeftChild()<<endl;
    
    tree1 obj[6];
    /*for(int i =2;i<=10;i++)
    {
        
        }
    */
    
    obj[0].createTreeNode(2);
    root.setLeftChild(obj[0]);
    obj[1].createTreeNode(3);
    root.setRightChild(obj[1]);
    obj[2].createTreeNode(3);
    obj[0].setLeftChild(obj[2]);
    obj[3].createTreeNode(4);
    obj[0].setRightChild(obj[3]);
    obj[4].createTreeNode(5);
    obj[1].setLeftChild(obj[4]);
    obj[5].createTreeNode(6);
    obj[1].setRightChild(obj[5]);
    obj[6].createTreeNode(7);
    obj[1].setLeftChild(obj[6]);
    serializeTree(root);
    int arr[8]={8,7,6,5,4,3,2,1};
    //void deSerialize(arr);
}
