/*
 * RegionRect_save_load.cpp
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

#include <cstdlib>
#include <cstdio>
#include <Pds/RaString>
#include <Pds/RaFile>
#include <Pds/RegionRect>


int Pds::RegionRect::FilePrint(FILE *fd) const
{
    return fprintf(fd,"%d\t%d\t%d\t%d\n",this->L0,this->C0,this->Nlin,this->Ncol);
}

bool Pds::RegionRect::FileScan(FILE *fd)
{
    char* data=NULL;
    fpos_t init;
    int id;
    
    if(fd==NULL)    return false;

    // init tiene la posicion actual.
    fgetpos(fd,&init);

    while(feof(fd)==0)
    {
        data=Pds::Ra::Fgets(fd);
        
        if(Pds::Ra::IsSpacesString(data)==false)
        {
            id=this->LoadString(data);

            free(data);	
            if(id==true)  return true;
            else
            {
                fsetpos(fd,&init);
                return false;
            }
        }
        free(data);
    }

    // reinicio el descriptor
    fsetpos(fd,&init);
    return false;
}


bool Pds::RegionRect::LoadString(const std::string &stdstr)
{
    const char *data=stdstr.c_str();
    if(data==NULL) return false;

    int N=Pds::Ra::ElementsInString(data); 
    if(N!=4)
    {
        fprintf(stderr,"ERROR: Reading the string: %s",data);
        fprintf(stderr,"ERROR: They was found only %d of 4 elements.",N);
        fprintf(stderr,"\n");	
        return false;
    }

    Pds::RegionRect T;
    char *initptr=(char*)data;
    char *endptr;
    long number;
    unsigned long numberu;


    number = strtol(initptr, &endptr,10);
    if(initptr==endptr)
    {
        fprintf(stderr,"ERROR: Reading the first element of string: %s",data);
        fprintf(stderr,"ERROR: The number is not a long number.");
        fprintf(stderr,"\n");
        return false;
    }
    T.L0=number;
    initptr=endptr;

    number = strtol(initptr, &endptr,10);
    if(initptr==endptr)
    {
        fprintf(stderr,"ERROR: Reading the second element of string: %s",data);
        fprintf(stderr,"ERROR: The number is not a long number.");
        fprintf(stderr,"\n");
        return false;
    }
    T.C0=number;  
    initptr=endptr;

    numberu= strtoul(initptr, &endptr,10);
    if(initptr==endptr)
    {
        fprintf(stderr,"ERROR: Reading the third element of string: %s",data);
        fprintf(stderr,"ERROR: The number is not an unsigned long number.");
        fprintf(stderr,"\n");
        return false;
    }
    T.Nlin=numberu;
    initptr=endptr;

    numberu= strtoul(initptr, &endptr,10);
    if(initptr==endptr)
    {
        fprintf(stderr,"ERROR: Reading the fourth element of string: %s",data);
        fprintf(stderr,"ERROR: The number is not an unsigned long number.");
        fprintf(stderr,"\n");
        return false;
    }
    T.Ncol=numberu;  
    initptr=endptr;

    (*this)=T;
    return true;
}
