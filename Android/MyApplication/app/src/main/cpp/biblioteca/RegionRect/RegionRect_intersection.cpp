/*
 * RegionRect_intersection.cpp
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

Pds::RegionRect Pds::RegionRect::Intersection(const Pds::RegionRect &B) const
{
    int C0;
    unsigned int Ncol;
    int L0;
    unsigned int Nlin;

    if(this->IsEmpty()) return Pds::RegionRect();
    if(B.IsEmpty())     return Pds::RegionRect();

    if(this->C0<B.C0)
    {
        if( (this->C0+(int)this->Ncol-1)>=B.C0 )
        {
            C0=B.C0;
            if( (this->C0+this->Ncol-1)>(B.C0+B.Ncol-1) )   Ncol=B.Ncol;
            else                                            Ncol=this->C0+this->Ncol-B.C0;
        }
        else
            return Pds::RegionRect();
    }
    else
    {
        if( (B.C0+(int)B.Ncol-1)>=this->C0 )
        {
            C0=this->C0;
            if( (B.C0+B.Ncol-1)>(this->C0+this->Ncol-1) )   Ncol=this->Ncol;
            else                                    Ncol=B.C0+B.Ncol-this->C0;

        }
        else
            return Pds::RegionRect();
    }


    if(this->L0<B.L0)
    {
        if( (this->L0+(int)this->Nlin-1)>=B.L0 )
        {
            L0=B.L0;
            if( (this->L0+this->Nlin-1)>(B.L0+B.Nlin-1) )   Nlin=B.Nlin;
            else                                            Nlin=this->L0+this->Nlin-B.L0;
        }
        else
            return Pds::RegionRect();
    }
    else
    {
        if( (B.L0+(int)B.Nlin-1)>=this->L0 )
        {
            L0=this->L0;
            if( (B.L0+B.Nlin-1)>(this->L0+this->Nlin-1) )   Nlin=this->Nlin;
            else                                            Nlin=B.L0+B.Nlin-this->L0;
        }
        else
            return Pds::RegionRect();
    }

    Pds::RegionRect R(L0,C0,Nlin,Ncol);

    return R;
}

