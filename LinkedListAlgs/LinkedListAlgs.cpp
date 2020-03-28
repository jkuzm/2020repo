// LinkedListAlgs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1. How to Find Middle Element of Linked List in Single Pass
// Read more : https://javarevisited.blogspot.com/2012/12/how-to-find-middle-element-of-linked-list-one-pass.html#ixzz6HqRecfzx
// 2. Not here. How do you check if a given linked list contains a cycle? How do you find the starting node of the cycle?
// It's in older project algs_findPermutations_FloydCycleFind
// 3. How do you reverse a linked list? using nice short video https://www.youtube.com/watch?v=D7y_hoT_YZI
// 4. How do you reverse a singly linked list without recursion: using 3 pointers in iteration
// 5.  How are duplicate nodes removed in an unsorted linked list?
// 5.1 using 2 loops https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/?source=post_page---------------------------
// 6.1 size of list iterative
// 6.2 size of list recursive
// 7 Get Nth from last node in linked list
// 8. How do you find the sum of two linked lists using Stack
// 8.1 Using a loop algo as a simple sample: for reverse order of digits, 1->2->3 = 321 https://www.youtube.com/watch?v=LLPuC5kWD8U
// 8.2 use of stack for both numbers as link represent direct order of digits: 1->2->3 = 123

#include <iostream>
#include <list> 
#include <unordered_set>
#include <stack>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void reverseIteratively(Node** head_ref) {
    Node* prev = NULL;
    Node* curr = *head_ref;
    Node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev; // will be updated in upper level by using reference to the head
}

Node* reverseRecursively(Node* head) {
    Node* newHead;
    if (head->next == NULL) //base case
        return head;
    newHead = reverseRecursively(head->next);
    head->next->next = head;
    head->next  = NULL;
    cout << "current node with NULL: " << head->data << " returning newHead: " << newHead->data << endl;
    
    return newHead;
}

