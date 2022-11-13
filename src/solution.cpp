#include "solution.h"

int countElements(Node* tree) {
    if(tree == nullptr)  return 0;
    return  1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) {
    if(tree == nullptr) return 0;
    if(tree->left == nullptr && tree->right == nullptr) return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
    if(tree == nullptr) return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
}

int sumElements(Node* tree) {
    if(tree == nullptr) return 0;
    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if(tree == nullptr) return 0;
    if(level == 0)
        return tree->key;
    return sumElementsAtLevel(tree->left, level - 1 ) + sumElementsAtLevel(tree->right, level - 1);
}

bool isEmpty(Node* tree){
    return tree->left == nullptr && tree->right == nullptr;
}

bool isMirror(Node* leftTree, Node* rightTree ){
    if(leftTree == nullptr && rightTree == nullptr) return true;
    if(isEmpty(leftTree) && isEmpty(rightTree)) return leftTree->key == rightTree->key;
    else if(isEmpty(leftTree) || isEmpty(rightTree)) return false;
    else
        return leftTree->key == rightTree->key && isMirror(leftTree->left, rightTree->right) &&
                isMirror(leftTree->right, rightTree->left);
}

// https://www.baeldung.com/cs/binary-tree-is-symmetric
bool isSymmetric(Node* tree) {
    if( tree == nullptr) return false;
    if(isEmpty(tree)) return true;

    return isMirror(tree->left, tree->right);
}


bool isBTSInOrder(Node* tree, Node* prev){
    if(tree) {
        if(!isBTSInOrder(tree->left, prev))
            return false;
        if(prev!= nullptr && tree->key <- prev->key )
            return false;
        prev = tree;
        return isBTSInOrder(tree->right, prev);

    }
    return true;
}

bool BTS(Node* tree, Node* left, Node* right){
    if(tree == nullptr || isEmpty(tree))
        return true;

    if(left && right && left->key < tree->key && tree->key <= right->key){
        return BTS(left, left->left, left->right) && BTS(right, right->left, right->right);
    }
    else if(left && !right && left->key < tree->key){
            return BTS(left, left->left, left->right);
    }
    else if(!left && right && tree->key <= right->key){
        return BTS(right, right->left, right->right);
    }
    else{
        return false;
    }

}

bool isBST(Node* tree) {
    if(tree == nullptr) return true;
    return BTS(tree, tree->left, tree->right);
}
    //Queue, stack, linked list,  doubly-list, iterator
void print(Node* tree) {
    if (tree == nullptr) return;
    print(tree->left);
    std::cout << tree->key;
    print(tree->right);
}

void inorderTreeWalk(Node* tree, std::vector<int>& numbers){

    if(tree != nullptr) {
        inorderTreeWalk(tree->left, numbers);
        numbers.push_back(tree->key);
        inorderTreeWalk(tree->right, numbers);
    }
}

void preorderTreeWalk(Node* tree, std::vector<int>& numbers){

    if(tree != nullptr) {
        numbers.push_back(tree->key);
        preorderTreeWalk(tree->left, numbers);
        preorderTreeWalk(tree->right, numbers);
    }
}

void postorderTreeWalk(Node* tree, std::vector<int>& numbers){

    if(tree != nullptr) {
        postorderTreeWalk(tree->left, numbers);
        postorderTreeWalk(tree->right, numbers);
        numbers.push_back(tree->key);
    }
}
