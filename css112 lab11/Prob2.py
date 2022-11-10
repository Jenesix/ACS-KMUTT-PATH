def Problem2():
    return [sum([i, i+2, i+4, i+6, i+8]) for i in range(1,100,10)]
    
print(Problem2())