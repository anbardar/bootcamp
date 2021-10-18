#include <iostream>

int main()
{
    char answer;
    int counter =64;
    int med;


std::cout<<"Choose a number between 1 to 128 (keep it in your mind)"<< std::endl;

std::cout<<"Is your number bigger than "<< counter<<"? (y/n + Enter)"<< std::endl;
std::cin>>answer;
if (answer == 'y') 
{
for(int i= 0; i<6; i++)
{
    med = counter/2;
    counter = counter + med;
    std::cout<<"Is your number bigger than "<< counter<<"? (y/n + Enter)"<< std::endl;
    std::cin>> answer;
}
                    if (answer == 'y')
                    {
                            med = med/2;
                            counter = counter + med;
                            std::cout<<"Is your number bigger than "<<counter<<"? (y/n + Enter)"<< std::endl;
                            std::cin>> answer;
                            if (answer == 'y')
                            {
                                        med = med/2;
                                        counter = counter + med;
                                        std::cout<<"Is your number bigger than"<< counter<<"? (y/n + Enter)"<< std::endl;
                                        std::cin>> answer;
                                        if (answer == 'y')
                                        {
                                            std::cout<<"your number is 128!"<< std::endl;
                                        }
                                        else std::cout<<"Fuck off!"<< std::endl;
                            }else 
                            {

                            }
                            

                    }

            }

    return 0;

}



