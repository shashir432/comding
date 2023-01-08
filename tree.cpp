#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

void print(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L:"<<root->left->data<<",";
    }
    else{
        cout<<"L:-1,";
    }
    if(root->right!=NULL){
        cout<<"R:"<<root->right->data;
    }
    else{
        cout<<"R:-1";
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter rootdata:";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftchild=takeinput();
    BinaryTreeNode<int>* rightchild=takeinput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}

void printlevel(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L:"<<front->left->data<<",";
            q.push(front->left);
        }
        else{
            cout<<"L:-1";
        }
        if(front->right!=NULL){
            cout<<"R:"<<front->right->data;
            q.push(front->right);
        }
        else{
            cout<<"R:-1";
        }
        cout<<endl;
    }
}

void printlinebyline(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<front->data<<" ";
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
}

void printlinebyline2(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* front=q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
        }
        cout<<endl;
    }
}

BinaryTreeNode<int>* takeinputlevel(){
    int rootdata;
    //cout<<"Enter rootdata:";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        //cout<<"Enter left child of "<<front->data<<":";
        int l;
        cin>>l;
        if(l!=-1){
            BinaryTreeNode<int>* leftchild=new BinaryTreeNode<int>(l);
            q.push(leftchild);
            front->left=leftchild;
        }
        //cout<<"Enter right child of "<<front->data<<":";
        int r;
        cin>>r;
        if(r!=-1){
            BinaryTreeNode<int>* rightchild=new BinaryTreeNode<int>(r);
            q.push(rightchild);
            front->right=rightchild;
        }
    }
    return root;
}

int count(BinaryTreeNode<int>* root){
    if(root==NULL)
    return 0;
    int cnt=0;
    cnt+=count(root->left);
    cnt+=count(root->right);
    return cnt+1;
}

bool isNodePresent(BinaryTreeNode<int> *node, int key){
    if(node==NULL)
    return 0;
    if(node->data==key)
    return 1;
    bool b=isNodePresent(node->left,key);
    if(b)
    return 1;
    b=isNodePresent(node->right,key);
    if(b)
    return 1;
    return 0;
}

int height(BinaryTreeNode<int>* root){
    if(root==NULL)
    return 0;
    int h=0;
    int n=height(root->left);
    if(n>h){
        h=n;
    }
    n=height(root->right);
    if(n>h)
    h=n;
    return h+1;
}

void mirrorBinaryTree(BinaryTreeNode<int>* node){
    if(node==NULL)
    return;
    mirrorBinaryTree(node->left);
    mirrorBinaryTree(node->right);
    std::swap(node->left,node->right);
}

