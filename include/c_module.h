#ifndef C_MODULE_H
#define C_MODULE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 500

<<<<<<< HEAD

void get_input(char *text, int *key, int *column);
=======
void get_input_text(char *text);
void get_input_keys(int *key, int *column,int choose);
void Caesar(const char* text, int key);
void CaesarForceCrack(const char* text);
>>>>>>> 61aca59925293e1f90b93183ef5ebc9dc2d98a24

#endif //C_MODULE_H