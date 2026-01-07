#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

class Huffman{
    public:
    char c;
    int freq;
    Huffman* left;
    Huffman* right;

    Huffman(char c,int freq){
        this->c=c;
        this->freq=freq;
        left=right=NULL;
    }
};

class compare{  // min heap
    public:

    bool operator()(Huffman* a, Huffman* b){
        return a->freq > b->freq;
    }
};

void printcodes(Huffman* root,string code){

    if(!root) return;

    if(root->left == NULL && root->right==NULL){
        cout<<root->c<<": "<< code<<endl;
    }

    printcodes(root->left, code + "0");
    printcodes(root->right, code + "1");

}

int main(){

    // Build the min_heap (based on frequency)
    // 1️⃣ element type: store pointers to Huffman nodes
    // 2️⃣ container: uses vector internally to store nodes
    // 3️⃣ comparator: makes it a min-heap (based on freq)

    priority_queue<Huffman* , vector<Huffman*> , compare> pq;

    string s="abcdef";
    vector<int> freq={5, 9, 12, 13, 16, 45};
    int n=s.size();

  // 1. Push leaf nodes
    for(int i=0;i<n;i++){
        pq.push( new Huffman(s[i],freq[i]) );
    }

    // 2. Build the tree

    while(pq.size() > 1){
        Huffman* left=pq.top(); pq.pop();
        Huffman* right=pq.top(); pq.pop();
        // For internal nodes, we use a dummy char like '$'

        Huffman* newnode=new Huffman('$',left->freq + right->freq);
        newnode->left=left;
        newnode->right=right;
        pq.push(newnode);
    }

    printcodes(pq.top(),"");
    return 0;
}