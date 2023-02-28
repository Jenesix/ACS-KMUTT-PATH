import numpy as np

# Define the matrix of coefficients and the column vector of constants
A = np.array([[2, 6, 1], [1, 2, -1], [5, 7, -4]], dtype=float)
b = np.array([7, -1, 9], dtype=float)
n = len(b)

# Augment the matrix A with the column vector b
Ab = np.concatenate((A, b.reshape(n, 1)), axis=1)

# Apply Gauss Elimination Method to the augmented matrix Ab
for i in range(n-1):
    # Find the row with the largest absolute value in the i-th column
    max_row = i
    for j in range(i+1, n):
        if abs(Ab[j,i]) > abs(Ab[max_row,i]):
            max_row = j
    # Swap the i-th and max_row-th rows
    Ab[[i,max_row]] = Ab[[max_row,i]]
    # Subtract multiples of the i-th row from the other rows to eliminate their i-th column entries
    for j in range(i+1, n):
        Ab[j] -= Ab[j,i]/Ab[i,i] * Ab[i]
            
# Back-substitute to obtain the solution vector
x = np.zeros(n)
for i in range(n-1, -1, -1):
    x[i] = (Ab[i,n] - np.dot(Ab[i,i+1:n], x[i+1:n]))/Ab[i,i]

# Print the solution vector with two decimal places
print("Solution:")
print(np.around(x, decimals=2))
