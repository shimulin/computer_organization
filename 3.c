#include <stdio.h>

int main() {
    int f, i, j;
    int h[9] = {0}, x[6] = {0}, y[6] = {0};
    FILE *input = fopen("../input/3.txt", "r");
    for (i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for (i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for (i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);

    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (f = 0; f < 3; f++) {
                asm volatile(
                    "mul t0, %[h], %[x]\n\t" // "t0 can change to x5"
                    "add %[y], %[y], t0\n\t"
                    : [y] "+r" (y[2 * i + j])
                    : [x] "r" (x[2 * f + j]), [h] "r" (h[3 * i + f])
                    : "t0" // x5 no need to declare t0 ~ t6 only seven variables can be used
                );
            }
        }
    }

    p_y = &y[0];
    for (i = 0; i < 6; i++) {
        printf("%d ", *p_y++);
    }
    printf("\n");
    return 0;
}
