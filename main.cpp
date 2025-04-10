//main.cpp

#include <iostream> //Standard Input Output Stream
#include <fstream> //Standard File Stream
#include <string> //Standard String
#include <vector> //Standard Vector

using namespace std; //Reduce the width of the code | removes std::

//Matrix Class
template<typename T> //Allow Integers and Doubles
class Matrix {
    private: //Hidden Data

        vector<vector<T>> data; //Matrix Data
        size_t theSize; //Matrix Size

        //Out of Bounds Function
        bool inBounds(const int i, const int n) {
            if (i > n) { //Check if index is in bounds
                cout << "Error 01: Out of Bounds" << endl; //Error Message
                return false; //Index is out of bounds
            } else {
                return true; //Index is in bounds
            }
        }
        
    public:    

        //Matrix: Constructor
        Matrix(vector<vector<T>> matrix, size_t n) {
            data = matrix; //Assign data
            theSize = n; //Assign size
        };

        //Matrix: Destructor
        ~Matrix() {}

        //Matrix: Copy Function
        Matrix<T> copy() {
            vector<vector<T>> copyData(theSize, vector<T>(theSize)); //Copy Vector

            //Copy each data element inside the original matrix
            for (size_t i = 0; i < theSize; ++i) { 
                for (size_t j = 0; j < theSize; ++j) {
                    copyData[i][j] = data[i][j];
                }
            }
            Matrix<T> copyMatrix(copyData, theSize); //Create a copy matrix using vector
            return copyMatrix; //Return the matrix
        }

        //Matrix: Print Function
        void print() {
            //Print each data element inside the matrix
            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    if (data[i][j] < 10) { //Add a space for numbers less than 10
                        cout << " " << data[i][j] << " ";
                    } else { //Print the number as it is
                        cout << data[i][j] << " ";
                    }
                }
                cout << endl; //Move to the next row
            }
            cout << endl; //Adds an extra line at the bottom of the finished matrix
        }

        //Matrix: Print Function (Vector)
        void printVector(const vector<vector<T>> vectorData, const size_t n) {
            //Print each element inside the matrix
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    if (vectorData[i][j] < 10) { //Add a space for numbers less than 10
                        cout << " " << vectorData[i][j] << " ";
                    } else { //Print the number as it is
                        cout << vectorData[i][j] << " ";
                    }
                }
                cout << endl; //Move to the next row
            }
            cout << endl; //Adds an extra line at the bottom of the finished matrix

        }

        //Matrix: Add Function
        void add(const Matrix<T> other) {
            vector<vector<T>> resultMatrix(theSize, vector<T>(theSize)); //Vector to store the result

            //Add elements on the same row and column together from both matrices
            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    resultMatrix[i][j] = data[i][j] + other.data[i][j];
                }
            }
            cout << "Add Matrix Display" << endl; //Add Message
            printVector(resultMatrix, theSize); //Print the vector result
        }

        //Matrix: Multiply Function
        void multiply(const Matrix<T> other) {
            vector<vector<T>> resultMatrix(theSize, vector<T>(theSize)); //Vector to store the result

            //Multiply elements from Matrix 1 row and Matrix 2 column then adding them together
            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    double sum = 0; //Double to store both integers and sums
                    for (size_t k = 0; k < theSize; ++k) {
                        double product = data[i][k] * other.data[k][j];
                        sum += product;
                    }
                    resultMatrix[i][j] = sum; //Assign the sum to the correct position in the result vector
                }
            }

            cout << "Multiply Matrix Display" << endl; //Multiplication Message
            printVector(resultMatrix, theSize); //Print the vector result
        }
        
        //Matrix: Major & Minor Diagonal Sum Function
        void diagonalSum() {
            //Local Variables
            double majorDiagonal = 0;
            double minorDiagonal = 0;

            //Add up all the diagonal values
            for (size_t i = 0; i < theSize; ++i) {
                majorDiagonal += data[i][i];
                minorDiagonal += data[i][(theSize-1) - i];
            }

            cout << "Major Diagonal Elements Sum: " << majorDiagonal << endl; //Print the major diagonal sum
            cout << "Minor Diagonal Elements Sum: " << minorDiagonal << endl; //Print the minor diagonal sum
        }

        //Matrix: Swap Row Function
        void swapRow(const int rowInit, const int rowChange) {
            Matrix<T> copyMatrix = copy(); //Create a copy of the Matrix
            //Check Valid Row Inputs and then swap the row data
            if (inBounds(rowInit, theSize) && inBounds(rowChange, theSize)) {
                for (size_t i = 0; i < theSize; ++i) {
                    copyMatrix.data[rowInit][i] = data[rowChange][i];
                    copyMatrix.data[rowChange][i] = data[rowInit][i];
                }
                cout << endl; copyMatrix.print(); //Print the copy with change
            }
        }

        //Matrix: Swap Column Function
        void swapCol(const int colInit, const int colChange) {
            Matrix<T> copyMatrix = copy(); //Create a copy of the Matrix
            //Check Valid Column Inputs and then swap the column data
            if (inBounds(colInit, theSize) && inBounds(colChange, theSize)) {
                for (size_t i = 0; i < theSize; ++i) {
                    copyMatrix.data[i][colInit] = data[i][colChange];
                    copyMatrix.data[i][colChange] = data[i][colInit];
                }
                cout << endl; copyMatrix.print(); //Print the copy with change
            }
        }

        //Matrix: Update Function (Integer)
        void update(const int row, const int col, int value) {
            Matrix<T> copyMatrix = copy(); //Create a copy of the Matrix
            //Check Valid row and column and update the value
            if (inBounds(row, theSize) && inBounds(col, theSize))
            copyMatrix.data[row][col] = value;

            cout << endl; copyMatrix.print(); //Print the copy with change
        }

        //Matrix: Update Function (Double)
        void update(const int row, const int col, double value) {
            Matrix<T> copyMatrix = copy(); //Create a copy of the Matrix
            //Check Valid row and column and update the value
            if (inBounds(row, theSize) && inBounds(col, theSize))
            copyMatrix.data[row][col] = value;

            cout << endl; copyMatrix.print(); //Print the copy with change
        }
};

