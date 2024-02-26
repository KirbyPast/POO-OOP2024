#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <cstdint>
#include <cstdio>
using namespace std;


char sir[100], * p;
char sir_separat[50][50];
FILE* fisier;
int main()
{
    int c = 0;
    scanf("%[^\n]s", sir);
    p = strtok(sir, " ");
    while (p) {
        strcpy(sir_separat[c++], p);
        p = strtok(NULL, " ");
    }
    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (strlen(sir_separat[i]) < strlen(sir_separat[j])) {
                swap(sir_separat[i], sir_separat[j]);
            }
        }
    }
    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (strlen(sir_separat[i]) == strlen(sir_separat[j])) {
                if (strcmp(sir_separat[i], sir_separat[j]) > 0) swap(sir_separat[i], sir_separat[j]);
            }
        }
    }
    for (int i = 0; i < c; i++) {
        cout << sir_separat[i] << '\n';
    }
    return 0;

}