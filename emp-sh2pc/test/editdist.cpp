#include "emp-sh2pc/emp-sh2pc.h"
#include <new>
using namespace emp;
using namespace std;

int LEN = 3;
int a_len = 3, b_len = 3;
int bitsize = 32;
// declaring method
Integer editDist(Integer *a, Integer *b, Integer m, Integer n);

Integer getVal(Integer *a, Integer idx, int len){
    // Outputs a[idx] where a is a secret integer array of 
    // size n and idx is a secret index.
    Integer zero = Integer(bitsize, 1, PUBLIC);
    int i;
    Integer val = zero;
    for(i = 0; i < len; i++){
        Integer curr = Integer(bitsize, i, PUBLIC);
        val = val.select(curr==idx, a[i]);
    }
    return val;
    
}

Integer editDist(Integer *a, Integer *b, Integer m, Integer n){
    Integer zero = Integer(bitsize, 0, PUBLIC);
    Integer one = Integer(bitsize, 1, PUBLIC);

    
    Bit true_val(true, PUBLIC);
    Bit false_val(false, PUBLIC);
    // Defining base case conditions 
    Bit cond1 = (m == -one);
    Bit cond2 = (n == -one);
    Bit cond3 = (getVal(a, m, a_len) == getVal(b, n, b_len));

    if((cond1|cond2).reveal<bool>()){
        //Need to return max(m, n) + 1
        return m.select(m<n, n)+one;
    }
    else{
        Integer t1 = editDist(a, b, m-one, n);
        Integer t2 = editDist(a, b, m, n-one);
        Integer t3 = editDist(a, b, m-one, n-one);

        Integer tmp = t1.select(t1>t2, t2);
        Integer min_val = t3.select(t3>tmp, tmp);
        

        
        Integer distance = (one+min_val).select(cond3, t3);
        
        return distance;
    }

}


void test_editDist(string inputs_a[], string inputs_b[], int len) {

    Integer sum(bitsize, 0, PUBLIC);
    Integer prod(bitsize, 0, PUBLIC);
    Integer length(bitsize, len-1, PUBLIC);
    Integer a[len];
    Integer b[len];

    for( int i=0; i<len; i++) {
        a[i] = Integer(bitsize, inputs_a[i], ALICE);
        b[i] = Integer(bitsize, inputs_b[i], BOB);

    }

    cout << "* Edit Distance = " << editDist(a, b, length, length).reveal<int>()<<  endl;
}


int main(int argc, char** argv) {

    /* TO-DO
     ---------
     * Map alphabets to numbers.
     * sCurrently the lengths of both the strings should 
     be equal. Change it to unequal lengths.

    */
    //int bitsize;    

    // run computation with semi-honest model
    int port, party;
    parse_party_and_port(argv, &party, &port);
    NetIO * io = new NetIO(party==ALICE ? nullptr : "127.0.0.1", port);

    setup_semi_honest(io, party);

    if (argc != 4) {
      cout << "Usage: ./editDist <party> <port> <bitsize>" << endl
           << endl;
      delete io;
      return 0;
    }

    cout << "Calculating edit distance of two inputs of length " << LEN << endl;

    bitsize = atoi(argv[3]);


    char fname_a[40];
    char fname_b[40];

    sprintf(fname_a, "data/editdist/1.dat");
    sprintf(fname_b, "data/editdist/2.dat");
    ifstream infile_a(fname_a);
    ifstream infile_b(fname_b);

    string inputs_a[LEN];
    string inputs_b[LEN];

    if( infile_a.is_open() && infile_b.is_open()) {
        for( int i=0; i<LEN; i++) {
            getline( infile_a, inputs_a[i]);
            getline( infile_b, inputs_b[i]);
        }

        infile_a.close();
        infile_b.close();
        test_editDist(inputs_a, inputs_b, LEN);
        delete io;
    }

    
}


