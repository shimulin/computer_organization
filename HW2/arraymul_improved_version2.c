"improved_loop:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

    "vsetivli t0, 8, e16\n\t"
    "addi %[others_cnt], %[others_cnt], 1\n\t"

    "sub %[arr_size], %[arr_size], t0\n\t"
    "addi %[sub_cnt], %[sub_cnt], 1\n\t"

    "slli t0, t0, 1\n\t"
    "addi %[others_cnt], %[others_cnt], 1\n\t"

    "vle16.v v0, (%[h])\n\t"
    "addi %[lw_cnt], %[lw_cnt], 1\n\t"

    "vle16.v v1, (%[x])\n\t"
    "addi %[lw_cnt], %[lw_cnt], 1\n\t"

    "vmul.vv v1, v0, v1\n\t"
    "addi %[mul_cnt], %[mul_cnt], 1\n\t"

    "vadd.vx v1, v1, %[id]\n\t"
    "addi %[add_cnt], %[add_cnt], 1\n\t"

    "vse16.v v1, (%[y])\n\t"
    "addi %[sw_cnt], %[sw_cnt], 1\n\t"
    
    "add %[h], %[h], t0\n\t"
    "addi %[add_cnt], %[add_cnt], 1\n\t"

    "add %[x], %[x], t0\n\t"
    "addi %[add_cnt], %[add_cnt], 1\n\t"

    "add %[y], %[y], t0\n\t"
    "addi %[add_cnt], %[add_cnt], 1\n\t"

    "bnez %[arr_size], improved_loop\n\t"