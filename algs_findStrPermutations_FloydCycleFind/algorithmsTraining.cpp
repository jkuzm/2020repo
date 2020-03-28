// algorithmsTraining.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1. find and print all permutations of a string using recursive functions
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// 2. Floyds cycle finding algorithm from here https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/


#include <iostream>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) //we reached base in iterations
        cout << str << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[i], str[l]);
        }
    }
}

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int val) {
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printLinksInList(Node* headNode) {
    int circuitBreak = 20;
    for (Node* iter = headNode; iter != NULL &&  iter->next != NULL && --circuitBreak > 0; iter = iter->next) {
        cout << "Node " << iter->data << " --> " << iter->next->data << endl;
    }
}

void detectLoop(Node* list) {
    Node* slow_p = list, * fast_p = list;
    cout << "\nslow_p data " << slow_p->data << " fast_p data " << fast_p->data << endl;

    int it = 0;
    bool foundLoop = false;

    while (slow_p != NULL && fast_p != NULL && fast_p->next != NULL) { // I could skip != NULL but keeping for readability
        
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        it++;
        if (slow_p == fast_p) {
            cout << "slow_p data " << slow_p->data << " fast_p data " << fast_p->data << endl;
            cout << "Found a loop in iteration : " << it << endl;
            foundLoop = true;
            break;
        }
        else
            cout << "slow_p data " << slow_p->data << " fast_p data " << fast_p->data << endl;

    }
    if (!foundLoop) {
        cout << "Not found loop after iteration : " << it << endl;
    }
    else {
        cout << "Now - looking for a val of position where ponter is skewed: " << endl;
        //according to Floyds algorithm rule: now keeping fast_p, z-ing slow_p and
        //moving one step at a time for each:
        //This 2nd part of algorithm - to find a position of a cycle - doesn't work for me as 2 cycles meet in pos 0
        slow_p = list;
        while(fast_p != slow_p) {
            cout << "slow_p data " << slow_p->data << " fast_p data " << fast_p->data << endl;
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
        cout << "Found a cycle in a Node with value : " << slow_p->data << endl;
    }

}

int main()
{
    std::cout << "Hello World!\n";
    string str = "ABC";
    permute(str, 0, str.size() - 1);

    Node* head = NULL;

    push(&head, 5);
    push(&head, 10);
    push(&head, 15);
    push(&head, 20);
    push(&head, 25);
    push(&head, 30);
    push(&head, 35);
    push(&head, 40);
    push(&head, 45);
    push(&head, 50);
    push(&head, 55);
    printLinksInList(head);

    //for debug we create a loop:
    Node * cycled_node_p = head->next->next->next->next->next->next->next->next->next->next;
    cycled_node_p->next = head->next->next;
    cout << "we insert wrong link into element with value : " << cycled_node_p->data << endl;
    cout << "after creating  this cycle:" << endl;
    printLinksInList(head);

    detectLoop(head);
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
