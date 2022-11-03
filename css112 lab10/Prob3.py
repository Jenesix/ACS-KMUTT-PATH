def Problem3(N):
  primes = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
  odd_dict_of_primes =  {i:j for (i,j) in dict(zip(range(len(primes)),primes)).items() if i%2 != 0} 
  return odd_dict_of_primes
print(Problem3(100))