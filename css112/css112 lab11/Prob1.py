def gen5odds():
    for i in range(1,100,10):
        yield [i, i+2, i+4, i+6, i+8]
 
def Problem1(): 
    return [sum(i) for i in gen5odds()]

print(Problem1())
