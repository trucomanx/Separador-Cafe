/*
 * Vector_operator_binario.cpp
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



#include <Pds/Vector>


////////////////////////////////////////////////////////////////////////

Pds::Vector Pds::Vector::Conv(const Pds::Vector &B, bool Same) const
{
    if(this->IsEmpty()) return Pds::Vector();
    if(B.IsEmpty())     return Pds::Vector();
    
    unsigned int id,k;
    double S;
    unsigned int init,end;
    
    unsigned int id_init=0;
    unsigned int id_end=this->nlin-2+B.nlin;
    unsigned int N=this->nlin-1+B.nlin;
    if(Same==true)
    {
        id_init=B.nlin/2;
        id_end =this->nlin-1+B.nlin/2;
        N      =this->nlin;
    }

    
    Pds::Vector D(N);
    
    for(id=id_init;id<=id_end;id++)
    {
        S=0.0;
        init = ((id+1)>    B.nlin) ? id-B.nlin+1 : 0;
        end  = ((id+1)<this->nlin) ? id          : this->nlin-1;
        
        for(k=init;k<=end;k++)
        S=S+this->array[k][0]*B.array[id-k][0];
        
        D.array[id-id_init][0]=S;
    }

    return D;
}
////////////////////////////////////////////////////////////////////////
#include <iostream>

Pds::Vector Pds::Vector::XCorr(const Pds::Vector &B, bool same) const
{
    if(this->IsEmpty()) return Pds::Vector();
    if(B.IsEmpty())     return Pds::Vector();
    
    int id,k;
    double S;
    int init,end;
    
    int N=this->nlin;
    if(same==false)  N=N+B.nlin-1;
    
    int id_init=0;
    if(same==false)  id_init=1-(int)(B.nlin);
    
    Pds::Vector D(N);
    
    for(id=id_init;id<=((int)(this->nlin)-1);id++)
    {
        S=0.0;
        init =  (0>=id) ? (-id): 0;
        end  = ((B.nlin-1)<=(this->nlin-1-id)) ? (B.nlin-1): (this->nlin-1-id);
        
        for(k=init;k<=(int)end;k++)
        S=S+this->array[id+k][0]*B.array[k][0];
        
        D.array[id-id_init][0]=S;
    }

    return D;
}
