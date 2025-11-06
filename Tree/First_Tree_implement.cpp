#include<iostream>
#include<queue>
using namespace std;


// Make Node for Tree..
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

//Build tree
Node* Build_tree(Node* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout << "Enter left child of " << data <<endl;
    root->left=Build_tree(root->left);

    cout << "Enter right child of " << data <<endl;
    root->right=Build_tree(root->right);

    return root;
}


void preOrder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);

    cout<<root->data<<" ";
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


void LevelOrder_Traversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp!=NULL){
        cout<<temp->data<<" ";

        if(temp->left!=NULL)  q.push(temp->left);

        if(temp->right!=NULL) q.push(temp->right);
        
        }

        else if(!q.empty()){
            q.push(NULL);
        }
   }

} 

int main(){
    // 40 30 25 -1 -1 35 -1 -1 50 45 -1 -1 60 -1 -1

    Node* root=NULL;

    root=Build_tree(root);


    cout << "\nPreorder Traversal: ";
    preOrder(root);

    cout << "\nPostOrder Traversal: ";
    postOrder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout<<"\nLevelOrder Traversal: ";
    LevelOrder_Traversal(root);

    return 0;
}