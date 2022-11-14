#include "catch2/catch_all.hpp"
#include "solution.h"

using namespace std;

void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
Node* createTree(){
    Node* tree = new Node(6);

    tree->left = new Node(5);
    tree->left->left = new Node(2);
    tree->left->right = new Node(5);
    tree->right = new Node(7);
    tree->right->right = new Node(8);

    return tree;
}

TEST_CASE("Validate countElements") {
    Node* test = new Node(5);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);

    CHECK(countElements(nullptr) == 0);
    CHECK(countElements(test) == 4);
    test->left->left->right = new Node(18);
    CHECK(countElements(test) == 5);
    clean(test);
}


TEST_CASE("Validate countLeafs") {
    Node* test = new Node(5);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);
    CHECK(countLeafs(nullptr) == 0);
    CHECK(countLeafs(test) == 2);
    test->left->left->right = new Node(18);
    test->left->left->left = new Node(20);
    CHECK(countLeafs(test) == 3);
    clean(test);
}

TEST_CASE("Validate height") {
    CHECK(height(nullptr) == 0);
    Node* test = new Node(5);
    CHECK(height(test) == 1);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);
    test->left->left->right = new Node(18);
    CHECK(height(test) == 4);
    clean(test);
}

TEST_CASE("Validate sumElements") {
    CHECK(sumElements(nullptr) == 0);
    Node* test = new Node(5);
    CHECK(sumElements(test) == 5);
    test->left = new Node(6);
    test->right = new Node(1);
    test->left->left = new Node(2);
    test->left->left->right = new Node(3);
    CHECK(sumElements(test) == 17);
    clean(test);
}

TEST_CASE("Validate sumElementsAtLevel") {
    CHECK(sumElementsAtLevel(nullptr, 0) == 0);
    Node* test = new Node(5);
    CHECK(sumElementsAtLevel(test,0) == 5);
    test->left = new Node(6);
    test->right = new Node(1);
    test->left->left = new Node(2);
    test->left->left->right = new Node(3);
    CHECK(sumElementsAtLevel(test, 0) == 5);
    CHECK(sumElementsAtLevel(test, 1) == 7);
    CHECK(sumElementsAtLevel(test, 2) == 2);
    CHECK(sumElementsAtLevel(test, 3) == 3);

    clean(test);

}

TEST_CASE("Validate isSymmetric") {
    Node* test = new Node(5);
    CHECK(isSymmetric(test) == true);

    test->left = new Node(6);
    test->right = new Node(1);
    CHECK(isSymmetric(test) == false);

    test->left->key = 1;
    CHECK(isSymmetric(test) == true);

    test->left->left = new Node(2);
    test->right->right = new Node(2);
    CHECK(isSymmetric(test) == true);

    test->right->right = new Node(3);
    CHECK(isSymmetric(test) == false);
    clean(test);
}

TEST_CASE("Validate isBST") {

    Node* test = new Node(5);
    CHECK(isBST(test) == true);


    test->left = new Node(0);
    CHECK(isBST(test) == true);

    test->left->key = 12;
    CHECK(isBST(test) == false);

    test->left->key = 0;
    test->right = new Node(10);
    CHECK(isBST(test) == true);

    test->right->right = new Node(20);
    CHECK(isBST(test) == true);

    test->right->left = new Node(30);
    CHECK(isBST(test) == false);

    clean(test);
}

TEST_CASE("Validate inorder tree walk"){
    Node* test = createTree();
    std::vector<int> expected;
    expected.push_back(2);
    expected.push_back(5);
    expected.push_back(5);
    expected.push_back(6);
    expected.push_back(7);
    expected.push_back(8);

    std::vector<int> toTest;
    inorderTreeWalk(test, toTest);
    while (!expected.empty()){
        CHECK(expected.back() == toTest.back());
        expected.pop_back();
        toTest.pop_back();
    }
    clean(test);
}

TEST_CASE("Validate preorder tree walk"){
    Node* test = createTree();
    std::vector<int> expected;
    expected.push_back(6);
    expected.push_back(5);
    expected.push_back(2);
    expected.push_back(5);
    expected.push_back(7);
    expected.push_back(8);

    std::vector<int> toTest;
    preorderTreeWalk(test, toTest);
    while (!expected.empty()){
        CHECK(expected.back() == toTest.back());
        expected.pop_back();
        toTest.pop_back();
    }
    clean(test);
}

TEST_CASE("Validate postorder tree walk"){
    Node* test = createTree();
    std::vector<int> expected;
    expected.push_back(2);
    expected.push_back(5);
    expected.push_back(5);
    expected.push_back(8);
    expected.push_back(7);
    expected.push_back(6);

    std::vector<int> toTest;
    postorderTreeWalk(test, toTest);
    while (!expected.empty()){
        CHECK(expected.back() == toTest.back());
        expected.pop_back();
        toTest.pop_back();
    }
    clean(test);
}
