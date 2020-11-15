/*
 * Matrix_getset_extras.cpp
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

#include <Pds/Matrix>
#include <Pds/Vector>
#include <Pds/Size>

#include <cmath>

Pds::Vector Pds::Matrix::GetDiagonal(void) const
{   
    if(this->IsEmpty()) return Pds::Vector();
    
    unsigned int N=std::min(this->nlin,this->ncol);
    
    double** array=Pds::Matrix::ArrayAllocate(N,1);
    if(array==NULL)     return Pds::Vector();
    
    Pds::Vector C;
    
    for(unsigned int lin=0;lin<N;lin++)
    array[lin][0]=this->array[lin][lin];
    
    C.array=array;
    C.nlin=N;
    C.ncol=1;
    
    return C;
}
    
bool Pds::Matrix::SetDiagonal(const Pds::Vector V)
{   
    if(this->IsEmpty()) return false;
    if(V.IsEmpty())     return false;
    
    unsigned int N=std::min(V.Nlin(),std::min(this->nlin,this->ncol));
    
    for(unsigned int lin=0;lin<N;lin++)
    this->array[lin][lin]=V.Get(lin,0);
    
    return true;
}

////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::GetMatrix(unsigned int lin_init,unsigned int col_init,unsigned int lin_end,unsigned int col_end) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();
    
    if(lin_init >= lin_end) return Pds::Matrix();
    if(col_init >= col_end) return Pds::Matrix();
    
    if(lin_init >= this->nlin) return Pds::Matrix();
    if(col_init >= this->ncol) return Pds::Matrix();
    
    Pds::Matrix A(lin_end-lin_init+1,col_end-col_init+1);
    
    unsigned int Lend=std::min(this->nlin-1,lin_end);
    unsigned int Cend=std::min(this->ncol-1,col_end);
    
    for(unsigned int lin=lin_init;lin<=Lend;lin++)
    for(unsigned int col=col_init;col<=Cend;col++)
    A.array[lin-lin_init][col-col_init]=this->array[lin][col];
    
    return A;
}

Pds::Matrix Pds::Matrix::GetMatrix(unsigned int lin_init,unsigned int col_init,Pds::Size size) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();
    
    if(lin_init >= this->nlin) return Pds::Matrix();
    if(col_init >= this->ncol) return Pds::Matrix();
    
    Pds::Matrix A(size.nlin,size.ncol);
    
    unsigned int Lend=std::min(this->nlin-1,lin_init+size.nlin-1);
    unsigned int Cend=std::min(this->ncol-1,col_init+size.ncol-1);
    
    for(unsigned int lin=lin_init;lin<=Lend;lin++)
    for(unsigned int col=col_init;col<=Cend;col++)
    A.array[lin-lin_init][col-col_init]=this->array[lin][col];
    
    return A;
}


bool Pds::Matrix::SetMatrix(unsigned int lin,unsigned int col,const Pds::Matrix &B)
{
    if(this->IsEmpty()) return false;
    if(B.IsEmpty())     return false;
    
    if( (lin+B.Nlin()) > this->nlin ) return false;
    if( (col+B.Ncol()) > this->ncol ) return false;
    
    for(unsigned int l=0;l<B.Nlin();l++)
    for(unsigned int c=0;c<B.Ncol();c++)
    this->array[lin+l][col+c]=B.Get(l,c);
    
    return true;
}
////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::GetRow(unsigned int lin) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();
    
    if(lin >= this->nlin)  return Pds::Matrix();
    
    Pds::Matrix Ans(1,this->ncol);
    
    for(unsigned int col=0;col<this->ncol;col++)
    Ans.array[0][col]=this->array[lin][col];
    
    return Ans;
}

Pds::Matrix Pds::Matrix::GetCol(unsigned int col) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();
    
    if(col >= this->ncol)  return Pds::Matrix();
    
    Pds::Matrix Ans(this->nlin,1);
    
    for(unsigned int lin=0;lin<this->nlin;lin++)
    Ans.array[lin][0]=this->array[lin][col];
    
    return Ans;
}


////////////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::GetRows(unsigned int lin_init,unsigned int lin_end) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();
    
    if(lin_init >= lin_end)     return Pds::Matrix();
    
    if(lin_init >= this->nlin)  return Pds::Matrix();
    
    Pds::Matrix A(lin_end-lin_init+1,this->ncol);
    
    unsigned int Lend=std::min(this->nlin-1,lin_end);
    unsigned int Cend=this->ncol-1;
    
    for(unsigned int lin=lin_init;lin<=Lend;lin++)
    for(unsigned int col=0       ;col<=Cend;col++)
    A.array[lin-lin_init][col]=this->array[lin][col];
    
    return A;
}

Pds::Matrix Pds::Matrix::GetCols(unsigned int col_init,unsigned int col_end) const
{
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL)) return Pds::Matrix();
    
    if(col_init >= col_end)     return Pds::Matrix();
    
    if(col_init >= this->ncol)  return Pds::Matrix();
    
    Pds::Matrix A(this->nlin,col_end-col_init+1);
    
    unsigned int Cend=std::min(this->ncol-1,col_end);
    unsigned int Lend=this->nlin-1;
    
    for(unsigned int lin=0       ;lin<=Lend;lin++)
    for(unsigned int col=col_init;col<=Cend;col++)
    A.array[lin][col-col_init]=this->array[lin][col];
    
    return A;
}

Pds::Matrix Pds::Matrix::GetRows(std::list<unsigned int> List) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();

    // verifica si la lista de indices existe en la matriz
    for (auto pdat = List.begin(); pdat != List.end(); pdat++) 
    {
        if( (*pdat)>=this->nlin )   return Pds::Matrix();
    }
    
    Pds::Matrix A(List.size(),this->ncol);
    
    unsigned int lin=0;
    
    for (auto pdat = List.begin(); pdat != List.end(); pdat++) 
    {
        for(unsigned int col=0;col<this->ncol;col++)
        A.array[lin][col]=this->array[*pdat][col];

        lin++;

    }
    
    return A;
}

Pds::Matrix Pds::Matrix::GetCols(std::list<unsigned int> List) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();

    // verifica si la lista de indices existe en la matriz
    for (auto pdat = List.begin(); pdat != List.end(); pdat++) 
    {
        if( (*pdat)>=this->ncol )   return Pds::Matrix();
    }
    
    Pds::Matrix A(this->nlin,List.size());
    
    unsigned int col=0;
    
    for (auto pdat = List.begin(); pdat != List.end(); pdat++) 
    {
        for(unsigned int lin=0;lin<this->nlin;lin++)
        A.array[lin][col]=this->array[lin][*pdat];

        col++;
    }
    
    return A;
}


#include <set>
Pds::Matrix Pds::Matrix::GetRowsRand(unsigned int N) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();
    
    unsigned int L=this->nlin;

    if(N==0)    return Pds::Matrix();
    if(N>L)     return Pds::Matrix();
     
    Pds::Matrix A(N,this->ncol);

    unsigned int id;
    std::set<unsigned int> SetId; 

    for(unsigned int lin=0;lin<N;lin++)
    {   
        do{
            id=rand()%L;
        }while(SetId.count(id)!=0); 
        SetId.insert(id);

        for(unsigned int col=0;col<this->ncol;col++)
        {
            A.array[lin][col]=this->array[id][col];
        }
    }
    return A;
}

Pds::Matrix Pds::Matrix::GetColsRand(unsigned int N) const
{
    if((this->ncol==0)||(this->nlin==0)||(this->array==NULL)) return Pds::Matrix();
    
    unsigned int L=this->ncol;

    if(N==0)    return Pds::Matrix();
    if(N>L)     return Pds::Matrix();
     
    Pds::Matrix A(this->nlin,N);

    unsigned int id;
    std::set<unsigned int> SetId; 

    for(unsigned int col=0;col<N;col++)
    {   
        do{
            id=rand()%L;
        }while(SetId.count(id)!=0); 
        SetId.insert(id);

        for(unsigned int lin=0;lin<this->nlin;lin++)
        {
            A.array[lin][col]=this->array[lin][id];
        }
    }
    return A;
}

////////////////////////////////////////////////////////////////////////////////


bool Pds::Matrix::SetRowValue(unsigned int lin,double value)
{   
    if(lin>=this->nlin) return false;
    
    if(this->IsEmpty()) return false;
    
    for(unsigned int col=0;col<this->ncol;col++)
    this->array[lin][col]=value;
    
    return true;
}

bool Pds::Matrix::SetColValue(unsigned int col,double value)
{   
    if(col>=this->ncol) return false;
    
    if(this->IsEmpty()) return false;
    
    for(unsigned int lin=0;lin<this->nlin;lin++)
    this->array[lin][col]=value;
    
    return true;
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

Pds::Vector Pds::Matrix::GetColVector(unsigned int col) const
{   
    if(col>=this->ncol) return Pds::Vector();
    
    double** array=Pds::Matrix::ArrayAllocate(this->nlin,1);
    if(array==NULL)     return Pds::Vector();
    
    Pds::Vector C;
    
    for(unsigned int lin=0;lin<this->nlin;lin++)
    array[lin][0]=this->array[lin][col];
    
    C.array=array;
    C.nlin=this->nlin;
    C.ncol=1;
    return C;
}
    

    
bool Pds::Matrix::SetColVector(unsigned int col,const Pds::Vector V)
{   
    if(col>=this->ncol) return false;
    
    if(this->IsEmpty()) return false;
    if(V.IsEmpty())     return false;
    
    unsigned int Nlin=std::min(V.Nlin(),this->nlin);
    
    for(unsigned int lin=0;lin<Nlin;lin++)
    this->array[lin][col]=V.Get(lin);
    
    return true;
}
    
bool Pds::Matrix::SetColVector(unsigned int col,double (*func)(double),const Pds::Vector V)
{   
    if(col>=this->ncol) return false;
    
    if(this->IsEmpty()) return false;
    if(V.IsEmpty())     return false;
    
    unsigned int Nlin=std::min(V.Nlin(),this->nlin);
    
    for(unsigned int lin=0;lin<Nlin;lin++)
    this->array[lin][col]=(*func)(V.Get(lin));
    
    return true;
}
    
bool Pds::Matrix::SetColVector(unsigned int col,double (*func)(double,double),const Pds::Vector V,double var)
{   
    if(col>=this->ncol) return false;
    
    if(this->IsEmpty()) return false;
    if(V.IsEmpty())     return false;
    
    unsigned int Nlin=std::min(V.Nlin(),this->nlin);
    
    for(unsigned int lin=0;lin<Nlin;lin++)
    this->array[lin][col]=(*func)(V.Get(lin),var);
    
    return true;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

Pds::Vector Pds::Matrix::GetRowAsColVector(unsigned int lin) const
{   
    if(lin>=this->nlin) return Pds::Vector();
    
    double** array=Pds::Matrix::ArrayAllocate(this->ncol,1);
    if(array==NULL)     return Pds::Vector();
    
    Pds::Vector C;
    
    for(unsigned int id=0;id<this->ncol;id++)
    array[id][0]=this->array[lin][id];
    
    C.array=array;
    C.nlin=this->ncol;
    C.ncol=1;
    return C;
}
    
