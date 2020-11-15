/*
 * FuncMatrix.cpp
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

#include <cmath>

#include <Pds/Matrix>
#include <Pds/Vector>
#include <Pds/MathMatrix>
#include <Pds/FuncMatrix>
#include <list>
#include <cmath>


bool Pds::Meshgrid(const Pds::Vector &SpaceX,const Pds::Vector &SpaceY,Pds::Matrix &X,Pds::Matrix &Y)
{
    if(SpaceX.IsEmpty())    return false;
    if(SpaceY.IsEmpty())    return false;
    double var;
    
    unsigned int Nx=SpaceX.Nel();
    unsigned int Ny=SpaceY.Nel();
    X=Pds::Zeros(Nx,Ny);
    Y=Pds::Zeros(Nx,Ny);

    for(unsigned int col=0;col<Ny;col++)
    X.SetColVector(col,SpaceX);

    for(unsigned int col=0;col<Ny;col++)
    {
        var=SpaceY.Get(col);
        Y.SetColValue(col,var);
    }
    return true;
}

Pds::Matrix Pds::Mountain(unsigned int N,double L)
{
    Pds::Matrix Z(N,N);
    double x,y,z;
    unsigned int i,j;

    L=fabs(L);
    
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
        x=(L*2.0*i)/(N-1.0)-L;
        y=(L*2.0*j)/(N-1.0)-L;

        z=  x*exp(-x*x-y*y);

        z=z*126.0+127.0;
    
        Z.At(i,j)=z;
    }
    return Z;
}

Pds::Matrix Pds::Peaks(unsigned int N,double L)
{
    Pds::Matrix Z(N,N);
    double x,y,z;
    unsigned int i,j;

    L=fabs(L);
    
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
        x=(L*2.0*i)/(N-1.0)-L;
        y=(L*2.0*j)/(N-1.0)-L;


        z=  (3.0/8.0)*pow(1.0-x,2)*exp(-pow(x,2)-pow(1.0+y,2) ) 
            -(10.0/8.0)*(x/5.0 - pow(x,3) - pow(y,5))*exp(-pow(x,2)-pow(y,2)) 
            -(1.0/24.0)*exp(-pow(x+1.0,2) - pow(y,2)) ;

        z=z*126.0+127.0;
    
        Z.At(i,j)=z;
    }
    return Z;
}

Pds::Matrix Pds::Operate(double (*func)(double x,double y),const Pds::Matrix &X,const Pds::Matrix &Y)
{
    return Pds::Matrix(func,X,Y);
}

Pds::Matrix Pds::Operate(double (*func)(double x,double y,double z),const Pds::Matrix &X,const Pds::Matrix &Y,const Pds::Matrix &Z)
{
    return Pds::Matrix(func,X,Y,Z);
}

Pds::Matrix Pds::MatrixId(unsigned int N)
{
    Pds::Matrix A(N);
    A.FillId();
    return A;
}

Pds::Matrix Pds::MatrixId(const Pds::Size &S)
{
    Pds::Matrix A(S.nlin,S.ncol);
    A.FillId();
    return A;
}

Pds::Matrix Pds::MatrixId(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    A.FillId();
    return A;
}

Pds::Matrix Pds::RandN(unsigned int N)
{
    Pds::Matrix A(N);
    A.FillRandN();
    return A;
}

Pds::Matrix Pds::RandN(const Pds::Size &S)
{
    Pds::Matrix A(S.nlin,S.ncol);
    A.FillRandN();
    return A;
}

Pds::Matrix Pds::RandN(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    A.FillRandN();
    return A;
}

Pds::Matrix Pds::RandU(unsigned int N)
{
    Pds::Matrix A(N);
    A.FillRandU();
    return A;
}

Pds::Matrix Pds::RandU(const Pds::Size &S)
{
    Pds::Matrix A(S.nlin,S.ncol);
    A.FillRandU();
    return A;
}

Pds::Matrix Pds::RandU(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    A.FillRandU();
    return A;
}

Pds::Matrix Pds::Diag(Pds::Matrix A)
{
    unsigned int id;
    
    if(A.IsEmpty())
    {
        Pds::Matrix B;
        return B;
    }
    
    unsigned int N=A.Nlin()*A.Ncol();
    Pds::Matrix B(N,N);
    
    for(id=0;id<N;id++)
    {
        B.Set(id,id,A.Get(id));
    }
    return B;
}


Pds::Matrix Pds::Eye(unsigned int N)
{
    unsigned int lin;
    
    Pds::Matrix A(N);
    
    if(A.IsEmpty())  return A;
    
    for(lin=0;lin<N;lin++)
    A.Set(lin,lin,1.0);
    
    return A;
}

Pds::Matrix Pds::Ones(const Pds::Size &S)
{
    Pds::Matrix A(S.nlin,S.ncol);
    
    if(A.IsEmpty())  return A;
    
    A.Fill(1.0);
    return A;
}

Pds::Matrix Pds::Ones(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    
    if(A.IsEmpty())  return A;
    
    A.Fill(1.0);
    return A;
}

Pds::Matrix Pds::Ones(unsigned int N)
{
    Pds::Matrix A(N,N);
    
    if(A.IsEmpty())  return A;
    
    A.Fill(1.0);
    return A;
}

Pds::Matrix Pds::Zeros(const Pds::Size &S)
{
    Pds::Matrix A(S.nlin,S.ncol);
    
    return A;
}

Pds::Matrix Pds::Zeros(unsigned int Nlin,unsigned int Ncol)
{
    Pds::Matrix A(Nlin,Ncol);
    
    return A;
}

Pds::Matrix Pds::Zeros(unsigned int N)
{
    Pds::Matrix A(N,N);
    
    return A;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::CountingTable(unsigned int N,unsigned int M)
{
    if(N==0)    return Pds::Matrix();
    if(M==0)    return Pds::Matrix();
    if(M==1)    return Pds::Matrix(N,1);

    unsigned int L=(int)pow(1.0*M,1.0*N);
    unsigned int q,r;
    
    Pds::Matrix Ans(L,N);
    
    for(unsigned int lin=0;lin<L;lin++)
    {
        q=lin;
        for(unsigned int col=0;col<N;col++)    
        {
            r=q%M;
            Ans.Set(lin,col,r);
            q=q/M;
        }
    }

    return Ans;
}

Pds::Matrix Pds::CountingTable(unsigned int N, int min, int max, unsigned int from_id)
{
    if(min>max)return Pds::Matrix();
    unsigned int M=max+1-min;
    
    if(N==0)    return Pds::Matrix();
    if(M==1)    return Pds::Matrix(N,1);

    unsigned int L=(int)pow(1.0*M,1.0*N);
    if(from_id>=L)  return Pds::Matrix();
    unsigned int q,r;

    Pds::Matrix Ans(L-from_id,N);
    
    for(unsigned int lin=from_id;lin<L;lin++)
    {
        q=lin;
        for(unsigned int col=0;col<N;col++)    
        {
            r=q%M;
            Ans.Set(lin-from_id,col,1.0*r+min);
            q=q/M;
        }
    }

    return Ans;
}
Pds::Matrix Pds::MultisetIndexSum(unsigned int N,unsigned int M)
{
    unsigned int Nlin=0;
    Pds::Matrix A,Block;

    if (N==1)   return Pds::Matrix(1,1,M);
    if (M==0)   return Pds::Zeros(1,N);

    Nlin=Pds::NmultichooseK(N-1,M);
    A=Pds::MergeHor({   Pds::MultisetIndexSum(N-1,M),
                        Pds::Zeros(Nlin,1)});
    
    for(unsigned int m=1;m<=M;m++)
    {

        Nlin=Pds::NmultichooseK(N-1,M-m);
        Block=Pds::MergeHor({   Pds::MultisetIndexSum(N-1,M-m),
                                Pds::Matrix(Nlin,1,m)});
        A=Pds::MergeVer({A,Block});
    }
    return A;
}

std::string Pds::MultisetIndexSumToString(const Pds::Matrix &ID,std::string Separator,unsigned int xinit)
{
    std::string str="";
    std::string str_m="";
    unsigned int L=ID.Nlin();
    unsigned int N=ID.Ncol();
    unsigned int lin,col,id;
    
    for(lin=0;lin<L;lin++)
    {
        str_m="";
        for (col=0;col<N;col++)
        {
            id=ID.Get(lin,col);
            if(id>1)    str_m=str_m+"x_{"+std::to_string(col+xinit)+"}^{"+std::to_string(id)+"}";
            if(id==1)   str_m=str_m+"x_{"+std::to_string(col+xinit)+"}";

        }
        if (str_m.length()==0)  str_m="1";
        
        if(lin==0)  str=str_m;
        else        str=str+Separator+ str_m;
    }
    return str;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Monomials(const Pds::Matrix &X,unsigned int M,Pds::Matrix &ID)
{
    if(X.IsEmpty()) return Pds::Matrix();
    if(M==0)        return Pds::Matrix(X.Nlin(),1,1);
    if(M==1)        return X;
    
    unsigned int N=X.Ncol();
    unsigned int L=Pds::NmultichooseK(N,M);
    
    ID=Pds::MultisetIndexSum(N,M);

    Pds::Vector V;
    Pds::Matrix R(X.Nlin(),L);

    for(unsigned int i=0;i<L;i++)
    {
        V=X.Multiindex(ID.GetRowAsColVector(i));
        R.SetColVector(i,V);
    }

    return R;
}

Pds::Matrix Pds::Monomials(const Pds::Matrix &X,unsigned int M)
{
    Pds::Matrix ID;
    return Pds::Monomials(X,M,ID);
}
////////////////////////////////////////////////////////////////////////////////

std::list<unsigned int>  Pds::Find(const Pds::Matrix &A)
{
    return A.Find();
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix  Pds::MergeVer(const std::list<Pds::Matrix> list)
{
    unsigned int Ncol=0;
    unsigned int Nlin=0;
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        if(i==0)    Ncol=pmat->Ncol();
        else
        {
            if(pmat->Ncol()!=Ncol)
            {
                pds_print_error_message("The "<<i<<"-th matrix in list don't have the same column length of 0-th.");
                return Pds::Matrix();
            }
        }

        Nlin=Nlin+pmat->Nlin();
        i++;
    }
    
    Pds::Matrix A(Nlin,Ncol);
    
    unsigned int lin=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        A.SetMatrix(lin,0,*pmat);
        lin=lin+pmat->Nlin();
    }

    return A;
}


Pds::Matrix  Pds::MergeVer(const std::initializer_list<Pds::Matrix> list)
{
    unsigned int Ncol=0;
    unsigned int Nlin=0;
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        if(i==0)    Ncol=pmat->Ncol();
        else
        {
            if(pmat->Ncol()!=Ncol)
            {
                pds_print_error_message("The "<<i<<"-th matrix in list don't have the same column length of 0-th.");
                return Pds::Matrix();
            }
        }

        Nlin=Nlin+pmat->Nlin();
        i++;
    }
    
    Pds::Matrix A(Nlin,Ncol);
    
    unsigned int lin=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        A.SetMatrix(lin,0,*pmat);
        lin=lin+pmat->Nlin();
    }

    return A;
}

Pds::Matrix  Pds::MergeHor(const std::list<Pds::Matrix> list)
{
    unsigned int Ncol=0;
    unsigned int Nlin=0;
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        if(i==0)    Nlin=pmat->Nlin();
        else
        {
            if(pmat->Nlin()!=Nlin)
            {
                pds_print_error_message("The "<<i<<"-th matrix in list don't have the same line length of 0-th.");
                return Pds::Matrix();
            }
        }

        Ncol=Ncol+pmat->Ncol();
        i++;
    }
    
    Pds::Matrix A(Nlin,Ncol);
    
    unsigned int col=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        A.SetMatrix(0,col,*pmat);
        col=col+pmat->Ncol();
    }

    return A;
}

Pds::Matrix  Pds::MergeHor(const std::initializer_list<Pds::Matrix> list)
{
    unsigned int Ncol=0;
    unsigned int Nlin=0;
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        if(i==0)    Nlin=pmat->Nlin();
        else
        {
            if(pmat->Nlin()!=Nlin)
            {
                pds_print_error_message("The "<<i<<"-th matrix in list don't have the same line length of 0-th.");
                return Pds::Matrix();
            }
        }

        Ncol=Ncol+pmat->Ncol();
        i++;
    }
    
    Pds::Matrix A(Nlin,Ncol);
    
    unsigned int col=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        A.SetMatrix(0,col,*pmat);
        col=col+pmat->Ncol();
    }

    return A;
}


Pds::Matrix  Pds::RegressorMatrix(const std::initializer_list<Pds::Matrix> list)
{
    unsigned int Ncol=0;
    unsigned int Nlin=0;
    
    unsigned int i=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        if(i==0)    Ncol=pmat->Ncol();
        else
        {
            if(pmat->Ncol()!=Ncol)
            {
                pds_print_error_message("The "<<i<<"-th matrix in list don't have the same column length of 0-th.");
                return Pds::Matrix();
            }
        }

        Nlin=Nlin+pmat->Nlin();
        i++;
    }
    
    Pds::Matrix A(Nlin,Ncol+1);
    A.SetColValue(0,1.0);
    
    unsigned int lin=0;
    for (auto pmat = list.begin(); pmat != list.end(); pmat++) 
    {
        A.SetMatrix(lin,1,*pmat);
        lin=lin+pmat->Nlin();
    }

    return A;
}



Pds::Matrix  Pds::RegressorMatrix(const Pds::Matrix &B)
{     
    Pds::Matrix A(B.Nlin(),B.Ncol()+1);
    A.SetColValue(0,1.0);
    
    A.SetMatrix(0,1,B);

    return A;
}

Pds::Matrix  Pds::RegressorMatrix(const Pds::Matrix &B,unsigned int M)
{
    if(B.IsEmpty()) return Pds::Matrix();
    if(M==0)        return Pds::Ones(B.Nlin(),1);

    Pds::Matrix A=Pds::RegressorMatrix(B);
    if(M==1)        return A;

    for(unsigned int m=2;m<=M;m++)
    {
        A=Pds::MergeHor({A,Pds::Monomials(B,m)});
    }
    return A;
}


Pds::Matrix  Pds::RegressorMatrix(const Pds::Matrix &B,unsigned int M,Pds::Matrix &ID)
{
    if(B.IsEmpty()) return Pds::Matrix();
    
    ID=Pds::Zeros(1,B.Ncol());
    if(M==0)        return Pds::Ones(B.Nlin(),1);
    
    ID=Pds::MergeVer({ID,Pds::Eye(B.Ncol())});
    Pds::Matrix A=Pds::RegressorMatrix(B);
    if(M==1)        return A;

    Pds::Matrix TMPID;
    for(unsigned int m=2;m<=M;m++)
    {
        A=Pds::MergeHor({A,Pds::Monomials(B,m,TMPID)});
        ID=Pds::MergeVer({ID,TMPID});
    }
    return A;
}

