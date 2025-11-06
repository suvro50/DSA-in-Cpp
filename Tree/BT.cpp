#include<iostream>
#include<climits>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node* Buile_tree(Node* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    root=new Node(data);
    
    if(data==-1){
        return NULL;
    }

    cout<<"Enter left child of "<<data<<endl;
    root->left=Buile_tree(root->left);

    cout<<"Enter right child of "<<data<<endl;
    root->right=Buile_tree(root->right);

    return root;

}

void LevelOrder_Traversal(Node* root){
    if(root==NULL) return;

   queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp!=NULL){
           cout<<temp->data<<" ";

           if(temp->left!=NULL) q.push(temp->left);
           if(temp->right!=NULL) q.push(temp->right);

        }else if(!q.empty()){
            q.push(NULL);
        }
    }

}

void preOrder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int tree_height(Node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return 0;
    }

    int left_height=tree_height(root->left);
    int right_height=tree_height(root->right);

    if(left_height>right_height){
        return left_height+1;
    }else{
        return right_height+1;
    }
}

int count_Node(Node* root){
    if(root==NULL) return 0;

    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int left=count_Node(root->left);
    int right=count_Node(root->right);
    int sum=left+right+1;

    return sum;
}

int count_leaf_node(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }

     int left=count_leaf_node(root->left);
     int right=count_leaf_node(root->right);

    return left+right;
}

int count_parents_node(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 0;
    }

    int left=count_parents_node(root->left);
    int right=count_parents_node(root->right);

    return left+right+1;
}


int count_one_child(Node* root){
    if(root==NULL){
        return 0;
    }
    
     int left=count_one_child(root->left);
     int right=count_one_child(root->right);

    if( (root->left==NULL && root->right!=NULL) || (root->right==NULL && root->left!=NULL) ){
        return left+right+1;
    }


    return left+right;
}

int Node_sum(Node* root){
    if(root==NULL){
        return 0;
    }
    
    int left=Node_sum(root->left);
    int right=Node_sum(root->right);

    int ans=root->data;
    return ans+left+right;
}  

int max_node(Node* root){

    if(root==NULL){
        return INT_MIN;
    }

    int left=max_node(root->left);
    int right=max_node(root->right);

    int currentMax=root->data;

    if(left>currentMax){
        currentMax=left;
    }else if(right>currentMax){
        currentMax=right;
    }

    return currentMax;
}

int min_node(Node* root){
    if(root==NULL){
        return INT_MAX;
    }

    int left=min_node(root->left);
    int right=min_node(root->right);

    int countMin=root->data;

    if(left<countMin){
        countMin=left;
    }else if(right<countMin){
        countMin=right;
    }

    return countMin;
}

bool find_value(Node* root, int key){
    if(root==NULL) {
        return false;
    }
    if(root->data==key){
        return true;
    }

    bool left=find_value(root->left,key);
    bool right=find_value(root->right,key);

    return left || right;
}


bool isBalanced_Tree(Node* root) {
    if(root == NULL) return true;

    if(root->left == NULL && root->right == NULL) {
        return true; // leaf node is balanced
    }

    if(root->left != NULL && root->right != NULL) {
        if(isBalanced_Tree(root->left) && isBalanced_Tree(root->right)){
            return true;
        }
        else{
            return false;
        }

    }
    // node has only one child → not balanced
    return false;
}

 Node* LCA_BT( Node* root,int a , int b){  // Lowest Common Ancestor
    if(root==NULL){
        return NULL;
    }
    if(root->data==a || root->data==b ){ // Because a & b also be Ancestor
        return root;
    }

    Node* left=LCA_BT(root->left,a,b);
    Node* right=LCA_BT(root->right,a,b);

    if(left==NULL) return right;
    if(right==NULL) return left;
    
    return root;

 }

  bool isBalanced_height(Node* root) {
        if(root==NULL){
            return true;
        }

        bool lefttBalanced=isBalanced_height(root->left);
        bool rightBalanced=isBalanced_height(root->right);

         if(!lefttBalanced || !rightBalanced) return false;
         

        int left=tree_height(root->left);
        int right=tree_height(root->right);

        if(abs(left-right)<=1){
            return true;
        }else{
            return false;
        }
        
    }

int main(){

    // 40 30 25 -1 -1 35 -1 -1 50 45 -1 -1 60 -1 -1

    // -1 means node point to the NULL..

    Node* root =NULL;

    root=Buile_tree(root);

    cout<<"\nPreorder: ";
    preOrder(root);

    cout<<"\nLevelOrder Traversal: ";
    LevelOrder_Traversal(root);

    cout<<"\nTree height: ";
    cout<<tree_height(root);

    cout<<"\nTotal number of Nodes: ";
    cout<<count_Node(root);

    cout<<"\nTotal number of Leaf Nodes: ";
    cout<<count_leaf_node(root);

    cout<<"\nTotal parent Nodes: ";
    cout<<count_parents_node(root);

    cout<<"\nNode only have one child: ";
    cout<<count_one_child(root);

    cout<<"\nAll node sum: ";
    cout<<Node_sum(root);

    cout<<"\nMax Node: ";
    cout<<max_node(root);

    cout<<"\nMin Node: ";
    cout<<min_node(root);

    
    int a,b;
    cout<<"\nEnter a,b: ";
    cin>>a>>b;
    cout<<"LCA of "<<a<<" & "<<b<<"is: "<<LCA_BT(root,a,b)->data;

    if(isBalanced_Tree(root)){
        cout<<"\nThis is balanced tree.."<<endl;
    }else{
        cout<<"\nThis isn't balanced tree.."<<endl;
    }

    int key;
    cout<<"\nEnete key: ";
    cin>>key;

    if(find_value(root,key)){
        cout<<key<<" avalable in tree.."<<endl;
    }else{
        cout<<key<<" isn't avalable in tree.."<<endl;
    }



    
    return 0;
}