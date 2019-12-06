import random
import sklearn.cluster
import pickle
import matplotlib.pyplot as plt
import numpy as np
k = 3
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
tmp1 = []
tmp2 = []
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
	tmp1.append(gg1)
	tmp2.append(gg2)
	fx.write("%s\n"%str1)
	fy.write("%s\n"%str2)
tmp = tmp1 + tmp2
print (tmp)
with open('data/kmeans/kmeans_data.pkl', 'wb') as f:
	pickle.dump(tmp, f)

# tmp = np.asarray(tmp)
# init_c = tmp[:k]
# c= sklearn.cluster.k_means(tmp,init = init_c, n_clusters= 3,n_init = 10)
# print (c)
# center = c[0]
# labels = c[1]
# plt.scatter(tmp[:, 0], tmp[:, 1], c=labels,
#             s=50, cmap='viridis');
# plt.scatter(
#     center[:, 0], center[:, 1],
#     s=250, marker='*',
#     c='red', edgecolor='black',
#     label='centroids'
# )
# plt.legend(scatterpoints=1)
# plt.grid()
# plt.show()



