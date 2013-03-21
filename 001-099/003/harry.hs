prime = 2 : filter ((==1) . length . pFs) [3,5..]
 
pFs n = factor n primes
  where
    fa n (p:ps) 
        | p*p > n        = [n]
        | n `mod` p == 0 = p : fa (n `div` p) (p:ps)
        | otherwise      = fa n ps
 
euler3 = last (pFs 317584931803)
