/*
 * FuncVector.cpp
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

#include <Pds/Vector>
#include <Pds/FuncVector>

Pds::Vector Pds::LinSpace(double start,double end,unsigned int N)
{
    Pds::Vector V(N);
    unsigned int id;
    double factor=(end-start)/(N-1.0);
    
    V.Set(0,start);
    V.Set(N-1,end);
    
    if(N>2)
    for(id=1;id<(N-1);id++)
    V.Set(id,start+factor*id);
    
    return V;
}

Pds::Vector Pds::GeomSpace(double start,double end,unsigned int N)
{
    if((start==0)||(start*end<0))
    {
        Pds::Vector V;
        return V;
    }
    
    Pds::Vector V(N);
    unsigned int id;
    double factor=pow(end/start,1.0/(N-1.0));
    
    V.Set(0,start);
    V.Set(N-1,end);
    
    if(N>2)
    for(id=1;id<(N-1);id++)
    V.Set(id,start+factor*id);

    return V;
}


////////////////////////////////////////////////////////////////////////

Pds::Vector Pds::X2D(void)
{
    Pds::Vector A(2);
    A.Set(0,1.0);
    return A;
}

Pds::Vector Pds::Y2D(void)
{
    Pds::Vector A(2);
    A.Set(1,1.0);
    return A;
}

////////////////////////////////////////////////////////////////////////

Pds::Vector Pds::X3D(void)
{
    Pds::Vector A(3);
    A.Set(0,1.0);
    return A;
}

Pds::Vector Pds::Y3D(void)
{
    Pds::Vector A(3);
    A.Set(1,1.0);
    return A;
}

Pds::Vector Pds::Z3D(void)
{
    Pds::Vector A(3);
    A.Set(2,1.0);
    return A;
}
