sumSquares <- function(l, u)
{
  s <- 0
  for (i in l:u)
  {
    s <- s + (i^2)
  }
  return (s)
}

squareSum <- function(l, u)
{
  return(sum(l:u)^2)
}

print(abs(squareSum(1, 100)-sumSquares(1, 100)))
