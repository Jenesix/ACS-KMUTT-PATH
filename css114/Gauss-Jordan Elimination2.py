import numpy as np

# Define the matrix of coefficients and the column vector of constants
A = np.array([[1, -1, -1, -1], [-2, 4, 3, 0], [0, -4, 2, 3], [2, 2, 0, -5]], dtype=float)
b = np.array([2, -3, -1, 5], dtype=float)
n = len(b)

# Augment the matrix A with the column vector b
Ab = np.concatenate((A, b.reshape(n, 1)), axis=1)

# Apply Gauss-Jordan Elimination Method to the augmented matrix Ab
for i in range(n):
    # Find the row with the largest absolute value in the i-th column
    max_row = i
    for j in range(i+1, n):
        if abs(Ab[j,i]) > abs(Ab[max_row,i]):
            max_row = j
    # Swap the i-th and max_row-th rows
    Ab[[i,max_row]] = Ab[[max_row,i]]
    # Scale the i-th row so that its leading coefficient is 1
    Ab[i] /= Ab[i,i]
    # Subtract multiples of the i-th row from the other rows to eliminate their i-th column entries
    for j in range(n):
        if j != i:
            Ab[j] -= Ab[j,i] * Ab[i]
            
# Extract the solution vector from the augmented matrix Ab
x = Ab[:,n]

# Print the solution vector with two decimal places
print("Solution:")
print(np.around(x, decimals=2))
