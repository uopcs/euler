{-# OPTIONS_GHC -funbox-strict-fields #-} -- Auto unpack strict records.
module Main where

import Control.Monad.Writer (execWriter, tell)
import Data.Monoid

-- Max represents the longest known chain length and the input used to create it.
data Max = Max { getMax :: !Integer, getInp :: !Integer } deriving (Eq)

-- We need to be able to compare Max values to find a new Max.
instance Ord Max where
    compare (Max a _) (Max b _) = compare a b

-- Max values for a monoid over 'max'.
instance Monoid Max where
    {-
    Technically Max is a semigroup but Writer expects a monoid.
    Since we're searching positive numbers we'll use 0 as the identity but this won't be useful in a general case.
    -}
    mempty = Max 0 0
    mappend a b = max a b

main :: IO ()
main = print $ getInp $ execWriter $ mapM_ (tell . makeMax) [2..999999]
    where
        makeMax n = Max (sizeChain n) n

-- Find size of chain.
sizeChain :: Integer -> Integer
sizeChain 1 = 1
sizeChain n = 1 + (sizeChain $ collatz n)

-- Get next term in the Collatz sequence.
collatz :: Integer -> Integer
collatz n
    | even n = n `div` 2
    | otherwise = 3 * n + 1