void push(Node** head_ref, int val) {
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printLinksInList(Node* headNode) {
    int circuitBreak = 20;
    for (Node* iter = headNode; iter != NULL && iter->next != NULL && --circuitBreak > 0; iter = iter->next) {
        cout << "Node " << iter->data << " --> " << iter->next->data << endl;
    }
}

void printNodesInList(Node* head) {
    int circuitBreak = 20;
    for (Node* iter = head; iter != NULL && --circuitBreak > 0; iter = iter->next) {
        cout << "Node " << iter->data;
        if (iter->next != NULL)
            cout << " --> ";
        else
            cout << endl;
    }

}

void removeDupsUsing2Loops(Node * head) {
    Node* ptr1 = head, * ptr2, * dup;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr2->next->data == ptr1->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete dup;
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void removeDupsUsingSetOfSeen(Node* head) {
    unordered_set<int> seen;
    Node * curr;
    Node * prev = NULL;

    if (head != NULL) {
        curr = head;
    
        while (curr != NULL) {
            if (seen.find(curr->data) != seen.end()) {
                if (prev != NULL) //to adress comp warning
                    prev->next = curr->next;
                delete curr;
            }
            else {
                prev = curr;
                seen.insert(curr->data);
            }
            if (prev != NULL)
                curr = prev->next;
        }
    }
}

int sizeOfListIterative(Node* head) {
    int size = 0;
    for (Node* curr = head; curr != NULL; curr = curr->next)
        size++;
    return size;
}

int sizeOfListRecursive(Node* curr) {
    if (curr == NULL)
        return 0; //base case
    return 1 + sizeOfListRecursive(curr->next);
}

Node * getNthFromLastNode(Node* head, int n) {
    Node* lead = head;
    Node* lag = NULL;
    int cnt = 0;
    while (lead != NULL) {
        if (cnt++ == n) {
            if(lag != NULL)
                lag = head;
        }
        if (cnt > n) {
            if(lag != NULL)
                lag = lag->next;
        }
        lead = lead->next;
    }
    return lag;
}

//find the sum of two linked lists where 1->2->3 would be 321 so the head of list is an LSD (least significant digit)

Node* add2listsReverseOrderDigits(Node* first, Node* second, Node** res) {

    int carry = 0, sum;
    stack<int> resStacked;
    while (first != NULL || second != NULL) {
        sum = carry + ((first) ? first->data : 0) + ((second) ? second->data : 0);
        carry = sum / 10;
        sum = sum % 10;
        resStacked.push(sum);

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    // and here it goes, using stack as a result is in an opposite order if places in linst as is


    if (carry > 0)
        resStacked.push(carry);

    while (!resStacked.empty()) {
        push(res, resStacked.top());
        resStacked.pop();
    }
    return *res;
}
inline void linkedList2Stack(Node* ll, stack<int>& ss_ref) {
    while (ll != NULL) {
        ss_ref.push(ll->data);
        ll = ll->next;
    }
}

inline void queue2List(queue<int>& ss_ref, Node** head) {
    if (*head != NULL) //list must be terminated with NULL
        *head = NULL;
    while (!ss_ref.empty()) {
        push(head, ss_ref.front());
        ss_ref.pop();
    }
}

Node* add2ListsDirectOrderDigits(Node* first, Node* second) {
    stack<int> st1, st2;
    queue<int> resQue;
    Node* resList = NULL;
    linkedList2Stack(first, st1);
    linkedList2Stack(second, st2);
    int val1, val2, sum = 0, carry = 0;
    while (!st1.empty() || !st2.empty()) {
        val1 = (st1.empty()) ? 0 : st1.top();
        val2 = (st2.empty()) ? 0 : st2.top();
        if (!st1.empty()) {
            val1 = st1.top();
            st1.pop();
        }
        else val1 = 0;
        if (!st2.empty()) {
            val2 = st2.top();
            st2.pop();
        }
        else val2 = 0; 
        sum = carry + val1 + val2;
        carry = sum / 10;
        sum = sum % 10;
        resQue.push(sum);
    }
    if(carry > 0)
        resQue.push(sum);
    queue2List(resQue, &resList);
    return resList;
}

int main()
{
    std::cout << "Hello World!\n";
    list<int> mylist({ 10,20,30,40,50,60,70 });
    for (auto i : mylist) {
        cout << i << " ";
    }
    cout << endl;
    list<int>::iterator fullspeed_it = mylist.begin();
    list<int>::iterator halfspeed_it = mylist.begin();
    int len = 0;
    while (fullspeed_it != mylist.end()) {
        if (++len % 2 == 0)
            halfspeed_it++;
        fullspeed_it++;
    }
    //if(len%2 == 1)
       // halfspeed_it++;
    cout << "1. middle of linked list is : " << *halfspeed_it;
    
    Node* myNodes = NULL;
    push(&myNodes, 11);
    push(&myNodes, 12);
    push(&myNodes, 13);
    push(&myNodes, 14);
    push(&myNodes, 15);
    cout << "\nmyNodes links:" << endl;
    printLinksInList(myNodes);
    reverseIteratively(&myNodes);
    cout << "2.1 - reverse in iteration with3 pointers" << endl;
    printLinksInList(myNodes);
    cout << "2.2 - reverse with recursion" << endl;
    Node *newHead = reverseRecursively(myNodes);
    printLinksInList(newHead);
    cout << "Lets insert some dups" << endl;
    push(&newHead, 11);
    push(&newHead, 15);
    printLinksInList(newHead);
    printNodesInList(newHead);
    removeDupsUsing2Loops(newHead);
    cout << "After removal of dups using 2 loops" << endl;
    printNodesInList(newHead);
    cout << "Lets insert some more dups for 2nd function of dup removal" << endl;
    push(&newHead, 12);
    push(&newHead, 14);
    printNodesInList(newHead);
    removeDupsUsingSetOfSeen(newHead);
    cout << "after dups removal" << endl;
    printNodesInList(newHead);
    cout << "Iterative: size of this list is : " << sizeOfListIterative(newHead) << endl;
    cout << "Recursive: size of this list is : " << sizeOfListRecursive(newHead) << endl;
    Node *nth_p = getNthFromLastNode(newHead, 3);
    if (nth_p == NULL)
        cout << "This list has no " << 3 << "rd element." << endl;
    else
        cout << "3rd node is "<< nth_p->data;
    cout << "Lets add 2 lists (digits order is reversed, the head is a least significant digit)" << endl;
    Node* list1 = NULL, * list2 = NULL;
    push(&list1, 1);
    push(&list1, 9);
    push(&list2, 3);
    push(&list2, 4);
    push(&list2, 5);
    printNodesInList(list1);
    cout << "and" << endl;
    printNodesInList(list2);
    Node* res = NULL;
    res = add2listsReverseOrderDigits(list1, list2, &res);
    cout << "result of sum :" << endl;
    printNodesInList(res);
    cout << "same lists but in direct order of digits" << endl;
    res = add2ListsDirectOrderDigits(list1, list2);
    printNodesInList(res);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
