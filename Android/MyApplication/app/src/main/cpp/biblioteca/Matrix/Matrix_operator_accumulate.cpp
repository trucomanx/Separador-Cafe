/*
 * Matrix_operator_acumulate.cpp
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
Pds::Matrix& Pds::Matrix::operator = (double val)
{
    if(false==this->Copy(val))
        this->MakeEmpty();

    //std::cout<<"used copy assignment\n";
    return *this;
}

bool Pds::Matrix::Copy(double val)
{
    double **newarray=NULL;

    newarray= Pds::Matrix::ArrayAllocate(1,1);
    if(newarray==NULL) 
    {
        return false;
    }

    newarray[0][0]=val;

    Pds::Matrix::ArrayRelease(this->array,this->nlin);
    this->nlin=1;
    this->ncol=1;
    this->array=newarray;

    return true;
}

Pds::Matrix& Pds::Matrix::operator = (const Pds::Matrix &A)
{
    if(false==this->Copy(A))
        this->MakeEmpty();

    //std::cout<<"used copy assignment\n";
    return *this;
}

bool Pds::Matrix::Copy(const Pds::Matrix &A)
{
    unsigned int lin,col;
    double **newarray=NULL;
    
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {

        if(A.IsEmpty())
        {
            this->MakeEmpty();
            return true;
        }

        newarray= Pds::Matrix::ArrayAllocate(A.nlin,A.ncol);
        if(newarray==NULL) 
        {
            return false;
        }

        for (lin = 0; lin < A.nlin; lin++)
        for (col = 0; col < A.ncol; col++)
        {
                newarray[lin][col]=A.array[lin][col];
        }

        Pds::Matrix::ArrayRelease(this->array,this->nlin);
        this->nlin=A.nlin;
        this->ncol=A.ncol;
        this->array=newarray;
        
    }
    return true;
}
////////////////////////////////////////////////////////////////////////
Pds::Matrix& Pds::Matrix::operator *=(double b)
{
    if(false==this->MulAssig(b))
        this->MakeEmpty();
    
    return *this;
}

bool Pds::Matrix::MulAssig(double b)
{
    if( this->IsEmpty() )   return false;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]*b;
    }

    return true;
}

Pds::Matrix& Pds::Matrix::operator *=(const Pds::Matrix &B)
{
    if(false==this->MulAssig(B))
        this->MakeEmpty();
    
    return *this;
}

bool Pds::Matrix::MulAssig(const Pds::Matrix &B)
{
    if( B.IsEmpty() )           return false;
    if( this->IsNotMulBy(B) )   return false;

    unsigned int lin,col,id;
    
    unsigned int Nlin=this->nlin;
    unsigned int Ncol=B.ncol;
    double S;
    
    double **arr=Pds::Matrix::ArrayAllocate(Nlin,Ncol);
    if( arr==NULL )             return false;
    
    for(lin=0;lin<Nlin;lin++)
    for(col=0;col<Ncol;col++)
    {
        S=0.0;
        for(id=0;id<this->ncol;id++)
        S=S+this->array[lin][id]*B.array[id][col];
        
        arr[lin][col]=S;
    }
    
    Pds::Matrix::ArrayRelease(this->array,this->nlin);
    
    this->nlin=Nlin;
    this->ncol=Ncol;
    this->array=arr;
    
    return true;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix& Pds::Matrix::operator -=(double b)
{
    if(false==this->SubAssig(b))
        this->MakeEmpty();
    
    return *this;
}

bool Pds::Matrix::SubAssig(double b)
{
    if( this->IsEmpty() )   return false;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]-b;  
    }

    return true;
}

Pds::Matrix& Pds::Matrix::operator -=(const Pds::Matrix &B)
{
    if(false==this->SubAssig(B))
        this->MakeEmpty();
    
    return *this;
}

bool Pds::Matrix::SubAssig(const Pds::Matrix &B)
{
    if( this->IsNotSimilarTo(B) )   return false;
    if( B.IsEmpty() )                return true;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]-B.array[lin][col];  
    }

    return true;
}
////////////////////////////////////////////////////////////////////////
Pds::Matrix& Pds::Matrix::operator +=(double b)
{
    if(false==this->AddAssig(b))
        this->MakeEmpty();
    
    return *this;
}

bool Pds::Matrix::AddAssig(double b)
{
    if( this->IsEmpty() )   return false;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]+b;
    }

    return true;
}

Pds::Matrix& Pds::Matrix::operator +=(const Pds::Matrix &B)
{
    if(false==this->AddAssig(B))
        this->MakeEmpty();
    
    return *this;
}

bool Pds::Matrix::AddAssig(const Pds::Matrix &B)
{
    if( this->IsNotSimilarTo(B) )   return false;
    if( B.IsEmpty() )                return true;

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=this->array[lin][col]+B.array[lin][col];  
    }

    return true;
}
////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::AddAssigAt(unsigned int l0,unsigned int c0,const Pds::Matrix &B)
{
    if( B.IsEmpty() )       return false;
    if( this->IsEmpty() )   return false;

    if(l0>=this->Nlin())    return false;
    if(c0>=this->Ncol())    return false;

    unsigned int lin;
    unsigned int col;
    unsigned int lin_end;
    unsigned int col_end;
    
    lin_end=this->Nlin()-l0;
    if(lin_end>B.Nlin()) lin_end=B.Nlin();
    
    col_end=this->Ncol()-c0;
    if(col_end>B.Ncol()) col_end=B.Ncol();
    
    for(lin=0;lin<lin_end;lin++)
    for(col=0;col<col_end;col++)
    {
        this->array[lin+l0][col+c0]=this->array[lin+l0][col+c0]+B.array[lin][col];  
    }

    return true;
}
////////////////////////////////////////////////////////////////////////
