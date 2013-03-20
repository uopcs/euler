module Main where

getDigits :: Int -- ^ Right-most position (0 for units, 1 for tens, etc.)
          -> Int -- ^ Number of places to the left you require.
          -> Int -- ^ The number you are operating on.
          -> Int
getDigits r s n = (n `div` (10^r)) `mod` (10^s)

getWrittenLength :: Int -> Int
getWrittenLength 0 = length "zero"
getWrittenLength n
    | n < 100 = getTensAndUnits n
    | otherwise = getThousands n

getTensAndUnits :: Int -> Int
getTensAndUnits n
    | (n `mod` 100) < 20 = units $ getDigits 0 2 n
    | otherwise = (tens $ getDigits 1 1 n) + (units $ getDigits 0 1 n)

units :: Int -> Int
units 0 = 0
units 1 = length "one"
units 2 = length "two"
units 3 = length "three"
units 4 = length "four"
units 5 = length "five"
units 6 = length "six"
units 7 = length "seven"
units 8 = length "eight"
units 9 = length "nine"
units 10 = length "ten"
units 11 = length "eleven"
units 12 = length "twelve"
units 13 = length "thirteen"
units 14 = length "fourteen"
units 15 = length "fifteen"
units 16 = length "sixteen"
units 17 = length "seventeen"
units 18 = length "eighteen"
units 19 = length "nineteen"

tens :: Int -> Int
tens 2 = length "twenty"
tens 3 = length "thirty"
tens 4 = length "forty"
tens 5 = length "fifty"
tens 6 = length "sixty"
tens 7 = length "seventy"
tens 8 = length "eighty"
tens 9 = length "ninety"

getHundreds :: Int -> Int
getHundreds n
    | hds > 0 = base + (if getDigits 0 2 n > 0 then length "and" else 0)
    | otherwise = getTensAndUnits n
    where
        base = units hds + hdlen + getTensAndUnits n
        hdlen = length "hundred"
        hds = getDigits 2 1 n

getThousands :: Int -> Int
getThousands n
    | tds > 0 = base + (if getDigits 0 3 n > 0 then length "and" else 0)
    | otherwise = getHundreds n
    where
        base = units tds + tdlen + getHundreds n
        tdlen = length "thousand"
        tds = getDigits 3 3 n

main :: IO ()
main = print $ sum $ map getWrittenLength [1..1000]
