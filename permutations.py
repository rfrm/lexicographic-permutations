#!/usr/bin/env python
from string import join
import pdb

def remove(c, string):
  return string.replace(c, "", 1)  

def swap(perm, chars):
  n = len(perm)
  p = perm[0]
  gt = [c for c in chars if p < c]
  if len(gt)>0:
    new_p = min(gt)
    remaining = join(sorted(remove(new_p, chars)), "")
    swaped = new_p + remaining
    return swaped[:n]
  else:
    return None

def nextPermutation(perm, chars):
  n = len(perm)  
  if n == 1:    
    return swap(perm, chars)
  else:
    p, ps = perm[0], perm[1:]
    next_ps = nextPermutation(ps, remove(p, chars))
    if next_ps:
      return p + next_ps
    else:
      return swap(perm, chars)

size = 3
string = "abcdefg"
perm = "".join(sorted(string)[:size])

# while True: 
#   if perm:
#     print perm
#     perm = nextPermutation(perm, string)
#   else:
#     break

print swap("BAA", "AABBBC")
