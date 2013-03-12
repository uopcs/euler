-- Haskell Solution

prob1 :: [Int] -> Int
prob1 [] = 0
prob1 (x:xs)
    |(mod x 3 == 0) || (mod x 5 == 0) = prob1 xs + x
    |otherwise = prob1 xs
	
main = prob1 [0...999]