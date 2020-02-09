#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
class KeyPair {
private:
    int rowIndex;
    int columnIndex;
    double value;
public:
    KeyPair(int r, int c, double v) {
        rowIndex = r;
        columnIndex = c;
        value = v;
    }
    int getRow() {
        return rowIndex;
    }
    int getColumn() {
        return columnIndex;
    }
    double getValue() {
        return value;
    }
};
int main(int argc, char** argv) {
    std::cout << "Provide values for matrix (3x3)? Enter Y for yes or N for no: ";
    std::string a;
    std::cin >> a;
    int length = 3;
    double matrix1[length][length];
    double matrix[length][length];//U
    double matrix2[length][length];//L
    double resultVal[1][length];
    /* Generates 3x3 matrix with random integers between 10 and 99*/
    if (a.compare("Y") == 0) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                std::cout << "Enter element for row " << (i+1) << " and column " << (j+1) << ": ";
                double element;
                std::cin >> element;
                matrix1[i][j] = element;
                matrix[i][j] = matrix1[i][j];
            }
            std::cout << "Enter element for col " << (i+1) << " for vector B: ";
            double element;
            std::cin >> element;
            resultVal[0][i] = element;
            std::cout << std::endl;
        }
    } else {
        std::cout << "Generating 3x3 matrix(between 10 and 99)..." << std::endl;
        srand(time(0));
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                matrix1[i][j] = (rand()%90)+10;
                matrix[i][j] = matrix1[i][j];
            }
            resultVal[0][i] = (rand()%90)+10;
        }
    }
    std::cout << "Matrix A with augmented vector B: " << std::endl;
    for(int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            std::string a = std::to_string(matrix1[i][j]);
            int len = 20 - a.length();
            std::cout << matrix1[i][j];
            for (int space = 0; space < len; space++)  {
                std::cout << " ";
            }
        }
        std::cout << resultVal[0][i] << std::endl;
    }
    std::cout << std::endl;
    /* Performs the LU decomposition */
    /* Determining Upper Triangular Matrix U */
    int initCol = 0;
    int initRow = 0;
    std::vector<KeyPair> keys;
    std::cout << "Upper triangular matrix U: " << std::endl;
    for (int i = 0; i < length-1; i++) {
        double pivot = matrix[i][i];
        for (int j = i+1; j < length; j++) {
            double multiplier = (matrix[j][i])/pivot;
            double temp = round(multiplier*100)/100;
            KeyPair tree(j,i,temp);
            keys.push_back(tree);
            for (int k = 0; k < length; k++) {
                matrix[j][k] = matrix[j][k] - round(multiplier*matrix[i][k]*100)/100;
            }
        }
        initCol++;
        initRow++;
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            std::string a = std::to_string(matrix[i][j]);
            int len = 20 - a.length();
            std::cout << matrix[i][j];
            for (int space = 0; space < len; space++)  {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    /* Determining the L (lower triangular matrix) */
    std::cout << "Lower triangular matrix L: " << std::endl;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i == j) {
                matrix2[i][j] = 1;
            } else if (i < j) {
                matrix2[i][j] = 0;
            } else {
                
                for (int k = 0; k < keys.size(); k++) {
                    if (keys[k].getRow() == i and keys[k].getColumn() == j) {
                        matrix2[i][j] = round(keys[k].getValue()*100)/100;
                    }
                }
                
            }
        }
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            std::string a = std::to_string(matrix2[i][j]);
            int len = 20 - a.length();
            std::cout << matrix2[i][j];
            for (int space = 0; space < len; space++)  {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
