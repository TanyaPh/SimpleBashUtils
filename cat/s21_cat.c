#include "s21_cat.h"

void clean_op(struct options *op) {
    op -> B = 0;
    op -> E = 0;
    op -> N = 0;
    op -> S = 0;
    op -> T = 0;
    op -> V = 0;
}

void find_options(char **argv, int i, struct options *op) {
    for (int j = 1; argv[i][j] == 'b' || argv[i][j] == 'e' || argv[i][j] == 'E' || argv[i][j] == 'n'
                 || argv[i][j] == 's' || argv[i][j] == 't' || argv[i][j] == 'T' || argv[i][j] == 'v'; j++) {
        if (argv[i][j] == 'b')
            op -> B = 1;
        if (argv[i][j] == 'e') {
            op -> E = 1;
            op -> V = 1;
        }
        if (argv[i][j] == 'E')
            op -> E = 1;
        if (argv[i][j] == 'n')
            op -> N = 1;
        if (argv[i][j] == 's')
            op -> S = 1;
        if (argv[i][j] == 't') {
            op -> T = 1;
            op -> V = 1;
        }
        if (argv[i][j] == 'T')
            op -> T = 1;
        if (argv[i][j] == 'v')
            op -> V = 1;
    }
}

void find_options_GNU(char **argv, int i, struct options *op) {
    if (!strcmp(argv[i], "--number-nonblank"))
        op -> B = 1;
    if (!strcmp(argv[i], "--number"))
        op -> N = 1;
    if (!strcmp(argv[i], "--squeeze-blank"))
        op -> S = 1;
}

void check_S(struct options *op, struct variables *var, FILE* f) {
    if (op -> S == 1) {
        if (var->pr_ch == '\n' && var->now_ch == '\n') {
            for (; var->now_ch == '\n';) {
                var->pr_ch = var->now_ch;
                var->now_ch = fgetc(f);
            }
            if ((op -> N == 1) && (op -> B == 0) && (op -> E == 1)) {
                var->count++;
                printf("%6d\t$\n", var->count);
            } else if ((op -> N == 1) && (op -> B == 0)) {
                var->count++;
                printf("%6d\t\n", var->count);
            } else if (op -> E == 1) {
                printf("$\n");
            } else {
                printf("\n");
            }
        }
    }
}

void check_B(struct options *op, struct variables *var) {
    if (op -> B == 1) {
        if ((var->pr_ch == '\n' && var->now_ch != '\n') || (var->count == 0 && var->now_ch != '\n')) {
            var->count++;
            printf("%6d\t", var->count);
        }
    }
}

void check_N(struct options *op, struct variables *var) {
    if (op -> N == 1) {
        if (var->pr_ch == '\n' || var->count == 0) {
            var->count++;
            printf("%6d\t", var->count);
        }
    }
}

void check_E(struct options *op, struct variables *var) {
    if (op -> E == 1) {
        if (var->now_ch == '\n') {
            printf("$");
        }
    }
}

void check_T(struct options *op, struct variables *var, FILE* f) {
    if (op -> T == 1) {
        for (; var->now_ch == '\t';) {
            printf("^I");
            var->pr_ch = var->now_ch;
            var->now_ch = fgetc(f);
        }
    }
}

void check_V(struct options *op, struct variables *var) {
    if (op -> V == 1) {
        if ((var->now_ch >= 0 && var->now_ch < 9) || (var->now_ch > 10 && var->now_ch < 32)) {
            var->now_ch += 64;
            printf("^");
        } else if (var->now_ch == 127) {
            var->now_ch -= 64;
            printf("^");
        }
    }
}

void work_file(int argc, char **argv, struct options *op, struct variables *var) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            FILE *f;
            f = fopen(argv[i], "r+");
            if (!f) {
                printf("cat: %s: No such file or directory", argv[i]);
            } else {
                var->count = 0;
                while ((var->now_ch = fgetc(f)) != EOF) {
                    check_S(op, var, f);
                    check_B(op, var);
                    if (op -> B == 0)
                        check_N(op, var);
                    check_T(op, var, f);
                    check_E(op, var);
                    check_V(op, var);
                    printf("%c", var->now_ch);
                    var->pr_ch = var->now_ch;
                }
            fclose(f);
            }
        }
    }
}

void parser(int argc, char **argv, struct options *op) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'b' || argv[i][1] == 'e' || argv[i][1] == 'E' || argv[i][1] == 'n'
                || argv[i][1] == 's' || argv[i][1] == 't' || argv[i][1] == 'T' || argv[i][1] == 'v')
                find_options(argv, i, op);
            else if (argv[i][1] == '-')
                find_options_GNU(argv, i, op);
            else
                printf("s21_cat: illegal option -- %c", argv[i][1]);
        }
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        struct options *op = &t_options;
        struct variables *var = &t_variables;
        clean_op(op);
        parser(argc, argv, op);
        work_file(argc, argv, op, var);
    }
    return 0;
}
