#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Create linked list from user input
ListNode* createList(int n) {
    if (n == 0)
        return NULL;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    return head;
}

// Merge function
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if (head1 == NULL || head2 == NULL)
        return (head1 == NULL) ? head2 : head1;

    if (head1->val <= head2->val) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

// Print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1, n2;

    cout << "Enter number of nodes in List 1: ";
    cin >> n1;
    cout << "Enter elements of List 1 (sorted): ";
    ListNode* head1 = createList(n1);

    cout << "Enter number of nodes in List 2: ";
    cin >> n2;
    cout << "Enter elements of List 2 (sorted): ";
    ListNode* head2 = createList(n2);

    ListNode* merged = mergeTwoLists(head1, head2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}