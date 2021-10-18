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
