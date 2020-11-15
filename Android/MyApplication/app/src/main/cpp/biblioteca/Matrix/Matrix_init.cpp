/*
 * Matrix_init.cpp
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

#include <cstdlib>
#include <cmath>
#include <Pds/Matrix>

bool Pds::Matrix::FillRandN(void)
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        double cos_2piU=cos(2.0*M_PI*rand()/(RAND_MAX+1.0));
        double sqrt_m2lnV=sqrt(-2.0*log((RAND_MAX+1.0-rand())/(RAND_MAX+1.0)));
        this->array[lin][col]=cos_2piU*sqrt_m2lnV;
    }

    return true;
}

bool Pds::Matrix::FillRandU(void)
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=rand()/(RAND_MAX+1.0);
    }

    return true;
}

bool Pds::Matrix::FillRandC(double p1)
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=rand()<(RAND_MAX*p1);
    }

    return true;
}

bool Pds::Matrix::FillRandU(double begin, double end)
{
    if(this->IsEmpty())   return false;
    
    double min=std::min(begin,end);
    double max=std::max(begin,end);
    double alpha=(max-min)/RAND_MAX;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=rand()*alpha+min;
    }

    return true;
}

bool Pds::Matrix::FillRandU(int begin, int end)
{
    if(this->IsEmpty())   return false;
    
    int min=std::min(begin,end);
    int max=std::max(begin,end);
    double alpha=((double)max-(double)min)/RAND_MAX;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=rand()*alpha+min;
    }

    return true;
}

bool Pds::Matrix::Fill(double val)
{
    if(this->IsEmpty())   return false;

    unsigned int lin,col;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=val;
    }

    return true;
}

bool Pds::Matrix::FillId(void)
{
    if(this->IsEmpty())   return false;

    unsigned int lin,col;
    unsigned int N=0;
    
    for(col=0;col<this->ncol;col++)
    for(lin=0;lin<this->nlin;lin++)
    {
        this->array[lin][col]=N;
        N++;
    }

    return true;
}

bool Pds::Matrix::FillLinSpace(double begin,double end)
{
    if(this->IsEmpty())   return false;

    unsigned int lin,col,id;
    unsigned int N=(this->nlin)*(this->ncol);
    double alpha=(end-begin)/(N-1.0);

    id=0;
    for(col=0;col<this->ncol;col++)
    for(lin=0;lin<this->nlin;lin++)
    {
        this->array[lin][col]=begin+id*alpha;
        id++;
    }
    this->array[this->nlin-1][this->ncol-1]=end;

    return true;
}
