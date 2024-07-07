#include <iostream>
#include <queue>
#include <stack>
using namespace ::std;

class BinarySearchTree
{
private:
    struct Node
    {
        int data;
        Node *left = nullptr, *right = nullptr;
    };
    Node *root = nullptr;
    Node *createNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        return newNode;
    }

    int countLeaves(Node *root)
    {
        if (root == nullptr)
            return 0;
        else if (root->left == nullptr && root->right == nullptr)
            return 1;

        int lc = countLeaves(root->left);
        int rc = countLeaves(root->right);
        return lc + rc;
    }

public:
    BinarySearchTree(int data)
    {
        root = createNode(data);
    }

    bool isEmpty()
    {
        return (root == nullptr);
    }

    Node *getRoot()
    {
        return root;
    }

    int countLeafNodes()
    {
        return countLeaves(root);
    }

    int getHeight(Node *root)
    {
        if (root == nullptr)
            return -1;

        int lHeiht = getHeight(root->left);
        int rHeight = getHeight(root->right);
        int m = lHeiht > rHeight ? lHeiht : rHeight;
        return 1 + m;
    }

    void insert(Node *root, int data)
    {
        if (root == nullptr)
        {
            root = createNode(data);
            return;
        }
        else if (data < root->data)
        {
            if (root->left == nullptr)
            {
                root->left = createNode(data);
                return;
            }
            else
                insert(root->left, data);
        }
        else if (data > root->data)
        {
            if (root->right == nullptr)
            {
                root->right = createNode(data);
                return;
            }
            else
                insert(root->right, data);
        }
        // only executes when data equals the data of any node
        else
        {
            cout << "Node already exists in tree!" << endl;
            return;
        }
    }

    void deleteNode(int value)
    {
        if (isEmpty())
        {
            cout << "Tree is empty!!" << endl;
            return;
        }

        // search the node
        Node *curr = root, *prev = nullptr;
        while (curr && curr->data != value)
        {
            prev = curr;
            if (value > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // check if value is not found
        if (!curr)
        {
            cout << "Value doesn't exist in Tree!!" << endl;
            return;
        }

        // if the curr has no nodes
        if (!curr->left && !curr->right)
        {
            // if not first node;
            // if prev is nullptr, means root node
            if (prev)
            {
                if (prev->left == curr)
                    prev->left = nullptr;
                else
                    prev->right = nullptr;
            }
            else
                root = nullptr;
            delete curr;
        }
        // if the curr has nodes on only one side
        else if (!curr->left || !curr->right)
        {
            // if prev is nullptr, means root node, if not then other node
            if (prev)
            {
                // if nodes are on left side of curr
                // assign left nodes to appropriate side of prev
                if (curr->left)
                {
                    if (curr == prev->left)
                        prev->left = curr->left;
                    else
                        prev->right = curr->left;
                }
                // if nodes are on right side of curr
                // assign right nodes to appropriate side of prev
                else
                {
                    if (curr == prev->left)
                        prev->left = curr->right;
                    else
                        prev->right = curr->right;
                }
            }
            else
            {
                if (root->left)
                    root = root->left;
                else if (root->right)
                    root = root->right;
            }
            delete curr;
        }
        else
        {
            Node *temp = curr->right, *prevTemp = curr;
            while (temp->left != nullptr)
            {
                prevTemp = temp;
                temp = temp->left;
            }
            // on temp's left there exists no value
            // assign prevTemp left to right of temp
            prevTemp->left = temp->right;

            // assign childs of curr to temp
            temp->right = curr->right;
            temp->left = curr->left;

            // link the temp with previous (parent) node
            // if deletion node is not root node
            if (prev)
            {
                if (prev->right == curr)
                    prev->right = temp;
                else
                    prev->left = temp;
            }
            else
                root = temp;

            delete curr;
            curr = nullptr;
        }
    }

    bool search(int data)
    {
        Node *temp = root;
        while (temp != nullptr)
        {
            if (data == temp->data)
                return true;
            else if (data < temp->data)
                temp = temp->left;
            else if (data > temp->data)
                temp = temp->right;
        }
        cout << "Value not found!!" << endl;
        return false;
    }

    void inOrderTraversal(Node *root)
    {
        if (root == nullptr)
            return;

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void preOrderTraversal(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void postOrderTraversal(Node *root)
    {
        if (root == nullptr)
            return;

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    void levelOrderTraversal()
    {
        if (isEmpty())
            return;

        queue<Node *> q;
        q.push(root);
        q.push(nullptr);

        Node *temp = nullptr;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp)
            {
                cout << temp->data << " ";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (!q.empty())
            {
                cout << endl;
                q.push(nullptr);
            }
        }
        cout << endl;
    }

    void preOrderIterative()
    {
        if (isEmpty())
            return;

        stack<Node *> s;
        s.push(root);

        Node *temp = nullptr;
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";

            // if intemediate node
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        cout << endl;
    }

    void inOrderIterative()
    {
        if (isEmpty())
            return;

        Node *curr = root;
        stack<Node *> s;
        while (!s.empty() || curr)
        {
            if (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
        cout << endl;
    }

    void postOrderIterative()
    {
        if (isEmpty())
            return;

        stack<Node *> s;

        Node *curr = root;
        while (!s.empty() || curr)
        {
            if (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                Node *temp = s.top()->right;
                if (temp)
                    curr = temp;
                else
                {
                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";
                    while (!s.empty() && temp == s.top()->right)
                    {
                        temp = s.top();
                        s.pop();
                        cout << temp->data << " ";
                    }
                }
            }
        }
        cout << endl;
    }

    int findCeil(int key)
    {
        int ceil = INT_MIN;
        Node *curr = root;

        while (curr)
        {
            if (key == curr->data)
                return curr->data;
            if (key > curr->data)
                curr = curr->right;
            else
            {
                ceil = curr->data;
                curr = curr->left;
            }
        }
        return ceil;
    }

    int findFloor(int key)
    {
        int ceil = INT_MIN;
        Node *curr = root;

        while (curr)
        {
            if (key == curr->data)
                return curr->data;
            if (key < curr->data)
                curr = curr->left;
            else
            {
                ceil = curr->data;
                curr = curr->right;
            }
        }
        return ceil;
    }

    int sumNodes(Node *root)
    {
        if (root == nullptr)
            return 0;

        int leftSum = root->data + sumNodes(root->left);
        int rightSum = leftSum + sumNodes(root->right);
        return rightSum;
    }
    bool matchVal(Node *root, int val)
    {
        if (root == nullptr)
            return false;

        if (root->data == val)
            return true;
        else if (root->data < val)
            return matchVal(root->right, val);
        else
            return matchVal(root->left, val);
    }

    bool sameValue(Node *root1, Node *root2)
    {
        if (!root2)
            return true;

        bool check = matchVal(root1, root2->data);

        if (!check)
            return false;

        bool leftCheck = sameValue(root1, root2->left);
        bool rightCheck = sameValue(root1, root2->right);

        return leftCheck && rightCheck;
    }

    bool sameStructure(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
            return true;
        if ((!root1 && root2) || (root1 && !root2))
            return false;

        bool leftCheck = sameStructure(root1->left, root2->left);
        bool rightCheck = sameStructure(root1->right, root2->right);

        return leftCheck && rightCheck;
    }
};

int main()
{
    BinarySearchTree t(20);
    t.insert(t.getRoot(), 30);
    t.insert(t.getRoot(), 10);
    t.insert(t.getRoot(), 15);
    t.insert(t.getRoot(), 5);
    t.insert(t.getRoot(), 17);
    t.insert(t.getRoot(), 35);
    t.insert(t.getRoot(), 25);

    BinarySearchTree t1(12);
    t1.insert(t1.getRoot(), 15);
    t1.insert(t1.getRoot(), 6);
    t1.insert(t1.getRoot(), 8);
    t1.insert(t1.getRoot(), 2);

    // cout << t.sameValue(t.getRoot(), t1.getRoot());
    // cout << t.sameStructure(t.getRoot(), t1.getRoot());

    // t.postOrderTraversal(t.getRoot());
    // cout << endl;
    // t.inOrderTraversal(t.getRoot());
    // cout << endl;
    // t.preOrderTraversal(t.getRoot());
    // cout << endl;
    // t.levelOrderTraversal();
    // t.preOrderIterative();

    cout << t.countLeafNodes();
    // t.inOrderIterative();
    // t.postOrderIterative();

    // t.deleteNode(19);
    // t.inOrderIterative();
    // cout << t.getHeight(t.getRoot());
    // cout << t.findFloor(22);

    // cout << t.sumNodes(t.getRoot());
    return 0;
}