#include <iostream>
#include <time.h>

typedef struct Node_t{
    int data;
    Node_t *next = nullptr;
} Node_t;

void print(Node_t* firstNode) {
    if(firstNode != nullptr) {
        Node_t* nextNode = firstNode;
        while(nextNode != nullptr) {
            std::cout << "( " << nextNode->data << " )   ";
            nextNode = nextNode->next;
        }
        std::cout << std::endl;
    } else {
        std::cout << "The list is empty, start by adding new items" << std::endl;
    }
}

int main()
{
    bool exit = false;
    Node_t* firstNode = nullptr;
    while(!exit) {
        std::cout << "\nChoose an alternative from the menu below: (1-4) \n1. Add new \n2. Remove \n3. Print \n4. Exit" << std::endl;
        int user_input;
        std::cin >> user_input;
        if(user_input == 1) { //New item
            int user_data;
            std::cout << std::endl << "Specify a data to add to the list: " << std::endl;
            std::cin >> user_data;
            Node_t *currentNode= firstNode;
            if (firstNode == nullptr) {
                firstNode = new Node_t;
                currentNode= firstNode;
            } else {
                int user_index;
                std::cout << std::endl << "Specify the index to add the new data to (zero indexed): " << std::endl;
                std::cin >> user_index;
                if (user_index == 0) { //add first in list
                    currentNode= new Node_t;
                    currentNode->next = firstNode;
                    firstNode = currentNode;
                } else {
                    for(int i = 0; i < user_index-1; i++) { //search element to add the new element after
                        currentNode= currentNode->next;
                    }
                    Node_t *nextNode = currentNode->next;
                    currentNode->next = new Node_t;
                    currentNode= currentNode->next;
                    currentNode->next = nextNode;
                }
            }
            currentNode->data = user_data;

        } else if(user_input == 2) { //Remove item
            Node_t *removeNode= firstNode;
            firstNode = firstNode->next;
            delete removeNode;
        } else if(user_input == 3) { //Print
            print(firstNode);
        } else if(user_input == 4) { //Exit
            exit = true;
        } else {
            std::cout << std::endl << "Invalid input, please try again!" << std::endl;
        }
    }
}
