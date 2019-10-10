#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void eigenVector(const char* pattern, int pLen, int* vector) {
    vector[0] = 0;
    int k = 0;
    for (int i=1; i<pLen; i++) {
        while(k > 0 && pattern[k] != pattern[i]) {
            k = vector[k]; // 
        }
        if (pattern[k] == pattern[i]){
            k++;
        }
        
        vector[i] = k;
    }
}

int kmpMatch(const char* pattern, int pLen, const char* target, int tLen) {
    int n = 0; // the count of matched
    
    int vector[pLen];
    eigenVector(pattern, pLen, vector);

    for (int i = 0; i < tLen; i++) {
        while(n > 0 && pattern[n] != target[i]) {
            n = vector[n];
        }
        if (pattern[n] == target[i]) {
            n++;
        }
        if (n >= pLen) {
            return i - n + 1;
        }
    }
    return -1;
}