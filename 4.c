#include <stdio.h>

int main() {
    int i = 0;
    int h[9] = {0}, x[6] = {0}, y[6] = {0};

    FILE *input = fopen("../input/4.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);  

    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];

    asm volatile(
        "li %[i], 0\n\t" // set i = 0
        "outer_loop:\n\t" // i loop

        "   li %[j], 0\n\t" // set j = 0
        "   middle_loop:\n\t" // j loop
        "   li x29, 0\n\t"

        "       li %[f], 0\n\t" // set f = 0
        "       inner_loop:\n\t" // f loop

        "           li x5, 4\n\t"
        "           mul x5, x5, %[i]\n\t" // x5 = i
        "           li x28, 3\n\t"
        "           mul x5, x5, x28\n\t" // x5 = 3i
        "           add x6, %[h], x5\n\t" // x6 = p_h + 3i
        "           li x28, 4\n\t"
        "           mul x5, x28, %[f]\n\t" // x5 = f
        "           add x6, x6, x5\n\t" // x6 = p_h + 3i + f

        "           li x5, 4\n\t"
        "           mul x5, x5, %[f]\n\t"
        "           li x28, 2\n\t"
        "           mul x5, x5, x28\n\t"
        "           add x7, %[x], x5\n\t"
        "           li x28, 4\n\t"
        "           mul x5, x28, %[j]\n\t"
        "           add x7, x7, x5\n\t"

        "           lw x6, 0(x6)\n\t"
        "           lw x7, 0(x7)\n\t"
        "           mul x6, x6, x7\n\t"
        "           add x29, x29, x6\n\t"

        "           li x7, 4\n\t"
        "           mul x7, x7, %[i]\n\t"
        "           li x28, 2\n\t"
        "           mul x7, x7, x28\n\t"
        "           add x7, %[y], x7\n\t"
        "           li x28, 4\n\t"
        "           mul x5, x28, %[j]\n\t"
        "           add x7, x7, x5\n\t"
        "           sw x29, 0(x7)\n\t"

        "           addi %[f], %[f], 1\n\t" // f++
        "           bne %[f], %[inner_loop_count], inner_loop\n\t" // if f != 3, go to inner_loop (run 3 times)

        "           addi %[j], %[j], 1\n\t" // j++
        "           bne %[j], %[middle_loop_count], middle_loop\n\t" //if j != 2, go to middle_loop (run 2 times)

        "           addi %[i], %[i], 1\n\t" // i++
        "           bne %[i], %[outer_loop_count], outer_loop\n\t" // if i != 3, go to outer_loop (run 3 times)

        : [y] "+r" (p_y), [h] "+r" (p_h), [x] "+r" (p_x)
        : [i] "r" (0), [j] "r" (0), [f] "r" (0), [inner_loop_count] "r" (3), [middle_loop_count] "r" (2), [outer_loop_count] "r" (3)
        : "x5", "x6", "x7", "x28", "x29"
    );

    p_y = &y[0];
    for (i = 0; i < 6; i++) {
        printf("%d ", *p_y++);
    }
    printf("\n");
    return 0;   
}