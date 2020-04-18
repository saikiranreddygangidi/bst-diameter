
#include<iostream> 
using namespace std;
struct node{
    int value;
    struct node *left;
    struct node *rigth;
};
int max1=0;
struct node* createnode(int value)
{struct node *p;
     p=(struct node *)malloc(sizeof(struct node));
     p->value=value;
     p->rigth=NULL;
     p->left=NULL;
     return p;

}
void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->left);

        cout<<p->value << endl;
        inorder(p->rigth);
    }
}
int diameter(struct node *root)
{ int k=0;
    if(root->left==NULL && root->rigth==NULL)
    {
        return 0;
    }
    else
     if(root->left==NULL)
     {k=1+diameter(root->rigth);
       max1=k>max1?k:max1;
         return k;
     }
     else if(root->rigth==NULL){
            k=1+diameter(root->left);
       max1=k>max1?k:max1;
         return k;
         }
     else
        {k=1+diameter(root->left)+1+diameter(root->rigth);
           max1=k>max1?k:max1;
            if(1+diameter(root->left)>1+diameter(root->rigth))
             return 1+diameter(root->left);
            else
             return 1+diameter(root->rigth);
        }

}
int heigth(struct node *root){
    if(root->left==NULL && root->rigth==NULL)
    {
        return 0;
    }
    else
     if(root->left==NULL)
         return 1+heigth(root->rigth);
     else if(root->rigth==NULL)
         return 1+heigth(root->left);
     else
        {
            if(1+heigth(root->left)>1+heigth(root->rigth))
             return 1+heigth(root->left);
            else
             return 1+heigth(root->rigth);
        }

}
struct node* createbst(struct node *root,int value)
{
    if(root==NULL)
     return createnode(value);
    if(value<=root->value)
        root->left=createbst(root->left,value);
    if(value>root->value)
     root->rigth=createbst(root->rigth,value);
return root;
}

int main()
{
   struct node *root=NULL;
   int n,i,a[]={14,10,8,7,9,13,11,12,15};
       for(i=0;i<9;i++)
        root=createbst(root,a[i]);

    inorder(root);
    cout<<"heigth of tree " <<heigth(root) <<endl;
    diameter(root);
    cout<<"diameter of tree " << max1<<endl;
}
