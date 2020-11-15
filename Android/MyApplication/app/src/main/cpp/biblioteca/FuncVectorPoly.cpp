/*
 * FuncVectorPoly.cpp
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
#include <Pds/Vector>
#include <Pds/Matrix>
#include <Pds/MathMatrix>
#include <Pds/FuncMatrix> 
#include <Pds/FuncVectorPoly>
#include <iostream>


Pds::Matrix Pds::PolyMat(Pds::Vector X, unsigned int ORDER)
{
    unsigned int col;

    Pds::Matrix P(X.Nlin(),ORDER+1);
    if(P.IsEmpty()) return P;
    
    for(col=0;col<=ORDER;col++)
    {
        P.SetColVector(col,pow,X,col);
    }
    
    return P;
}

Pds::Matrix Pds::PolyMat(double x, unsigned int ORDER)
{
    unsigned int col;

    Pds::Matrix P(1,ORDER+1);
    if(P.IsEmpty()) return P;
    
    for(col=0;col<=ORDER;col++)
    {
        P.Set(col,pow(x,col));
    }
    
    return P;
}


Pds::Vector Pds::PolyFit(Pds::Vector X, Pds::Vector Y, unsigned int ORDER)
{
    unsigned int col;
    
    if(X.Nlin()!=Y.Nlin())  return Pds::Matrix();
    
    double M1=fabs(X.Max());
    double M2=fabs(X.Min());
    double Max=M1>M2?M1:M2;

    X.MulAssig(1.0/Max);
    
    // Calculando a matriz de Vandermonde
    Pds::Matrix Vander(X.Nlin(),ORDER+1);
    if(Vander.IsEmpty())    return Vander;
    for(col=0;col<=ORDER;col++)
    {
        Vander.SetColVector(col,pow,X,col);
    }
    
    // Calculando inv(MtM)
    double rcond=0;
    Pds::Matrix mat=(Vander.MtM()).Inv(&rcond);
    
    
    if(rcond<Pds::Ra::WarningRCond)
    {
        pds_print_warning_message("POLYFIT FUNCTION RETURNED A VOID MATRIX.");
        pds_print_warning_message("Rcond "<<rcond<<" < "<<Pds::Ra::WarningRCond);
        return Pds::Matrix();
    }
    
    Pds::Vector P=mat.MulT(Vander)*Y;
    
    for(col=0;col<=ORDER;col++)
    {
        P.RowMulAssig (col,pow(1.0/Max,col));
    }
    
    return P;
}

Pds::Vector Pds::PolyVal(Pds::Vector P,Pds::Vector X)
{
    Pds::Vector B;
    B=Pds::PolyMat(X,P.Nlin()-1)*P;
    return B;
}


Pds::Matrix Pds::PolyVal(Pds::Vector P,Pds::Matrix X)
{
    Pds::Matrix B=P.Get(0)*Pds::Ones(X.Size());
    
    Pds::Matrix Tmp=Pds::Ones(X.Size());
    for(unsigned int i=1;i<P.Nel();i++)
    {
        Tmp=Tmp.Product(X);
        B.AddAssig(P.Get(i)*Tmp);
    }
    return B;
}


Pds::Vector Pds::PolyVal(Pds::Vector P,double x)
{
    Pds::Vector B;
    B=Pds::PolyMat(x,P.Nlin()-1)*P;
    return B;
}


Pds::Vector Pds::PolyDer(Pds::Vector P,unsigned int N)
{
    if(P.IsEmpty()) return P;
    
    if(N==0)        return P;
    else if(N>=P.Nlin())    return Pds::Vector(1);
    else
    {
        unsigned int id;
        unsigned int M;
        
        if(P.Nlin()>1)  M=P.Nlin()-1;
        else            M=1;
        
        Pds::Vector R(M);
        
        for (id=0;id<M;id++)
        R.Set(id,0,P.Get(id+1,0)*(id+1));
        
        if(N==1)    return R;
        else        return Pds::PolyDer(R,N-1);
    }

}

Pds::Vector Pds::PolyMul(Pds::Vector &P,Pds::Vector &Q)
{
    return P.Conv(Q);
}

Pds::Vector Pds::PolyAdd(Pds::Vector &P,Pds::Vector &Q)
{
    if(P.IsEmpty()) return P;
    if(Q.IsEmpty()) return Q;
    
    if(P.Nlin()>Q.Nlin())
    {
        Pds::Vector V(P);
        V.AddAssigAt(0,0,Q);
        return V;
    }
    else
    {
        Pds::Vector V(Q);
        V.AddAssigAt(0,0,P);
        return V;
    }
}
