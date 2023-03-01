ุimport numpy as np

A = np.array([[1, 2, 3], [2, 3, 1], [-2, 3, -2]])

n, m = A.shape

L = np.zeros((n, n))
U = np.zeros((n, m))

for k in range(n):
    L[k, k] = 1.0
    for j in range(k, m):
        U[k, j] = A[k, j] - np.dot(L[k, :k], U[:k, j])
    for i in range(k+1, n):
        L[i, k] = (A[i, k] - np.dot(L[i, :k], U[:k, k])) / U[k, k]

def LU_answer(L,U,b)
    y = np.linalg.solve(L,b)
    x = np.linalg.solve(U,y)
    
    return x
    
print("L =")
print(L)
print("U =")
print(U)
print("Answer: ", x)
