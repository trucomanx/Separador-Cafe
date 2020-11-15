/*
 * RegionRect_varied.cpp
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


#include <Pds/RegionRect>

#include <iostream>
#include <string>

void Pds::RegionRect::Print(std::string str) const
{
    std::cout<<str<<this->L0<<"\t"<<this->C0<<"\t"<<this->Nlin<<"\t"<<this->Ncol<<std::endl;
    return;
}

void Pds::RegionRect::PrintStylized(std::string str) const
{
    std::cout<<str<<"("<<this->L0<<","<<this->C0<<")"<<"["<<this->Nlin<<","<<this->Ncol<<"]"<<std::endl;
    return;
}

void Pds::RegionRect::MakeEmpty(void)
{
    this->L0=0;
    this->C0=0;
    this->Nlin=0;
    this->Ncol=0;
}
