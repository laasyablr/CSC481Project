import random
a = 10
b = 2

fx = open("data/kmeans/1.dat", 'w')
fy = open("data/kmeans/2.dat", 'w')
    
xs = []
ys = []
init = str(a) + ',' + str(b)
fx.write("%s\n"%init)
fy.write("%s\n"%init)
for i in range(a):
	tmpx = []
	tmpy = []
	str1 = ''
	str2 = ''

	for j in range(b):

		if j != 0:
			str1 += ','
			str2 += ','
		# tmpx.append(random.uniform(0, 100))
		# tmpy.append(random.uniform(0, 100))
		str1 += str(random.uniform(0, 100))

		str2 += str(random.uniform(0, 100))

	fx.write("%s\n"%str1)
	fy.write("%s\n"%str2)
# 	xs.append(tmpx)
# 	ys.append(tmpy)
# print (xs)
# print(ys)


