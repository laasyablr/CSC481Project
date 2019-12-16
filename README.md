# emp-sh2pc[![Build Status](https://travis-ci.org/emp-toolkit/emp-sh2pc.svg?branch=master)](https://travis-ci.org/emp-toolkit/emp-sh2pc)

<img src="https://raw.githubusercontent.com/emp-toolkit/emp-readme/master/art/logo-full.jpg" width=300px/>

## Installation
0. mkdir csc481Lele && cd csc481lele
1. Install prerequisites using instructions   `wget https://goo.gl/wmt4KB -O install.sh && bash install.sh`.
2. git clone https://github.com/laasyablr/CSC481Project
3. cp -r ./CSC481Project ./emp-sh2pc
4. cd emp-sh2pc && cmake . && sudo make install

## Test
### Test kmeans in secure computing
* Data generation: `python kmeans_datagen.py  --n 10` ( n is the number of the points of each person).
* Run the kmeans with secure computing: `./bin/kmeans 1 1212 3 & ./bin/kmeans 2 1212 3 > kmeans_output`. Usage: ./bin/kmeans <party> <port> <k>, where k is the number of the clusters of K-means. The reuslt of kmenas will save to ./kmeans_output. The first two column is the coordinates of each points, and the third column is the lable of k-menas cluster.
* Result varification: to varify our kmeans algorithm, we apply a standart kmeans tool on the original data with same cluster number and compare the visulazation of two differnt approach.
* If you want to test the code in lcal machine, type

   `./run ./bin/[binaries] 12345 [more opts]`
* IF you want to test the code over two machine, type

  `./bin/[binaries] 1 12345 [more opts]` on one machine and 
  
  `./bin/[binaries] 2 12345 [more opts]` on the other.
  
  IP address is hardcoded in the test files. Please replace
  SERVER_IP variable to the real ip.

* example_semi_honest should run as 
	`./bin/example 1 12345 123 & ./bin/example 2 12345 124`
	
	because different parrties needs different numbers

### Question
Please send email to wangxiao@cs.umd.edu

## Acknowledgement
This work was supported in part by the National Science Foundation under Awards #1111599 and #1563722.
