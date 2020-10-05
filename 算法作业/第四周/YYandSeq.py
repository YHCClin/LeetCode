from math import log10,floor

def solve(n):
  length=0
  i=1
  while length<n:
    n-=length
    length+=floor(log10(i))+1
    i+=1
  print("len:",length)
  i=1
  length=1
  while length<n:
    n-=length
    i+=1
    length=floor(log10(i))+1
  return str(i)[n-1]