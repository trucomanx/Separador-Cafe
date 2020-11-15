/*
 * Matrix_operator.cpp
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

#include <string>
#include <iostream>

#include <Pds/Matrix>

////////////////////////////////////////////////////////////////////////
Pds::Matrix operator+(double b,const Pds::Matrix &mat)
{
    return mat.Add(b);
}


Pds::Matrix Pds::Matrix::operator +(double b) const
{
    return this->Add(b);
}

Pds::Matrix Pds::Matrix::Add(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]+b;
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator +(const Pds::Matrix &B) const
{
    return this->Add(B);
}

Pds::Matrix Pds::Matrix::Add(const Pds::Matrix &B) const
{
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();
    if( B.IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(B.nlin,B.ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]+B.array[lin][col];  
    }

    return Ans;
}



////////////////////////////////////////////////////////////////////////

Pds::Matrix operator-(double b,const Pds::Matrix &mat)
{
    Pds::Matrix C=mat;
    return -(C.Sub(b));
}


Pds::Matrix Pds::Matrix::operator -(double b) const
{
    return this->Sub(b);
}

Pds::Matrix Pds::Matrix::Sub(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]-b;
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator -(const Pds::Matrix &B) const
{
    return this->Sub(B);
}

Pds::Matrix Pds::Matrix::Sub(const Pds::Matrix &B) const
{
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();
    if( B.IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(B.nlin,B.ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]-B.array[lin][col];  
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix operator*(double b,const Pds::Matrix &mat)
{
    return mat.Mul(b);
}


Pds::Matrix Pds::Matrix::operator *(double b) const
{
    return this->Mul(b);
}

Pds::Matrix Pds::Matrix::Mul(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]*b;
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

Pds::Matrix operator/(double b,const Pds::Matrix &mat)
{
    return mat.DivSelf(b);
}

Pds::Matrix Pds::Matrix::DivSelf(double b) const
{
    if( this->IsEmpty() )   return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=b/this->array[lin][col];
    }

    return Ans;
}
////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator /(double b) const
{
    return this->Div(b);
}

Pds::Matrix Pds::Matrix::Div(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    //this->Print("(+)this\n");

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]/b;
    }

    return Ans;
}


Pds::Matrix Pds::Matrix::operator/(const Pds::Matrix &B) const
{
    return this->Div(B);
}

Pds::Matrix Pds::Matrix::Div(const Pds::Matrix &B) const
{
    if( this->IsNotSimilarTo(B) )    return Pds::Matrix();
    
    Pds::Matrix Ans(B.Size());
    
    unsigned int lin,col;
   
    for(lin=0;lin<B.nlin;lin++)
    for(col=0;col<B.ncol;col++)
    {       
        Ans.array[lin][col]=(this->array[lin][col])/B.array[lin][col];
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator *(const Pds::Matrix &B) const
{
    return this->Mul(B);
}

Pds::Matrix Pds::Matrix::Mul(const Pds::Matrix &B) const
{
    if( this->IsNotMulBy(B) )    return Pds::Matrix();
    
    Pds::Matrix Ans(this->nlin,B.ncol);

    //this->Print("(*)this\n");
    
    unsigned int lin,col,k;
    double S;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<B.ncol;col++)
    {
        S=0.0;
        for(k=0;k<B.nlin;k++)
        {
            S=S+this->array[lin][k]*B.array[k][col];  
        }
        
        Ans.array[lin][col]=S;
    }
    return Ans;
}

Pds::Matrix Pds::Matrix::MulT(const Pds::Matrix &B) const
{
    if( this->ncol!=B.ncol )    return Pds::Matrix();
    
    Pds::Matrix Ans(this->nlin,B.nlin);
    
    unsigned int lin,col,k;
    double S;
   
    for(lin=0;lin<Ans.nlin;lin++)
    for(col=0;col<Ans.ncol;col++)
    {
        S=0.0;
        for(k=0;k<B.ncol;k++)
        {
            S=S+this->array[lin][k]*B.array[col][k];
        }
        
        Ans.array[lin][col]=S;
    }
    return Ans;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::AddRowMatrix(const Pds::Matrix &B) const
{
    if(!B.IsRowMatrix())    return Pds::Matrix();
    if(this->ncol!=B.ncol)  return Pds::Matrix();
    
    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<Ans.nlin;lin++)
    for(col=0;col<Ans.ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]+B.array[0][col];  
    }

    return Ans;
}


Pds::Matrix Pds::Matrix::SubRowMatrix(const Pds::Matrix &B) const
{
    if(!B.IsRowMatrix())    return Pds::Matrix();
    if(this->ncol!=B.ncol)  return Pds::Matrix();
    
    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<Ans.nlin;lin++)
    for(col=0;col<Ans.ncol;col++)
    {
        Ans.array[lin][col]=this->array[lin][col]-B.array[0][col];  
    }

    return Ans;
}
////////////////////////////////////////////////////////////////////////

/* problemas de baja precedencia
Pds::Matrix Pds::Matrix::operator^(const Pds::Matrix &B) const
{
    return this->Pow(B);
}
*/
Pds::Matrix Pds::Matrix::Pow(const Pds::Matrix &B) const
{
    if( this->IsNotSimilarTo(B) )    return Pds::Matrix();
    
    Pds::Matrix Ans(B.Size());
    
    unsigned int lin,col;
   
    for(lin=0;lin<B.nlin;lin++)
    for(col=0;col<B.ncol;col++)
    {       
        Ans.array[lin][col]=pow(this->array[lin][col],B.array[lin][col]);
    }

    return Ans;
}

