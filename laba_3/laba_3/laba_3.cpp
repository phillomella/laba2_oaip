/*Построить двоичное дерево поиска из букв вводимой строки.
Вывести его на экран в виде дерева. Удалить из дерева все буквы, встречающиеся
более одного раза. Вывести оставшиеся элементы дерева.*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class TreeNode {
public:
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char ch) {
        value = ch;
        left = NULL;
        right = NULL;
    }
};

void insert(TreeNode*& root, char ch) {
    if (root == NULL) {
        root = new TreeNode(ch);
    }
    else if (ch < root->value) {
        insert(root->left, ch);
    }
    else {
        insert(root->right, ch);
    }
}

void printTree(TreeNode* root, int depth = 0) {
    if (root == NULL) {
        return;
    }
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << root->value << endl;
    printTree(root->left, depth + 1);
}

void removeDuplicates(TreeNode*& root, map<char, int>& count) {
    if (root == NULL) {
        return;
    }
    removeDuplicates(root->left, count);
    removeDuplicates(root->right, count);
    if (count[root->value] > 1) {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            root = temp;
        }
        else {
            TreeNode* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->value = temp->value;
            removeDuplicates(root->right, count);
        }
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    TreeNode* root = NULL;
    for (char ch : str) {
        if (isalpha(ch)) {
            insert(root, ch);
        }
    }

    printTree(root);

    map<char, int> count;
    for (char ch : str) {
        if (isalpha(ch)) {
            count[ch]++;
        }
    }

    removeDuplicates(root, count);

    cout << "After removing duplicates: " << endl;
    printTree(root);

    return 0;
}