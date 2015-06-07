# euler_q1

s <- 0
for (i in 1:1000)
{
  if (i %% 3 == 0 || i %% 5 == 0)
  {
    s <- s + i
  }
}
print(s)
