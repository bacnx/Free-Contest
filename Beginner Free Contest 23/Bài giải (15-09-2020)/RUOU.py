banned = ["ABSINTH", "TEQUILA", "VODKA", "WHISKEY", "WINE", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE"]
n = int(input())
res = 0
for i in range(0,n):
	p = input()
	try:
		age = int(p)
		if age<18:
			res+=1
	except ValueError:
	 	if p in banned:
	 		res+=1

print(res)
