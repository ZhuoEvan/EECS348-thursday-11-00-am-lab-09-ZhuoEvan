//main.cpp

#include <iostream> //Standard Input Output Stream
#include <fstream> //Standard File Stream
#include <string> //Standard String
#include <vector> //Standard Vector

using namespace std; //Reduce the width of the code | removes std::

template<typename T>
class Matrix {
    private:

        vector<vector<T>> data;
        size_t theSize;
        
    public:    

        //Matrix: Constructor
        Matrix(vector<vector<T>> matrix, size_t n) {
            data = matrix;
            theSize = n;
        };

        //Matrix: Destructor
        ~Matrix() {}

        //Matrix: Print Function
        void print() {
            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    if (data[i][j] < 10) {
                        cout << " " << data[i][j] << " ";
                    } else {
                        cout << data[i][j] << " ";
                    }
                }
                cout << endl; //Move to the next row
            }
            cout << endl; //Adds an extra line at the bottom of the finished matrix
        }

        //Matrix: Print Function (Vector)
        void printVector(const vector<vector<T>> vectorData, const size_t n) {
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    if (vectorData[i][j] < 10) {
                        cout << " " << vectorData[i][j] << " ";
                    } else {
                        cout << vectorData[i][j] << " ";
                    }
                }
                cout << endl; //Move to the next row
            }
            cout << endl; //Adds an extra line at the bottom of the finished matrix

        }

        //Matrix: Add Function
        void add(const Matrix<T> other) {
            vector<vector<T>> resultMatrix(theSize, vector<T>(theSize));

            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    resultMatrix[i][j] = data[i][j] + other.data[i][j];
                }
            }
            cout << "Add Matrix Display" << endl;
            printVector(resultMatrix, theSize);
        }

        //Matrix: Multiply Function
        void multiply(const Matrix<T> other) {
            vector<vector<T>> resultMatrix(theSize, vector<T>(theSize));

            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    double sum = 0;
                    for (size_t k = 0; k < theSize; ++k) {
                        double product = data[i][k] * other.data[k][j];
                        sum += product;
                    }
                    resultMatrix[i][j] = sum;
                }
            }

            cout << "Multiply Matrix Display" << endl;
            printVector(resultMatrix, theSize);
        }
        
        //Matrix: Major & Minor Diagonal Sum Function
        void diagonalSum() {
            double majorDiagonal = 0;
            double minorDiagonal = 0;

            for (size_t i = 0; i < theSize; ++i) {
                majorDiagonal += data[i][i];
                minorDiagonal += data[i][(theSize-1) - i];
            }

            cout << "Major Diagonal Elements Sum: " << majorDiagonal << endl;
            cout << "Minor Diagonal Elements Sum: " << minorDiagonal << endl;
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

//Out of Bounds Function
bool inBounds(const int i, const int n) {
    if (i > n) { //Check if index is in bounds
        cout << "Error 01: Out of Bounds" << endl; //Error Message
        return false; //Index is out of bounds
    } else {
        return true; //Index is in bounds
    }
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

//Matrix Result Function for Integer
void matrixResult(Matrix<int> mx1, Matrix<int> mx2) {
    cout << "Matrix 1" << endl;
    mx1.print();
    cout << "Matrix 2" << endl;
    mx2.print();

    mx1.add(mx2);
    mx1.multiply(mx2);

    if (selectMatrix()) {
        cout << "Matrix 1 Diagonal Sums" << endl;
        mx1.diagonalSum();
    } else { 
        cout << "Matrix 2 Diagonal Sums" << endl; 
        mx2.diagonalSum();
    }
    return;
}

//Matrix Result Function for Double
void matrixResult(Matrix<double> mx1, Matrix<double> mx2) {
    cout << "Matrix 1" << endl;
    mx1.print();
    cout << "Matrix 2" << endl;
    mx2.print();

    mx1.add(mx2);
    mx1.multiply(mx2);

    if (selectMatrix()) {
        cout << "Matrix 1 Diagonal Sums" << endl;
        mx1.diagonalSum();
    } else { 
        cout << "Matrix 2 Diagonal Sums" << endl; 
        mx2.diagonalSum();
    }
    return;
}

//Build Matrix Function
void buildMatrix(string fileName) {
    //Local Variables
    size_t n;
    int t;

    //
    ifstream inputFile(fileName);
    inputFile >> n >> t;
    if (validHeader(n, t) && t == 0) {
        cout << "Integer Matrix" << endl;
        //Initialize the Matrices
        vector<vector<int>> mx1;
        vector<vector<int>> mx2;

        //Resizing the Matrices to size n
        mx1.resize(n, vector<int>(n));
        mx2.resize(n, vector<int>(n));

        //
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx1[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx2[i][j];
            }
        }
        inputFile.close(); //Close the File

        //
        Matrix<int> matrix1(mx1, n);
        Matrix<int> matrix2(mx2, n);
        matrixResult(matrix1, matrix2);

    } else if (validHeader(n, t) && t == 1) {
        cout << "Double Matrix" << endl;
        //Initialize the Matrices
        vector<vector<double>> mx1;
        vector<vector<double>> mx2;

        //Resizing the Matrices to size n
        mx1.resize(n, vector<double>(n));
        mx2.resize(n, vector<double>(n));

        //
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx1[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inputFile >> mx2[i][j];
            }
        }
        inputFile.close(); //Close the File

        //
        Matrix<double> matrix1(mx1, n);
        Matrix<double> matrix2(mx2, n);
        matrixResult(matrix1, matrix2);

    } return;
}

//Main Function
int main() {
    cout << "[Starting Lab 9 main.cpp Program]" << endl; //Start Program Message
    //Local Variables
    string fileName;

    //REMEMBER TO REMOVE THE COMMENT LINE!
    //cout << "Enter the file name with dot extension: ", cin >> fileName;
    fileName = "matrix.txt";
    buildMatrix(fileName);

    cout << "[Lab 9 main.cpp Program is Completed]" << endl;
    return 0; //Program Run was Successful
}