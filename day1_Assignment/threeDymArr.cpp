#include <iostream>
#include <cstdlib>

int main()
{
unsigned int number;
unsigned int random;
unsigned int arr[8][9][11];
int i,j,k;
std::cout<<"Enter a positive number as a range:" << std::endl;
std::cin>> number;

    for(i=0;i<8 ;i++)
    {
        for(j=0;j<9 ;j++)
        {
            for(k=0; k<11; k++)
            {
                random = rand()% number;
                arr[i][j][k]  = random;
                std::cout << arr[i][j][k] << " \t";
            }std::cout << std::endl;
        }std::cout << std::endl;     
          
    }
    
    std::cout << std::endl;
    
}

    