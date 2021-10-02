/*
Given a sorted linked list node of size n, construct a binary search tree by

Taking the value of the k = floor(n / 2)(0-indexed) smallest node and setting it as the root.
Recursively constructing the left subtree using the linked list left of the kth node.
Recursively constructing the right subtree using the linked list right of the kth node.
Constraints

n ≤ 100,000

Example 1
Input
node = [1, 3, 4, 6]
Output
[4, [3, [1, null, null], null], [6, null, null]]

Link: https://binarysearch.com/problems/Linked-List-to-Binary-Search-Tree
*/

/**
 * public class Tree {
 *   int val;
 *   Tree left;
 *   Tree right;
 * }
 */

/**
 * class LLNode {
 *   int val;
 *   LLNode next;
 * }
 */
class LinkedListToBinarySearchTree {
    public Tree linkedListToBinarySearchTree(LLNode node) {
        if (node == null)
            return null;
        if (node.next == null) {
            Tree treeNode = new Tree();
            treeNode.val = node.val;
            return treeNode;
        }
        LLNode slow = node;
        LLNode fast = node.next;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        LLNode mid = slow.next;
        slow.next = null;
        Tree root = new Tree();
        root.val = mid.val;
        root.left = solve(node);
        root.right = solve(mid.next);
        return root;
    }
}
