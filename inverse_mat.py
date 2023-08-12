# Matrix Inversion using Gauss Jordan method, implemented in python.

PRINT_PROCESS = True

# Printing functions.
def printc(string):
    """
    Prints the string only if PRINT_PROCESS is true.
    """
    if PRINT_PROCESS:
        print(string)

def printm(mat, x = 2, force_print = False):
    """
    Prints Matrix if PRINT_PROCESS or force_print is true.
    """
    if PRINT_PROCESS or force_print:
        m = len(mat)
        n = len(mat[0])
        for i in range(m):
            print("[", end = "\t")
            for j in range(n):
                print(round(mat[i][j], x), end = '\t')
            print("]", end = "\n")
        return


# Functions to find determinat.
def determinant(mat):
    """
    Return Determinant of a matrix recursively.
    """
    if len(mat)== 1:
        return mat[0][0]

    first_row = mat[0]
    det = 0
    for i in range(len(first_row)):
        cofactor = first_row[i]* determinant(cofactor_matrix(mat, i))
        
        if (i+1)%2: #odd i+1
            det += cofactor
        else:
            det -= cofactor
    return det

def cofactor_matrix(mat, p):
    """
    Returns cof
    """
    n = len(mat)
    new_mat = []
    for i in range(1, n):
        row = []
        for j in range(n):
            if j != p:
                row.append(mat[i][j])
        new_mat.append(row)
    return new_mat

# Functions to find inverse. 
def augmented_matrix(mat):
    """
    Returns augmented matrix From a given squre matrix.
    """
    n = len(mat)
    new_mat = []
    for i in range(n):
        dummy_row = mat[i]      #represents row of augmented matrix
        for cell in range(n):
            if cell == i:
                dummy_row.append(1)
            else:
                dummy_row.append(0)

        new_mat.append(dummy_row)
    return new_mat
 
def invert_augment(mat):
    """
    Inverts Augmented matrix.
    Swaps the position of identity matrix.
    """
    n = len(mat)
    printm(mat)
    for i in range(n):      #traversing all columns of first half.
        printc(f"==================COL_:{i}===================")

        # make ith element unity.
        # traversing along the row (In a augmented matrix, no. of col = 2 * no. of row)
        printc(f"Row:{i}")
        pivot = mat[i][i]
        for j in range(2*n):        
            mat[i][j] = mat[i][j] / pivot
        printm(mat)


        for row in range(n):    #traversing along each columns.
    
            if row != i:
                printc(f"Row:{row}")
                printc("0")
                # make other element zero.
                # traversing along the row. ( 2n)
                pivot = mat[row][i]
                for col in range(2*n): 
                    mat[row][col] = mat[row][col] - mat[i][col] * pivot
                printm(mat)

    return mat

def inv_from_aug(mat):
    """
    Retrives back inverted matrix from augment
    """
    n = len(mat)
    return [ row[n:] for row in mat]

def inverse(mat):
    """
    Gives inverse matrix from a square matrix provided.
    """
    if len(mat) != len(mat[0]):
        raise ValueError ("No of Row and No of Column are Unequal")
    printc("Checking Determinant...")
    det = determinant(mat)
    if not det:
        raise ValueError ("Non-Invertible Matrix: Determinant = 0")

    printc(f"\nInvertible Matrix with determinant = {round(det, 3)}")
    aug = augmented_matrix(mat)
    printc("\nInput Matrix")
    printm(mat)
    printc("\nAugmented Matrix")
    printm(aug)
    printc("\nRow Operations:")
    aug = invert_augment(aug)
    inv = inv_from_aug(aug)
    printc("\nDONE\n")
    return inv


if __name__== "__main__":

    # testing
    matrix = [[45]]

    matrix_A = [[12, 34],[-3, 22]]
    matrix_B = [[12, 35, 61], [0, -2, 12], [-3, 6, 15]]
    matrix_C = [[23, 12, -5, -65],
                [80, 0, 36, 33],
                [34, 38, 58, -46],
                [5.88, 1.732, 9, 28]
            ]
    
    matrix_D = [ [5, 7, 9], [4, 3, 8], [7, 5, 6]]

    printm(matrix_D, force_print = True)
    print(determinant(matrix_D))
    inv = inverse(matrix_D)
    # printm(inv, 9,  force_print = True)  
