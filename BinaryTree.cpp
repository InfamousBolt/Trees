#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right; 
}Node;

Node* createNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void preOrder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(Node* root){
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void levelOrder(Node* root){
    queue<Node*> q;
    if(root==NULL)
        return;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        cout<<curr->data<<" ";
    }
}

void average(Node* root){
    queue<Node*> q;
    Node* curr;
    long long sum=0;
    float n=0;
    if(root==NULL)
        return;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        curr=q.front();
        q.pop();
        if(curr==NULL){
            printf("%.2f ",sum/n);
            sum=0;
            n=0;
            if(q.empty())
                return;
            q.push(NULL);

        }else{
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            
            sum+=curr->data;
            n+=1;
        }
    }
}

int height(Node* root){
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

int size(Node* root){
    if(root==NULL)
        return 0;
    return size(root->left)+size(root->right)+1;
}
bool searchKey(int key, Node* root){
    if(root==NULL)
        return false;
    else if(root->data==key){
        return true;
    }else if(root->data>key){
        return searchKey(key,root->left);
    }
    return searchKey(key,root->right);
}

void bstSearch(int key, Node* root){
    if(searchKey(key,root))
        cout<<"Key is present\n";
    else
        cout<<"Key is not present\n";
}

Node* insert(Node* root, int data){
   if(root==NULL){
       root=createNode(data);
       return root;
   }
   if(data<root->data)
       root->left=insert(root->left,data);
   else if(data>root->data)
       root->right=insert(root->right,data);
    return root;
}



int main(){
    Node* root=createNode(48);
    root->left=createNode(12);
    root->left->left=createNode(6);
    root->left->right=createNode(6);
    root->right=createNode(12);
    root->right->left=createNode(6);
    root->right->right=createNode(6);
    postOrder(root);
    cout<<"\n";
    return 0;
}