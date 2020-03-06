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

node* create_link(node n_ary[])
{
    int i;
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
    return &n_ary[1];
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
    node* r = create_link(&n_ary);

    return 0;
}
