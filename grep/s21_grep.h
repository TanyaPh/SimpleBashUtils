#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

struct options {
    int E;
    int I;
    int V;
    int C;
    int L;
    int N;
    int H;
    int S;
    int F;
    int O;
}      t_options;

struct variables {
    int count;
    int identity;
    int quantity;
    int n;
}      t_variables;

void clean_op(struct options *op);
void clean_var(struct variables *var);
void print_file(struct options *op, int file, char *str);
int check_I(struct options *op);
void check_V(struct options *op, char *str1, struct variables *var, int file, char *str);
void check_L(struct options *op, struct variables *var);
void check_C(struct options *op, struct variables *var);
void check_O(struct options *op, char *STR, struct variables *var, int file, int n, char *str);
void check_N(struct options *op, char *str1, struct variables *var, int file, int n, char *str);
void check_F(struct options *op, char *str, char *file);
void s21_open(struct options *op, struct variables *var, int argc, char **argv, char *STR, int k, int file);
void find_options(char **argv, int i, struct options *op, int *b, int *g);
void parser(int argc, char **argv, struct options *op, int *b, int *g);
void count_file(int argc, char **argv, int *z, int p, int k, int *file);

#endif  // SRC_GREP_S21_GREP_H_
