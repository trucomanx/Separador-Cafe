/*
 * Array.cpp
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


#include <Pds/Array>
#include <iostream>


// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
Pds::Array<Datum>::Array(void)
{
    this->array=NULL;
    this->nlin=0;
    this->ncol=0;
}

template <class Datum>
void MyArrayRelease(Datum** &array,unsigned int Nlin)
{
    if(array!=NULL)
    {
        for (unsigned int j = 0; j < Nlin; j++)
        { 
            delete [] array[j];
            array[j]=NULL;
        }
        delete [] array;
        array=NULL;
    }
}


template <class Datum>
Pds::Array<Datum>::Array(unsigned int Nlin,unsigned int Ncol)
{
    unsigned int lin,col;

    this->array=NULL;
    this->nlin=0;
    this->ncol=0;
    
    if((Nlin==0)||(Ncol==0))    return;

    this->array= new Datum*[Nlin];
    if(this->array==NULL) return;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        this->array[lin] = new Datum[Ncol];
        if(this->array[lin]==NULL)
        {
            MyArrayRelease(this->array,lin);
            this->array=NULL;
            return;
        }
        for (col = 0; col < Ncol; col++) this->array[lin][col]=0;
    }

    this->nlin=Nlin;
    this->ncol=Ncol;
    
    return;
}

template <class Datum>
Pds::Array<Datum>::Array(unsigned int Nlin,unsigned int Ncol,Datum val)
{
    unsigned int lin,col;

    this->array=NULL;
    this->nlin=0;
    this->ncol=0;
    
    if((Nlin==0)||(Ncol==0))    return;

    this->array= new Datum*[Nlin];
    if(this->array==NULL) return;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        this->array[lin] = new Datum[Ncol];
        if(this->array[lin]==NULL)
        {
            MyArrayRelease(this->array,lin);
            this->array=NULL;
            return;
        }
        for (col = 0; col < Ncol; col++) this->array[lin][col]=val;
    }

    this->nlin=Nlin;
    this->ncol=Ncol;
    
    return;
}

template <class Datum>
Pds::Array<Datum>::Array(const Pds::Size &S)
{
    unsigned int lin,col;

    this->array=NULL;
    this->nlin=0;
    this->ncol=0;

    unsigned int Nlin=S.nlin;
    unsigned int Ncol=S.ncol;
    
    if((Nlin==0)||(Ncol==0))    return;

    this->array= new Datum*[Nlin];
    if(this->array==NULL) return;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        this->array[lin] = new Datum[Ncol];
        if(this->array[lin]==NULL)
        {
            MyArrayRelease(this->array,lin);
            this->array=NULL;
            return;
        }
        for (col = 0; col < Ncol; col++) this->array[lin][col]=0;
    }

    this->nlin=Nlin;
    this->ncol=Ncol;
    
    return;
}



template <class Datum>
Pds::Array<Datum>::Array(const Pds::Array<Datum> &A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        unsigned int lin,col;

        this->array=NULL;
        this->nlin=0;
        this->ncol=0;
        
        if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return;

        this->array= new Datum*[A.nlin];
        if(this->array==NULL) return;
        
        
        for (lin = 0; lin < A.nlin; lin++)
        {
            this->array[lin] = new Datum[A.ncol];
            if(this->array[lin]==NULL)
            {
                MyArrayRelease(this->array,lin);
                this->array=NULL;
                return;
            }
            for (col = 0; col < A.ncol; col++) this->array[lin][col]=A.array[lin][col];
        }

        this->nlin=A.nlin;
        this->ncol=A.ncol;

        //this->Print("testeo\n");
        //std::cout<<"A.nlin:"<<this->nlin<<std::endl;
        //std::cout<<"A.ncol:"<<this->ncol<<std::endl;
    }
}


template <class Datum>
Pds::Array<Datum>::~Array(void)
{
    MyArrayRelease(this->array,this->nlin);
    this->array=NULL;
    this->nlin=0;
    this->ncol=0;
    
}


template <class Datum>
Pds::Array<Datum>& Pds::Array<Datum>::operator = (const Pds::Array<Datum> &A)
{
    if(false==this->Copy(A))
        this->MakeEmpty();

    //std::cout<<"used copy assignment\n";
    return *this;
}

template <class Datum>
bool Pds::Array<Datum>::Copy(const Pds::Array<Datum> &A)
{
   
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        unsigned int lin,col;


        
        Datum **tmparray=NULL;

        if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return false;

        tmparray= new Datum*[A.nlin];
        if(tmparray==NULL) return false;
        
        
        for (lin = 0; lin < A.nlin; lin++)
        {
            tmparray[lin] = new Datum[A.ncol];
            if(tmparray[lin]==NULL)
            {
                MyArrayRelease(tmparray,lin);
                tmparray=NULL;
                return false;
            }
            for (col = 0; col < A.ncol; col++) tmparray[lin][col]=A.array[lin][col];
        }

        MyArrayRelease(this->array,A.nlin);
        this->array=tmparray;
        this->nlin=A.nlin;
        this->ncol=A.ncol;
    }
    return true;
}

