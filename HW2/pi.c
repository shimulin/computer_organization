"li t1, 0\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"li t2, -1\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"loop:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"neg t2, t2\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"add t4, t1, t1\n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"

"addi t4, t4, 1\n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"

"fcvt.d.w f1, t4\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"fcvt.d.w f2, t2\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"fdiv.d f1, f2, f1\n\t"
"addi %[div_cnt], %[div_cnt], 1\n\t"

"fadd.d %[pi], %[pi], f1\n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"

"addi t1, t1, 1\n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"

"bne t1, %[N], loop\n\t"