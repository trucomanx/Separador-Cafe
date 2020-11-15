/*
 * RaTools.cpp
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


#include <Pds/RaTools>
#include <Pds/RaString>
#include <Pds/RaDefines>

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>      // std::ifstream


#ifndef PDS_LIBRARY_VERSION
#define PDS_LIBRARY_VERSION ""
#endif

#ifndef PDS_LIBRARY_PACKAGE
#define PDS_LIBRARY_PACKAGE ""
#endif
////////////////////////////////////////////////////////////////////////////////

std::string Pds::Ra::Version(void)
{
    return PDS_LIBRARY_VERSION;
}

void Pds::Ra::PrintVersion(std::string str)
{
    std::cout<<str<<PDS_LIBRARY_VERSION<<std::endl;
}
////////////////////////////////////////////////////////////////////////////////

std::string Pds::Ra::Package(void)
{
    return PDS_LIBRARY_PACKAGE;
}

void Pds::Ra::PrintPackage(std::string str)
{
    std::cout<<str<<PDS_LIBRARY_PACKAGE<<std::endl;
}

////////////////////////////////////////////////////////////////////////
void Pds::Ra::Randomize(void)
{
    std::srand(std::time(0)+std::clock());
}
////////////////////////////////////////////////////////////////////////////////
bool Pds::Ra::IsBigEndian(void)
{
        short int word = 0x0001;
        char *b = (char *)&word;
        return (b[0] ? false : true);
}
