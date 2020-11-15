/*
 * Size.cpp
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


#include <Pds/Size>
#include <Pds/Matrix>


Pds::Size::Size(void)
{
    this->nlin=0;
    this->ncol=0;
    return;
}

Pds::Size::Size(unsigned int Nlin,unsigned int Ncol)
{
    this->nlin=Nlin;
    this->ncol=Ncol;
    return;
}

Pds::Size::Size(const Size &A)
{
    if(this!=&A) //Comprueba que no se esté intentando igualar un objeto a sí mismo
    {
        this->nlin=A.nlin;
        this->ncol=A.ncol;
    }

    return;
}


Pds::Size::~Size(void)
{
    this->nlin=0;
    this->ncol=0;
}

#include <iostream>
#include <string>

void Pds::Size::Print(std::string str)
{
    std::cout<<str<<this->nlin<<"\t"<<this->ncol<<std::endl;
    return;
}

void Pds::Size::PrintStylized(std::string str)
{
    std::cout<<str<<"["<<this->nlin<<","<<this->ncol<<"]"<<std::endl;
    return;
}
