#ifndef WEEK6_TREE_H
#include <iostream>
#include <vector>
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
};

int countElements(Node*);
int countLeafs(Node*);
int sumElements(Node*);
int sumElementsAtLevel(Node*, unsigned);
int height(Node*);
bool isBST(Node*);
bool isSymmetric(Node*);
void inorderTreeWalk(Node* tree, std::vector<int>& numbers);
void preorderTreeWalk(Node* tree, std::vector<int>& numbers);
void postorderTreeWalk(Node* tree, std::vector<int>& numbers);

#define WEEK6_TREE_H

#endif //WEEK6_TREE_H
