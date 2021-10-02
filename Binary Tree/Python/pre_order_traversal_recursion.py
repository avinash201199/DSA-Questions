# Recursive function to perform pre-order traversal of the tree
def preorder(root):
 
    # return if the current node is empty
    if root is None:
        return
 
    # Display the data part of the root (or current node)
    print(root.data, end=' ')
 
    # Traverse the left subtree
    preorder(root.left)
 
    # Traverse the right subtree
    preorder(root.right)
