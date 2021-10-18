#ifndef SHAPES_H
#define SHAPES_H
#include<iostream>
#include<cmath>

using namespace std;

int grid[9][9];



class cell {
public:
    cell() = default;
    cell(const int &_p, const int &_a):Perimiter(_p),Area(_a){}
    virtual ~cell() = 0;
    bool operator <(const Shape &s);
    bool operator >(const Shape &s);
    bool operator ==(const Shape &s);
    void searchInRow() {}
    void searchInCol() {}
    void searchInSquare() {}
private:
    int Perimiter = 0, Area = 0;
};

class Circle : public Shape {
public:
    ~Circle() = default;
    Circle(const int &radius):Shape((2*radius*3),std::pow(radius,2)){}
};

class Rectangle : public Shape {
  public:
    ~Rectangle() = default;
    Rectangle(const int &height,const int &width):Shape((2*height)+(2*width),(height*width)){}
};

class Triangle : public Shape {
  public:
    ~Triangle() = default;
    Triangle(const int &width,const int &height):Shape(3*width,height*width/2){}
};

#endif // SHAPES_H


// bool isPresentInCol(int col, int num){ //check whether num is present in col or not
//    for (int row = 0; row < 9; row++)
//       if (grid[row][col] == num)
//          return true;
//    return false;
// }
// bool isPresentInRow(int row, int num){ //check whether num is present in row or not
//    for (int col = 0; col < N; col++)
//       if (grid[row][col] == num)
//          return true;
//    return false;
// }
// bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
// //check whether num is present in 3x3 box or not
//    for (int row = 0; row < 3; row++)
//       for (int col = 0; col < 3; col++)
//          if (grid[row+boxStartRow][col+boxStartCol] == num)
//             return true;
//    return false;
// }
// void sudokuGrid(){ //print the sudoku grid after solve
//    for (int row = 0; row < N; row++){
//       for (int col = 0; col < N; col++){
//          if(col == 3 || col == 6)
//             cout << " | ";
//          cout << grid[row][col] <<" ";
//       }
//       if(row == 2 || row == 5){
//          cout << endl;
//          for(int i = 0; i<N; i++)
//             cout << "---";
//       }
//       cout << endl;
//    }
// }
// bool findEmptyPlace(int &row, int &col){ //get empty location and update row and column
//    for (row = 0; row < N; row++)
//       for (col = 0; col < N; col++)
//          if (grid[row][col] == 0) //marked with 0 is empty
//             return true;
//    return false;
// }
// bool isValidPlace(int row, int col, int num){
//    //when item not found in col, row and current 3x3 box
//    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
// col - col%3, num);
// }
// bool solveSudoku(){
//    int row, col;
//    if (!findEmptyPlace(row, col))
//       return true; //when all places are filled
//    for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
//       if (isValidPlace(row, col, num)){ //check validation, if yes, put the number in the grid
//          grid[row][col] = num;
//          if (solveSudoku()) //recursively go for other rooms in the grid
//             return true;
//          grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
//       }
//    }
//    return false;
// }
// int main(){

//    cout<< "Type the numbers of your sudoku puzzle then press enter(type 0 for empty cells and seperate the numbers with space):"<< endl;
// for(int i=0;i<9;i++)
// {
//         for(int j=0; j<9; j++)
//         {
//             cin >> grid[i][j];
//         }
// }
// cout << endl;
//    if (solveSudoku() == true)
//       sudokuGrid();
//    else
//       cout << "No solution exists";
   
//    return 0;
// }