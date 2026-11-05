#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparison = 0, assignment = 0;

//zwykły mergesort
void merge(int*& tab, int*& help, int left, int middle, int right){
    int i = left;
    ++assignment;
    int j = middle + 1;
    ++assignment;
    int k = left;
    ++assignment;

    comparison += 2;
    while (i <= middle && j <= right){
        ++comparison;
        if (tab[i] <= tab[j]){
            help[k] = tab[i];
            ++assignment;
            ++i;
            ++assignment;
        }
        else{
            help[k] = tab[j];
            ++assignment;
            ++j;
            ++assignment;
        }
        ++k;
        ++assignment;

        comparison += 2;
    }
    ++comparison;
    while (i <= middle){
        help[k] = tab[i];
        ++assignment;
        ++i;
        ++assignment;
        ++k;
        ++assignment;

        ++comparison;
    }

    ++comparison;
    assignment += 2;
    for (int l = left; l <= right; ++l){
        tab[l] = help[l];
        ++assignment;

        ++comparison;
        ++assignment;
    }
}

void mergesort_h(int*& tab, int*& help, int left, int right){
    ++comparison;
    if (left < right){
        int middle = (left + right) / 2;
        ++assignment;
        mergesort_h(tab, help, left, middle);
        mergesort_h(tab, help, middle + 1, right);
        merge(tab, help, left, middle, right);
    }
}

void mergesort(int*& tab, int size){
    int* help = new int[size];
    ++assignment;

    ++comparison;
    assignment += 2;
    for (int i = 0; i < size; ++i){
        help[i] = tab[i];
        ++assignment;

        ++comparison;
        ++assignment;
    }
    mergesort_h(tab, help, 0, size - 1);
    delete [] help;
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

        mergesort(tab, n);

        for (int i = 0; i < n; ++i){
            cout << tab[i] << " ";
        }
        comp += comparison;
        assi += assignment;
        comparison = 0;
        assignment = 0;
    }
    cout << comp / k << " " << assi / k;

    delete [] tab;
}
