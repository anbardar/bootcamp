#include <iostream>
#include <time.h>

int main()
{
    int r;
    int x_size;
    int y_size;
    int z_size;
    std::cout << "Specify a positive number" << std::endl;
    std::cin >> r;
    std::cout << "Specify the first dimension (x)" << std::endl;
    std::cin >> x_size;
    std::cout << "Specify the second dimension (y)" << std::endl;
    std::cin >> y_size;
    std::cout << "Specify the third dimension (z)" << std::endl;
    std::cin >> z_size;

    unsigned int ***array_ptr = new unsigned int**[x_size];
    
    srand (time(NULL)); // random seed, rand()%r is getting repeated so this line makes it more "random"!
    for(int i = 0; i < x_size; i++) {

            unsigned int **x_pointer = new unsigned int*[y_size];
            array_ptr[i] = x_pointer;

        for(int j = 0; j < y_size; j++) {

                unsigned int *y_pointer = new unsigned int[z_size];
                x_pointer[j] = y_pointer;
    
            for(int k = 0; k < z_size; k++) {

                    int random_number = rand() % r;
                    y_pointer[k] = random_number;
            }
        }
    }
    for(int i = 0; i < x_size; i++) {
        std::cout << "  ";
        for(int j = 0; j < y_size; j++) {
            std::cout << "  ";
            for(int k = 0; k < z_size; k++) {
                
                std::cout << array_ptr[i][j][k];
                if(k < z_size-1) {
                    std::cout << " ";
                }
            }
            
            std::cout << "  ";
            if(j < y_size-1) {
                std::cout << "\t";
            }
        
        }
        std::cout << "  " << std::endl;
    }
    delete array_ptr;
}