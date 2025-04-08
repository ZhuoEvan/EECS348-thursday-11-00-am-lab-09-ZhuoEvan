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

        //Matrix: Add Function
        void add(const Matrix<T> other) {
            vector<vector<T>> resultMatrix;

            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    resultMatrix[i][j] = data[i][j] + other.data[i][j];
                }
            }
            Matrix<T> result(resultMatrix, size_t theSize);
            cout << "Result of Matrix Addition" << endl;
            result.print();
        }



};

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
}

//Matrix Result Function for Double
void matrixResult(Matrix<double> mx1, Matrix<double> mx2) {
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