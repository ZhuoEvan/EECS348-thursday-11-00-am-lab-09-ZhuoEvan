//main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

using namespace std; //Reduce the width of the code | removes std::

template<typename T>
class Matrix {
    private:

        vector<vector<T>> data;
        size_t theSize;

    public:

        Matrix(const int n) {

        }

        void print() {
            for (size_t i = 0; i < theSize; ++i) {
                for (size_t j = 0; j < theSize; ++j) {
                    cout << Matrix::matrix[i][j] << " ";
                }
                cout << endl; //Move to the next row
            }
            cout << endl; //Adds an extra line at the bottom of the finished matrix
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
bool sizeCheck (const int n) {
    return (n > 0);
}

//Type Flag Check Function
bool typeFlagCheck (const int typeFlag) {
    return (typeFlag >= 0 && typeFlag < 2);
}

//Extract Function
void extract(string fileName) {
    int num;
    //Local Variables
    ifstream inputFile(fileName);
    while (getline(num, inputFile)) {
        cout << num << endl;
    }



}

//Main Function
int main() {
    cout << "[Starting Lab 9 main.cpp Program]" << endl; //Start Program Message
    //Local Variables
    string fileName;
    int n, typeFlag;

    //REMEMBER TO REMOVE THE COMMENT LINE!
    //cout << "Enter the file name with dot extension: ", cin >> fileName;
    fileName = "matrix.txt";
    
    extract(fileName);

    cout << "[Lab 9 main.cpp Program is Completed]" << endl;
    return 0; //Program Run was Successful
}