module Main where

{-
Problem:
========

Starting in the top left corner of a 2x2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner.

+---+---+      +>>>+---+      +---+---+      +---+---+
|   |   |      |   V   |      V   |   |      V   |   |
+---+---+  =>  +---+>>>+  OR  +>>>+>>>+  OR  +---+---+  etc.
|   |   |      |   |   V      |   |   V      V   |   |
+---+---+      +---+---+      +---+---+      +>>>+>>>+

How many such routes are there through a 20x20 grid?

Solution:
=========

This is a problem of permutations. Each path is a permutation of movements to
the right and movement downwards.

 * The number of Rights must equal the number of Downs
 * For an nxn grid, there are n Rights and n Downs.

Because each path is a permutation of n downs and n rights, there are (2n)!
different permutations. However, this includes duplicate arrangements of downs
and rights which produce the same result, so we need to divide by the
permutations of downs (n!) and permutations of rights (n!).

So, the final solution is (2n)!/(n!^2).

    For n=20: 40!/(20!^2) = 137846528820

While investigating this I noticed that Pascal's triangle is very relevant to
this problem (and permutations in general):

                        Ones
Row:                   /  Natural numbers   -- Sum:
0                     1  /                  -- 1
1                   1   1                   -- 2
2                 1   2   1                 -- 4
3               1   3   3   1               -- 8
4             1   4   6   4   1             -- 16
5           1   5  10  10   5   1           -- 32
6         1   6  15  20  15   6   1         -- 64
7       1   7  21  35  35  21   7   1       -- 128
8     1   8  28  56  70  56  28   8   1     -- 256
9   1   9  36  84 126 126  84  36   9   1   -- 512

There is an operation, nCr (n choose r) which is the value in Pascal's triangle
in row n, position r. nCr can also be used to count permutations. Given a set S
size n, the number of possible subsets of size r is nCr.

Interestingly, the sum of row n is equal to the size of the powerset of a set
of size n. But I digress.

nCr is defined by: n!/(r!*(n-r)!).

The definition for nCr looks fairly similar to the solution to our problem. In
fact, our solution can be expressed in terms of nCr as 2nCn - an expression
used for producing central binomial coefficients (but that's a story for another
time).

But that is not all! The solution for n can also be found by summing row n
squared:

    For n=3: 1 3 3 1 = 1^2 + 3^2 + 3^2 + 1^2 = 1 + 9 + 9 + 1 = 20.

Oh Pascal's triangle. You never cease to amaze me.
-}

-- Calculate factorial.
fact :: Integer -> Integer
fact n = product [1..n]

-- n choose r
nCr :: Integer -> Integer -> Integer
nCr n r = fact n `div` (fact r * fact (n - r))

centralBinomialCoefficient :: Integer -> Integer
centralBinomialCoefficient n = nCr (2*n) n

main :: IO ()
main = print $ centralBinomialCoefficient 20
