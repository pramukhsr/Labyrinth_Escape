// Pramukh Sreerama UIC Sprin 2021 CS 251 Professor Reckinger

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct ROW {
    T*  Cols;     // array of column elements
    size_t NumCols; // total # of columns (0..NumCols-1)
  };

  ROW* Rows;    // array of ROWs
  size_t  NumRows;  // total # of rows (0..NumRows-1)
    
public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 Grid.  All
  // elements are initialized to the default value of T.
  //
  Grid() {
    Rows = new ROW[4];  // 4 rows
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r].Cols = new T[4];
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (size_t c = 0; c < Rows[r].NumCols; ++c) {
        Rows[r].Cols[c] = T();  // default value for type T:
      }
    }
  }

  //
  // parameterized constructor:
  //
  // Takes user inputted number of rows and columns to construct grid
  Grid(size_t R, size_t C) {
    
      Rows = new ROW[R];
      NumRows = R;
      for (size_t r = 0; r < NumRows; ++r) {
          Rows[r].Cols = new T[C];
          Rows[r].NumCols = C;
          for (size_t c = 0; c < Rows[r].NumCols; ++c) {
              Rows[r].Cols[c] = T();
          }
      }
  }

  //
  // destructor:
  //
  // called automatically to deconstruct and free memory allocated
  virtual ~Grid() {

     if(Rows != nullptr) {
        for(size_t r = 0; r < NumRows; ++r) {
            if (Rows[r].Cols != nullptr) {
                delete [] Rows[r].Cols;
            }
        }
        delete [] Rows;
     }
  }

  //
  // copy constructor:
  //
  // creates a copy of a grid to another grid
  Grid(const Grid<T>& other) {
        this->Rows = new ROW[other.NumRows];
        this->NumRows = other.NumRows;

        for (size_t r = 0; r < other.NumRows; ++r) {
          this->Rows[r].Cols = new T[other.Rows[r].NumCols];
          this->Rows[r].NumCols = other.Rows[r].NumCols;

          for (size_t c = 0; c < Rows[r].NumCols; ++c) {
              this->Rows[r].Cols[c] = other.Rows[r].Cols[c];
          }
      }
  }

  //
  // copy operator=
  //
  // similar to copy operator this one uses the = operator
  Grid& operator=(const Grid& other) {
      Grid<T> temp;
      if (this == &other) {
            return *this;
        }
        if(Rows != nullptr) {
        for(size_t r = 0; r < NumRows; ++r) {
            if (Rows[r].Cols != nullptr) {
                delete [] Rows[r].Cols;
            }
        }
        delete [] Rows;
        }

        this->Rows = new ROW[other.NumRows];
        this->NumRows = other.NumRows;

        for (size_t r = 0; r < other.NumRows; ++r) {
          this->Rows[r].Cols = new T[other.Rows[r].NumCols];
          this->Rows[r].NumCols = other.Rows[r].NumCols;

          for (size_t c = 0; c < Rows[r].NumCols; ++c) {
              this->Rows[r].Cols[c] = other.Rows[r].Cols[c];
          }
      }

      return *this;
  }

  //
  // numrows
  //
  // returns the number of rows in the grid
  size_t numrows() const {
    return NumRows;  // TO DO:  update this, it is only here so code compiles.
  }
  

  //
  // numcols
  //
  // returns the number of columns per row
  size_t numcols(size_t r) const {
      return Rows[r].NumCols;  // TO DO:  update this, it is only here so code compiles.
  }


  //
  // size
  //
  // returns the total size of the grid
  size_t size() const {
      return (NumRows* Rows[0].NumCols);  // TO DO:  update this, it is only here so code compiles.
  }


  //
  // ()
  //
  // returns the value at position r,c as long as it is not out of bounds
  T& operator()(size_t r, size_t c) {
      if (r < 0 || r >= NumRows)
        {
         throw out_of_range("Number of rows out of range");
        }

      if (c < 0 || c >= Rows[r].NumCols)
        {
         throw out_of_range("Number of columns out of range");
        }
      return Rows[r].Cols[c];
  }

  //
  // _output
  //
  // for testing purposes this will output the entire grid horizontally
  void _output() {

      for(size_t r = 0; r < NumRows; ++r) {
          for (size_t c = 0; c < Rows[r].NumCols; ++c) {
              cout << Rows[r].Cols[c] << " ";
          }
          cout << endl;
      }
  }

};
