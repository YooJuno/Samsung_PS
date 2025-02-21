#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* nxtNode;
};

struct HeadNode
{
    Node* head;
};

HeadNode* createList()
{
    HeadNode* h = new HeadNode;
    h->head = NULL;
    return h;
}

void pushBack(HeadNode* headNode, int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->nxtNode = NULL;
    
    if(headNode->head == NULL)
    {
        headNode->head = newNode;
        return ;
    }

    Node* lastNode = headNode->head;
    while(lastNode->nxtNode != NULL)
    {
        lastNode = lastNode->nxtNode;
    }

    lastNode->nxtNode = newNode;
}

void popBack(HeadNode* headNode)
{
    if(headNode->head == NULL) return;

    Node* newNode = headNode->head;
    Node* preNode;

    while(newNode->nxtNode != NULL)
    {
        preNode = newNode; // 도태
        newNode = newNode->nxtNode; // 진화
    }
    free(newNode);
    preNode->nxtNode = NULL;
}

void printAllNode(HeadNode* headNode)
{
    Node* newNode = headNode->head;

    while(newNode != NULL)
    {
        cout << newNode->data;
        newNode = newNode->nxtNode;
        if(newNode != NULL) cout << " -> ";
    }

    cout << endl;
}

auto main() -> int
{
    HeadNode* H = createList();
    pushBack(H, 10);
    pushBack(H, 9);

    pushBack(H, 8);
    popBack(H);
    
    pushBack(H, 7);
    pushBack(H, 6);

    pushBack(H, 5);
    popBack(H);
    
    pushBack(H, 4);
    pushBack(H, 3);

    pushBack(H, 2);
    popBack(H);

    printAllNode(H);
    
    return 0;
}