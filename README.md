# emp-sh2pc[![Build Status](https://travis-ci.org/emp-toolkit/emp-sh2pc.svg?branch=master)](https://travis-ci.org/emp-toolkit/emp-sh2pc)

<img src="https://raw.githubusercontent.com/emp-toolkit/emp-readme/master/art/logo-full.jpg" width=300px/>

## Installation
0. `mkdir csc481Lele && cd csc481lele`
1. Install prerequisites using instructions   `wget https://goo.gl/wmt4KB -O install.sh && bash install.sh`.
2. `git clone https://github.com/laasyablr/CSC481Project`
3. `cp -r ./CSC481Project ./emp-sh2pc`
4. `cd emp-sh2pc && cmake . && sudo make install`
<img src="https://github.com/laasyablr/CSC481Project/blob/master/fig/compare.png" width=800px/>
## Test
### Test kmeans in secure computing
* Data generation: `python kmeans_datagen.py  --n 10` ( n is the number of the points of each person).
* Run the kmeans with secure computing: `./bin/kmeans 1 1212 3 & ./bin/kmeans 2 1212 3 > kmeans_output`. Usage: `./bin/kmeans <party> <port> <k>`, where k is the number of the clusters of K-means. Port address is hardcoded in the test files. Please replace
  SERVER_IP variable to the real ip. The reuslt of kmenas will save to ./kmeans_output. The first two column is the coordinates of each points, and the third column is the lable of k-menas cluster.
* Result varification: to varify our kmeans algorithm, we apply a standart kmeans tool on the original data with same cluster number and compare the visulazation of two differnt approach. To see the results of our secure kmeans: `python kmeans_gt.py --mode secure`, to see the 'ground truth' results obtained by official optimized kmeans:`python kmeans_gt.py --mode official`

### Question
Please send email to lchen63@cs.rochester.edu

## Acknowledgement
This work was a course project in URCS csc281. The code is modified based on https://github.com/PlatONnetwork/emp-sh2pc.
