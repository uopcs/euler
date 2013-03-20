problem_7 = primes !! 10000

primes = 2 : filter ((==1) . length . primeFactors) [3,5...]
