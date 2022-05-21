#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_mastermind.h"


int main(int ac, char **av) {
    int j = 0;
    ac = ac + 1;
    char error_flag = 0;
    char* s_code;
    int attempts;
    char* inp = {0};
    char input_code[32];
    int* answer;

    if (*(av + 1)) {

            if (av[1][0] == '-') {

                if ((av[1][1] == 'c') && (av[1][2] == '\0')) {

                    if (*(av + 2)) {

                        if (error_check(*(av + 2)) > 0) {
                            error_flag = 2;
                        }
                        else {
                            s_code = code(*(av + 2));
                            attempts = 10;
                        }
                    }
                    else {
                        error_flag = 2;
                    }
                }
                else if ((av[1][1] == 'c') && (av[1][2] == 't') && (av[1][3] == '\0')) {

                    if (*(av + 2) && *(av + 3)) {
                        attempts = atoi(*(av + 3));

                        if (error_check(*(av + 2)) > 0 || attempts == 0) {
                            error_flag = 2;
                        }
                        else {
                            s_code = *(av + 2);
                        }
                    }
                    else {
                        error_flag = 2;
                    }
                }
                else if ((av[1][1] == 't') && (av[1][2] == '\0')) {

                    if (*(av + 2)) {
                        attempts = atoi(*(av + 2));

                        if (attempts == 0) {
                            error_flag = 2;
                        }
                        s_code = code(inp);
                    }
                    else {
                        error_flag = 2;
                    }
                }
                else {
                    error_flag = 2;
                }
            }
            else {
                error_flag = 2;
            }
        }
        else {
            s_code = code(inp);
            attempts = 10;
        }

        if (error_flag > 0) {
            printf("Invalid function call\n");
            return 0;
        }
        printf("Will you find the secret code?\n---\n");

        while (j < attempts) {
            printf("Round %d\n", j);
            write(1, ">", 1);
            read(0, input_code, sizeof(input_code));

            if (error_check(input_code) > 0) {
                printf("Wrong input!\n");
            }
            else {
                answer = my_mastermind(input_code, s_code);

                if (answer[0] == 4) {
                    printf("Congratz! You did it!\n");
                    return 0;
                }
                printf("Well placed pieces: %d\nMisplased pieces: %d\n---\n", answer[0], answer[1]);
                j++;
            }
        }
        printf("You lose!\n");
        return 0;
}