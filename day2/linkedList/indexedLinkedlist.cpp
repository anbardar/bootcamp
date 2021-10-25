#include <iostream>


typedef struct struct_list{
    int number;
    //struct struct_list *prevoius = nullptr;
    struct struct_list *next = nullptr;
} list;




list* findNode(unsigned int index)
{
    list *current_Node = this->first_Node;
    for(int i = 0; i < index; i++) {
        current_Node = current_Node->next;
    }
    return current_Node;
}

void add(void *MYlist, unsigned int index) 
{
    list *current_Node;
    if (this->first_Node == nullptr) {
        this->first_Node = new list;
        current_Node = this->first_Node;
    } else {
        if (index == 0) { //add first in list
            current_Node = new list;
            current_Node->next = first_Node;
            first_Node = current_Node;
        } else {
            current_Node = findNode(index-1); //find the node to add the new node after
            list *next_Node = current_Node->next;
            current_Node->next = new list;
            current_Node = current_Node->next;
            current_Node->next = next_Node;
        }
    }
    current_Node->MYlist = MYlist;
}



void remove(unsigned int index) 
{


        list *current_Node;
        
            if (index == 0)
        {
        current_Node = findNode(index);
        current_Node->next = nullptr;
        } else

        {
        list *temp_Node;
        current_Node = findNode(index-1);
        temp_Node = findNode(index);
        current_Node->next=temp_Node->next;
        
        }
}



void *getMYlist(unsigned int index) {
    list *node = findNode(index);
    void *MYlist = nullptr;
    if (node != nullptr) {
        MYlist = node->MYlist;
    }
    return MYlist;
}

void printList(unsigned int index)
{
    //needs to define the previous pointer and make a loop list too, 2 make the print works efficiently
}





// int main()
// {
//     int number;
//     int userchoice;
//     int index;
//     list myList;
    
//     std::cout << "Enter a number to your list and then your desired index of it, the list starts fr 0:" << std::endl;
//     std::cin >> number >> index;
//     list->number = number;
//     list->next 

//     while(1)
//     {
//     std::cout << "What to do? 1.Add a number to wanted index? 2.Remove with index 3.Print 4.Exit:" << std::endl;
//     std::cin >> userchoice;
//     if(choice == 1)
//     {
//     std::cout << "Enter the number and index:" << std::endl;
//     std::cin >> number >> index;
//     add(myList,index);
//     }
//     else if(userchoice == 2)
//     {
//         remove(index);
//     }
//     else if (userchoice == 3)
//     {

//     }
//     else 
//     {
//         if (choice == 4)
//         return 0;
//     }
// }


//     return 0;

// }