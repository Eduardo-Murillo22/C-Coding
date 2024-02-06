#include<iostream>
#include<ctime>
#include<queue>

using namespace std;

struct Tnode {
    int data;
    struct Tnode *right;
    struct Tnode *left;
    int height; // Added for balancing
};

class tree {
public:
    Tnode *root;

    tree() : root(NULL) {}

    Tnode *insert(Tnode *current, int data) {
        if (current == NULL) {
            Tnode *newNode = new Tnode;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = 1; // New node has height 1
            return newNode;
        }
        else if (data < current->data) {
            current->left = insert(current->left, data);
        }
        else if (data >= current->data) {
            current->right = insert(current->right, data);
        }

        // Update height of the current node
        current->height = 1 + max(height(current->left), height(current->right));

        // Get the balance factor
        int balance = getBalance(current);

        // Perform rotations if necessary
        if (balance > 1) {
            if (data < current->left->data) {
                return rotateRight(current);
            } else {
                current->left = rotateLeft(current->left);
                return rotateRight(current);
            }
        }

        if (balance < -1) {
            if (data > current->right->data) {
                return rotateLeft(current);
            } else {
                current->right = rotateRight(current->right);
                return rotateLeft(current);
            }
        }

        return current;
    }

    Tnode *Delete(Tnode *current, int data) {
        if (current == NULL) {
            return current;
        }

        if (data < current->data) {
            current->left = Delete(current->left, data);
        } else if (data > current->data) {
            current->right = Delete(current->right, data);
        } else {
            if (current->left == NULL) {
                Tnode* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == NULL) {
                Tnode* temp = current->left;
                delete current;
                return temp;
            }

            Tnode* temp = minValueNode(current->right);

            current->data = temp->data;
            current->right = Delete(current->right, temp->data);
        }

        // Update height of the current node
        current->height = 1 + max(height(current->left), height(current->right));

        // Get the balance factor
        int balance = getBalance(current);

        // Perform rotations if necessary
        if (balance > 1) {
            if (getBalance(current->left) >= 0) {
                return rotateRight(current);
            } else {
                current->left = rotateLeft(current->left);
                return rotateRight(current);
            }
        }

        if (balance < -1) {
            if (getBalance(current->right) <= 0) {
                return rotateLeft(current);
            } else {
                current->right = rotateRight(current->right);
                return rotateLeft(current);
            }
        }

        return current;
    }
    //in order traversal
    void INdisplay(Tnode* node) {
        if (node != NULL) {
            INdisplay(node->left);
            cout << node->data << " ";
            INdisplay(node->right);
        }
    }

    //Post order traversal

    void POSTdisplay(Tnode* node) {
        if (node != NULL) {
            POSTdisplay(node->left);
            POSTdisplay(node->right);
            cout << node->data << " ";
            
        }
    }

    //in order traversal

    void PREdisplay(Tnode* node) {
        if (node != NULL) {
            cout << node->data << " ";
            PREdisplay(node->left);
            PREdisplay(node->right);
        }
    }
    
    //Level traversal
    void LevelDisplay() {
        if (root == nullptr) {
            return;
        }

        std::queue<Tnode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            Tnode* current = nodeQueue.front();
            nodeQueue.pop();

            std::cout << current->data << " ";

            if (current->left != NULL) {
                nodeQueue.push(current->left);
            }

            if (current->right != NULL) {
                nodeQueue.push(current->right);
            }
        }
    }


private:
    int height(Tnode* node) {
        if (node == NULL) return 0;
        return node->height;
    }

    int getBalance(Tnode* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    Tnode* rotateRight(Tnode* y) {
        Tnode* x = y->left;
        Tnode* T2 = x->right;

        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Tnode* rotateLeft(Tnode* x) {
        Tnode* y = x->right;
        Tnode* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Tnode* minValueNode(Tnode* node) {
        Tnode* current = node;

        while (current->left != NULL) {
            current = current->left;
        }

        return current;
    }
};

int main() {
    srand(static_cast<unsigned int> (time(NULL)));
    tree T;
    int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    
//    insert 10 random elements
    cout << "Array added int to the tree" << endl;
    for(int i=0;i < 10;i++){
//        int Rnum = rand()% 20 + 1;
        T.root = T.insert(T.root, test[i]);   
//        cout << Rnum << " ";
    }
    cout << endl << endl;
    
    
    cout << endl;
    cout << "In Order traversal display" << endl;
    T.INdisplay(T.root);
    cout << endl;

    cout << endl;
    cout << "Post Order traversal " << endl;
    T.POSTdisplay(T.root);
    cout << endl;

    cout << endl;
    cout << "Pre-Order traversal" << endl;
    T.PREdisplay(T.root);
    cout << endl;

    cout << endl;
    cout << "Level Order traversal(From top to bottom)" << endl;
    T.LevelDisplay();
    cout << endl;
    return 0;
}