void preorder(BinaryTreeNode<int>* root){
    if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root){
    if(root==NULL)
    return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(BinaryTreeNode<int>* root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int fun(BinaryTreeNode<int>* root,int &maxi){  //finds which path left or right gives max sum 
        if(root==NULL)
        return 0;
        int leftsum=max(0,fun(root->left,maxi));
        int rightsum=max(0,fun(root->right,maxi));
        maxi=max(maxi,leftsum+rightsum+root->data);
        return max(leftsum,rightsum)+root->data;
}

int maxPathSum(BinaryTreeNode<int>* root) {
        int maxi=0;
        fun(root,maxi);
        return maxi;
}

int diameter(BinaryTreeNode<int>* root){
    if(root==NULL)
    return 0;
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option3,max(option2,option1));
}

bool isBalanced(BinaryTreeNode<int>* root){
    if(root==NULL)
    return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

vector<int> topview(BinaryTreeNode<int>* root){
    vector<int> v;
    if(root==NULL)
    return v;
    queue<pair<BinaryTreeNode<int>*,int> > q;  //stores node and line in pair
    map<int,int> mp;  //this sorted map maps line to the node data
    q.push({root,0});   //line refers to the line vertical line in which node lies
    while(!q.empty()){
        auto it=q.front();
        BinaryTreeNode<int>* front=it.first;
        int line=it.second;
        q.pop();
        if(mp.find(line)==mp.end())//line not found
        mp[line]=front->data;
        if(front->left)
        q.push({front->left,line-1});
        if(front->right)
        q.push({front->right,line+1});
    }
    for(auto it:mp)
    v.push_back(it.second);
    return v;
}

vector<int> bottomview(BinaryTreeNode<int>* root){
    vector<int> v;
    if(root==NULL)
    return v;
    queue<pair<BinaryTreeNode<int>*,int>> q;  //stores node and line in pair
    map<int,int> mp;  //this sorted map maps line to the node data
    q.push({root,0});   //line refers to the line vertical line in which node lies
    while(!q.empty()){
        auto it=q.front();
        BinaryTreeNode<int>* front=it.first;
        int line=it.second;
        q.pop();
        mp[line]=front->data;
        if(front->left)
        q.push({front->left,line-1});
        if(front->right)
        q.push({front->right,line+1});
    }
    for(auto it:mp)
    v.push_back(it.second);
    return v;
}

void recursion(BinaryTreeNode<int>* root,int level,vector<int> &v){
    if(root==NULL)
    return;
    if(v.size()==level)v.push_back(root->data);
    recursion(root->left,level+1,v);
    recursion(root->right,level+1,v);
}

vector<int> leftview(BinaryTreeNode<int>* root){
    vector<int> v;
    recursion(root,0,v);
    return v;
}

void recursion2(BinaryTreeNode<int>* root,int level,vector<int> &v){
    if(root==NULL)
    return;
    if(v.size()==level)
    v.push_back(root->data);
    recursion2(root->right,level+1,v);
    recursion2(root->left,level+1,v);
}

vector<int> rightview(BinaryTreeNode<int>* root){
    vector<int> v;
    recursion2(root,0,v);
    return v;
}

bool isSymmetricalHelp(BinaryTreeNode<int>* left,BinaryTreeNode<int>* right){
    if(left==NULL || right==NULL)
    return left==right;
    //preorder
    if(left->data!=right->data)
    return false;
    return isSymmetricalHelp(left->left,right->right) && isSymmetricalHelp(left->right,right->left);
}

bool isSymmetrical(BinaryTreeNode<int>* root){
    if(root==NULL)
    return true;
    return isSymmetricalHelp(root->left,root->right);
}

bool isSameTree(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2){
    if(root1==NULL || root2==NULL)
    return root1==root2;
    //preorder
    if(root1->data!=root2->data)
    return false;
    return isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);
}

vector<int> ipreorder(BinaryTreeNode<int>* root){
    vector<int> preorder;
    if(root==NULL)
    return preorder;
    stack<BinaryTreeNode<int>*> s;
    s.push(root);
    while(!s.empty()){
        BinaryTreeNode<int>* top=s.top();
        s.pop();
        preorder.push_back(top->data);
        if(top->right!=NULL){
            s.push(top->right);
        }
        if(top->left!=NULL){
            s.push(top->left);
        }
    }
    return preorder;
}

vector<int> iinorder(BinaryTreeNode<int>* root){
    vector<int> inorder;
    if(root==NULL)
    return inorder;
    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int>* node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()==true) break;
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    return inorder;
}

int main()
{
    //non-symmetrical but balanced: 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    //symmetrical and balanced: 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1 
    //unbalanced and unsymmetrical: 1 -1 2 -1 3 -1 -1
    // BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    // root->left=node1;
    // root->right=node2;
    BinaryTreeNode<int>* root=takeinputlevel();
    printlevel(root);
    cout<<"count: "<<count(root)<<endl;
    cout<<"is node present or not: "<<isNodePresent(root,69)<<endl;
    cout<<"height: "<<height(root)<<endl;
    cout<<"preorder: ";
    vector<int> v= ipreorder(root);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    cout<<"inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"max path sum: "<<maxPathSum(root)<<endl;
    cout<<"top view: ";
    vector<int> tv=topview(root);
    for(auto it:tv)
    cout<<it<<" ";
    cout<<endl;
    cout<<"bottom view: ";
    vector<int> bv=bottomview(root);
    for(auto it:bv)
    cout<<it<<" ";
    cout<<endl;
    cout<<"left view: ";
    vector<int> lv=leftview(root);
    for(auto it:lv)
    cout<<it<<" ";
    cout<<endl;
    cout<<"right view: ";
    vector<int> rv=rightview(root);
    for(auto it:rv)
    cout<<it<<" ";
    cout<<endl;
    cout<<"isSymmetrical: "<<isSymmetrical(root)<<endl;
    cout<<"isBalanced: "<<isBalanced(root)<<endl;
    cout<<"line by line:"<<endl;
    printlinebyline2(root);
    delete root;
    return 0;
}



