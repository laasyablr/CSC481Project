#include "emp-sh2pc/emp-sh2pc.h"
#include <new>
using namespace emp;
using namespace std;

int LEN = 3;
int bitsize = 20;

Float edistance(){

}

Float closestCluster(){

}

Float computeNewCluster(){

}

Float* kmeans(Integer *a, Integer *b, int m, int n){


}

void test_kmeans(string inputs_a[], string inputs_b[], int len) {

    
    Integer a[len];
    Integer b[len];

    for( int i=0; i<len; i++) {
        a[i] = Integer(bitsize, inputs_a[i], ALICE);
        b[i] = Integer(bitsize, inputs_b[i], BOB);
    }

    cout << "Edit Distance = " << editDist(a, b, len-1, len-1)<<  endl;
}


int main(int argc, char** argv) {
    int bitsize;    

    // run computation with semi-honest model
    int port, party;
    parse_party_and_port(argv, &party, &port);
    NetIO * io = new NetIO(party==ALICE ? nullptr : "127.0.0.1", port);

    setup_semi_honest(io, party);

    if (argc != 4) {
      cout << "Usage: ./kmeans <party> <port> <bitsize>" << endl
           << endl;
      delete io;
      return 0;
    }

    cout << "Calculating edit distance of two inputs of length " << LEN << endl;

    bitsize = atoi(argv[3]);

    char fname_a[40];
    char fname_b[40];

    sprintf(fname_a, "data/kmeans/1.dat", bitsize);
    sprintf(fname_b, "data/kmeans/2.dat", bitsize);

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

    test_kmeans(inputs_a, inputs_b, LEN);
    delete io;
}


