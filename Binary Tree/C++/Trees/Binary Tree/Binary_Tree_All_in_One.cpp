/*
 Author - Manjur Alam Middey 
 LinkedIn:- https://www.linkedin.com/in/manjur-alam-middey/
In this cpp file I have code :-
01.    Pre Order Traversal of Binary Tree
02.    In Order Traversal of Binary Tree
03.    Post Order Traversal of Binary Tree
04.    Level Order Traversal of Binary Tree
05.    Vertical Order Traversal(O(n^2)) of Binary Tree
06.    Vertical Order Traversal (optimal O(n logn)) of Binary Tree
07.    Left view of Binary Tree
08.    Right view of Binary Tree
09.    Top view of Binary Tree
10.    Bottom view of Binary Tree
11.    Diameter (O(N)) of Binary Tree
12.    Diameter (optimal O(N)) of Binary Tree
13.    Height of Binary Tree
14.    Find maximum value node in Binary Tree
15.    Find minimum value node in Binary Tree
16.    Search a node in Binary Tree
17.    Sum of leaf node in Binary Tree
18.    Find LCA between two nodews in Binary Tree
19.    Find path from root node to given node in Binary Tree
20.    Find path between two given nodes  in Binary Tree
21.    Find distance between two given nodes  in Binary Tree
22.    Sum of Kth level level in Binary Tree
23.    construct binary tree from preorder and inorder traversal
24.    construct binary tree from postorder and inorder traversal
25.    Total no of Nodes in Binary Tree
26.    Sum of all nodes in Binary tree
27.    How mant Binary tree can constructed from n nodes
28.    Identical Binary Tree
29.    Zigzag Traversal
30.    Convert a Binary Tree into its Mirror Tree
31.    Convert a given Binary Tree to Doubly Linked List
*/


#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printPreorder(Node* node)
{
    // in PreOrder print will be - NLR
    if (node == NULL) 
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
} 

