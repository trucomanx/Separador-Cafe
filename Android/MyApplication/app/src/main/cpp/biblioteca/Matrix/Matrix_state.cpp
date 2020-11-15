/*
 * Matrix_state.cpp
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


bool Pds::Matrix::IsEmpty(void) const
{
    if((this->nlin)==0)    return true;
    if((this->ncol)==0)    return true;
    if((this->array)==NULL)    return true;

    return false;
}

bool Pds::Matrix::IsNotEmpty(void) const
{
    if((this->nlin)==0)    return false;
    if((this->ncol)==0)    return false;
    if((this->array)==NULL)    return false;

    return true;
}


bool Pds::Matrix::IsSimilarTo(const Pds::Matrix &B) const
{
    if((this->nlin)!=B.nlin)    return false;
    if((this->ncol)!=B.ncol)    return false;
    
    if( ((this->array)==NULL)&&(B.array==NULL) )    return true;
    if( ((this->array)!=NULL)&&(B.array==NULL) )    return false;
    if( ((this->array)==NULL)&&(B.array!=NULL) )    return false;
    
    return true;
}
bool Pds::Matrix::IsNotSimilarTo(const Pds::Matrix &B) const
{
    if((this->nlin)!=B.nlin)    return true;
    if((this->ncol)!=B.ncol)    return true;
    
    if( ((this->array)==NULL)&&(B.array==NULL) )    return false;
    if( ((this->array)!=NULL)&&(B.array==NULL) )    return true;
    if( ((this->array)==NULL)&&(B.array!=NULL) )    return true;
 
    return false;
}

bool Pds::Matrix::IsMulBy(const Pds::Matrix &B) const
{
    if(this->IsEmpty())  return false;
    if(B.IsEmpty())      return false;
    
    if((this->ncol)!=B.nlin)    return false;
    
    return true;
}

bool Pds::Matrix::IsNotMulBy(const Pds::Matrix &B) const
{
    if(this->IsEmpty())  return true;
    if(B.IsEmpty())      return true;
    
    if((this->ncol)!=B.nlin)    return true;
    
    return false;
}


bool Pds::Matrix::IsInSizeRange(double lin,double col) const
{
    if(this->IsEmpty())      return false;
    if(col<0)               return false;    
    if(lin<0)               return false;
    if(col>(this->ncol-1))  return false;    
    if(lin>(this->nlin-1))  return false;
    
    return true;
}


bool Pds::Matrix::IsInRange(unsigned int lin,unsigned int col) const
{
    if(this->IsEmpty())  return false;
    if(col>=this->ncol) return false;    
    if(lin>=this->nlin) return false;
    
    return true;
}

bool Pds::Matrix::IsNotInRange(unsigned int lin,unsigned int col) const
{
    if(this->IsEmpty())  return true;
    if(col>=this->ncol) return true;    
    if(lin>=this->nlin) return true;
    
    return false;
}

bool Pds::Matrix::IsZero(void) const
{
    if(this->IsEmpty()) return false;
    
    for(unsigned int lin=0;lin<this->nlin;lin++)
    for(unsigned int col=0;col<this->ncol;col++)
    if(this->array[lin][col]!=0.0)  return false;
    
    return true;
}

bool Pds::Matrix::IsColMatrix(void) const
{
    if(this->IsEmpty()) return false;
    if(this->ncol==1) return true;
    return false;
}


bool Pds::Matrix::IsRowMatrix(void) const
{
    if(this->IsEmpty()) return false;
    if(this->nlin==1) return true;
    return false;
}

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::IsLeq(double val) const
{
    if(this->IsEmpty())  return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]>val)
    return false;
    
    return true;
}

bool Pds::Matrix::IsLeq(const Pds::Matrix &B) const
{
    if(this->IsEmpty())         return false;
    if(this->IsNotSimilarTo(B)) return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]>B.array[lin][col])
    return false;
    
    return true;
}

bool Pds::Matrix::IsGeq(double val) const
{
    if(this->IsEmpty())  return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]<val)
    return false;
    
    return true;
}

bool Pds::Matrix::IsGeq(const Pds::Matrix &B) const
{
    if(this->IsEmpty())         return false;
    if(this->IsNotSimilarTo(B)) return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]<B.array[lin][col])
    return false;
    
    return true;
}

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::IsEqualTo(double val) const
{
    if(this->IsEmpty())  return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]!=val)
    return false;
    
    return true;
}

bool Pds::Matrix::IsEqualTo(const Pds::Matrix &B) const
{
    if(this->IsEmpty())         return false;
    if(this->IsNotSimilarTo(B)) return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]!=B.array[lin][col])
    return false;
    
    return true;
}

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::HasNan(void) const
{
    if(this->IsEmpty())  return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(std::isnan(this->array[lin][col]))
    return true;
    
    return false;
}

bool Pds::Matrix::HasInf(void) const
{
    if(this->IsEmpty())  return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(std::isinf(this->array[lin][col]))
    return true;
    
    return false;
}

bool Pds::Matrix::HasNotFinite(void) const
{
    if(this->IsEmpty())  return false;
    
    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(!std::isfinite(this->array[lin][col]))
    return true;
    
    return false;
}


