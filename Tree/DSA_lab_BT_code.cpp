#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(char data)
{
    TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printTree(TreeNode* root, int space = 0)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    int COUNT = 5;
    space += COUNT;

    // Print right child first
    printTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root->data);

    // Print left child
    printTree(root->left, space);
}


void preorder(TreeNode* root)
{
    if(root==NULL) return;

    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void inorder(TreeNode* root)
{
    if(root==NULL) return;

    inorder(root->left);

    printf("%c ", root->data);

    inorder(root->right);
}

void postorder(TreeNode* root)
{
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int height(TreeNode* root)
{
    if(root==NULL) /// root NULL
    {
        return 0;
    }
    else if(root->left==NULL && root->right==NULL) /// child count: 0
    {
        return 0;
    }
    else
    {
        if(root->left!=NULL && root->right!=NULL) /// child count: 2
        {
            int left_side_height = height(root->left);
            int right_side_height = height(root->right);

            if(left_side_height>right_side_height)
            {
                return left_side_height + 1;
            }
            else
                return right_side_height + 1;

        }
        else if(root->left!=NULL) /// child count: 1 (Left Child)
        {
            int left_side_height = height(root->left);
            return left_side_height + 1;
        }
        else /// child count: 1 (Right Child)
        {
            int right_side_height = height(root->right);
            return right_side_height + 1;
        }
    }
}


int findValue(TreeNode* root, char value)
{
    if(root==NULL) return 0;
    else if(root->data==value) return 1;
    else
    {
        int left_answer = findValue(root->left, value);
        int right_answer = findValue(root->right, value);

        return left_answer || right_answer;
    }
}

int countNodes(TreeNode* root)
{
    if(root==NULL) return 0;
    else
    {
        int left_answer = countNodes(root->left);
        int right_answer = countNodes(root->right);
        return left_answer + right_answer + 1;
    }
}

int countLeaves(TreeNode* root)
{
    if(root==NULL) return 0;
    else if(root->left==NULL && root->right==NULL) return 1;
    else
    {
        int left_answer = countLeaves(root->left);
        int right_answer = countLeaves(root->right);
        return left_answer + right_answer;
    }
}

int main()
{
    TreeNode* root = createNode('A');

    root->left = createNode('B');
    root->right = createNode('C');

    root->left->left = createNode('D');
    root->left->right = createNode('E');

    root->right->left = createNode('F');
    root->right->right = createNode('G');

    root->right->right->left = createNode('H');


     printTree(root);
    /// preorder(root);
    /// inorder(root);

    /// postorder(root);
    printf("%d\n", height(root));

    return 0;
}