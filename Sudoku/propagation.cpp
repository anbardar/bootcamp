#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>


using namespace std;



class Possible {
   vector<bool> _b;  //makes it easy to access bits
public:
   Possible() : _b(9, true) {}
   bool   is_on(int i) const { return _b[i-1]; }
   int    count()      const { return std::count(_b.begin(), _b.end(), true); } //count possibilities(trues) in each cell
   void   eliminate(int i)   { _b[i-1] = false; }
   int    val()        const {
      auto it = find(_b.begin(), _b.end(), true); //possibilities stored in the vector for each cell
      return (it != _b.end() ? 1 + (it - _b.begin()) : -1);  //derive the digit (1-9) out from the boolean value of the corresponding bit location based on being t or f
   }
   string str(int wth) const;
};

string Possible::str(int width) const {  //check exactly what is it doing? (filling in the possible numbers for each cell, 1 to 9) just has been used in print function
   string s(width, ' ');
   int k = 0;
   for (int i = 1; i <= 9; i++) {
      if (is_on(i)) s[k++] = '0' + i;
   }
   return s;
} 

class Sudoku {
   vector<Possible> _cells; //sudoku obj is consist of a vector of _b cells (possible obj)
   static vector< vector<int> > _group, _neighbors, _groups_of; //sudoku obj has a member (a vector) to recognize the correcponding col, row and square for each cell
   //vector of vector is two dimentinal array
   bool     eliminate(int k, int val);
public:
   Sudoku(string s);
   static void init();

   Possible possible(int k) const { return _cells[k]; }
   bool     is_solved() const;      //check soduko is solved or not by checking the available possibilities for each cell, it should be one per each to consider soduko solved
   bool     assign(int k, int val);
   int      least_count() const;
   void     write(ostream& o) const;
};

bool Sudoku::is_solved() const {  
   for (int k = 0; k < _cells.size(); k++) {
      if (_cells[k].count() != 1) {
         return false;
      }
   }
   return true;
}

void Sudoku::write(ostream& o) const {
   int width = 1;
   for (int k = 0; k < _cells.size(); k++) {
      width = max(width, 1 + _cells[k].count());  //check if the number of possibilities for each cell is higher than 1 
   }
   const string sep(3 * width, '-'); //do not get what sep function is doing, is it from templates or libraries?
   for (int i = 0; i < 9; i++) {
      if (i == 3 || i == 6) {
         o << sep << "+-" << sep << "+" << sep << endl;
      }
      for (int j = 0; j < 9; j++) {
         if (j == 3 || j == 6) o << "| ";
         o << _cells[i*9 + j].str(width);
      }
      o << endl;
   }
}

vector< vector<int> > 
Sudoku::_group(27), Sudoku::_neighbors(81), Sudoku::_groups_of(81);

void Sudoku::init() {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         const int k = i*9 + j;
         const int x[3] = {i, 9 + j, 18 + (i/3)*3 + j/3};
         for (int g = 0; g < 3; g++) {
            _group[x[g]].push_back(k);
            _groups_of[k].push_back(x[g]);
         }
      }
   }
   for (int k = 0; k < _neighbors.size(); k++) {
      for (int x = 0; x < _groups_of[k].size(); x++) {
         for (int j = 0; j < 9; j++) {
            int k2 = _group[_groups_of[k][x]][j];
            if (k2 != k) _neighbors[k].push_back(k2); //this function is used to delete the last character from the string
         }
      }
   }
}

bool Sudoku::assign(int k, int val) {
   for (int i = 1; i <= 9; i++) {
      if (i != val) {
         if (!eliminate(k, i)) return false;
      }
   }
   return true;
}

bool Sudoku::eliminate(int k, int val) {
   if (!_cells[k].is_on(val)) {
      return true;
   }
   _cells[k].eliminate(val);
   const int N = _cells[k].count();
   if (N == 0) {
      return false;
   } else if (N == 1) {
      const int v = _cells[k].val();
      for (int i = 0; i < _neighbors[k].size(); i++) {
         if (!eliminate(_neighbors[k][i], v)) return false;
      }
   }
   for (int i = 0; i < _groups_of[k].size(); i++) {
      const int x = _groups_of[k][i];
      int n = 0, ks;
      for (int j = 0; j < 9; j++) {
         const int p = _group[x][j];
         if (_cells[p].is_on(val)) {
            n++, ks = p;
         }
      }
      if (n == 0) {
         return false;
      } else if (n == 1) {
         if (!assign(ks, val)) {
            return false;
         }
      }
   }
   return true;
}

int Sudoku::least_count() const {
   int k = -1, min;
   for (int i = 0; i < _cells.size(); i++) {
      const int m = _cells[i].count();
      if (m > 1 && (k == -1 || m < min)) {
         min = m, k = i;
      }
   }
   return k;
}

Sudoku::Sudoku(string s) 
  : _cells(81) 
{
   int k = 0;
   for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '1' && s[i] <= '9') {
         if (!assign(k, s[i] - '0')) {
            cerr << "error" << endl;
            return;
         }
         k++;
      } else if (s[i] == '0' || s[i] == '.') {
         k++;
      }
   }
}

unique_ptr<Sudoku> solve(unique_ptr<Sudoku> S) {
   if (S == nullptr || S->is_solved()) {
      return S;
   }
   int k = S->least_count();
   Possible p = S->possible(k);
   for (int i = 1; i <= 9; i++) {
      if (p.is_on(i)) {
         unique_ptr<Sudoku> S1(new Sudoku(*S));
         if (S1->assign(k, i)) {
            if (auto S2 = solve(std::move(S1))) {
               return S2;
            }
         }
      }
   }
   return{} ;
}

int main() {
   Sudoku::init();
   string line;
   while (getline(cin, line)) { //getinline This function is used to store a stream of characters as entered by the user in the object memory.
      if (auto S = solve(unique_ptr<Sudoku>(new Sudoku(line)))) { //modify functions to print the possibilities in the vector
         S->write(cout);
      } else {
         cout << "No solution in constraint propogation, let's try brute force!" << endl;//add brute force here
      }
      
   }
   return 0;
}