#include <stdio.h>
#include <math.h>

int main() {
    int input_num;
    scanf("%d", &input_num);
    printf("%d = ", input_num);

    int first = 1, count = 0;

    // Factorize by 2
    while (input_num % 2 == 0) {
        first = 0;
        input_num /= 2;
        count++;
    }

    // Print factorization of 2
    if (count == 1) {
        printf("2");
    } else if (count > 1) {
        printf("2^%d", count);
    }
    count = 0;

    // Factorize by odd numbers from 3 onwards
    for (int i = 3; i <= sqrt(input_num); i += 2) {
        if (input_num % i == 0) {
            if (!first) {
                printf(" x ");
            }
            first = 0;
            while (input_num % i == 0) {
                input_num /= i;
                count++;
            }
            if (count == 1) {
                printf("%d", i);
            } else if (count > 1) {
                printf("%d^%d", i, count);
            }
            count = 0;
        }
    }

    // If there's a prime factor greater than sqrt(input_num)
    if (input_num > 1) {
        // If input_num its self isn't a prime number plus x sign
        if (!first) {
            printf(" x ");
        }
        printf("%d", input_num);
    }

    printf("\n");

    return 0;
}
