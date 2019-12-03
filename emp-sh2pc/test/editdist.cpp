#include "emp-sh2pc/emp-sh2pc.h"
#include <new>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace emp;
using namespace std;

int bitsize = 32;
int a_len, b_len;
// declaring method
Integer editDist(Integer *a, Integer *b, Integer m, Integer n);

Integer getVal(Integer *a, Integer idx, int len){
    // Outputs a[idx] where a is a secret integer array of 
    // size n and idx is a secret index.
    //cout << "In getval : " << len << " " << idx.reveal<int>() << endl;
    Integer zero = Integer(bitsize, 0, PUBLIC);
    int i;
    Integer val = zero;
    for(i = 0; i <= len; i++){
        //cout << "a[i] = " <<  a[i].reveal<int>() << endl;
        Integer curr = Integer(bitsize, i, PUBLIC);
        val = val.select(curr==idx, a[i]);
        //cout << "In for:" << i << " " << val.reveal<int>() << endl;
    }
    //cout << "Done!" << val.reveal<int>() << endl;
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
    

    if((cond1|cond2).reveal<bool>()){
        //Need to return max(m, n) + 1
        //cout << "Base case" << endl;
        return m.select(m<n, n)+one;
    }
    else{
        Bit cond3 = (getVal(a, m, a_len) == getVal(b, n, b_len));
        //cout << m.reveal<int>() << ",  "  << n.reveal<int>() << endl;
        //cout << a[3].reveal<int>() << endl;
        //cout << a[m.reveal<int>()].reveal<int>() << " " << b[n.reveal<int>()].reveal<int>() << endl;
        
        //Bit cond3 = (a[m.reveal<int>()] ==  b[n.reveal<int>()]);
        Integer t1 = editDist(a, b, m-one, n);
        Integer t2 = editDist(a, b, m, n-one);
        Integer t3 = editDist(a, b, m-one, n-one);

        Integer tmp = t1.select(t1>t2, t2);
        Integer min_val = t3.select(t3>tmp, tmp);
        

        
        Integer distance = (one+min_val).select(cond3, t3);
        //cout << "Distance " << distance.reveal<int>() << endl;
        return distance;
    }

}


void test_editDist(string inputs_a[], string inputs_b[], int num_str) {

    for( int i=0; i<num_str; i++) {
        a_len = inputs_a[i].length()-1; //Integer(bitsize, len(inputs_a[i]), PUBLIC);
        b_len = inputs_b[i].length()-1; //Integer(bitsize, len(inputs_b[i]), PUBLIC);
        //cout << a_len << " " << inputs_a[i] << endl;
        Integer a[a_len+2];
        Integer b[b_len+2];
        for(int j = 0; j <= a_len; j++){

            a[j] = Integer(bitsize, tolower((char)inputs_a[i][j]), ALICE);
            //cout << "a[" << j << "] " << a[j].reveal<int>() << endl;
        }
        
        for(int j = 0; j <= b_len; j++){
            b[j] = Integer(bitsize, tolower((char)inputs_b[i][j]), BOB);
            //cout << "b[" << j << "] " << b[j].reveal<int>() << endl;
        }
        
        cout << "* Edit Distance(" << inputs_a[i] <<", " << inputs_b[i] <<") = " << editDist(a, b, Integer(bitsize, a_len, PUBLIC), Integer(bitsize, b_len, PUBLIC)).reveal<int>()<<  endl;
    }

    
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

    //cout << "Calculating edit distance of two inputs of length " << LEN << endl;

    bitsize = atoi(argv[3]);


    char fname_a[40];
    char fname_b[40];

    sprintf(fname_a, "data/editdist/1.dat");
    sprintf(fname_b, "data/editdist/2.dat");
    ifstream infile_a(fname_a);
    ifstream infile_b(fname_b);

    
    string tmp;
    
    int num_str;

    if( infile_a.is_open() && infile_b.is_open()) {
        getline( infile_a, tmp);
        getline( infile_b, tmp);
        stringstream tmp1(tmp);
        tmp1 >>  num_str;
        cout <<  "Number of string: " << num_str << endl;
        string inputs_a[num_str];
        string inputs_b[num_str];

        for( int i=0; i<num_str; i++) {
            getline( infile_a, inputs_a[i]);
            getline( infile_b, inputs_b[i]);

        }

        infile_a.close();
        infile_b.close();
        test_editDist(inputs_a, inputs_b, num_str);
        delete io;
    }

    
}


