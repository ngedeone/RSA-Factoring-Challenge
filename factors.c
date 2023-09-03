#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - factorize a number and print the factorization
 * number - the number to be factorized
 * returns nothing
 * */
void factorize(int number) {
    int i;
    for (i = 2; i <= number; i++) {
        while (number % i == 0) {
            printf("%d=", number);
            printf("%d*", i);
            number /= i;
        }
    }
    printf("%d\n", 1);
}
/**
 * main - the entry point of the programme
 * argc - argument count
 * argv - argument vector
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        if (number > 1) {
            factorize(number);
        }
    }

    fclose(file);
    return 0;
}
