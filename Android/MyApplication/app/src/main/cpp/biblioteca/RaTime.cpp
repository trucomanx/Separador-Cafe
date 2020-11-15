/*
 * RaTime.cpp
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

#include <Pds/RaDefines>
#include <Pds/RaTime>

#include <iostream>


namespace Pds{
namespace Ra{
    clock_t StartTime =0;
}
}

clock_t Pds::Ra::Tic(void)
{
    return Pds::Ra::StartTime = clock();
}

double Pds::Ra::Toc(void)
{
    double T=(clock() - Pds::Ra::StartTime) / (double)CLOCKS_PER_SEC;
    
    std::cout<< "Elapsed time: ";
    if(T>60.0)      std::cout<< T/60.0 << " min";
    else if(T>1.0)  std::cout<< T << " s";
    else            std::cout<< T*1000 << " ms";
    std::cout<< std::endl;
    
    return T;
}


double Pds::Ra::Toc(clock_t start_time)
{
    double T=(clock() - start_time) / (double)CLOCKS_PER_SEC;
    
    std::cout<< "Elapsed time: ";
    if(T>60.0)      std::cout<< T/60.0 << " min";
    else if(T>1.0)  std::cout<< T << " s";
    else            std::cout<< T*1000 << " ms";
    std::cout<< std::endl;
    
    return T;
}
