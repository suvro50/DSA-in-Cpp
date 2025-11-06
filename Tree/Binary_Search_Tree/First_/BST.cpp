#include<iostream>
#include<queue>
#include<climits>
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

Node* Insertdata_BST(Node* root,int data){  // T.O( Ologn )
    
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data > root->data){
        root->right=Insertdata_BST(root->right,data);
    }else{
        root->left=Insertdata_BST(root->left,data);
    }
    return root;
}

Node* Input_BST(Node* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    while(data!=-1){
        root=Insertdata_BST(root,data);
        cin>>data;
    }
    return root;
}


bool search_Node(Node* root,int key){   // T.C(logn)  or Worst Case O(n);
                                        // S.C(H)
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }

    if(key>root->data){
        bool right=search_Node(root->right,key);
        return right;
    }else{
        bool left=search_Node(root->left,key);
        return left;
    }
    
}

Node* maximun(Node* root){ 

    if (root == NULL) {
        return NULL;
    }

    Node* temp=root;

    while(temp->right!=NULL){
        temp=temp->right;
    }
   return temp;
}

Node* Minimum(Node* root){

    if (root == NULL) {
        return NULL;
    }
    
    Node* temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}



Node* DeletefromBST( Node* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int max=maximun(root->left)->data;
            root->data=max;
            root->left=DeletefromBST(root->left,max);
            return root;
        }


    }else{
        if(data<root->data){
            root->left=DeletefromBST(root->left,data);
            return root;
        }else{
            root->right=DeletefromBST(root->right,data);
            return root;
        }
    }
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void Inorder(Node* root){  // Inorder given sorted tree
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}


void LevelOrderTraverse(Node* root){
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

            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);

        }else if(!q.empty()){
             cout << endl;  
            q.push(NULL);
        }
    }
}

bool valid_BST(Node* root, long long min=LLONG_MIN, long long max=LLONG_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data <= min || root->data >= max){
        return false;
    }

    bool left=valid_BST(root->left,min,root->data);
    bool right=valid_BST(root->right,root->data,max);

    return left && right;
    
}


int predecessor(Node* root,int key){ 

    Node* pre=NULL;

    while(root!=NULL){

        if(root->data==key){
            if(root->left!=NULL){
                pre=maximun(root->left);
            }
            break;
        }else if(key < root->data){
            root=root->left;

        }else if(key > root->data ){
            pre=root;
            root=root->right;
        }
    }
    
    if(pre==NULL){
        return -1;
    }else{
        return pre->data;
    }
}

int successor(Node* root,int key){

    Node* suc=NULL;

    while(root!=NULL){
        if(root->data==key){
            if(root->right!=NULL){
                suc=Minimum(root->right);
            }
            break;
        }else if( key < root->data){
            suc=root;
            root=root->left;
        }else if( key > root->data){
            root=root->right;
        }
    }
    
    if(suc==NULL){
        return -1;
    }else{
        return suc->data;
    }

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

 


int count = 0;  // Your global counter

int kthSmallestHelper(Node* root, int k) {
    if (!root) return -1;

    // 1. Go Left
    int left = kthSmallestHelper(root->left, k);
    if (left != -1) return left; // Found in left

    // 2. Visit Root
    count++;
    if (count == k) return root->data;

    // 3. Go Right
    return kthSmallestHelper(root->right, k);

}

int kthSmallest(Node* root, int k) {
    // 1. RESET the global counter every time
    count = 0; 
    
    // 2. CALL the helper function to find the answer
    return kthSmallestHelper(root, k);
}


void inorder(Node* root, vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool Two_sum(Node* root,int key){
    vector<int> inorderval;

    inorder(root,inorderval);

    int i=0, j=inorderval.size()-1;

    while(i<j){
        int  sum=inorderval[i]+inorderval[j];

        if(sum==key){
            return true;
        }else if(sum<key){
            i++;
        }else{
            j--;
        }
    }
    return false;
}


int main(){

    //40 30 25 35 50 45 60 -1

    //     40
    //   /    \
    //  30    50
    // /  \  /  \
   // 25  35 45  60

    Node* root=NULL;

   root=Input_BST(root);

    cout<<"\n Preorder: ";
    preorder(root);

    cout<<"\n Inorder: ";
    Inorder(root);

    cout<<"\n LevelOrderTraverser: \n";
    LevelOrderTraverse(root);

    cout<<"\nMaximum node: ";
    cout<<maximun(root)->data;

    cout<<"\nMinimum node: ";
    cout<<Minimum(root)->data;

    int sum;
    cout<<"\nEnter two sum key: ";
    cin>>sum;
    if(Two_sum(root,sum)){
        cout<<"true";
    }else{
        cout<<"false";
    }
     int a,b;
    cout<<"\nEnter a,b: ";
    cin>>a>>b;
    cout<<"LCA of "<<a<<" & "<<b<<"is: "<<LCA_BT(root,a,b)->data;

    int key;
    cout<<"\nEnter Key for predecessor & successor : ";
    cin>>key;
    cout<<"\nPredecessor of "<<key<<" is: "<<predecessor(root,key);
    cout<<"\nsuccessor of "<<key<<" is: "<<successor(root,key);
    

    if(valid_BST(root)){
        cout<<"\nValid BST..";
    }else{
         cout<<"\n Not Valid BST..";
    }
    int w;
    cout<<"\nEnter delete Key: ";
    cin>>w;

    root=DeletefromBST(root,w);

    cout<<"\n Preorder: ";
    preorder(root);
    
    cout<<"\n Inorder: ";
    Inorder(root);

    cout<<"\n LevelOrderTraverser: \n";

    LevelOrderTraverse(root);

    // int key;
    // cout<<"\nEnter Key: ";
    // cin>>key;

    // if(search_Node(root,key)){
    //     cout<<key<<" is avalabe in tree\n";
    // }else{
    //     cout<<key<<" isn't avalabe in tree\n";
    // }



    return 0;
}