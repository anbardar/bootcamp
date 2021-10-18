
#include <iostream>
//using namespace std;

int main()
{ 
 int min=1,max=128;

 std::cout<< "Think of a number between ["<<min<< " and "<<max<<")"<< std::endl;

char userResp;//char size variable created for user response

 int compGuess = 64;//the middle of the range
    
  for(int i=0;i<6;i++)
        {
            std::cout<< compGuess << "   is your number!" << std::endl;
            std::cout<<"Otherwise, is it higher? (enter y/n) :"<< std::endl;
            std::cin>>userResp;//User input (y or n)  overwrites userResp

                if (userResp =='y')
                    {
                        min= compGuess+(compGuess/2);
                        compGuess+=(compGuess/2);
                                        }
                    else 
                        {
                            max = compGuess-(compGuess/2);
                            compGuess -= (compGuess/2); 
                        }


        } 
       
        std::cout<< "I bet your number is "<<compGuess;   
}
        