//Matrix Selection Function
bool selectMatrix() {
    //Local Variables
    int n = 0; //Store User Input
    bool selectVal; //User Input Result

    while (n <= 0 || n >= 3) { //Constant Input until a Valid Input
        cout << "Enter '1' or '2' to Select Matrix 1 or Matrix 2: "; cin >> n; //Input Message and get user input
        if (n == 1) selectVal = true; //Matrix 1 Selection
        else if (n == 2) selectVal = false; //Matrix 2 Selection
        else {
            cout << "Error 04: Invalid Input" << endl << endl; //Error Message
        }
    }
    return selectVal; //Return the boolean
}

//Size Check Function
bool sizeCheck (const size_t n) {
    if (n > 0) return true; //Valid Size
    else { //Display Error Message
        cout << "Error 02: Negative/Decimal Size" << endl;
        return false; //Invalid Size
    }
}

//Type Flag Check Function
bool typeFlagCheck (const int typeFlag) {
    if (typeFlag >= 0 && typeFlag < 2) return true; //Valid typeFlag
    else { //Display Error Message
        cout << "Error 03: Invalid typeFlag" << endl;
        return false; //Invalid typeFlag
    };
}

//Valid Header Check Function
bool validHeader(const size_t n, const int t) {
    return (sizeCheck(n) && typeFlagCheck(t)); //Check Size and typeFlag
}

//Matrix Result Function (Integer)
void matrixResult(Matrix<int> mx1, Matrix<int> mx2) {
    cout << "Matrix 1" << endl; mx1.print(); //Print Matrix 1
    cout << "Matrix 2" << endl; mx2.print(); //Print Matrix 2

    mx1.add(mx2); //Add two matrices and display the result
    mx1.multiply(mx2); //Multiply two matrices and display the result

    //Get the sum of matrix diagonal elements
    cout << "Matrix Diagonal Elements" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        mx1.diagonalSum();
    } else { //Matrix 2 Selected
        mx2.diagonalSum();
    }
    cout << endl;

    //Swap matrix rows and display the result
    cout << "Swap Matrix Rows" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        int rowInit, rowChange;
        cout << "Enter a row to swap (1/2): "; cin >> rowInit;
        cout << "Enter another row to swap (2/2): "; cin >> rowChange;
        mx1.swapRow(rowInit, rowChange);
    } else { //Matrix 2 Selected
        int rowInit, rowChange;
        cout << "Enter a row to swap (1/2): "; cin >> rowInit;
        cout << "Enter another row to swap (2/2): "; cin >> rowChange;
        mx2.swapRow(rowInit, rowChange);
    }

    //Swap matrix columns and display the result
    cout << "Swap Matrix Columns" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        int colInit, colChange;
        cout << "Enter a column to swap (1/2): "; cin >> colInit;
        cout << "Enter another column to swap (2/2): "; cin >> colChange;
        mx1.swapCol(colInit, colChange);
    } else { //Matrix 2 Selected
        int colInit, colChange;
        cout << "Enter a column to swap (1/2): "; cin >> colInit;
        cout << "Enter another column to swap (2/2): "; cin >> colChange;
        mx2.swapCol(colInit, colChange);
    }

    //Update matrix rows and display the result
    cout << "Update Matrix" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        int row, col, value;
        cout << "Enter a row index (1/3): "; cin >> row;
        cout << "Enter a column index (2/3): "; cin >> col;
        cout << "Enter a new value (3/3): "; cin >> value;
        mx1.update(row, col, value);
    } else { //Matrix 2 Selected
        int row, col, value;
        cout << "Enter a row index (1/3): "; cin >> row;
        cout << "Enter a column index (2/3): "; cin >> col;
        cout << "Enter a new value (3/3): "; cin >> value;
        mx2.update(row, col, value);
    }
    return; //Return to Main
}

