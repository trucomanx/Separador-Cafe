/*
 * RaFile.cpp
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
#include <Pds/RaFile>
#include <Pds/RaDefines>

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>      // std::ifstream

////////////////////////////////////////////////////////////////////////////////

char *Pds::Ra::Fgets(FILE *fd)
{
    char *line=NULL;
    int i;
    fpos_t init;
    int count,N;
    char c;

    if(fd==NULL)    return NULL;

    // init tiene la posicion actual.
    fgetpos(fd,&init);

    // Cuento en count el numero de caracteres incluyendo el salto de linea
    count=0;    c=0;
    while( (c!=10)&&(c!=EOF) )  /* \n */
    {
        c=fgetc(fd);
        if(c!=EOF) count++;
    }

    // cuento 1 retorno de carro si este existe despues del salto de linea.
    if(c!=EOF)
    {
        c=fgetc(fd);
        /* \r */
        if(c==13) count++;
    }

    // reinicio el descriptor
    fsetpos(fd,&init);

    // Numero total de caracteres incluyendo el salto de linea y 1 retorno de 
    // carro posterior si existe.
    N=count;

    // copio N caracteres desde el archivo
    line=(char*)calloc(N+1,sizeof(char));
    if (line==NULL) return NULL;
    for(i=0;i<N;i++)
    {    
        line[i]=fgetc(fd);
    }

    // N entiendo porque funciona, mas funciona.
    if(c==EOF)  
    {
        fseek( fd, 0, SEEK_END );
        fgetc(fd);
    }

    return line;
}

////////////////////////////////////////////////////////////////////////////////

long Pds::Ra::SignificativeLinesInFile(const char*filepath)
{
    long count;
    std::string line;

    if (filepath==NULL)         return -1;
    if (strlen(filepath)==0)    return -1;

    std::ifstream ifs(filepath, std::ifstream::in);	
    if (ifs.is_open()==false)   return -1;

    count=0;
    while(!ifs.eof())
    {
        line.clear();

        if (std::getline(ifs, line))
        if(Pds::Ra::IsSpacesString(line.c_str())==false) count++;
    }

    ifs.close();

	return count;
}


bool Pds::Ra::ElementsInFile(const char* filepath,unsigned int &Nel)
{
    unsigned int count;
    int N;

    std::string line;

    if (filepath==NULL)         return false;
    if (strlen(filepath)==0)    return false;

    std::ifstream ifs(filepath, std::ifstream::in);	
    if (ifs.is_open()==false)   return false;

    count=0;
    while(!ifs.eof())
    {
        line.clear();

        if (std::getline(ifs, line))
        if(Pds::Ra::IsSpacesString(line.c_str())==false)
        {
            N=Pds::Ra::ElementsInString(line);
            count=count+(unsigned int )N;
        }
    }

    ifs.close();

    Nel=count;
    
    return true;
}

bool Pds::Ra::ArraySizeInFile(const char*filepath,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int count;
    int N;
    unsigned int last_ncol=0;

    std::string line;

    if (filepath==NULL)         return false;
    if (strlen(filepath)==0)    return false;

    std::ifstream ifs(filepath, std::ifstream::in);	
    if (ifs.is_open()==false)   return false;

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
                ifs.close();
                return false;
            }            
            count++;
        }
    }

    ifs.close();

    Nlin=count;
    Ncol=last_ncol;

	return true;
}

