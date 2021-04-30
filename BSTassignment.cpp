#include <iostream>
#include <stdio.h>

using namespace std;

int rootCount = 1, nodeCount = 0;

struct bstNode{
    int data;
    bstNode * left;
    bstNode * right;
};
//insert a node
bstNode * Insert(bstNode * root, int value){
    bstNode * newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    if(root == NULL){
        root = newNode;
    }else{
        struct bstNode * temp = root;
        while(1){
            if((temp -> data) >= (newNode -> data)){
            if((temp -> left) == NULL){
                temp -> left = newNode;
                break;
            }else{
                temp = temp -> left;
            }
            }else{
                if((temp -> right) == NULL){
                    temp -> right = newNode;
                    break;
                }else{
                    temp = temp -> right;
                }
            }
        }
    }
    return root;
};

// inserting node to a binary search tree using recursion
// bstNode * GetNewNode(int value){
//     bstNode * newNode = (struct bstNode *)malloc(sizeof(struct  bstNode));
//     newNode -> data = value;
//     newNode -> left = NULL;
//     newNode -> right = NULL;
//     return newNode;
// }
// bstNode * Insert(bstNode * root, int value){
//     if(root == NULL){
//        root = GetNewNode(value);
//     }else if(value <= root->data){
//         root -> left = Insert(root -> left, value);
//     }else{
//         root -> right =  Insert(root -> right, value);
//     }
//     return root;
// }

//searching value
bool Search(bstNode * root, int value){
    if(root == NULL){
        return false;
    }else if(root -> data == value){
        return true;
    }else if(root -> data >= value){
        return Search(root -> left, value);
    }else{
        return Search(root -> right, value);
    }
};
//finding minimum
bstNode * FindMin(bstNode * root){
    while (root->left) {
        root = root->left;
    }
    return root;
};
//finding maximum
bstNode * FindMax(bstNode * root){
    while (root->right) {
        root = root->right;
    }
    return root;
};
//finding the height
int findMaxBetween(int a, int b){
  if(a >= b)
    return a;
  else
    return b;
}
int FindHeightOfTree(bstNode * root){
    if(root == NULL){
        return 0;
    }else{
        return findMaxBetween(FindHeightOfTree(root->left), FindHeightOfTree(root->right)) + 1;
    } 
}
//preorder traversal
void PreOrder(bstNode * root){
    if(root == NULL){
        return;
    }else{
        cout << root-> data << " ";
        PreOrder(root -> left);
        PreOrder(root -> right);
    }
};
//inorder traversal
void InOrder(bstNode * root){
    if(root == NULL){
        return;
    }else{
        InOrder(root -> left);
        cout << root-> data << " ";
        InOrder(root -> right);
    }
};
//postorder traversal
void PostOrder(bstNode * root){
    if(root == NULL){
        return;
    }else{
        PostOrder(root -> left);
        PostOrder(root -> right);
        cout << root -> data << " ";
    }
};
//deleting a node
bstNode * Delete(bstNode * root, int value){
    if(root == NULL){
        return root;
    }else if(value < root -> data){
        root -> left = Delete(root -> left, value);   
    }else if(value > root -> data){
        root -> right = Delete(root -> right, value);
    }else{
        if(root -> left == NULL && root -> right == NULL){
        delete root;
        root = NULL;
        return root;
    }else if(root -> left == NULL){
        bstNode * temp = root;
        root = root -> right;
        delete temp;
    }else if(root -> right == NULL){
        bstNode * temp = root;
        root = root -> left;
        delete temp;
    }else{
        bstNode * temp = FindMin(root -> right);
        root -> data = temp -> data;
        root -> right = Delete(root -> right, temp -> data);
    }
    }
    return root;
};
// counting nodes using post order traveral
int CountBstNodes(bstNode * root){
    if(root == NULL){
        return 0;
    }else{
        CountBstNodes(root -> left);
        CountBstNodes(root -> right);
        nodeCount++;
    }
    return nodeCount;
};
//finding successor of a node
bstNode * FindSuccessor(bstNode * root, bstNode * successorNode, int value){
    if(root == NULL){
        successorNode = root;
    }else if(root -> data == value){
        if(root -> right){
            successorNode = FindMin(root -> right);
        }
    }else if(root -> data > value){
        successorNode = root;
        FindSuccessor(root -> left, successorNode, value);
    }else{
        FindSuccessor(root -> right, successorNode, value);
    }
    return successorNode;
};
//printing the binary tree
void printBT(const string& prefix, const bstNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;
        cout << (isLeft ? "|____ " : (rootCount == 1 ? "\nRoot:" : "|____ ") );
        rootCount++;
        cout << node-> data << endl;
        printBT( prefix + (isLeft ? "|   " : "    "), node-> left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node-> right, false);
    }
}
void printBT(const bstNode* node)
{
    printBT("", node, false);  
}



