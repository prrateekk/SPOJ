t=input()

while(t):
	e,n=raw_input().split()
	e=eval(e)
	n=eval(n)
	x=int((e+n)/3)
	if (x>e) :print(e)
	elif x>n:print(n)
	else:print(x)
	t-=1

