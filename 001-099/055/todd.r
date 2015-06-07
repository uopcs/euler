reverseInt <- function(i)
{
  r <- toString(i)
  r <- strsplit(r, split=NULL)[[1]]
  r <- rev(r)
  r <- paste(r, collapse='')
  return(as.numeric(r))
}

checkPalindrome <- function(i)
{
  p <- toString(i)
  p <- strsplit(p, split=NULL)[[1]]
  while (T)
  {
    if (length(p) < 2)
    {
      return(T)
    }
    if (p[1] != p[length(p)])
    {
      return(F)
    }
    p <- p[-1]
    p <- p[-length(p)]
  }
}

iterate <- function(i)
{
  r <- reverseInt(i)
  return(as.numeric(i+r))
}

testLychrel <- function(k)
{
  for (i in 1:50)
  {
    k <- iterate(k)
    if (checkPalindrome(k))
    {
      return(T)
    }
  }
  return(F)
}

count <- 0
for (i in 1:9999)
{
  if (suppressWarnings(testLychrel(i)) == F)
  {
    count <- count + 1
  }
}
print(count)
