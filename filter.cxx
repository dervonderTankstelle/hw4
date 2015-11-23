#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void reading(const int N, double* p, const string noisy);
void Ausgabe_auf_englisch(const int N, double* p, const string noisy);
void filtern(const int N, double* p, const string noisy);

int main(){
        const int N = 237;
        int n;
        const string noisy = "noisy.txt";
        double* p = new double[n];

        reading(N,p,noisy);
        filtern(N,p,noisy);
        Ausgabe_auf_englisch(N,p,noisy);
        
        delete[] p;
        return 0;
}
//filtern drei mal ;)
void filtern(const int N, double* p, const string noisy){
        //g[i] = (f[i-1] + f[i] + f[i+1])/3

        double altp, neup = p[N-1];

        for(int u = 0; u < 3;u++){
        for(int i = 0; i < N; i++){

                altp = p[i];
                p[i] = (neup + p[i] +p[i+1])/3.0;
                neup = altp;
        }
}
}

void reading(const int N, double* p, const string noisy){

        ifstream in(noisy.c_str());
        for(int i = 0; i < N; i++){
                in >> p[i];
        }
        in.close();
}

void Ausgabe_auf_englisch(const int N, double* p, const string noisy){

        ofstream out("gefiltert_3.txt");

        for(int i = 0; i < N; i++){
        out << p[i] << endl;
        }
out.close();
} 