//Matrix Result Function (Double)
void matrixResult(Matrix<double> mx1, Matrix<double> mx2) {
    cout << "Matrix 1" << endl; mx1.print(); //Print Matrix 1
    cout << "Matrix 2" << endl; mx2.print(); //Print Matrix 2

    mx1.add(mx2); //Add two matrices and display the result
    mx1.multiply(mx2); //Multiply two matrices and display the result

    //Get the sum of matrix diagonal elements
    cout << "Matrix Diagonal Elements" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        mx1.diagonalSum();
    } else { //Matrix 2 Selected
        mx2.diagonalSum();
    }
    cout << endl;

    //Swap matrix rows and display the result
    cout << "Swap Matrix Rows" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        int rowInit, rowChange;
        cout << "Enter a row to swap (1/2): "; cin >> rowInit;
        cout << "Enter another row to swap (2/2): "; cin >> rowChange;
        mx1.swapRow(rowInit, rowChange);
    } else { //Matrix 2 Selected
        int rowInit, rowChange;
        cout << "Enter a row to swap (1/2): "; cin >> rowInit;
        cout << "Enter another row to swap (2/2): "; cin >> rowChange;
        mx2.swapRow(rowInit, rowChange);
    }

    //Swap matrix columns and display the result
    cout << "Swap Matrix Columns" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        int colInit, colChange;
        cout << "Enter a column to swap (1/2): "; cin >> colInit;
        cout << "Enter another column to swap (2/2): "; cin >> colChange;
        mx1.swapCol(colInit, colChange);
    } else { //Matrix 2 Selected
        int colInit, colChange;
        cout << "Enter a column to swap (1/2): "; cin >> colInit;
        cout << "Enter another column to swap (2/2): "; cin >> colChange;
        mx2.swapCol(colInit, colChange);
    }

    //Update matrix rows and display the result
    cout << "Update Matrix" << endl;
    if (selectMatrix()) { //Matrix 1 Selected
        int row, col;
        double value;
        cout << "Enter a row index (1/3): "; cin >> row;
        cout << "Enter a column index (2/3): "; cin >> col;
        cout << "Enter a new value (3/3): "; cin >> value;
        mx1.update(row, col, value);
    } else { //Matrix 2 Selected
        int row, col;
        double value;
        cout << "Enter a row index (1/3): "; cin >> row;
        cout << "Enter a column index (2/3): "; cin >> col;
        cout << "Enter a new value (3/3): "; cin >> value;
        mx2.update(row, col, value);
    }
    return;
}

//Build Matrix Function
void buildMatrix(string fileName) {
    //Local Variables
    size_t n;
    int t;

    //Access the File
    ifstream inputFile(fileName);
    inputFile >> n >> t; //Access the size and type information
    if (validHeader(n, t) && t == 0) {
        //Initialize the Matrices
        vector<vector<int>> mx1;
        vector<vector<int>> mx2;

        //Resizing the Matrices to size n
        mx1.resize(n, vector<int>(n));
        mx2.resize(n, vector<int>(n));

        //Transferring the first four lines after size and type into Matrix 1 vector
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx1[i][j];
            }
        }
        //Transferring the last four lines into Matrix 2 vector
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx2[i][j];
            }
        }
        inputFile.close(); //Close the File

        //Creating Two Matrices from the vectors and size
        Matrix<int> matrix1(mx1, n);
        Matrix<int> matrix2(mx2, n);
        matrixResult(matrix1, matrix2); //Running the Functions

    } else if (validHeader(n, t) && t == 1) {
        //Initialize the Matrices
        vector<vector<double>> mx1;
        vector<vector<double>> mx2;

        //Resizing the Matrices to size n
        mx1.resize(n, vector<double>(n));
        mx2.resize(n, vector<double>(n));

        //Transferring the first four lines after size and type into Matrix 1 vector
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx1[i][j];
            }
        }
        //Transferring the last four lines into Matrix 2 vector
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx2[i][j];
            }
        }
        inputFile.close(); //Close the File

        //Creating Two Matrices from the vectors and size
        Matrix<double> matrix1(mx1, n);
        Matrix<double> matrix2(mx2, n);
        matrixResult(matrix1, matrix2); //Running the Functions

    } return; //Return to Main
}

//Main Function
int main() {
    cout << "[Starting Lab 9 main.cpp Program]" << endl; //Start Program Message
    //Local Variables
    string fileName;

    cout << "Enter the file name with dot extension: ", cin >> fileName; //Get File Input from User
    buildMatrix(fileName); //Build Matrix from File Input

    cout << "[Lab 9 main.cpp Program is Completed]" << endl; //End Program Message
    return 0; //Program Run was Successful
}