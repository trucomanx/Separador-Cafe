/*
 * FuncMatrixRotation.cpp
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
#include <Pds/FuncMatrixRotation>

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Rot2D(double RadAngle)
{
    Pds::Matrix A(2,2);
    A.Set(0,0,+cos(RadAngle)); A.Set(0,1,-sin(RadAngle));
    A.Set(1,0,+sin(RadAngle)); A.Set(1,1,+cos(RadAngle));
    return A;
}

Pds::Matrix Pds::RotX(double RadAngle)
{
    Pds::Matrix A(3,3);
    A.Set(0,0,1.0);A.Set(0,1,0.0           ); A.Set(0,2,0.0           );
    A.Set(1,0,0.0);A.Set(1,1,+cos(RadAngle)); A.Set(1,2,-sin(RadAngle));
    A.Set(2,0,0.0);A.Set(2,1,+sin(RadAngle)); A.Set(2,2,+cos(RadAngle));
    return A;
}

Pds::Matrix Pds::RotY(double RadAngle)
{
    Pds::Matrix A(3,3);
    A.Set(0,0,+cos(RadAngle));A.Set(0,1,0.0); A.Set(0,2,+sin(RadAngle));
    A.Set(1,0,0.0           );A.Set(1,1,1.0); A.Set(1,2,0.0           );
    A.Set(2,0,-sin(RadAngle));A.Set(2,1,0.0); A.Set(2,2,+cos(RadAngle));
    return A;
}

Pds::Matrix Pds::RotZ(double RadAngle)
{
    Pds::Matrix A(3,3);
    A.Set(0,0,+cos(RadAngle));A.Set(0,1,-sin(RadAngle)); A.Set(0,2,0.0);
    A.Set(1,0,+sin(RadAngle));A.Set(1,1,+cos(RadAngle)); A.Set(1,2,0.0);
    A.Set(2,0,0.0           );A.Set(2,1,0.0           ); A.Set(2,2,1.0);
    return A;
}
