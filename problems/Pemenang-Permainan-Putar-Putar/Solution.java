import java.util.Scanner;

public class Solution {
    private static void survivor(CircularLinkedList cl, int k) {
        Node currNode = cl.head;
        while (cl.head != cl.tail) {
            for (int i = 0; i < k - 1; i++) {
                currNode = currNode.next;
            }
            System.out.println(currNode.data);
            cl.delete(currNode);
            currNode = currNode.next;
        }
        System.out.println("Survivor: " + cl.head.data);
    }

    public static void main(String[] args) {
        CircularLinkedList cl = new CircularLinkedList();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            cl.insert(i);
        }
        int k = sc.nextInt();
        sc.close();
        survivor(cl, k);
    }
}

class CircularLinkedList {
    Node head;
    Node tail;

    /**
     * Inserts a new node at the end of the circular linked list.
     * 
     * @param data The data for the new node.
     */
    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
            newNode.next = head;
        } else {
            tail.next = newNode;
            tail = newNode;
            tail.next = head;
        }
    }

    /**
     * Delete a node from the circular linked list.
     */

    public void delete(Node node) {
        if (head == null) {
            System.out.println("The list is empty.");
            return;
        }
        if (head == node) {
            if (head == tail) {
                head = null;
                tail = null;
            } else {
                head = head.next;
                tail.next = head;
            }
            return;
        }
        Node temp = head;
        while (temp.next != head && temp.next != node) {
            temp = temp.next;
        }
        if (temp.next == head) {
            System.out.println("The node is not in the list.");
            return;
        }
        if (temp.next == tail) {
            tail = temp;
        }
        temp.next = temp.next.next;
    }

    /**
     * Displays all nodes in the circular linked list.
     */
    public void printList() {
        if (head == null) {
            System.out.println("The list is empty.");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
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
