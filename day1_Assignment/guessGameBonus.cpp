
#include <iostream>
//using namespace std;

int main()
{ 
 int min=1,max=128;
 int temp;

 std::cout<< "Think of a number between "<<min<< " and "<<max << std::endl;
 std::cout << std::endl;

char userResp;//char size variable created for user response

 int compGuess = 64;//the middle of the range
    
  for(int i=0;i<6;i++)
  
        {
            std::cout<< compGuess << "   is your number!" << std::endl;
            std::cout << std::endl;
            //std::cout<< min << "       "<< max << std::endl;

            std::cout<<"Otherwise, is it higher? (enter y/n) :"<< std::endl;
            std::cout << std::endl;
            std::cin>>userResp;//User input (y or n)  overwrites userResp
            std::cout << std::endl;
            
                if (userResp =='y')
                    {
                        min = compGuess;
                        temp = compGuess;
                        compGuess= temp + ((max-min)/2);
                                        }
                    else if (userResp =='n')
                        {
                        max = compGuess;
                        temp = compGuess;
                        compGuess= temp - ((max-min)/2);
                        }

        } 
       
std:: cout << compGuess << "    is your number!"<< std::endl;
}
        