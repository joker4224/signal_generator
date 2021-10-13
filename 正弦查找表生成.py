import math
lh=50
sin_table=[]
for i in range(0,1000,1) :
	sin_i=math.sin(i/1000*2*math.pi)
	sin_table.append(int((sin_i+1)*lh/2))
print(sin_table)