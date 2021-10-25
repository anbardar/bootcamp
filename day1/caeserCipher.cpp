#include <iostream>
#include <cstdlib>

int main()
{
std::string cipher = "OSSLV";

for (char c: cipher)
{
    char a = c -7;
    std::cout << a << std::endl;
}
std::cout << "-----"<< std::endl;
for(size_t i=0; i<cipher.size(); i++)
std::cout << cipher[i] << std::endl; 

std::cout << "******************************"<< std::endl; 

char b;

std::string cipher1 = "VKRIMHZKTIAR";

for (char c1: cipher1)
{
    b = c1 -19;
    if( b >= 'A'&& b <= 'Z') {
        
        std::cout<< b << std::endl;
       
    }  else if(b < 'A')
                {
                     b = b + (('Z' - 'A') + 1);
                        std::cout << b << std::endl;
                }
}
std::cout << "-----"<< std::endl;
for(size_t j=0; j<cipher1.size(); j++)
std::cout << cipher1[j] << std::endl;
}


//general encryption and dycryption of Caeser Chiper
	
// #include<iostream>
// #include<string.h>
// using namespace std;


// int main()

// {
// cout<<"Enter the message:\n";

// char msg[100];
// cin.getline(msg,100); //take the message as input

// int i, j;
// int length,encDyc,key;

// cout << "Enter key: ";
// cin >> key;
// length = strlen(msg);

// cout<<"Enter your choice \n1. Encryption \n2. Decryption \n";
// cin>>encDyc;

// char letter[100];

// if (encDyc==1) //encryption
//    {
      
//       for(int i = 0; msg[i] != '\0'; ++i) 
//       {
//          letter[i] = msg[i];
//          //encrypt for lowercase

//     if (letter[i] >= 'a' && letter[i] <= 'z')
//          {
//             letter[i] = letter[i]+ key;
//                 if (letter[i]> 'z') 
//             {
//                 letter[i] = letter[i]- 'z' + 'a' - 1;
//             }

//             msg[i] = letter[i];
//          }
//          //encrypt for uppercase
//     else if (letter[i] >= 'A' && letter[i] <= 'Z')
//     {
//         letter[i] = letter[i] + key;
//             if (letter[i] > 'Z')
//             {
//                letter[i] = letter[i] - 'Z' + 'A' - 1;
//             }
//         msg[i] = letter[i];
//     }

//       }

//       printf("Encrypted message: %s", msg); //%s to prins a string or %d for printing a decimal int
//    } 
// else if (encDyc == 2)  //decryption
//     {
//       for(int i = 0; msg[i] != '\0'; ++i) 
//         {
//          letter[i] = msg[i];
//          //decrypt for lowercase

//         if(letter[i] >= 'a' && letter[i] <= 'z') 
//             {
//                 letter[i] = letter[i] - key;

//                 if(letter[i] < 'a')
//                 {
//                     letter[i] = letter[i] + 'z' - 'a' + 1;
//                 }
//             msg[i] = letter[i];
//             }
//          //decrypt for uppercase
//     else if(letter[i] >= 'A' && letter[i] <= 'Z') 
//     {
//             letter[i] = letter[i] - key;

//             if(letter[i] < 'A') 
//             {
//                letter[i] = letter[i] + 'Z' - 'A' + 1;
//             }

//             msg[i] = letter[i];
//     }
//         }
//       cout << "Decrypted message: " << msg;
//     }
// }