class BinNode<E> {
    private BinNode<E> left, right;
    private E data;

    public BinNode(E data, BinNode<E> left, BinNode<E> right) {
        this.left = left;
        this.right = right;
        this.data = data;
    }

    public BinNode<E> getLeft() {
        return left;
    }

    public void setLeft(BinNode<E> left) {
        this.left = left;
    }

    public BinNode<E> getRight() {
        return right;
    }

    public void setRight(BinNode<E> right) {
        this.right = right;
    }

    public E getData() {
        return data;
    }

    public void setData(E data) {
        this.data = data;
    }
}

class BinTree<E> {
    private BinNode<E> root;

    public BinTree(BinNode<E> root) {
        this.root = root;
    }

    public BinNode<E> getRoot() {
        return root;
    }

    public void setRoot(BinNode<E> root) {
        this.root = root;
    }
}
