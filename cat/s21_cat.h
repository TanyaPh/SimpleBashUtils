#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <string.h>

struct options {
    int B;
    int E;
    int N;
    int S;
    int T;
    int V;
}      t_options;

struct variables {
    int count;
    int pr_ch;
    int now_ch;
}      t_variables;

void clean_op(struct options *op);
void find_options(char **argv, int i, struct options *op);
void find_options_GNU(char **argv, int i, struct options *op);
void check_S(struct options *op, struct variables *var, FILE* f);
void check_B(struct options *op, struct variables *var);
void check_N(struct options *op, struct variables *var);
void check_E(struct options *op, struct variables *var);
void check_T(struct options *op, struct variables *var, FILE* f);
void check_V(struct options *op, struct variables *var);
void work_file(int argc, char **argv, struct options *op, struct variables *var);
void parser(int argc, char **argv, struct options *op);

#endif  // SRC_CAT_S21_CAT_H_
