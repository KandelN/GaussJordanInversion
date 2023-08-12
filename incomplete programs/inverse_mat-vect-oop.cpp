// Inversion of a 3x3 matrix is done by using vector object and applying object oriented methd of programming.
// Incomplete

#include <iostream>
#include <vector>
using namespace std;

class SqMatrix{
private:
    vector<vector<int>> matrix {
        { 5, 7, 9 },
        { 4, 3, 8 },
        { 7, 5, 6 }
    };
    int order = matrix.size();
    
    void makeAugmentedMatrix(){
        // Add the identity matrix of order at the end of original matrix.
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < 2 * order; j++) {
                if (j >= order){
                    // Add '1' at the 2nd diagonal places of the augmented 
                    // matrix to create a identity matrix
                    if (j == (i + order))
                        matrix[i].push_back(1);
                    else 
                        matrix[i].push_back(0);
                }
            }
        }
    }

public:
    void display(){
        for (int i=0; i < matrix.size(); i++){
            for (int j=0; j < matrix[i].size(); j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    void inverse(){
        float temp;
        printf("=== Augmented Matrix ===\n");
        makeAugmentedMatrix();
        display();

        // Replace a row by sum of itself and a constant multiple of another row of the matrix
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                if (j != i) {  // if not main diagonal
                    temp = matrix[j][i] / matrix[i][i];
                    for (int k = 0; k < 2 * order; k++) {
                        matrix[j][k] -= matrix[i][k] * temp;
                    }
                }
            }
        }

    }

};

int main(){

    SqMatrix a;
    a.display();
    a.inverse();
    cout << endl;
    a.display();

    return 0;
}