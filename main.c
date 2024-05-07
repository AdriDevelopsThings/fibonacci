#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <gmp.h>

typedef struct {
	mpz_t n;
	bool no_newline;
} arguments_t;

void print_usage(char* exec) {
	fprintf(stderr, "Usage: %s [OPTION]... N\nGet the N-th fibonacci number.\n\n  -n, --no-newline\tDon't print a newline after the integer.\n", exec);
}

void init_args(arguments_t* args) {
	mpz_init(args->n);
	mpz_set_ui(args->n, 0);
	args->no_newline = false;
}

int parse_args(arguments_t* args, int argc, char** argv, char* exec) {
	for (size_t i=0; i < argc; i++) {
		if (!strcmp(argv[i], "--help")) {
			print_usage(exec);
			return -1;
		} else if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--no-newline")) {
			args->no_newline = true;
		} else {
			if (mpz_set_str(args->n, argv[i], 10) != 0) {
				fprintf(stderr, "Error: The number %s is not an invalid integer.", argv[i]);
				return -1;
			}
		}
	}

	if (mpz_get_ui(args->n) == 0) {
		print_usage(exec);
		return -1;
	}
	return 0;
}

int main(int argc, char** argv) {
	arguments_t args;
	init_args(&args);
	if (parse_args(&args, argc - 1, &argv[1], argv[0]) < 0) {
		return -1;
	}

	mpz_t a, b;
	mpz_init(a);
	mpz_init(b);

	mpz_set_ui(a, 1);
	mpz_set_ui(b, 0);


	for (; mpz_sgn(args.n) == 1; mpz_sub_ui(args.n, args.n, 1)) {
		mpz_add(b, a, b);
		mpz_swap(a, b);
	}

	char* string = mpz_get_str(NULL, 10, a);
	printf("%s", string);
	if (!args.no_newline) {
		printf("\n");
	}

	return 0;
}
