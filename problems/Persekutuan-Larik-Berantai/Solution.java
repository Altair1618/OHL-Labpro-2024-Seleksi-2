import java.util.Scanner;

public class Solution {
    private static int gcd(int data, int data2) {
        if (data2 == 0) {
            return data;
        }
        return gcd(data2, data % data2);
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            ll.insert(x);
        }
        sc.close();

        // insert the GCD of n and n+1, between n and n+1
        Node currNode = ll.head;
        while (currNode.next != null) {
            int gcd = gcd(currNode.data, currNode.next.data);
            ll.insert(currNode, gcd);
            currNode = currNode.next.next;
        }

        ll.printList();
        sc.close();
    }
}

class LinkedList {

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

class Node {

    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}