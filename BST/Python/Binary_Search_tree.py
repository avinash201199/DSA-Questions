# Binary Search Tree operations in Python


# Create a node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def inorder(root):
    if root is not None:
        inorder(root.left)
        print(str(root.data) + "->", end=' ')
        inorder(root.right)
def preorder(root):
    if root is not None:
        print(str(root.data) + "->", end=' ')
        preorder(root.left)
        preorder(root.right)
def postorder(root):
    if root is not None:
        postorder(root.left)
        postorder(root.right)
        print(str(root.data) + "->", end=' ')


# Insert a node
def insert(node, key):
    if node is None:
        return Node(key)
    if key < node.data:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)
    return node

def searchNode(node, key):
    if (node == None):
        return False
 
    if (node.data == key):
        return True
 

    lsearch = searchNode(node.left, key)
 
    if lsearch:
        return True
 

    rsearch = searchNode(node.right, key)
 
    return rsearch
def searchResult(node, key):
    if (searchNode(node,key)):
        print(f"\nYes {key} does exist")
    else:
        print(f"\nNo {key} does not exist")




def minValueNode(node):
    cur= node


    while(cur.left is not None):
        cur = cur.left

    return cur



def deleteNode(root, key):


    if root is None:
        return root


    if key < root.data:
        root.left = deleteNode(root.left, key)
    elif(key > root.data):
        root.right = deleteNode(root.right, key)
    else:
      
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

      
        temp = minValueNode(root.right)

        root.data = temp.data

    
        root.right = deleteNode(root.right, temp.data)

    return root


root = None
root = insert(root, 11)
root = insert(root, 10)
root = insert(root, 21)
root = insert(root, 61)


print("\nInorder traversal: ", end=' ')
inorder(root)
print("\npostorder traversal: ", end=' ')
postorder(root)
print("\npreorder traversal: ", end=' ')
preorder(root)
searchResult(root,3)
root = deleteNode(root, 11)
root = deleteNode(root,30)
root = deleteNode(root, 21)
root = deleteNode(root, 61)
print("Inorder traversal: ", end=' ')
inorder(root)
searchResult(root,23)



