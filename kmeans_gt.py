import random
import sklearn.cluster
import matplotlib.pyplot as plt
import numpy as np
import pickle
k = 3

with open('data/kmeans/kmeans_data.pkl', 'rb') as f:
	tmp = pickle.load(f)

tmp = np.asarray(tmp)

def plot_gt(tmp, k ):
	init_c = tmp[:k]
	c= sklearn.cluster.k_means(tmp,init = init_c, n_clusters= 3,n_init = 10)
	print (c)
	center = c[0]
	labels = c[1]
	plt.scatter(tmp[:, 0], tmp[:, 1], c=labels,
	            s=50, cmap='viridis');
	plt.scatter(
	    center[:, 0], center[:, 1],
	    s=250, marker='*',
	    c='red', edgecolor='black',
	    label='centroids'
	)
	plt.legend(scatterpoints=1)
	plt.grid()
	plt.show()

def plot_secure(tmp, k):
	filepath = 'output_kmeans.txt'
	center = []
	labels = []
	with open(filepath) as fp:
		for cnt, line in enumerate(fp):
			line = line[:-1]
			print("Line {}: {}".format(cnt, line))
			if cnt < k:
				temp = line.split(',')
				gg = []
				for i in range(len(temp)):
					gg.append(float(temp[i]))
				center.append(gg)
			else:
				temp = line.split(',')
				for i in range(len(temp) -1):
					labels.append(int(temp[i]))
	center = np.asarray(center)
	labels = np.asarray(labels)

	plt.scatter(tmp[:, 0], tmp[:, 1], c=labels,
	            s=50, cmap='viridis');
	print (center)
	plt.scatter(
	    center[:, 0], center[:, 1],
	    s=250, marker='*',
	    c='red', edgecolor='black',
	    label='centroids'
	)
	plt.legend(scatterpoints=1)
	plt.grid()
	plt.show()

plot_secure(tmp, k)	

