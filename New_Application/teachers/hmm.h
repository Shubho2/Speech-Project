#ifndef _HMM_H_
#define _HMM_H_

using namespace std;

void runtime_VQ();
long double forword();
void backword();
void gamma_matrix();
void viterbi();
long double pstar();
int qstar();
void backtrack(int q);
void xi_matrix();
void reest_gamma();
void reest_pi();
void reest_A();
void adjust_B_matrix();
void show_A();
void show_pi();
void show_B();
void reest_B();
void store_log_file();
//void store_model(string model_path);
void set_all_to_zero();
void averaging_model(int no_of_model);
void load_model(int model_no);
void flush_alp_beta();
int testing_model();
void re_initialize_A_B_pi(int digit);
void retraining_model();
void initialize_A_B_pi();
int testing(int sec);
#endif