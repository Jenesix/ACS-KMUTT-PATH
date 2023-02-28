def gauss_jordan(A, b):
    n = len(A)
    Ab = [A[i] + [b[i]] for i in range(n)]

    for i in range(n):
        # Find the row with the largest pivot
        max_row = max(range(i, n), key=lambda r: abs(Ab[r][i]))

        # Swap the current row with the row containing the largest pivot
        Ab[i], Ab[max_row] = Ab[max_row], Ab[i]

        # Divide the pivot row by the pivot element
        pivot = Ab[i][i]
        Ab[i] = [x / pivot for x in Ab[i]]

        # Subtract the pivot row from all other rows
        for j in range(n):
            if j != i:
                factor = Ab[j][i]
                Ab[j] = [Ab[j][k] - factor * Ab[i][k] for k in range(n+1)]

    # Extract the solution vector from the augmented matrix
    x = [round(row[-1], 2) for row in Ab]

    return x

# Define the coefficients and right-hand side of the system of equations
A = [[1, -1, -1, -1],
     [-2, 4, 3, 0],
     [0, -4, 2, 3],
     [2, 2, 0, -5],]

b = [2, -3, -1, 5]

# Solve the system of equations using Gauss-Jordan elimination
x = gauss_jordan(A, b)

# Print the solution
print(x)
