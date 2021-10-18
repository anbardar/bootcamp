//Function to read from and write in a file
#include <iostream>
#include <fstream>
using namespace std;
int main()
{


    char sudokuTable[9][9];
    

 
cout<< "type the numbers of your sudoku puzzle (type 0 for empty cells):"<< endl;
for(int i=0;i<9;i++)
{
        for(int j=0; j<9; j++)
        {
            cin >> sudokuTable[i][j];
        }
}
  
//initiate the file
fstream file ("sudoku.txt");

  file.open ("sudoku.txt", ios::out | ios::in | ios::trunc); //opening file and give permissions

// Writing on file,  
 
  if (file.is_open())
  {
    for(int i=0;i<9;i++)
    {
        file<<"\n";
    for(int j=0; j<9; j++)
    {
    file << sudokuTable[i][j];

    }
   }
  }else
    {
      cerr<<"Error opening file!!"<<endl;
    }
file.close();
//reading from the file, 


file.open("sudoku.txt");

if (file.is_open())
{

for(int i=0;i<9;i++)
    {
        for(int j=0; j<9; j++)
        {
 
            file >> sudokuTable[i][j];
        
    }
   }
  }else
    {
      cerr<<"Error opening file!!"<<endl;
    }
    
for(int i=0;i<9;i++)
    {
        cout << "\n" <<endl;
        for(int j=0; j<9; j++)
        {
 
            cout << sudokuTable[i][j];
        }
    }
cout << "\n";
//closing the file
  file.close();

  return 0;

}
