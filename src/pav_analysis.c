#include <stdio.h>
#include <math.h>
#include "pav_analysis.h"


float compute_power(const float *x, unsigned int N) {
    float sum = 1.e-4;

    for (int i = 0; i < N; i++){
        sum = sum + (x[i]*x[i]);
    }

    float p = 10 * log10(sum/N);
    return p;
}
    

float compute_am(const float *x, unsigned int N) {
    float sum = 0;

    for(int n = 0; n < N; n++) {
        sum += fabs(x[n]);
    }
    float p = sum/N;

    return p;  
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