int main(){
    //creating head nodes 
    bstNode * root = NULL;
    bstNode * root1 = NULL;
    //inserting nodes in BST
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 16);
    root = Insert(root, 25);
    root = Insert(root, 21);
    root = Insert(root, 26);
    //// 11 9 4 2 7 3 17 0 5 1
    root1 = Insert(root1, 11);
    root1 = Insert(root1, 9);
    root1 = Insert(root1, 4);
    root1 = Insert(root1, 2);
    root1 = Insert(root1, 7);
    root1 = Insert(root1, 3);
    root1 = Insert(root1, 17);
    root1 = Insert(root1, 0);
    root1 = Insert(root1, 5);
    root1 = Insert(root1, 1);

    //printing binary tree
    cout << "\nBinary Tree" << endl;
    printBT(root);
    // searching 10 in BST
    cout << "Searching 10 in the first Binary tree" << endl;
    if(Search(root, 10) == 1){
        cout << "Found" << endl;
    }else{
        cout << "Not Found!" << endl;
    }
    
    //finding minimum and maximum
    bstNode * minimumNode = (struct bstNode *)malloc(sizeof(struct bstNode));
    bstNode * maximumNode = (struct bstNode *)malloc(sizeof(struct bstNode));
    minimumNode = FindMin(root);
    maximumNode = FindMax(root);
    cout << "\nMaximum: ";
    cout << minimumNode -> data << endl;
    cout << "Maximum: ";
    cout << maximumNode -> data << endl;
    
    // finding successor
    bstNode * SuccessorNode = nullptr;
    SuccessorNode = FindSuccessor(root, SuccessorNode, 12);
    if(SuccessorNode -> data){
        cout<< "Successor of 12 is: " << SuccessorNode -> data << endl;
    }else{
        cout << "There is no successor of 12" << endl;
    }
    // find height of a tree
    cout << "Height of the tree is: " << FindHeightOfTree(root) << endl;

    //preorder
    cout << "\nPreorder: ";
    PreOrder(root);
    cout << endl;
    //postorder
    cout << "\nPostorder: ";
    PostOrder(root);
    cout << endl;
    //InOrder
    cout << "\nInOrder: ";
    InOrder(root);
    cout << endl;
    //countring BST Nodes
    cout << "\nTotal Nodes in the BST: " << CountBstNodes(root) << endl;
    //deleting nodes from first BST(root)
    cout << "Deleting 20:\n";
    root = Delete(root, 20);
    printBT(root);
    cout << "Deleting 26: \n";
    root = Delete(root, 26);
    printBT(root);
    //couldn't find the solution of last task
    cout << "\nSecond BST\n";
    //traversing
    printBT(root1);
    cout << "\nPre: ";
    PreOrder(root1);
    cout << "\nIn: ";
    InOrder(root1);
    cout << "\nPost: ";
    PostOrder(root1);
    cout << "\n";
    cout << "\n\nMusiur Alam Opu(2012973642)\n\n" << endl;
    return 0;
}