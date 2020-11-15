/*
 * RegionRect_state.cpp
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
#include <Pds/Matrix>

bool Pds::RegionRect::IsEmpty(void) const
{
    if((this->Nlin==0)||(this->Ncol==0)) return true;

    return false;
}

bool Pds::RegionRect::IsInside(const Pds::RegionRect &R) const
{
    if(this->L0<R.L0) return false;
    if(this->C0<R.C0) return false;

    if( (this->L0+this->Nlin)>(R.L0+R.Nlin) ) return false;
    if( (this->C0+this->Ncol)>(R.C0+R.Ncol) ) return false;

    return true;
}

bool Pds::RegionRect::IsInside(const Pds::Matrix &A) const
{
    if(A.IsEmpty()) return false;
    if(this->L0<0)  return false;
    if(this->C0<0)  return false;

    if( (this->L0+this->Nlin)>A.Nlin() ) return false;
    if( (this->C0+this->Ncol)>A.Ncol() ) return false;

    return true;
}

