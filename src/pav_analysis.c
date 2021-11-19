#include <stdio.h>
#include <math.h>
#include "pav_analysis.h"


float compute_power(const float *x, unsigned int N) {
    float sum = 0;

    for (int i = 0; i < N; i++){
        sum = sum + (x[i]*x[i]);
    }

    float power = 10 * log10(sum/N);
    return power;
}
    

float compute_am(const float *x, unsigned int N) {
    float am = 0;

    for(int n = 0; n < N; n++) {
        am += fabs(x[n]);
    }

    return am;  
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float sum = 0;

    for (int i = 1; i < N; i++){
        if((x[i]>0 && x[i-1]<0)||(x[i]<0 && x[i-1]>0)){
            sum++;
        }
    }

    float zcr = (fm/2)*(sum/(N-1));
    
    return zcr;
}
