import java.util.Scanner;

public class Main {
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