void printInorder(Node* node)
{
    // in inOrder print will be - LNR
    if (node == NULL) 
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(Node* node)
{
    // in PostOrder print will be - LRN
    if (node == NULL) 
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printLevelOrder(Node* root)
{
    if(root == NULL) 
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout<<(temp->data)<<" ";
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

void findMInMax(Node *root, int *mn, int *mx, int hd)
{
    if(root==NULL) 
        return;
    *mn = min(*mn, hd);
    *mx = max(*mx, hd);
    findMInMax(root->left, mn, mx, hd-1);
    findMInMax(root->right, mn, mx, hd+1);
}

void printVerticalLine(Node *root, int i, int hd)
{
    if(root==NULL) 
        return;
    if(hd==i)
        cout<<(root->data)<<" ";

    printVerticalLine(root->left, i, hd-1);
    printVerticalLine(root->right, i, hd+1);
}

void printVerticalOrder(Node* root)
{
    int min=0, max=0;
    findMInMax(root, &min, &max, 0);
    for(int i=min; i<=max; i++)
    {
        printVerticalLine(root, i, 0);
    }
}

void getVerticalOrder(Node *root, int hd, map<int, vector<int> > &m)
{
    if(root==NULL) 
        return;
    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrderMap(Node* root)
{
    map<int, vector<int> >m;
    int hd = 0;
    getVerticalOrder(root, hd, m);
    map<int, vector<int> > ::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
        {
            cout<<it->second[i]<<" ";
        }
    }
}

bool isNodePresent(Node *root, int x)
{
    if (root == NULL) 
        return false;
    if (root->data == x) 
        return true;
    /* then recur on left sutree */
    bool res1 = isNodePresent(root->left, x);
    // node found, no need to look further
    if(res1) 
        return true;

    /* node is not found in left, so recur on right subtree */
    bool res2 = isNodePresent(root->right, x);
    return res2;
}

int minElmentInBT(Node *root)
{
    if (root == NULL)
      return INT_MAX;
    // Return minimum of 3 values:
    // 1) Root's data 2) Min in Left Subtree 3) Min in right subtree
    int res = root->data;
    int lres = minElmentInBT(root->left);
    int rres = minElmentInBT(root->right);
    if (lres < res)  
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}

int maxElmentInBT(Node *root)
{
    if (root == NULL)
      return INT_MIN;
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree 3) Max in right subtree
    int res = root->data;
    int lres = maxElmentInBT(root->left);
    int rres = maxElmentInBT(root->right);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}
int countAllnode(Node *root)
{
    if(root == NULL)
        return 0;
    return 1+countAllnode(root->left)+countAllnode(root->right);
}
int sumOfAllNodes(Node *root)
{
    if(root == NULL)
        return 0;
    return (root->data+sumOfAllNodes(root->left)+sumOfAllNodes(root->right));
}
void leaf_Sum(Node *root, int &sum)
{
    if(!root) 
        return;
    if(!root->left && !root->right)
    {
         sum += root->data;
    }
    leaf_Sum(root->left, sum);
    leaf_Sum(root->right, sum);
}

int sumOfLeafNodes(Node *root)
{
    int sum = 0;
    leaf_Sum(root, sum);
    return sum;
}

void printLeftView(Node *root)
{
    if(root== NULL) 
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=1; i<=n; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(i==1){
                cout<<(temp->data)<<" ";
            }
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void printRightView(Node *root)
{
    if(root== NULL) 
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=1; i<=n; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(i==n){
                cout<<(temp->data)<<" ";
            }
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void fillMap(Node* root, int d, int l, map<int, pair<int, int> >& m)
{
    if (root == NULL)
        return;

    if (m.count(d) == 0) {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l) {
        m[d] = make_pair(root->data, l);
    }

    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}
void printTopView(Node* root)
{
    map<int, pair<int, int> > m;
    // fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}

void printBottomViewUtil(Node *root, int curr, int hd, map<int, pair<int, int> > &m)
{
    if(root == NULL)
        return;
    // If node for a particular hd is not present, add to map
    if(m.find(hd) == m.end())
        m[hd] = make_pair(root->data, curr);
    else
    {
        pair<int, int> p = m[hd];
        if(p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root->data;
        }
    }
    printBottomViewUtil(root->left, curr+1, hd-1, m);
    printBottomViewUtil(root->right, curr+1, hd+1, m);
}
void printBottomView(Node *root)
{
    map<int, pair<int, int> > m;
    printBottomViewUtil(root, 0, 0, m);
    map<int, pair<int,int> > :: iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        pair<int, int> p = it->second;
        cout<<p.first<<" ";
    }
}

int sumOfKthLevel(Node *root, int level)
{
    int temp = 0;
    int sum = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        temp ++;
        for(int i=0; i<n; i++)
        {
            Node *node = q.front();
            if(temp == level)
                sum += (node->data);
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
    }
    return sum;
}
int height(Node *root)
{
    if(root == NULL) 
        return 0;
    return 1+max(height(root->left), height(root->right));
}

bool isPath(Node *root, vector<int>&vec, int x)
{
    if(root == NULL) 
        return false;
    vec.push_back(root->data);
    if(root->data == x) 
        return true;
    if(isPath(root->left, vec, x) || isPath(root->right, vec, x))
        return true;
    vec.pop_back();
    return false;
}

void printPath(Node*root, int x)
{
    vector<int> vec;
    if(isPath(root, vec, x))
    {
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }
    }
    else{
        cout<<"No Path is found...!!!";
    }
}

void printPathBetweenNodes(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    isPath(root, path1, n1);
    isPath(root, path2, n2);
    int intersection = -1;
    // Get intersection point
    int i = 0, j = 0;
    while (i != path1.size() || j != path2.size()) {

        // Keep moving forward until no intersection
        // is found
        if (i == j && path1[i] == path2[j]) {
            i++;
            j++;
        }
        else {
            intersection = j - 1;
            break;
        }
    }

    // Print the required path
    for (int i = path1.size() - 1; i > intersection; i--)
        cout << path1[i] << " ";

    for (int i = intersection; i < path2.size(); i++)
        cout << path2[i] << " ";
}

int diameterN2(Node *root)
{
    if(root == NULL) 
        return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    int left_diameter = diameterN2(root->left);
    int right_diameter = diameterN2(root->right);

    return max(1+left_height+right_height, max(left_diameter, right_diameter));
}

int diameterOptimal(Node *root, int *height)
{
    int lh=0, rh=0, ldia=0, rdia=0;
    if(root == NULL){
        *height = 0;
        return 0;
    }
    ldia = diameterOptimal(root->left, &lh);
    rdia = diameterOptimal(root->right, &rh);

    *height = max(lh, rh)+1;
    return max(1+lh+rh, max(ldia, rdia));
}

Node* findLCA(Node *root, int n1, int n2)
{
    if(root == NULL) 
        return NULL;
    if(root->data == n1 || root->data == n2) 
        return root;

    Node *leftLCA = findLCA(root->left, n1, n2);
    Node *rightLCA = findLCA(root->right, n1, n2);

    if(leftLCA && rightLCA) return root;
    if(leftLCA == NULL) return rightLCA;
    else return leftLCA;

}

int findLevel(Node *root, int k, int level)
{
    if(root==NULL)
        return -1;
    if(root->data == k) 
        return level;

    int left = findLevel(root->left, k, level+1);
    if(left == -1)
        return findLevel(root->right, k, level+1);
    return left;
}

int distanceBetweenNodes(Node *root, int a, int b)
{
    Node *lca = findLCA(root, a, b);
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
    return d1+d2;
}
int search(int arr[], int l, int r, int value)
{
    for(int i=l; i<=r; i++)
    {
        if(arr[i] == value)
            return i;
    }
}
Node* buildTreePreIn(int in[], int pre[], int start, int end)
{
    static int preIdx = 0;
    if(start>end)
        return NULL;
    Node *node = new Node(pre[preIdx++]);
    if(start == end)
        return node;
    int inIdx = search(in, start, end, node->data);
    node->left =  buildTreePreIn(in, pre, start, inIdx-1);
    node->right = buildTreePreIn(in, pre, inIdx+1, end);
    return node;
}
Node* buildTreePostIn(int in[], int post[], int start, int end, int *postIdx)
{
    if(start>end)
        return NULL;
    Node *node = new Node(post[*postIdx]);
    (*postIdx)--;
    if(start == end)
        return node;
    int inIdx = search(in, start, end, node->data);
    node->right = buildTreePostIn(in, post, inIdx+1, end, postIdx);
    node->left =  buildTreePostIn(in, post, start, inIdx-1, postIdx);
    return node;
}

long long int factorial(long long int n)
{
    if(n==1)
        return 1;
    return n*factorial(n-1);
}
long long int catalan(long long int n)
{
    if(n <= 1)
        return 1;
    long long int res = 0;
    for(long long int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);
    return res;
}
long long int countConstructedBT(long long int n)
{
    return catalan(n)*factorial(n);
}

bool identicalBT(Node *a, Node *b)
{
    if(a==NULL && b==NULL)
        return true;
    if(a && b)
    {
        bool op1 = a->data == b->data;
        bool op2 = identicalBT(a->left, b->left);
        bool op3 = identicalBT(a->right, b->right);
        if(op1 && op2 && op3)
            return true;
    }
    return false;
}

void zigzagTraversal(Node* root)
{
    if(root == NULL)
        return;
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    currLevel.push(root);
    bool leftToright = true;
    while(!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();
        if(temp)
        {
            cout<<temp->data<<" ";
            if(leftToright)
            {
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if(temp->right)
                    nextLevel.push(temp->right);
                if(temp->left)
                    nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty())
        {
            leftToright = !leftToright;
            swap(currLevel, nextLevel);
        }
    }
}

void mirrorOfBT(Node* root)
{
    if(root == NULL)
        return;
    else
    {
        mirrorOfBT(root->left);
        mirrorOfBT(root->right);
        swap(root->left, root->right);
    }
}

void BinaryTree2DoubleLinkedList(Node *root, Node **head)
{
    if(root == NULL)
        return;
    static Node *prev = NULL;
    BinaryTree2DoubleLinkedList(root->left, head);
    if(prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BinaryTree2DoubleLinkedList(root->right, head);
}
void printLinkedList(Node *node)
{
    while (node!=NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}
// This is only for boundry traversal of BT:-
void printLeft(Node* root, vector<int> &res)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            res.push_back(root->data);
            printLeft(root->left, res);
        }
        else if(root->right)
        {
            res.push_back(root->data);
            printLeft(root->right, res);
        }
    }
    void printRight(Node* root, vector<int> &res)
    {
        if(root==NULL)
            return;
        if(root->right)
        {
            printRight(root->right, res);
            res.push_back(root->data);
        }
        else if(root->left)
        {
            printRight(root->left, res);
            res.push_back(root->data);
        }
    }
    void printLeaves(Node* root, vector<int> &res)
    {
        if(root==NULL)
            return;
        printLeaves(root->left, res);
        if(root->left==NULL && root->right==NULL)
            res.push_back(root->data);
        printLeaves(root->right, res);
    }
    vector <int> printBoundary(Node *root)
    {
        vector <int> res;
        if(root==NULL)   
            return res;
        res.push_back(root->data);
        printLeft(root->left, res);
        printLeaves(root, res);
        printRight(root->right, res);

        return res;
    }
// This is only for boundry traversal of BT {end here}
// Driver Code
int main()
{

    // Contrust the Tree
    //      1
    //     /  \
    //    2    3
    //   / \  / \
    //  4   5 6  7
    // / \      / \
    //8   9    10  11

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->left->left->left = new Node(8); 
    root->left->left->right = new Node(9); 
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);


    cout << "\nPreorder traversal of binary tree is : ";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is : ";
    printInorder(root); 

    cout << "\nPostorder traversal of binary tree is : ";
    printPostorder(root);

    cout << "\nLevelorder traversal of binary tree is : ";
    printLevelOrder(root);

    cout << "\nVerticalorder traversal of binary tree is : ";
    printVerticalOrder(root);

    cout << "\nVerticalorder traversal using map of binary tree is : ";
    printVerticalOrderMap(root);

    cout << "\nLeft View of binary tree is : ";
    printLeftView(root);

    cout << "\nRight View of binary tree is : ";
    printRightView(root);

    cout << "\nTop View of binary tree is : ";
    printTopView(root);

    cout << "\nBottom View of binary tree is : ";
    printBottomView(root);

    cout << "\nHeight of binary tree is : ";
    cout<<height(root);

    cout << "\nPath from root to (10) in binary tree : ";
    printPath(root, 10);

    cout << "\nPath for unknown value in binary tree : ";
    printPath(root, 50);

    cout << "\nLCA of (6, 11) binary tree : ";
    cout<<findLCA(root, 6, 11)->data;

    cout << "\nDiameter (O(N^2)) of binary tree : ";
    cout<<diameterN2(root);

    cout << "\nDiameter (Optimal O(N)) of binary tree : ";
    int height = 0;
    cout<<diameterOptimal(root, &height);

    cout << "\nPath between (8, 5) in binary tree : ";
    printPathBetweenNodes(root, 8, 5);

    cout << "\nDistance between (8, 5) in binary tree : ";
    cout<<distanceBetweenNodes(root, 8, 5);

    cout << "\nIs 10 present in binary tree : ";
    cout<<isNodePresent(root, 10);

    cout << "\nIs 15 present in binary tree : ";
    cout<<isNodePresent(root, 15);

    cout << "\nMaximum element on binary tree : ";
    cout<<maxElmentInBT(root);

    cout << "\nMinimum element on binary tree : ";
    cout<<minElmentInBT(root);

    cout << "\nSum of leaf nodes on binary tree : ";
    cout<<sumOfLeafNodes(root);

    cout << "\nSum of Kth level in binary tree : ";
    cout<<sumOfKthLevel(root, 3);

    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7, 10, 11};
    int in[] = {8, 4, 9, 2, 5, 1, 6, 3, 10, 7, 11};
    int post[] = {8, 9, 4, 5, 2, 6, 10, 11, 7, 3, 1};
    int len = sizeof(in) / sizeof(in[0]);
    cout << "\nInorder traversal of the constructed (preorder and inorder) tree is : ";
    Node* node1 = buildTreePreIn(in, pre, 0, len - 1);
    printInorder(node1);
    cout << "\nInorder traversal of the constructed (postorder and inorder) tree is : ";
    int postIdx = len-1;
    Node* node2 = buildTreePostIn(in, post, 0, len - 1, &postIdx);
    printInorder(node2);

    cout<<"\nTotal no of nodes in binary tree is : ";
    cout<<countAllnode(root);

    cout<<"\nSum of all nodes in binary tree is : ";
    cout<<sumOfAllNodes(root);

    cout<<"\nCount of Binary tree with 5 nodes is: ";
    cout<<countConstructedBT(5);

    cout<<"\nCheck whether both trees are identical of not: ";
    cout<<identicalBT(root, root);

    cout<<"\nZigzag traversal of Binary Tree: ";
    zigzagTraversal(root);

    // mirror of Binary Tree
    mirrorOfBT(root);
    cout<<"\nMirror of Binary tree(inorder): ";
    printInorder(root);
    mirrorOfBT(root);

    // BT Convert to DLL
    Node *head = NULL;
    BinaryTree2DoubleLinkedList(root, &head);
    cout<<"\nPrint the converted Doubly Linked list: ";
    printLinkedList(head);

    cout<<"\n\n";
    return 0;
}
