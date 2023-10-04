#include <iostream>

using namespace std;
int first_func(int num, int (*func)(int));
int secon_func(int x);

int main(void){
    cout << first_func(2, secon_func) << endl;
    return 0;
}

int first_func(int num, int (*func)(int)){
    return func(num);
}

int secon_func(int x){
    return x;
}