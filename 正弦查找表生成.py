import math
lh=977
sin_table=[]
for i in range(0,1024,1) :
	sin_i=math.sin(i/1024*2*math.pi)
	sin_table.append(int((sin_i*lh/2)+lh/2))
print(sin_table)