/*
 * MathMatrix.cpp
 * 
 * Copyright 2018 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */


#include <Pds/MathMatrix>
#include <cmath>

Pds::Matrix Pds::Round(const Pds::Matrix &A)
{
    Pds::Matrix B(round,A);
    return B;
}

Pds::Matrix Pds::Abs(const Pds::Matrix &A)
{
    Pds::Matrix B(fabs,A);
    return B;
}

Pds::Matrix Pds::Sin(const Pds::Matrix &A)
{
    Pds::Matrix B(sin,A);
    return B;
}

Pds::Matrix Pds::Cos(const Pds::Matrix &A)
{
    Pds::Matrix B(cos,A);
    return B;
}

Pds::Matrix Pds::Tan(const Pds::Matrix &A)
{
    Pds::Matrix B(tan,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Exp(const Pds::Matrix &A)
{
    Pds::Matrix B(exp,A);
    return B;
}


Pds::Matrix Pds::TwoExp(const Pds::Matrix &A)
{
    Pds::Matrix B(exp2,A);
    return B;
}

Pds::Matrix Pds::Log(const Pds::Matrix &A)
{
    Pds::Matrix B(log,A);
    return B;
}

Pds::Matrix Pds::Ln(const Pds::Matrix &A)
{
    Pds::Matrix B(log,A);
    return B;
}

Pds::Matrix Pds::Log2(const Pds::Matrix &A)
{
    Pds::Matrix B(log2,A);
    return B;
}

Pds::Matrix Pds::Log10(const Pds::Matrix &A)
{
    Pds::Matrix B(log10,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Sqrt(const Pds::Matrix &A)
{
    Pds::Matrix B(sqrt,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Pow(const Pds::Matrix &A,double var)
{
    return Pds::Matrix(pow,A,var);
}

Pds::Matrix Pds::Pow(const Pds::Matrix &A,const Pds::Matrix &B)
{
    return Pds::Matrix(pow,A,B);
}
////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Atan2(const Pds::Matrix &A,const Pds::Matrix &B)
{
    return Pds::Matrix(atan2,A,B);
}
////////////////////////////////////////////////////////////////////////
// Finciones de activacion
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
double Pds::SQNL(double x)
{   
    if (x>2.0)      return 1.0;
    else if(x>0.0)  return x-x*x/4;
    else if(x>-2.0) return x+x*x/4;
    else            return -1.0;
}

Pds::Matrix Pds::SQNL(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::SQNL,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::Gaussian(double x)
{   
    return exp(-x*x);
}

Pds::Matrix Pds::Gaussian(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Gaussian,A);
    return B;
}


////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Tanh(const Pds::Matrix &A)
{
    Pds::Matrix B(tanh,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::Sigmoid(double x)
{   
    return 1/(1+exp(-x));
}

Pds::Matrix Pds::Sigmoid(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Sigmoid,A);
    return B;
}


////////////////////////////////////////////////////////////////////////
// Otros
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
double Pds::Logit(double x)
{   
    return log(x/(1.0-x));
}

Pds::Matrix Pds::Logit(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Logit,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::Sum(const Pds::Matrix &A)
{
    return A.Sum();
}

double Pds::Mean(const Pds::Matrix &A)
{
    return A.Mean();
}

double Pds::Var(const Pds::Matrix &A, double *mean)
{
    return A.Var(mean);
}

double Pds::Var(const Pds::Matrix &A)
{
    return A.Var();
}

////////////////////////////////////////////////////////////////////////
double Pds::Det(const Pds::Matrix &A)
{
    return A.Det();
}


double Pds::Rms(const Pds::Matrix &A)
{
    return A.Rms();
}

double Pds::SumSquare(const Pds::Matrix &A)
{
    return A.SumSquare();
}

double Pds::MeanAbsolute(const Pds::Matrix &A)
{
    return A.MeanAbsolute();
}

double Pds::MeanSquare(const Pds::Matrix &A)
{
    return A.MeanSquare();
}

double Pds::Norm(const Pds::Matrix &A)
{
    return A.Norm();
}

////////////////////////////////////////////////////////////////////////
double Pds::Sinc(double x)
{   
    if (x==0)   return 1;
    else        return sin(x)/x;
}

Pds::Matrix Pds::Sinc(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Sinc,A);
    return B;
}


////////////////////////////////////////////////////////////////////////
double Pds::Hb(double x)
{   
    return -x*log2(x)-(1.0-x)*log2(1.0-x);
}

Pds::Matrix Pds::Hb(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::Hb,A);
    return B;
}

////////////////////////////////////////////////////////////////////////

double Pds::HbInv(double h)
{
	double p_low,p_high,p_out;
    double h_out;
    double Error;
	if(h==1.0)	return 0.5;
	if(h==0.0)	return 0.0;
	if(h>1.0)	return Pds::Ra::Nan;
	if(h<0.0)	return Pds::Ra::Nan;

	p_low=0.0;	p_high=h/2;	
	p_out=0.0;

	//dp=0.001;
	if(h<=0.5)	{Error=h/1000000;}
	else		{Error=(1.0-h)/1000000;}
	
	do{
		p_out=(p_low+p_high)/2.0;

		h_out=Pds::Hb(p_out);

		if(h_out<h)	p_low  = p_out;
		else		p_high = p_out;
	}while(fabs(h-h_out)>Error);

	return p_out;
}

Pds::Matrix Pds::HbInv(const Pds::Matrix &A)
{
    Pds::Matrix B(Pds::HbInv,A);
    return B;
}

////////////////////////////////////////////////////////////////////////
double Pds::UnitStep(double x)
{   
    return (x >= 0);
}

Pds::Matrix Pds::UnitStep(const Pds::Matrix &A)
{
    return A.Geq(0);
}

double Pds::UnitRamp(double x)
{   
    if(x>=0)    return x;
    else        return 0.0;
}

Pds::Matrix Pds::UnitRamp(const Pds::Matrix &A)
{
    return Pds::Matrix(Pds::UnitRamp,A);
}

double Pds::Sign(double x)
{   
    return ((x > 0) - (x < 0));
}

Pds::Matrix Pds::Sign(const Pds::Matrix &A)
{
    return Pds::Matrix(Pds::Sign,A);
}


unsigned int Pds::Factorial(unsigned int n)
{
    return n == 0 ? 1 : n * Pds::Factorial(n - 1);
}


unsigned int Pds::NchooseK(unsigned int n,unsigned int k)
{
	double C;
	unsigned int a;
	unsigned int i;

    if(k>n) return 0;

	if((n-k)>k)	a=k;
	else		a=n-k;

	C=1.0;
	for(i=0;i<a;i++)	
	{
		C=C*(n-i)/(a-i);
	}

	return round(C);
}

unsigned int Pds::NmultichooseK(unsigned int n,unsigned int k)
{
    return Pds::NchooseK(n+k-1,k);
}
////////////////////////////////////////////////////////////////////////
// Integration
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
double Pds::SimpsonIntegration(double (*f)(double), double a,double b,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

	if(b<a)		return 0.0;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;
	h=(b-a)/n;

	S0=(*f)(a)+(*f)(b);
    
	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)(a+h*i);
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)(a+h*i);
	}

	return (S0+4.0*Si+2.0*Sp)*h/3.0;
}

////////////////////////////////////////////////////////////////////////
double Pds::SimpsonIntegration(double (*f)(double,double),double r, double a,double b,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

	if(b<a)		return 0.0;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;
	h=(b-a)/n;

	S0=(*f)(a,r)+(*f)(a+h*n,r);
	
	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)(a+h*i,r);
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)(a+h*i,r);
	}

	return (S0+4.0*Si+2.0*Sp)*h/3.0;
}

