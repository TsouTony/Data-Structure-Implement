#include<iostream>
#include<vector>

using namespace std;
vector<char> origin;

struct node
{
    char value;
    node* left;
    node* right;
};

bool is_odd(int n)
{
    if(n%2==0)return false;
    else return true;
}
void preorder(node* r)
{
    if(r!=NULL)
    {
        cout<<r->value<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}
void inorder(node* r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->value<<" ";
        inorder(r->right);
    }
}
void postorder(node* r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        cout<<r->value<<" ";
    }
}
node* copy_BT(node* r)
{
    if(r==NULL)return NULL;
    else{
        node* t=new node;
        t->value=r->value;
        t->left=copy_BT(r->left);
        t->right=copy_BT(r->right);
        return t;
    }
}

int main()
{
    string in;
    int i,type;
    //將input之BT存入一vector
    origin.push_back('0');
    getline(cin,in);
    for(i=0; i<in.size(); i++)
        if(in[i]!=' ')
            origin.push_back(in[i]);
    cout<<"orgin vector content: ";
    for(i=0; i<origin.size(); i++)
        cout<<origin[i]<<" ";
    cout<<endl;
    //將vector轉換成node
    node n_ary[origin.size()];
    for(i=0;i<origin.size();i++)
    {
        n_ary[i].value = origin[i];
    }
    cout<<"n_ary content: ";
    for(i=0;i<origin.size();i++)
        cout<<n_ary[i].value<<" ";
    cout<<endl;
    //將node間的親屬關係建立
    cout<<"origin.size(): "<<origin.size()<<endl;
    int n_num = origin.size()-1;
    for(i=1;i<origin.size();i++)
    {
        node* l=&n_ary[2*i];
        if(i<n_num/2)
        {
            node* r=&n_ary[2*i+1];
            n_ary[i].left = l;
            n_ary[i].right = r;
        }
        else if(i==n_num/2)
        {
            if(is_odd(n_num))
            {
                node* r=&n_ary[2*i+1];
                n_ary[i].left = l;
                n_ary[i].right = r;
            }
            else
            {
                n_ary[i].left=l;
                n_ary[i].right=NULL;
            }
        }
        else
        {
            n_ary[i].left=NULL;
            n_ary[i].right=NULL;
        }
    }
    node* r = &n_ary[1];
    for(i=1;i<origin.size();i++)
    {
        if(n_ary[i].left==NULL && n_ary[i].right==NULL)cout<<i<<"th's child: NULL"<<endl;
        else if(n_ary[i].left!=NULL && n_ary[i].right==NULL)cout<<i<<"th's child: "<<n_ary[i].left->value<<endl;
        else cout<<i<<"th's child: "<<n_ary[i].left->value<<" "<<n_ary[i].right->value<<endl;
    }

    node* copy_r=copy_BT(r);
    //print the copy tree
    cout<<"1: preorder"<<endl;
    cout<<"2: inorder"<<endl;
    cout<<"3: postorder"<<endl;
    while(1)
    {
        cout<<"input the type of traversal: ";
        cin>>type;
        switch(type)
        {
        case 1:
            preorder(copy_r);
            cout<<endl;
            break;
        case 2:
            inorder(copy_r);
            cout<<endl;
            break;
        case 3:
            postorder(copy_r);
            cout<<endl;
            break;
        default:
            cout<<"wrong input"<<endl;
        }
    }

    return 0;
}
