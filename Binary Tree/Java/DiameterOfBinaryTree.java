public class DiameterOfBinaryTree {
    /**
     * The diameter of a tree is the number of nodes on the longest path between two end nodes.
     */
    
    static class Node {
        int data;
        Node left, right;
    
        public Node(int data) {
          this.data = data;
          left = null;
          right = null;
        }
    }

    static class Height{
        int hi;
    }

    public static void main(String args[]){
        Node node = new Node(1);
        node.left = new Node(2);
        node.right = new Node(3);
        node.left.left= new Node(4);
        node.left.right= new Node(5);
        node.right.left= new Node(6);
        node.right.right= new Node(7);
        int diameter = findDiameterOfBinaryTree(node,new Height());
        System.out.println("Diameter of the binary tree is "+diameter);
    }

    private static int findDiameterOfBinaryTree(Node node, Height h) {
        if(node == null){
            h.hi = 0;
            return 0;
        }
        Height lheight = new Height();
        Height rHeight = new Height();
        //Recurisvely finding left diameter
        int lDiam = findDiameterOfBinaryTree(node.left, lheight);
        //Recurisvely finding right diameter
        int rDiam = findDiameterOfBinaryTree(node.right, rHeight);
        //Finding height of the node
        h.hi = Math.max(lheight.hi, rHeight.hi) + 1;
        
        return Math.max(lheight.hi + rHeight.hi + 1, Math.max(lDiam, rDiam));

    }
}
/*
Input  -      1         (Node is included in the diameter)
            /   \
           2     3
          / \   / \
         4   5  6  7
Output: Diameter of the binary tree is 5

Time Complexity : O(n)
*/