from math import *

for i in range(input()):
	n = input()
	sq = int(sqrt(n))
	i = 1
	sum = 0
	while(i<=sq):
		x = int(n/i)
		sum+=(x*i)
		y = int(n/(i+1))
		a = y+1
		b = x
		sum+=i*(((b-a+1)*(a+b))/2)
		sum = int(sum)
		i+=1
	if (sq==int(n/sq)):
		sum-=(sq*sq)
	sum-=(n*(n+1))/2
	print sum

