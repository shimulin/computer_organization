#define macro_pi_cycle_count pi_cycle_count = (add_cnt + sub_cnt + others_cnt) * 3 + (mul_cnt + div_cnt) * 4 + lw_cnt * 20 + sw_cnt * 15;
#define macro_pi_cpu_time pi_cpu_time = pi_cycle_count * cycle_time; 
#define macro_calc_pi_ratio pi_ratio = ((add_cnt + sub_cnt + others_cnt) * 3 + (mul_cnt + div_cnt) * 4) / pi_cycle_count;


#define macro_arraymul_baseline_cycle_count arraymul_baseline_cycle_count = (add_cnt + sub_cnt + others_cnt) * 3 + (mul_cnt + div_cnt) * 4 + lw_cnt * 20 + sw_cnt * 15;;
#define macro_arraymul_baseline_cpu_time arraymul_baseline_cpu_time = arraymul_baseline_cycle_count * cycle_time;
#define macro_calc_arraymul_baseline_ratio arraymul_baseline_ratio = ((add_cnt + sub_cnt + others_cnt) * 3 + (mul_cnt + div_cnt) * 4) / arraymul_baseline_cycle_count;

#define macro_improved_version1_cycle_count improved_version1_cycle_count = (add_cnt + sub_cnt + others_cnt) * 3 + (mul_cnt + div_cnt) * 4 + lw_cnt * 20 + sw_cnt * 15;;
#define macro_improved_version1_cpu_time improved_version1_cpu_time = improved_version1_cycle_count * cycle_time;

#define macro_improved_version2_cycle_count improved_version2_cycle_count = (add_cnt + sub_cnt + others_cnt) * 3 + (mul_cnt + div_cnt) * 4 + lw_cnt * 20 + sw_cnt * 15;;
#define macro_improved_version2_cpu_time improved_version2_cpu_time = improved_version2_cycle_count * cycle_time;
