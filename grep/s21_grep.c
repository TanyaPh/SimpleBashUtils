#include "s21_grep.h"

void clean_op(struct options *op) {
    op -> E = 0;
    op -> I = 0;
    op -> V = 0;
    op -> C = 0;
    op -> L = 0;
    op -> N = 0;
    op -> H = 0;
    op -> S = 0;
    op -> F = 0;
    op -> O = 0;
}

void clean_var(struct variables *var) {
    var->count = 0;
    var->identity = 0;
    var->quantity = 0;
    var->n = 0;
}

void print_file(struct options *op, int file, char *str) {
    if (op -> H == 0) {
        if (file > 1)
            printf("%s:", str);
    }
}

int check_I(struct options *op) {
    int t = REG_EXTENDED;
    if (op -> I == 1) {
        t = REG_EXTENDED | REG_ICASE;
    }
    return t;
}

void check_V(struct options *op, char *str1, struct variables *var, int file, char *str) {
    if (op -> V == 1 && op -> N == 0 && op -> C == 0 && op -> L == 0) {
        if (var->identity != 0) {
            print_file(op, file, str);
            printf("%s", str1);
        }
    }
}

void check_L(struct options *op, struct variables *var) {
    if (op -> L == 1) {
        if ((var->identity == 0 && op -> V == 0) || (var->identity != 0 && op -> V != 0))
            var->quantity++;
    }
}

void check_C(struct options *op, struct variables *var) {
    if (op -> C == 1) {
        if (op -> L == 0 && ((var->identity == 0 && op -> V == 0) || (var->identity != 0 && op -> V != 0)))
            var->count++;
        else if (op -> L == 1 && ((var->identity == 0 && op -> V == 0)
                || (var->identity != 0 && op -> V != 0)))
            var->count = 1;
    }
}

void check_O(struct options *op, char *STR, struct variables *var, int file, int n, char *str) {
    if (op -> O == 1 && op -> V == 0 && op -> C == 0 && op -> L == 0) {
        if (var->identity == 0 && op -> N == 0) {
            print_file(op, file, str);
            printf("%s\n", STR);
        }
        if (var->identity == 0 && op -> N == 1) {
            print_file(op, file, str);
            printf("%d:%s\n", n, STR);
        }
    }
}

void check_N(struct options *op, char *str1, struct variables *var, int file, int n, char *str) {
    if (op -> N == 1 && op -> C == 0 && op -> L == 0) {
        if (((var->identity == 0 && op -> V == 0 && op -> O == 0) || (var->identity != 0 && op -> V != 0))) {
            print_file(op, file, str);
            printf("%d:%s", n, str1);
        }
    }
}

void check_F(struct options *op, char *str, char *file) {
    if (op -> F == 1) {
        FILE *f;
        f = fopen(file, "r");
        if (!f) {
            if (op -> S == 0)
                printf("s21_grep: %s: No such file or directory\n", file);
        } else {
            char str2[1025];
            while (fgets(str2, 1024, f) != NULL) {
                strcpy(str, str2);
            }
            fclose(f);
        }
    }
}

void compare(struct options *op, struct variables *var, int i, char **argv, char *STR, FILE *f, int file) {
    regex_t restr;
    char str1[1025] = "";
    int flag = check_I(op);
    int n = 0;
    var->count = 0, var->quantity = 0;
    regcomp(&restr, STR, flag);
    while (fgets(str1, 1024, f) != NULL) {
        n++;
        var->identity = regexec(&restr, str1, 0, NULL, 0);
        check_C(op, var);
        check_L(op, var);
        check_N(op, str1, var, file, n, argv[i]);
        check_V(op, str1, var, file, argv[i]);
        check_O(op, STR, var, file, n, argv[i]);
        if (op -> N == 0 && op -> V == 0 && op -> O == 0 && op -> C == 0 && op -> L == 0) {
            if (var->identity == 0) {
                print_file(op, file, argv[i]);
                printf("%s", str1);
            }
        }
    }
    if (op -> C == 1) {
        print_file(op, file, argv[i]);
        printf("%d\n", var->count);
    }
    if (op -> L == 1 && var->quantity > 0) {
        printf("%s\n", argv[i]);
    }
    regfree(&restr);
}

void s21_open(struct options *op, struct variables *var, int argc, char **argv, char *STR, int k, int file) {
    for (int i = k+1; i < argc; i++) {
        if (argv[i][0] != '-') {
            FILE *f;
            f = fopen(argv[i], "r+");
            if (!f) {
                if (op -> S == 0)
                    printf("s21_grep: %s: No such file or directory\n", argv[i]);
            } else {
                compare(op, var, i, argv, STR, f, file);
                fclose(f);
            }
        }
    }
}


void find_options(char **argv, int i, struct options *op, int *b, int *g) {
    for (int j = 1; argv[i][j] == 'e' || argv[i][j] == 'i' || argv[i][j] == 'v' || argv[i][j] == 'c'
                 || argv[i][j] == 'l' || argv[i][j] == 'n' || argv[i][j] == 'h' || argv[i][j] == 's'
                 || argv[i][j] == 'f' || argv[i][j] == 'o'; j++) {
        if (argv[i][j] == 'e') {
            op -> E = 1;
            *g = i + 1;
        }
        if (argv[i][j] == 'i')
            op -> I = 1;
        if (argv[i][j] == 'v')
            op -> V = 1;
        if (argv[i][j] == 'c')
            op -> C = 1;
        if (argv[i][j] == 'l')
            op -> L = 1;
        if (argv[i][j] == 'n')
            op -> N = 1;
        if (argv[i][j] == 'h')
            op -> H = 1;
        if (argv[i][j] == 's')
            op -> S = 1;
        if (argv[i][j] == 'f') {
            op -> F = 1;
            *b = i + 1;
        }
        if (argv[i][j] == 'o')
            op -> O = 1;
    }
}

void parser(int argc, char **argv, struct options *op, int *b, int *g) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (strchr("eivclnhsfo", argv[i][1])) {
                find_options(argv, i, op, b, g);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        struct options *op = &t_options;
        struct variables *var = &t_variables;
        clean_op(op);
        clean_var(var);
        char STR[2048] = {0};
        int k = 2, file = 0, p = 0;
        int *g = &k;
        int *b = &p;
        parser(argc, argv, op, b, g);
        if (!op -> N && !op -> V && !op -> O && !op -> C && !op -> L &&
            !op -> E && !op -> I && !op -> H && !op -> S && !op -> F)
            k = 1;
        strcpy(STR, argv[k]);
        check_F(op, STR, argv[p]);
        if (p > k)
            k = p;
        for (int i = k+1; i < argc; i++) {
            if (argv[i][0] != '-') {
                file++;
            }
        }
        s21_open(op, var, argc, argv, STR, k, file);
    }
    return 0;
}
