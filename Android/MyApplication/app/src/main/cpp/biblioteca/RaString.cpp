/*
 * RaString.cpp
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

#include <Pds/RaString>
#include <Pds/RaDefines>

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>      // std::ifstream


bool Pds::Ra::IsSpacesString(const std::string &stdstr)//(const char *str)
{
    int i;
    const char *str=stdstr.c_str();
    int N=strlen(str);

    for(i=0;i<N;i++)
    {
        if(isspace(str[i])==0)  return  false;
    }

    return true;
}


int Pds::Ra::ElementsInString(const std::string &stdstr)
{

    int N=0;
    int i=0;
    const char *str=stdstr.c_str();
    if(str==NULL)   return -1;

    while(str[i]!=0)
    {
        while((isspace(str[i])!=0)&&(str[i]!=0))   i++;

        if((isspace(str[i])==0)&&(str[i]!=0))
        {
            N++;
            while((isspace(str[i])==0)&&(str[i]!=0))   i++;
        }
    }
    return N;
}

////////////////////////////////////////////////////////////////////////////////

#include <list>
#include <string>
#include <cstring>
#include <cstdlib>

std::list<std::string> Pds::Ra::SplitString(std::string str, std::string delimeters)
{
    std::list<std::string> Element;
    
    char *token=NULL;
    char *cadena=strdup(str.c_str());
    
    if(cadena==NULL)    return Element;
    
    token = strtok(cadena, delimeters.c_str());
    
    while( token != NULL )
    {
        Element.push_back(token);
        token = strtok(NULL, delimeters.c_str());
    }
   
    free(cadena);
    
    return Element;
}

////////////////////////////////////////////////////////////////////////////////

#include <sstream>
#include <iomanip>      // std::setprecision
#include <Pds/RaDefines>
#include <Pds/Matrix>
#include <Pds/Vector>

template std::string Pds::Ra::ToString<int>(int val);
template std::string Pds::Ra::ToString<unsigned int>(unsigned int val);
template std::string Pds::Ra::ToString<long>(long val);
template std::string Pds::Ra::ToString<unsigned long>(unsigned long val);
template std::string Pds::Ra::ToString<double>(double val);
template std::string Pds::Ra::ToString<float>(float val);
template std::string Pds::Ra::ToString<Pds::Matrix>(Pds::Matrix val);
template std::string Pds::Ra::ToString<Pds::Vector>(Pds::Vector val);
template std::string Pds::Ra::ToString<char>(char val);
template std::string Pds::Ra::ToString<const char*>(const char *val);
template std::string Pds::Ra::ToString<char*>(char *val);

template <typename T>
std::string Pds::Ra::ToString(T val)
{
    std::stringstream stream;
    stream <<std::setprecision(Pds::Ra::StringPrecision)<< val;
    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
#include <sstream>

bool Pds::Ra::ArraySizeInString(std::string str,unsigned int &Nlin,unsigned int &Ncol)
{
    std::stringstream ifs(str);
    unsigned int count;
    int N;
    unsigned int last_ncol=0;

    std::string line;
    if (str=="")    return false;

    count=0;
    while(!ifs.eof())
    {
        line.clear();

        if (std::getline(ifs, line))
        if(Pds::Ra::IsSpacesString(line.c_str())==false)
        {
            N=Pds::Ra::ElementsInString(line);
            if(count==0)    last_ncol=(unsigned int)N;
            else if(last_ncol!=(unsigned int)N)
            {
                return false;
            }            
            count++;
        }
    }

    Nlin=count;
    Ncol=last_ncol;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
#include <cstdio>

bool Pds::Ra::SaveString(std::string filepath, std::string str)
{
    FILE *fd=NULL;
    
    fd=fopen(filepath.c_str(),"w");
    if(fd==NULL)    return false;
    
    fprintf(fd,"%s",str.c_str());
    fclose(fd);
    
    return true;
}

