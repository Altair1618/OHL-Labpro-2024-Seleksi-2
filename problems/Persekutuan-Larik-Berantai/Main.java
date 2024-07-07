import java.util.Scanner;

public class Main {
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