////////////////////////////////////////////////////////////////////////
double Pds::ImproperIntegration(double (*f)(double), double a,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

    double x0,Sm;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;

	if(a>=0.0)
    {	
        Sm=0.0;
        x0=a;
    }
    else
    {
        Sm=Pds::SimpsonIntegration(f,a,0,n);
        x0=0;
    }

	h=1.0/((x0+1.0)*n);

	S0=0.0+(*f)(x0)*(x0+1.0)*(x0+1.0);

	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)((1.0/(h*i))-1.0)/((h*i)*(h*i));
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)((1.0/(h*i))-1.0)/((h*i)*(h*i));
	}
	return Sm+(S0+4.0*Si+2.0*Sp)*h/3.0;
}


double Pds::ImproperIntegration(double (*f)(double,double),double r, double a,unsigned int n)
{
	double S0,Si,Sp,h;
	unsigned int i;

    double x0,Sm;
	if(n<=0)	return 0.0;
	if(n%2!=0)	n=n+1;

	if(a>=0.0)
    {	
        Sm=0.0;
        x0=a;
    }
    else
    {
        Sm=Pds::SimpsonIntegration(f,r,a,0,n);
        x0=0;
    }

	h=1.0/((x0+1.0)*n);

	S0=0.0+(*f)(x0,r)*(x0+1.0)*(x0+1.0);

	for(i=1,Si=0;i<n;i=i+2)
	{
		Si=Si+(*f)((1.0/(h*i))-1.0,r)/((h*i)*(h*i));
	}
	
	for(i=2,Sp=0;i<n;i=i+2)
	{
		Sp=Sp+(*f)((1.0/(h*i))-1.0,r)/((h*i)*(h*i));
	}
	return Sm+(S0+4.0*Si+2.0*Sp)*h/3.0;
}
