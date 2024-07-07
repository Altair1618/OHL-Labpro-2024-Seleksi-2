
public class LinkedList {

    Node head; // head of the list, initially null

    /**
     * Inserts a new node with the given data at the end of the list.
     * 
     * @param data The data to be inserted in the new node.
     */
    public void insert(int data) {
        Node new_node = new Node(data);
        new_node.next = null;

        if (head == null) {
            head = new_node;
        } else {
            Node last = head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = new_node;
        }
    }

    /**
     * Inserts a new node with the given data after the specified node.
     * 
     * @param node The node after which the new data node is to be inserted.
     * @param data The data to be inserted in the new node.
     */
    public void insert(Node node, int data) {
        Node new_node = new Node(data);
        new_node.next = node.next;
        node.next = new_node;
    }

    /**
     * Prints the linked list starting from the head node.
     */
    public void printList() {
        Node currNode = head;
        System.out.print("[");
        while (currNode != null) {
            System.out.print(currNode.data);
            if (currNode.next != null) {
                System.out.print(", ");
            }
            currNode = currNode.next;
        }
        System.out.println("]");
    }
}
