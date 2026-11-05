#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparison = 0, assignment = 0;

void bubblesort(int*& tab, int size){
    bool check = false;
    ++assignment;
    int repeat = 0;
    ++assignment;

    ++comparison;
    while (check == false){
        check = true;
        ++assignment;

        ++comparison;
        assignment += 2;
        for (int i = 0; i < size - 1 - repeat; ++i){
            ++comparison;
            if (tab[i] > tab[i + 1]){
                swap(tab[i], tab[i + 1]);
                assignment += 3;
                check = false;
                ++assignment;
            }

            ++comparison;
            ++assignment;
        }

        ++repeat;
        ++assignment;

        ++comparison;
    }
}

int main(){
    srand(time(NULL));
    long long int comp = 0, assi = 0;
    int n;
    int k;
    cin >> n >> k;
    int* tab = new int[n];

    for (int test = 0; test < k; ++test){
        for (int i = 0; i < n; ++i){
            //cin >> tab[i];
            tab[i] = rand() % INT_MAX;
        }

        bubblesort(tab, n);

        /*for (int i = 0; i < n; ++i){
            cout << tab[i] << " ";
        }*/

        comp += comparison;
        assi += assignment;
        comparison = 0;
        assignment = 0;
    }
    cout << comp / k << " " << assi / k;

    delete [] tab;
}
