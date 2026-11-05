#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparison = 0, assignment = 0;

//mergesort na 3 części
void merge3(int*& tab, int*& help, int left, int middle1, int middle2, int right){
    int i = left;
    int j = middle1 + 1;
    int k = middle2 + 1;
    int l = left;
    int minimum;
    assignment += 4;

    comparison += 3;
    while (i <= middle1 && j <= middle2 && k <= right){
        comparison += 2;
        minimum = min({tab[i], tab[j], tab[k]});
        ++assignment;
        
        if (tab[i] == minimum){
            help[l] = tab[i];
            ++i;
            assignment += 2;
            ++comparison;
        }
        else if (tab[j] == minimum){
            help[l] = tab[j];
            ++j;
            assignment += 2;
            comparison += 2;
        }
        else if (tab[k] == minimum){
            help[l] = tab[k];
            ++k;
            assignment += 2;
            comparison += 3;
        }
        ++l;
        ++assignment;

        comparison += 3;
    }
    comparison += 2;
    while (i <= middle1 && j <= middle2){
        ++comparison;
        minimum = min(tab[i], tab[j]);
        ++assignment;

        if (tab[i] == minimum){
            help[l] = tab[i];
            ++i;
            assignment += 2;
            ++comparison;
        }
        else if (tab[j] == minimum){
            help[l] = tab[j];
            ++j;
            assignment += 2;
            comparison += 2;
        }
        ++l;
        ++assignment;

        comparison += 2;
    }
    comparison += 2;
    while (i <= middle1 && k <= right){
        ++comparison;
        minimum = min(tab[i], tab[k]);
        ++assignment;

        if (tab[i] == minimum){
            help[l] = tab[i];
            ++i;
            assignment += 2;
            ++comparison;
        }
        else if (tab[k] == minimum){
            help[l] = tab[k];
            ++k;
            assignment += 2;
            comparison += 2;
        }
        ++l;
        ++assignment;

        comparison += 2;
    }
    comparison += 2;
    while (j <= middle2 && k <= right){
        ++comparison;
        minimum = min(tab[j], tab[k]);
        ++assignment;

        if (tab[j] == minimum){
            help[l] = tab[j];
            ++j;
            assignment += 2;
            ++comparison;
        }
        else if (tab[k] == minimum){
            help[l] = tab[k];
            ++k;
            assignment += 2;
            comparison += 2;
        }
        ++l;
        ++assignment;

        comparison += 2;
    }
    ++comparison;
    while (i <= middle1){
        help[l] = tab[i];
        ++i;
        ++l;
        assignment += 3;

        ++comparison;
    }
    ++comparison;
    while (j <= middle2){
        help[l] = tab[j];
        ++j;
        ++l;
        assignment += 3;

        ++comparison;
    }

    assignment += 2;
    ++comparison;
    for (int m = left; m <= right; ++m){
        tab[m] = help[m];
        ++assignment;

        ++comparison;
        ++assignment;
    }
}

void mergesort3_h(int*& tab, int*& help, int left, int right){
    ++comparison;
    if (left < right){
        int middle1 = left + (right - left) / 3;
        int middle2 = middle1 + (right - left) / 3;
        assignment += 2;
        mergesort3_h(tab, help, left, middle1);
        mergesort3_h(tab, help, middle1 + 1, middle2);
        mergesort3_h(tab, help, middle2 + 1, right);
        merge3(tab, help, left, middle1, middle2, right);
    }
}

void mergesort3(int*& tab, int size){
    int* help = new int[size];
    ++assignment;

    assignment += 2;
    ++comparison;
    for (int i = 0; i < size; ++i){
        help[i] = tab[i];
        ++assignment;

        ++comparison;
        ++assignment;
    }
    mergesort3_h(tab, help, 0, size - 1);
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
            tab[i] = rand() % (INT_MAX / 100);
        }

        mergesort3(tab, n);

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
