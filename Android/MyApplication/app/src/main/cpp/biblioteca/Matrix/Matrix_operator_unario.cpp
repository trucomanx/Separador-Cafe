/*
 * Matrix_operator_unario.cpp
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

#include <string>
#include <iostream>

#include <Pds/Matrix>
#include <Pds/FuncMatrix>
#include <Pds/RaDefines>

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::PInv(double *rcond) const
{
    if(rcond!=NULL) *rcond=0;
    
    if( this->IsEmpty() )   return Pds::Matrix();
    
    Pds::Matrix mat=this->MtM().Inv(rcond);
    
    return mat.MulT(*this);
}


////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::Inv(double *rcond) const
{
    unsigned int lin,i,all;
    int id;
    double alpha;

    
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL)||(this->ncol!=this->nlin))
    {
        Pds::Matrix A;
        if(rcond!=NULL) *rcond =0;
        return A;
    }
    
    Pds::Matrix B(*this);
    Pds::Matrix A= Pds::Eye(this->nlin);
    
    // obtengo una matriz escalonada
    for(lin=0;lin<B.nlin;lin++)
    {
        id=B.RowSwapBelow(lin);
        if(id>=0)
        {
            if(((unsigned int)id)!=lin)
            {
                A.RowSwap((unsigned int)id,lin);
            }
            
            // genero una linea con 1 en la posicion (lin,lin)
            alpha=B.array[lin][lin];
            A.RowDivAssig(lin,alpha);
            for(all=lin;all<B.ncol;all++)
            {
                B.array[lin][all]=B.array[lin][all]/alpha;
            }
            
            // Abajo de la columna (:,lin) todo sera cerado
            for(i=lin+1;i<B.nlin;i++)
            {
                alpha=B.array[i][lin];
                if(B.array[i][lin]!=0)
                {
                    A.RowAddAssig(i,lin,-alpha);
                    
                    for(all=lin;all<B.ncol;all++)
                    B.array[i][all]=B.array[i][all]-alpha*(B.array[lin][all]);
                }
            }
            
            
        }
        else
        {
            A.MakeEmpty();
            if(rcond!=NULL) *rcond =0;
            return A;
        }
    }

    // reduzco la matriz
    for(lin=1;lin<B.nlin;lin++)
    {
        for(i=1;i<=lin;i++)
        {
            alpha=B.array[lin-i][lin];

            A.RowAddAssig(lin-i,lin,-alpha);
            
            for(all=lin;all<B.ncol;all++)
            B.array[lin-i][all]=B.array[lin-i][all]-alpha*(B.array[lin][all]);
        }
    }

    if(rcond!=NULL) *rcond=1.0/(this->PNorm1()*A.PNorm1());
    else
    {
        double r=1.0/(this->PNorm1()*A.PNorm1());
        
        if(r<Pds::Ra::WarningRCond)
        {
            pds_print_warning_message("The value of rcond is too small, rcond:"<<r);
        }
    }
    return A;
}
////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::MtM(void) const
{
    if( this->IsEmpty() )   return Pds::Matrix();

    Pds::Matrix Ans(this->ncol,this->ncol);

    unsigned int lin,col,id;
    double S;
   
    for(lin=0;lin<this->ncol;lin++)
    for(col=0;col<this->ncol;col++)
    {
        S=0;
        
        for(id=0;id<this->nlin;id++)
        S=S+this->array[id][lin]*this->array[id][col];
        
        Ans.array[lin][col]=S;
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::T(void) const
{
    if( this->IsEmpty() )   return Pds::Matrix();

    Pds::Matrix Ans(this->ncol,this->nlin);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[col][lin]=this->array[lin][col];  
    }

    return Ans;
}

////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator +(void) const
{
    return this->Minus();
}

Pds::Matrix Pds::Matrix::Plus(void) const
{
    if( this->IsEmpty() )   return Pds::Matrix();
    
    return *this;
}
////////////////////////////////////////////////////////////////////////
Pds::Matrix Pds::Matrix::operator -(void) const
{
    return this->Minus();
}

Pds::Matrix Pds::Matrix::Minus(void) const
{
    if( this->IsEmpty() )   return Pds::Matrix();

    Pds::Matrix Ans(this->nlin,this->ncol);

    unsigned int lin,col;
   
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        Ans.array[lin][col]=-this->array[lin][col];
    }

    return Ans;
}
