module Main where

import Data.List

data Dart = Miss | Single Int | Double Int | Triple Int deriving (Show, Eq)

bull :: Int
bull = 25

type Checkout = (Dart, Dart, Dart)

-- Score of a particular throw.
valueDart :: Dart -> Int
valueDart Miss = 0
valueDart (Single n) = n
valueDart (Double n) = n*2
valueDart (Triple n) = n*3

-- Score of a particular checkout.
valueCheckout :: Checkout -> Int
valueCheckout (d1, d2, d3) = (valueDart d1) + (valueDart d2) + (valueDart d3)

-- Test to see if two checkouts are considered the same.
equiv :: Checkout -> Checkout -> Bool
equiv (a1, a2, a3) (b1, b2, b3) = (a3 == b3) && ((a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1))

-- Test to see if a chackout is valid.
validCheckout :: Int -> Checkout -> Bool
validCheckout score c@(_, _, Double _) = (score - valueCheckout c) == 0
validCheckout _ _ = False

-- Helper test to filter combinations with unwanted Misses.
noMidMiss :: Checkout -> Bool
noMidMiss (x, y, z) = (z /= Miss) && (if y == Miss then x == Miss else True)

-- Posible scores (before modificaton).
numbers :: [Int]
numbers = 25:[1..20]

-- Possible scores for throws after modification.
availableHits :: [Dart]
availableHits = Miss : (filter (/= Triple bull) $ concatMap (\n -> [Single n, Double n, Triple n]) numbers)

-- List of all possible checkouts.
availableCheckouts :: [Checkout]
availableCheckouts = [(x, y, z) | x <- availableHits, y <- availableHits, z <- availableHits, noMidMiss (x,y,z)]

-- Build the list of checkouts available for a specific score.
buildCheckouts :: Int -> [Checkout]
buildCheckouts n = nubBy equiv $ filter (validCheckout n) availableCheckouts

main :: IO ()
main = print $ sum $ map (length . buildCheckouts) [1..99]
