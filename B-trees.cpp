#include <iostream>
using namespace std;

class BTreeNode {
    int *keys;          // Array of keys
    int m;              // Minimum degree (defines the range for number of keys)
    BTreeNode **pointer; // Array of child pointers
    int keyTally;       // Current number of keys
    bool isLeaf;        // True if the node is a leaf node

public:
    BTreeNode(int m, bool isLeaf);
    void traverse();

    // Search key in subtree rooted with this node
    BTreeNode *search(int k);

    // Insert a new key in the subtree rooted with this node
    void insertNonFull(int k);

    // Split the child y of this node
    void splitChild(int i, BTreeNode *y);

    friend class BTree;
};

class BTree {
    BTreeNode *root; // Pointer to root node
    int m;           // Minimum degree

public:
    BTree(int m) {
        root = nullptr;
        this->m = m;
    }

    void traverse() {
        if (root != nullptr)
            root->traverse();
    }

    BTreeNode *search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k);
};

BTreeNode::BTreeNode(int m1, bool leaf) {
    m = m1;
    isLeaf = leaf;
    keys = new int[2 * m - 1];
    pointer = new BTreeNode *[2 * m];
    keyTally = 0;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keyTally; i++) {
        if (!isLeaf)
            pointer[i]->traverse();
        cout << " " << keys[i];
    }
    if (!isLeaf)
        pointer[i]->traverse();
}

BTreeNode *BTreeNode::search(int k) {
    int i = 0;
    while (i < keyTally && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (isLeaf)
        return nullptr;

    return pointer[i]->search(k);
}

void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(m, true);
        root->keys[0] = k;
        root->keyTally = 1;
    } else {
        if (root->keyTally == 2 * m - 1) {
            BTreeNode *s = new BTreeNode(m, false);
            s->pointer[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->pointer[i]->insertNonFull(k);

            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = keyTally - 1;

    if (isLeaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        keyTally = keyTally + 1;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (pointer[i + 1]->keyTally == 2 * m - 1) {
            splitChild(i + 1, pointer[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        pointer[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->m, y->isLeaf);
    z->keyTally = m - 1;

    for (int j = 0; j < m - 1; j++)
        z->keys[j] = y->keys[j + m];

    if (!y->isLeaf) {
        for (int j = 0; j < m; j++)
            z->pointer[j] = y->pointer[j + m];
    }

    y->keyTally = m - 1;

    for (int j = keyTally; j >= i + 1; j--)
        pointer[j + 1] = pointer[j];

    pointer[i + 1] = z;

    for (int j = keyTally - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[m - 1];
    keyTally = keyTally + 1;
}

int main() {
    BTree t(3);

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed B-tree is: ";
    t.traverse();

    int key = 6;
    (t.search(key) != nullptr) ? cout << "\nKey " << key << " is found"
                                : cout << "\nKey " << key << " is not found";

    return 0;
}
