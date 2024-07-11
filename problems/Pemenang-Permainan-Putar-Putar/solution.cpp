#include <bits/stdc++.h>

#define ll                      long long
#define all(v)                  (v).begin(), (v).end()
#define forn(var, n)            for (ll var = 0; var < n; ++var)
#define forr(var, start, end)   for (ll var = start; var < end; ++var)
#define fori(var, start, end)   for (ll var = start; var > end; --var)
#define fora(var, obj)          for (auto var : obj)
#define MOD1                    (ll) (1e9 + 7)
#define MOD9                    (ll) (998244353)
#define prints(x)               cout << (x) << " "
#define println(x)              cout << (x) << "\n"
#define newl()                  cout << "\n"

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;
    Node* tail;

    CircularLinkedList() {
        this->head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            tail = head;

            return;
        }

        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    /**
     * Deletes the given node and returns the data of the deleted node.
     * @param node
     * @return int
     */
    int deleteNode(Node* node) {
        if (node == head) {
            int data = head->data;

            if (head->next == head) {
                head = nullptr;
                delete node;

                return data;
            } else {
                head = head->next;
                tail->next = head;
                delete node;

                return data;
            }
        }

        Node* temp = head;
        while (temp->next != node) {
            temp = temp->next;
        }

        if (node == tail) {
            tail = temp;
        }

        temp->next = node->next;
        int data = node->data;
        delete node;

        return data;
    }

    /**
     * Prints the circular linked list.
     * @return void
     */
    void printList() {
        Node* temp = head;
        
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

void solve() {
    ll n, k; cin >> n >> k;

    CircularLinkedList* cll = new CircularLinkedList();
    forn(i, n) {
        cll->insert(i + 1);
    }

    Node* temp = cll->head;
    while (cll->head->next != cll->head) {
        forn(i, k - 1) {
            temp = temp->next;
        }

        Node* next = temp->next;
        cout << cll->deleteNode(temp) << endl;
        temp = next;
    }

    prints("Survivor:");
    println(cll->head->data);
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}