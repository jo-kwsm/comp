s=input()
n=len(s)
for i in range(n/2):
  s=s[:-2]
  if s[:len(s)]==s[len(s):]:
    print(len(s))