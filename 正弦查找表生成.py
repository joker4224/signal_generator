import math
lh=977
sin_table=[]
for i in range(0,1024,1) :
	sin_i=math.sin(i/1024*2*math.pi)
	sin_table.append(int((sin_i+1)*(lh-1)/2)+1)
print(sin_table)