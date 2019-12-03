#include "emp-sh2pc/emp-sh2pc.h"
using namespace emp;
using namespace std;

void test_millionare(int party, int number) {
	Integer a(32, number, ALICE);
	Integer b(32, number, BOB);
	//Integer c(32, 2, XOR);
	Bit ba(true, ALICE);
    Bit bb(true, BOB);
    const Bit comp1 = a>b;    
    /*if (party == ALICE) {
    	 ba = (a==b).reveal<bool>(XOR);
  cout << "**A " << a.reveal<int>() << endl;
  cout << "**A " << b.reveal<int>() << endl;
}
if (party == BOB) {
	bb = (a==b).reveal<bool>(XOR);
  cout << "**B " << a.reveal<int>() << endl;
  cout << "**B " << b.reveal<int>() << endl;
}*/
//cout << "ba = " << ba.reveal<bool>() << ", bb =  " << bb.reveal<bool>() << endl;
    //cout << "IS a == b? " << (a==b).reveal<bool>() << ", shared val? " <<(ba^bb).reveal<bool>()<< endl;

    //cout << "true*false = " << (t-(t&t)).reveal<bool>() << endl;
	Integer c = a+b;
	cout << "(A) party = " << party << " c = " << c.reveal<int>(ALICE) << endl;
	cout << "(B) party = " << party << " c = " << c.reveal<int>(BOB) << endl;
	cout << "(P) party = " << party << " c = " << c.reveal<int>() << endl;
 
	cout << "Testing select: " << a.select(comp1, b).reveal<int>() << endl;
	//cout << "ALICE Input:\t"<<a.reveal<int>()<<endl;
	//cout << "BOB Input:\t"<<b.reveal<int>()<<endl;
	cout << "ALICE larger?\t"<< (a>b).reveal<bool>()<<endl;
}

void test_sort(int party) {
	int size = 10;
	Batcher batcher1, batcher2;
	Integer *A = new Integer[size];
	for(int i = 0; i < size; ++i) {
		batcher1.add<Integer>(32, rand()%1024);
		batcher2.add<Integer>(32, rand()%1024);
	}

	batcher1.make_semi_honest(ALICE);
	batcher2.make_semi_honest(BOB);

	for(int i = 0; i < size; ++i)
		A[i] = batcher1.next<Integer>() ^ batcher2.next<Integer>();

	sort(A, size);
	for(int i = 0; i < size; ++i)
		cout << A[i].reveal<string>()<<endl;
}

int main(int argc, char** argv) {
	int port, party;
	parse_party_and_port(argv, &party, &port);
	NetIO * io = new NetIO(party==ALICE ? nullptr : "127.0.0.1", port);

	setup_semi_honest(io, party);
	test_millionare(party, atoi(argv[3]));
	//test_sort(party);
	delete io;
}
