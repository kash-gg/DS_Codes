#include <stdio.h>

int main() {
    int num, count = 0, sum = 0;
    float average;

    while(1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if(num < 0) {
            break;
        }

        if(num % 2 != 0) {
            sum += num;
            count++;
        }
    }

    if(count != 0) {
        average = (float)sum / count;
    } else {
        average = 0;
    }

    printf("Count of odd numbers: %d\n", count);
    printf("Sum of odd numbers: %d\n", sum);
    printf("Average of odd numbers: %.2f\n", average);

    return 0;
}
