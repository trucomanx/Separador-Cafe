
/*
 * Array_getset.cpp
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



// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
unsigned int Pds::Array<Datum>::Nlin(void) const
{
    return this->nlin;
}

template <class Datum>
unsigned int Pds::Array<Datum>::Ncol(void) const
{
    return this->ncol;
}

template <class Datum>
unsigned int Pds::Array<Datum>::Nel(void) const
{
    return this->ncol*this->nlin;
}

template <class Datum>
Pds::Size Pds::Array<Datum>::Size(void) const
{
    return Pds::Size(this->nlin,this->ncol);
}

template <class Datum>
Datum Pds::Array<Datum>::Get(unsigned int lin,unsigned int col) const
{
    if(lin>=this->nlin) return 0;
    if(col>=this->ncol) return 0;
    
    return this->array[lin][col];
}

template <class Datum>
bool Pds::Array<Datum>::Set(unsigned int lin,unsigned int col,Datum val)
{
    if(lin>=this->nlin) return false;
    if(col>=this->ncol) return false;
    
    this->array[lin][col]=val;
    return true;
}


template <class Datum>
Datum &Pds::Array<Datum>::At(unsigned int lin,unsigned int col)
{
    lin=lin%(this->nlin);
    col=col%(this->ncol);
    
    return this->array[lin][col];
}

template <class Datum>
Datum &Pds::Array<Datum>::At(unsigned int id)
{
    id=id%((this->nlin)*(this->ncol));
   
    return this->array[id%this->nlin][id/this->nlin];
}
