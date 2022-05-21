#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_mastermind.h"

int* my_mastermind(char* cod, char* sample) {
    int i = 0;
    int j;
    int* result = malloc(8);
    while (i < 4) {
        j = 0;
        while (j < 4) {
            if ((cod[i] == sample[j]) && (i == j)) {
                result[0]++;
            }
            if ((cod[i] == sample[j]) && (i != j)) {
                result[1]++;
            }
            j++;
        }
        i++;
    }
    return result;
}


char* code(char* input) {
    int j = 0;
    int i = 0;
    char flag = 0;
    char letter;
    char* f_code = malloc(16);
    if (input) {

        while((input[j] != '\0') && (j < 4)) {
            f_code[j] = input[j];
            j++;
            }
        return f_code;
    }
    srand(time(NULL));

    while (j < 4) {
        letter = rand() % 8 + '0';
        i = 0;
        flag = 0;
        while (f_code[i] != '\0') {

            if (f_code[i] == letter) {
                flag++;
            }
            i++;
        }

        if (flag == 0) {
            f_code[j] = letter;
            j++;
        }
    }
    return f_code;
}


char error_check(char* input) {

    if (input) {
        int i = 0;
        int k;
        int result = 0;

        while ((input[i] != '\0') && (input[i] != '\n')) {

            if ((input[i] < '0') || (input[i] > '7')) {
                return 2;
                }
            i++;
        }

        if (i != 4) {
            return 2;
        }

        i = 0;
        while (i < 4) {
            k = 0;
            result = 0;

            while (k < 4) {

                if (input[i] == input[k]) {
                    result++;
                    }
                k++;
            }

            if (result > 1) {
                return 2;
            }
            i++;
        }
    }
    else {
        return 2;
    }
    return 0;
}