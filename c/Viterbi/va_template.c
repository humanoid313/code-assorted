// AUTHOR: Jake Gunther
//         Dept. of Electrical and Computer Engineering
//         Utah State University, Logan, Utah
//
// COURSE: ECE 6670 - Communication Systems II
//         Fall 2010
//
// FILE:   Template for Viterbi algorithm code.
//
// BUILD:  gcc va_template.c -o va -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For sqrt, log and fmod

#define CMULTR(xr,xi,yr,yi)   ((xr)*(yr) - (xi)*(yi)) /* Real part of product */
#define CMULTI(xr,xi,yr,yi)   ((xr)*(yi) + (xi)*(yr)) /* Imag part of product */

double gaussian (double mean, double variance);
int save_sig(double *p, int num, char *fname);
int load_sig(double **p, int * num, char *fname, char print_flag);

double * chan_r;
double * chan_i;
int L;  // Channel order
int L1; // Channel length, L+1

double *LUT_r;
double *LUT_i;
int M; // Size of constellation
int M1; // Mask
int b; // Number of bits per symbol
int bL;

double *data_r;
double *data_i;
int dlen; // Length of data record

int st; // Channel state (assumes that log2(M)*L < 32 bits)
int num_st; // Number of states M^L
int num_e;  // Number of edges  M^(L+1)

double nstd=0.0; // Noise standard deviation

int main(int argc, char* argv[])
{
   int i, n, e, k, et;
   double outr, outi, sr, si, cr, ci;

   // Load constellation and channel
   load_sig(&LUT_r, &M, "LUTr.dat",1);
   load_sig(&LUT_i, &M, "LUTi.dat",1);
   load_sig(&chan_r, &L1, "channelr.dat",1);
   load_sig(&chan_i, &L1, "channeli.dat",1);

   M1 = M-1; // Mask for extracting symbol index
   L = L1-1; // Memory (order) of channel
   for(i=M, b=0; i>1; i/=2, b++); // b=log2(M)
   for(i=0, num_st=1; i<L  ; i++, num_st*=M); // Computes M^L
   num_e = num_st * M;                        // Computes M^(L+1)
   bL = b*L;

   // Initial channel state
   st = rand() % num_st; // Between 0 and (M^L)-1

   // Allocate memory for the data
   dlen = 5; // Number of samples to generate
   data_r = (double*)calloc(dlen,sizeof(double));
   data_i = (double*)calloc(dlen,sizeof(double));

   // Start data generation
   for(n=0; n<dlen; n++) {
      i = rand() % M;     // Random new symbol
      e = (i << bL) | st; // Create edge information
      for(k=L, et = e, outr=0.0, outi=0.0; k>=0; k--, et>>=b) {
	 i = et & M1; // Extract symbol index
	 sr = LUT_r[i];  si = LUT_i[i]; // Look up symbol
	 cr = chan_r[k]; ci = chan_i[k]; // Channel coef
	 outr += CMULTR(cr,ci,sr,si); // Multiply accumulate for
	 outi += CMULTI(cr,ci,sr,si); // convolution with channel
      }
      st = e >> b; // Shift symbol indexes over for next time.
      data_r[n] = outr + nstd*gaussian(0.0,1.0); // Add Gaussian noise
      data_i[n] = outi + nstd*gaussian(0.0,1.0); // Add Gaussian noise
   }
   save_sig(data_r,dlen,"data_r.dat");
   save_sig(data_i,dlen,"data_i.dat");
   //printf("Printing \n");
    //load_sig(&data_r,&dlen, "data_r.dat",1);
    //load_sig(&data_i,&dlen, "data_i.dat",1);

   // NOTE TO STUDENTS: Put your Viterbi algorithm code here
   // or integrate it into the data generation loop above.
   // Given the input constellation, how should the noise
   // variance be scaled to achieve a given Eb/No in dB?

   return 1;
}

int load_sig(double **p, int *num, char *fname, char print_flag)
{
   int i, num_read;
   FILE * fp;
   if((fp = fopen(fname,"rb")) == NULL) {
      fprintf(stderr,"Could not open %s.\n",fname);
	  return 0;
   }
   fread(num,1,sizeof(int),fp);
   num_read = *num;
   (*p) = (double*)calloc(num_read,sizeof(double));
   fread(*p,sizeof(double),num_read,fp);
   fclose(fp);
   if(print_flag) {
      for(i=0; i<num_read; i++) {
	     printf("p[%d] = %g\n",i,(*p)[i]);
      }
   }
   return num_read;
}
// % Matlab function for writing data that
// % can be read using C function load_sig.
// function save_sig(x,len,fname)
// fp = fopen(fname,'wb');
// fwrite(fp,len,'int');
// fwrite(fp,x,'double');
// fclose(fp);

int save_sig(double *p, int num, char *fname)
{
   int num_write;
   FILE * fp;
   if((fp = fopen(fname,"wb")) == NULL) {
      fprintf(stderr,"Could not open %s.\n",fname);
	  return 0;
   }
   fwrite(&num,sizeof(int),1,fp);
   num_write = fwrite(p,sizeof(double),num,fp);
   fclose(fp);
   return num_write;
}
// % Matlab function for reading data written
// % by C function save_sig.
// function [x,len]=load_sig(fname)
// fp = fopen(fname,'rb');
// len = fread(fp,1,'int');
// x = fread(fp,len,'double');
// fclose(fp);


// Random number generation stuff
#define A  16807.0		/* multiplier */
#define M  2147483647.0		/* modulus */
static double r_seed=2.0;	/* seed number */

/*-------------------------------------------------*
 * rnd--generates a uniform random variable (0,1)  *
 *-------------------------------------------------*/
double rnd() {
  r_seed = fmod(A*r_seed,M);
  return (r_seed*4.656612875e-10);
}

/*--------------------------------------------------*
 * gaussian--generates a Gaussian random variable  *
 *           with mean a and standard deviation d.  *
 *--------------------------------------------------*/
double gaussian (double a, double d)
{
  static double t = 0.0;
  double x,v1,v2,r;
  if (t==0){
    do {
      v1 = 2.0*rnd() - 1.0;
      v2 = 2.0*rnd() - 1.0;
      r = v1*v1 + v2*v2;
    } while(r >= 1.0);
    r = sqrt((-2.0*log(r))/r);
    t = v2*r;
    return(a+v1*r*d);
  }
  else {
    x = t;
    t = 0.0;
    return(a+x*d);
  }
}

