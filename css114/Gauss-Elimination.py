def gauss_elimination(aug_matrix):
    # Applying Gaussian Elimination
    for i in range(len(aug_matrix)):
        # Find pivot row
        max_row = i
        for j in range(i+1, len(aug_matrix)):
            if abs(aug_matrix[j][i]) > abs(aug_matrix[max_row][i]):
                max_row = j
        aug_matrix[i], aug_matrix[max_row] = aug_matrix[max_row], aug_matrix[i]
        
        # Perform row operations to make entries below the pivot zero
        for j in range(i+1, len(aug_matrix)):
            ratio = aug_matrix[j][i] / aug_matrix[i][i]
            for k in range(i, len(aug_matrix[0])):
                aug_matrix[j][k] -= ratio * aug_matrix[i][k]

    # Back substitution to get the solution
    solution = [0 for i in range(len(aug_matrix))]
    for i in range(len(aug_matrix)-1, -1, -1):
        solution[i] = aug_matrix[i][-1] / aug_matrix[i][i]
        for j in range(i-1, -1, -1):
            aug_matrix[j][-1] -= aug_matrix[j][i] * solution[i]
    
    return solution
# Form augmented matrix
aug_matrix = [[2, 6, 1, 7],
              [1, 2, -1, -1],
              [5, 7, -4, 9]]

# Solve the system using Gaussian Elimination
solution = gauss_elimination(aug_matrix)

# Print the solution
print("x1 = {:.2f}".format(solution[0]))
print("x2 = {:.2f}".format(solution[1]))
print("x3 = {:.2f}".format(solution[2]))
