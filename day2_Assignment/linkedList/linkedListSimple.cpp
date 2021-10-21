#include <iostream>
#include <typeinfo>


typedef struct Node {
    int     data;
    struct Node *next = nullptr;    
}Node_t;


Node_t *findLast(Node_t *LinkedList) {
    if (LinkedList == nullptr) {    
        return LinkedList;
    }
    Node_t *current = LinkedList;
     while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void add(Node_t *LinkedList, int value) {

    if (LinkedList == nullptr) {
        // std::cout << "add: LinkedList == nullptr" << std::endl; 
        // LinkedList = new Node_t;
        LinkedList->data  = value;
        LinkedList->next = nullptr;        
    } else {
        Node_t  *newNode = new Node_t,
                *lastNode = findLast(LinkedList);
        newNode->next = nullptr;
        newNode->data = value;
        lastNode->next = newNode;    
    }
}

Node_t *remove(Node_t *LinkedList) {
    if (LinkedList == nullptr) {
        return LinkedList;
    }
    Node_t *next = LinkedList->next;
    std::cout << LinkedList->data << "  is removed" << std::endl; 
    delete LinkedList;
    return next;
}

void print(Node_t *LinkedList) 
{

    if (LinkedList == nullptr) {
        std::cout << "print: LinkedList == nullptr" << std::endl; 
        return;    
    }
    std::cout << "Printing data of linked list:" << std::endl; 
    while(LinkedList != nullptr) {
        std::cout << LinkedList->data << std::endl; 
        LinkedList = LinkedList->next;       
    }
}



int main()
{
    int data;
    int choice;
    Node_t *myList = new Node_t;
    std::cout << "Enter a number to make a list:" << std::endl;
    std::cin >> data;
    myList->data = data;

    while(1)
    {
    std::cout << "What to do? 1.Add number to end of the list 2.Remove from first 3.Print 4.Exit:" << std::endl;
    std::cin >> choice;
    if(choice == 1)
    {
    std::cout << "Enter the number:" << std::endl;
    std::cin >> data;
    add(myList,data);
    }
    else if(choice == 2)
    {
        myList = remove(myList);
    }
    else if (choice == 3)
    {
        print(myList);
    }
    else 
    {
        if (choice == 4)
        delete myList;
        return 0;
    }
}

    delete myList;
    return 0;

}