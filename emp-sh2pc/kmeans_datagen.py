import random
import sklearn
a = 10
b = 2
# fx = open("./1.dat", 'w')
# fy = open("./2.dat", 'w')

fx = open("data/kmeans/1.dat", 'w')
fy = open("data/kmeans/2.dat", 'w')
    
xs = []
ys = []
init = str(a) + ',' + str(b)
fx.write("%s\n"%init)
fy.write("%s\n"%init)
tmp = []
for i in range(a):
	tmpx = []
	tmpy = []
	str1 = ''
	str2 = ''
	gg1 = []
	gg2 = []
	for j in range(b):
		if j != 0:
			str1 += ','
			str2 += ','
		# tmp.append(random.uniform(0, 100))
		aa = random.uniform(0, 100)
		bb = random.uniform(0, 100)
		gg1.append(aa)
		gg2.append(bb)
		# tmp.append(random.uniform(0, 100))
		str1 += str(aa)

		str2 += str(bb)
	tmp.append(gg1)
	tmp.append(gg2)
	fx.write("%s\n"%str1)
	fy.write("%s\n"%str2)
print (tmp)
c, l = sklearn.cluster.k_means(tmp, n_clusters= 3,n_init = 10)
print (c,l)




