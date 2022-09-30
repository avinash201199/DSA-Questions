/*
 * 1. Implementation of linkedList Class (Node, data)
 * 2. Append Method: add value in the end of list
 * 3. Prepend Method: add value in the beginning of list
 * 4. deleteByValue Mathod: delete value from list
 * 5. isCyclicLinkedList Method:  Check if linkedList is cyclic in nature 
*/

public class LinkedList {

	public static class Node {
		private int data;
		private Node next;

		Node(int data) {
			this.data = data;
		}
	}

	private Node head;

	// add Node to the end of the linkedList
	public void append(Node n) {
		if (head == null) {
			head = n;
		} else {
			Node pointer = head;

			while (pointer.next != null) {
				pointer = pointer.next;
			}
			pointer.next = n;
		}

	}

	// prepand node
	public void prepend(Node n) {
		if (head != null) {
			n.next = head;
			head = n;
		}
	}

	public void deleteByValue(int data) {
		if (head != null) {
			if (head.data == data) {
				head = head.next;
			} else {
				Node pointer = head;
				while (pointer.next != null) {
					if (pointer.next.data == data) {

						pointer.next = pointer.next.next;
						return;
					}
					pointer = pointer.next;
				}
			}
		}
	}

	public boolean isCyclicLinkedList() {

		Node n1 = head;
		Node n2 = head.next;

		if (head == null)
			return false;

		while (n1 != null && n1.next != null && n2 != null && n2.next != null) {
			if (n1 == n2)
				return true;

			n1 = n1.next;
			n2 = n2.next.next;

		}
		return false;
	}

	public static void main(String[] args) {

		// create LinkedList
		LinkedList l = new LinkedList();
		// append & prepend values
		Node n = new Node(3);

		l.append(new Node(2));
		l.append(n);
		l.append(new Node(4));
		l.append(new Node(5));
		l.append(n);
		l.prepend(new Node(1));

		System.out.println(l.isCyclicLinkedList());

		// create second LinkedLIst
		LinkedList l2 = new LinkedList();
		// add values
		l2.append(new Node(2));
		l2.append(new Node(5));
		// delete value
		l2.deleteByValue(5);

		System.out.println(l2.isCyclicLinkedList());

	}

}