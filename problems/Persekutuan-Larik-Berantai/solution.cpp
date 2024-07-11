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

class LinkedList {
public:
    Node *head;

    LinkedList() {
        this->head = nullptr;
    }

    /**
     * Insert data to the end of the linked list
     * @param data
     * @return void
     */
    void insert(int data) {
        Node *newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    /**
     * Insert data after the given node
     * @param prev
     * @param data
     * @return void
     */
    void insert(Node *prev, int data) {
        if (prev == nullptr) {
            return;
        }

        Node *newNode = new Node(data);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    /**
     * Output the linked list with this format
     * [1, 2, 3, 4, 5]
     * @return void
     */
    void print() {
        Node *temp = head;
        
        cout << "[";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        
        cout << "]" << endl;
    }
};

void solve() {
    ll n; cin >> n;

    LinkedList list;
    forn(i, n) {
        ll x; cin >> x;
        list.insert(x);
    }

    Node *curr = list.head;
    while (curr->next != nullptr) {
        Node* prev = curr;
        curr = curr->next;
        list.insert(prev, gcd(prev->data, curr->data));
    }

    list.print();
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