/* problemas de baja precedencia
Pds::Matrix Pds::Matrix::operator^(double val) const
{
    return this->Pow(val);
}
*/

Pds::Matrix Pds::Matrix::Pow(double val) const
{
    if( this->IsEmpty() )    return Pds::Matrix();
    
    Pds::Matrix Ans(this->Size());
    
    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {       
        Ans.array[lin][col]=pow(this->array[lin][col],val);
    }

    return Ans;
}
////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::operator&(const Pds::Matrix &B) const
{
    return this->Product(B);
}

Pds::Matrix Pds::Matrix::Product(const Pds::Matrix &B) const
{
    if( this->IsNotSimilarTo(B) )    return Pds::Matrix();
    
    Pds::Matrix Ans(B.Size());
    
    unsigned int lin,col;
   
    for(lin=0;lin<B.nlin;lin++)
    for(col=0;col<B.ncol;col++)
    {       
        Ans.array[lin][col]=(this->array[lin][col])*B.array[lin][col];
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::Geq(Pds::Matrix B) const
{
    if( this->IsEmpty() )           return Pds::Matrix();
    if( B.IsEmpty() )               return Pds::Matrix();
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=( this->array[lin][col] >= B.array[lin][col] );
    }

    return Ans;
}

Pds::Matrix Pds::Matrix::Geq(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=(this->array[lin][col]>=b);
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::Leq(const Pds::Matrix &B) const
{
    if( this->IsEmpty() )           return Pds::Matrix();
    if( B.IsEmpty() )               return Pds::Matrix();
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=( this->array[lin][col] <= B.array[lin][col] );
    }

    return Ans;
}

Pds::Matrix Pds::Matrix::Leq(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=(this->array[lin][col]<=b);
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::EqualTo(const Pds::Matrix &B) const
{
    if( this->IsEmpty() )           return Pds::Matrix();
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=( this->array[lin][col] == B.array[lin][col] );
    }

    return Ans;
}

Pds::Matrix Pds::Matrix::EqualTo(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=(this->array[lin][col]==b);
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::NotEqualTo(const Pds::Matrix &B) const
{
    if( this->IsEmpty() )           return Pds::Matrix();
    if( this->IsNotSimilarTo(B) )   return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=( this->array[lin][col] != B.array[lin][col] );
    }

    return Ans;
}

Pds::Matrix Pds::Matrix::NotEqualTo(double b) const
{
    if( this->IsEmpty() )                return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=(this->array[lin][col]!=b);
    }

    return Ans;
}


////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::EqualToInf(void) const
{
    Pds::Matrix A(this->nlin,this->ncol);
    
    if(A.IsEmpty())      return A;
    if(this->IsEmpty())  return A;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    A.array[lin][col]=std::isinf(this->array[lin][col]);
    
    return A;
}


Pds::Matrix Pds::Matrix::EqualToNan(void) const
{
    Pds::Matrix A(this->nlin,this->ncol);
    
    if(A.IsEmpty())      return A;
    if(this->IsEmpty())  return A;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    A.array[lin][col]=std::isnan(this->array[lin][col]);
    
    return A;
}


Pds::Matrix Pds::Matrix::EqualToFinite(void) const
{
    Pds::Matrix A(this->nlin,this->ncol);
    
    if(A.IsEmpty())      return A;
    if(this->IsEmpty())  return A;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    A.array[lin][col]=std::isfinite(this->array[lin][col]);
    
    return A;
}

