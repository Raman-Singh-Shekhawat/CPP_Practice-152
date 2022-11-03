// 170. Level wise linkedlist: Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

/**********************************************************

    Following are the Binary Tree Node class structure and
    the Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    template <typename T>
    class Node {
        public:
        T data;
        Node<T> *next;
        Node(T data) {
            this->data=data;
            this->next=NULL;
        }
    };

***********************************************************/

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    bool newNode = true;

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL)
        {
            if (pendingNodes.empty())
            {
                ans.push_back(head);
                break;
            }
            ans.push_back(head);
            pendingNodes.push(NULL);
            head = tail = NULL;
            newNode = true;
        }
        else
        {
            if (newNode)
            {
                head = new Node<int>(front->data);
                tail = head;
                newNode = false;
            }
            else
            {
                Node<int> *node = new Node<int>(front->data);
                tail->next = node;
                tail = node;
            }
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }
    }

    return ans;
}