module Main where

isPrime :: Integral a => a -> Bool
isPrime p
    | even p = p == 2
    | otherwise = all ((0/=) . mod p) $ 2:[3,5..top]
    where
        top = floor $ sqrt $ fromIntegral p

primes = 2 : filter isPrime [3,5..2000000]

main :: IO ()
main = print $ sum primes
