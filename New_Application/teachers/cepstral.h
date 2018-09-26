#ifndef _CEPS_H_
#define _CEPS_H_

using namespace std;
void dcshift(string s);
void normalize(string s);
void croping(string str);
void trim();
extern long double* autocor(long double *arr );
extern long double* lpccoef(long double* r);
extern long double* cepstral_cal(long double *a);
#endif