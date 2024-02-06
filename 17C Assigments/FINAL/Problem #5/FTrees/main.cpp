#include <iostream>
#include <map>
#include <list>
#include <random>
#include <algorithm>

using namespace std;

struct TreeNode {
    string initials;
    int index;
    int height;
    TreeNode *left, *right;

    TreeNode(string i, int ind) : initials(i), index(ind), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode *node) {
    return (node != nullptr) ? node->height : 0;
}

int getBalance(TreeNode *node) {
    return (node != nullptr) ? getHeight(node->left) - getHeight(node->right) : 0;
}

void updateHeight(TreeNode *node) {
    if (node != nullptr) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

TreeNode *rotateRight(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode *rotateLeft(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode *insertToTree(TreeNode *root, const string &initials, int index) {
    if (root == nullptr) {
        return new TreeNode(initials, index);
    }

    if (initials < root->initials) {
        root->left = insertToTree(root->left, initials, index);
    } else if (initials > root->initials) {
        root->right = insertToTree(root->right, initials, index);
    } else {
        root->right = insertToTree(root->right, initials, index);
        return root;
    }

    // Update height of the current node
    updateHeight(root);

    // Get the balance factor to check if this node became unbalanced
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && initials < root->left->initials) {
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && initials > root->right->initials) {
        return rotateLeft(root);
    }

    // Left Right Case
    if (balance > 1 && initials > root->left->initials) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && initials < root->right->initials) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void deleteTree(TreeNode *root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void countNodesInTree(TreeNode *root, int &nodeCount) {
    if (root != nullptr) {
        countNodesInTree(root->left, nodeCount);
        nodeCount++;
        countNodesInTree(root->right, nodeCount);
    }
}

int countLevels(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftLevels = countLevels(root->left);
        int rightLevels = countLevels(root->right);
        return 1 + max(leftLevels, rightLevels);
    }
}

int searchInTree(TreeNode *root, const string &initials, int &nodeCount) {
    // Increment node count as we start traversing the tree
    nodeCount++;

    // Base cases: root is null or the initials are found
    if (root == nullptr || root->initials == initials) {
        return (root != nullptr) ? root->index : -1;
    }

    // Recur down the tree
    if (initials < root->initials) {
        return searchInTree(root->left, initials, nodeCount);
    } else {
        return searchInTree(root->right, initials, nodeCount);
    }
}

int hashing(const string &IN) {
    int val = 0;
    map<string, int> LtoN{
        {"A", 2},
        {"B", 2},
        {"C", 2},
        {"D", 3},
        {"E", 3},
        {"F", 3},
        {"G", 4},
        {"H", 4},
        {"I", 4},
        {"J", 5},
        {"K", 5},
        {"L", 5},
        {"M", 6},
        {"N", 6},
        {"O", 6},
        {"P", 7},
        {"Q", 7},
        {"R", 7},
        {"S", 7},
        {"T", 8},
        {"U", 8},
        {"V", 8},
        {"W", 9},
        {"X", 9},
        {"Y", 9},
        {"Z", 9}};

    for (int i = 0; i < IN.size(); i++) {
        map<string, int>::iterator it = LtoN.begin();

        while (it != LtoN.end()) {
            if (toupper(IN[i]) == (it->first)[0]) {
                val = val * 10 + it->second;
            }
            ++it;
        }
    }
    return val % 512;
}

string generateRandomInitials(mt19937 &rng) {
    string initials;

    uniform_int_distribution<int> distribution('A', 'Z');
    for (int i = 0; i < 3; ++i) {
        char randomLetter = static_cast<char>(distribution(rng));
        initials += randomLetter;
    }

    return initials;
}

int searchInList(list<int> linked_list, int target, int &nodeCount) {
    auto initialIt = linked_list.begin(); // Store the initial iterator position

    for (auto it = linked_list.begin(); it != linked_list.end(); ++it) {
        ++nodeCount;
        if (*it == target) {
            int distanceFromInitial = distance(initialIt, it);
            nodeCount += distanceFromInitial;
            return distance(linked_list.begin(), it);
        }
    }

    return -1; // Element not found
}

void displayHashTable(list<int> *linkedListArray, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Slot " << i << ": ";
        for (auto it = linkedListArray[i].begin(); it != linkedListArray[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main() {
    int size = 512;
    TreeNode *avlTree = nullptr;  // Single AVL tree
    list<int> *linkedListArray = new list<int>[size];

    mt19937 rng(random_device{}());

    int randNumber = 420;
    string searchInitials;
    int searchInitialsHash;
    int find = 0;

    for (int i = 0; i < size; i++) {
        string Initials = generateRandomInitials(rng);
        if (randNumber == i) {
            searchInitials = Initials;
            searchInitialsHash = hashing(Initials);
            find = i;
        }
        avlTree = insertToTree(avlTree, Initials, i);
        linkedListArray[hashing(Initials)].push_back(i);
    }

    // Count nodes in the AVL tree
    int avlNodeCount = 0;
    countNodesInTree(avlTree, avlNodeCount);

    // Display the entire hash table
//    displayHashTable(linkedListArray, size);

    // Search in the AVL tree
    int searchNodeCountAvl = 0;
    int searchResultAvl = searchInTree(avlTree, searchInitials, searchNodeCountAvl);

    // Print the results for AVL tree
    if (searchResultAvl != -1) {
        cout << "Letters to find in AVL tree: " << searchInitials << endl;
        cout << "Number of nodes traversed during search in AVL tree: " << searchNodeCountAvl << endl;
    } else {
        cout << "Element not found in AVL tree." << endl;
        cout << "Number of nodes traversed during search in AVL tree: " << searchNodeCountAvl << endl;
    }

    // Search for an element in the linked list
    int searchNodeCountList = 0;
    int searchResultList = searchInList(linkedListArray[searchInitialsHash], find, searchNodeCountList);
    
    

    // Print the search result for linked list
    if (searchResultList != -1) {
        cout << "Index found in slot " << searchInitials << ": hash -> " << searchInitialsHash << " (+1 node + distance -> " << searchResultList+1 << ")" << endl;
        cout << "Number of nodes traversed during search in linked list: " << searchNodeCountList << endl;
    } else {
        cout << "Element with index " << find << " not found in the linked list." << endl;
        cout << "Number of nodes traversed during search in linked list: " << searchNodeCountList << endl;
    }

    // Clean up memory
    deleteTree(avlTree);
    delete[] linkedListArray;

    return 0;
}
