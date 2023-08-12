// Inversion of a 3x3 matrix is done by using vector object of cpp.
// Incomplete

#include <iostream>
#include <vector>
using namespace std;


void printMatrix(vector<vector<float>> mat){
    for (int i=0; i < mat.size(); i++){
        for (int j=0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

vector<vector<float>> cofactorMatrix(vector<vector<float>> mat, int p){
    // Return cofactor matrix
    vector<vector<float>> newMatrix;
    for (int i=1; i<mat.size(); i++){
        vector<float> row;
        for (int j=0; j< mat.size(); j++){
            if (j != p)
                row.push_back(mat[i][j]);
        }
        newMatrix.push_back(row);
    }
    return newMatrix;
}

float determinant(vector<vector<float>> mat){
    // Return determinant recursively
    if (mat.size() == 1){
        return mat[0][0];
    }

    float det=0;
    for (int i=0; i< mat[0].size(); i++){
        float cofactor = mat[0][i] * determinant(cofactorMatrix(mat, i));

        if (i%2 == 0)  // if even
            det += cofactor;
        else // if odd
            det -= cofactor;
    }
    // return 1;
    return det;
}

vector<vector<float>> augmentedMatrix(vector<vector<float>> mat){
    // Add the identity matrix of order at the end of original matrix.
    int order = mat.size();
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < 2 * order; j++) {
            if (j >= order){
                // Add '1' at the 2nd diagonal places of the augmented 
                // matrix to create a identity matrix
                if (j == (i + order))
                    mat[i].push_back(1);
                else 
                    mat[i].push_back(0);
            }
        }
    }
    return mat;
}


int main(){
    vector<vector<float>> matrix {
        { 5, 7, 9 },
        { 4, 3, 8 },
        { 7, 5, 6 }
    };
    printMatrix(matrix);
    matrix = augmentedMatrix(matrix);
    printMatrix(matrix);
    cout << "here";
    float det = determinant(matrix);
    cout << "\n";
    cout << det;
    cout << "\nhello FINAL";
    return 0;
}