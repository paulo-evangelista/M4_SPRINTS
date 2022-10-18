#include <stdlib.h>
#include <iostream>

using namespace std;

float porcentagem(float min, float max, float num){
    float res = (num-min) / (max-min);
    return res;
}

int main(){
    cout<<porcentagem(50,100,50.5)<<endl;
}