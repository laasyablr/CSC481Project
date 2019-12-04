#include "emp-sh2pc/emp-sh2pc.h"
#include <new>
using namespace emp;
using namespace std;

/* Variables used:
N: Number of data points
D: Dimension of each data
K: Number of clusters for k-means
(vlen, elen): value and exponent length for float
bitsize: length of integers.
*/
int N, K, D;
int bitsize = 20;
const int vlen = 24, elen = 9;

Float compute_euclidean_distance(Float *point, Float *centroid){

}

Float assign_label_cluster(Float *distance, Float *point, Float **centroids){


}

Float compute_new_centroids(cluster_label, centroids){
    //Cross tabulation

}

Float* kmeans(Float **data, Float **centroids, int total_iter){

    

}


int main(int argc, char** argv) {
    int bitsize;    

    // run computation with semi-honest model
    int port, party;
    parse_party_and_port(argv, &party, &port);
    NetIO * io = new NetIO(party==ALICE ? nullptr : "127.0.0.1", port);

    setup_semi_honest(io, party);

    if (argc != 4) {
      cout << "Usage: ./kmeans <party> <port> <k>" << endl
           << endl;
      delete io;
      return 0;
    }

    cout << "Calculating edit distance of two inputs of length " << LEN << endl;

    const int k = atoi(argv[3]);
    K = k;

    char fname_a[40];
    char fname_b[40];

    sprintf(fname_a, "data/kmeans/1.dat");
    sprintf(fname_b, "data/kmeans/2.dat");

    ifstream infile_a(fname_a);
    ifstream infile_b(fname_b);

    string inputs_a[LEN];
    string inputs_b[LEN];

    if( infile_a.is_open() && infile_b.is_open()) {
        for( int i=0; i<LEN; i++) {
            getline( infile_a, inputs_a[i]);
            getline( infile_b, inputs_b[i]);
            cout << "A values " << inputs_a[i] <<", " << inputs_b[i] << endl;
        }
        infile_a.close();
        infile_b.close();
    }

    for(int i = 0; i< Na; i++) {
        for(int j = 0; j < D; j++){
            data[i][j] = Float(vlen, elen, ,ALICE);
        }
    }

    for(int i = Na; i < Na+Nb; i++) {
        for(int j = 0; j < D; j++){
            data[i][j] = Float(vlen, elen, ,BOB);
        }
    }

    Float centroids[k][d];

    centroids = kmeans(Float **data, Float **centroids, int total_iter);

    delete io;
}


