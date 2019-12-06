#include "emp-sh2pc/emp-sh2pc.h"
#include <new>
#include <iostream>
#include <fstream>
#include <vector>
using namespace emp;
using namespace std;

/* Variables used:
N: Number of data points
D: Dimension of each data
K: Number of clusters for k-means
(vlen, elen): value and exponent length for Float32
bitsize: length of integers.
*/
int Na, Nb, Da, Db;
int bitsize = 20;
int MAX_VAL = 1000;


Float32 compute_euclidean_distance(vector<Float32> point, vector<Float32> centroid){
    Float32 distance = Float32(0, PUBLIC);
    for(int i = 0; i < Da; i++)
        distance = distance + (point[i] - centroid[i])*(point[i] - centroid[i]);
    return distance;
}


Integer assign_label_cluster(vector<Float32> distance, vector<Float32> point, vector<vector<Float32> > centroids, int K){
    Float32 min_val = distance[0];
    Integer label = Integer(bitsize, 0, PUBLIC);

    for(int i = 0; i < K; i++){
        min_val = min_val.If(distance[i].less_than(min_val), distance[i]);
        //cout << distance[i].reveal<double>() << endl;
    }
    

    for(int i = 0; i < K; i++){
        label = label.select(distance[i].equal(min_val), Integer(bitsize, i, PUBLIC));
    }
    //cout << "Min Value = " << min_val.reveal<double>() << " " << label.reveal<int>() << endl;

    return label;
}

// vector<Float32> compute_new_centroids(vector<Float32>  point, vector<Float32>  curr_centroid){
//     vector<Float32> new_centroid;
//     for(int i = 0; i < Da; i++){
//         new_centroid.push_back((point[i] + curr_centroid[i])/2);
//         cout << new_centroid[i].reveal<double>() << " " ;
//     }
//     cout << endl;
//     return new_centroid;

// }



vector<vector<Float32> > create_centroid(vector<vector<Float32> > data, int K){
    vector<vector<Float32> > centroids;
    for(int i = 0; i < K; i++){
            centroids.push_back(data[i]);
        }
    return centroids;

}

vector<vector<Float32> > compute_new_centroids(vector<vector<Float32> > centroids, Integer idx, vector<Float32> point, int K){
    vector<vector<Float32> > new_centroids;


    for(int i = 0; i < K; i++){
        vector<Float32> tmp;
        for(int j = 0; j < Da; j ++){
            tmp.push_back(centroids[i][j].If(Integer(bitsize, i, PUBLIC) == idx, (centroids[i][j]+point[j])/2));
        }
        new_centroids.push_back(tmp);
    }
    return new_centroids;      
}

vector<vector<Float32> >  kmeans(int party,vector<vector<Float32> > data, int total_iter, int K){
    vector<vector<Float32> > centroids = create_centroid(data, K);
    vector<Integer> labels;
    for(int iter = 0; iter < total_iter; iter++){
        for(int i = 0; i < Na+Nb; i++){
            vector<Float32> distance;
            for(int idx_centroid = 0; idx_centroid < K; idx_centroid++){
                distance.push_back(compute_euclidean_distance(data[i], centroids[idx_centroid]));
            }

            Integer label = assign_label_cluster(distance, data[i], centroids, K);

            centroids = compute_new_centroids(centroids, label, data[i], K);

            if(iter == total_iter-1){
                labels.push_back(label);
            }
        }

    }

    for(int i = 0; i < Na+Nb; i++){
        //cout << "(" << data[i][0].reveal<double>() << ", " << data[i][1].reveal<double>() << ") = " << labels[i].reveal<int>() << endl;
        cout << data[i][0].reveal<double>() << "," << data[i][1].reveal<double>() << "," << labels[i].reveal<int>() << endl;

    }
    // for(int i = 0; i < K; i++){
    //         vector<Float32> row;
    //         for(int j = 0; j < Da; j++){
    //             cout << centroids[i][j].reveal<double>() << " ";
    //         }
    //         cout << endl;
    // }

    ofstream fout;
    fout.open("output_kmeans.txt");

    for(int i = 0; i < K; i++){
        //for(int j = 0; j < Da; j++)
        double num = centroids[i][0].reveal<double>();
        double num2 = centroids[i][1].reveal<double>();
        if(party == ALICE)
            fout << num  << "," << num2;
        fout << "\n";
    }

    for(int i = 0; i < Na+Nb; i++){
        int lbl = labels[i].reveal<int>();
        if(party == ALICE){
            fout << lbl << ',';
        }
    }
    fout << '\n';
    fout.close();


    return centroids;

 }


int main(int argc, char** argv) {

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


    int K = atoi(argv[3]);

    ifstream fin_a("data/kmeans/1.dat");
    ifstream fin_b("data/kmeans/2.dat");





    if( fin_a.is_open() && fin_b.is_open()) {
        string word, line;
        string temp;
        getline(fin_a, line); 
        stringstream sa(line); 
        getline(sa, word, ',');
        Na = stoi(word);
        
        getline(sa, word, ',');
        Da = stoi(word);
        cout << Na <<", " << Da << endl;

        getline(fin_b, line); 
        stringstream sb(line);
        getline(sb, word, ',');
        Nb = stoi(word);
        
        getline(sb, word, ',');
        Db = stoi(word);
        cout << Nb << ", " << Db << endl;
        
        

        vector<vector<Float32> > data;        
        for(int i = 0; i < Na; i++){
            getline(fin_a, line);
            stringstream sa1(line);
            vector<Float32> row;
            for(int j = 0; j < Da; j++){

                getline(sa1, word, ',');
                row.push_back( Float32((double)stof(word), ALICE));
            }
            data.push_back(row);
        }

        for(int i = Na; i < Na+Nb; i++){
            getline(fin_b, line);
            stringstream sa2(line);
            vector<Float32> row;
            for(int j = 0; j < Db; j++){

                getline(sa2, word, ',');
                row.push_back( Float32((double)stof(word), BOB));
            }
            data.push_back(row);
        }

        // for(int i = 0; i < Na+Nb; i++){
        //     for(int j = 0; j < Da; j++){
        //         cout << data[i][j].reveal<double>() << endl;
        //     }
        // }
        
        
        fin_a.close();
        fin_b.close();

        vector<vector<Float32> > centroids;
        int total_iter = 10;

        // for(int i = 0; i < K; i++){
        //     vector<Float32> row;
        //     for(int j = 0; j < Da; j++){
        //         row.push_back(zero);
        //     }
        //     centroids.push_back(row);
        // }

        centroids = kmeans(party, data, total_iter, K);
    }



    

    delete io;
}


