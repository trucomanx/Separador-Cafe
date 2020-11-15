/*
 * Matrix_rows.cpp
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

bool Pds::Matrix::RowSwap(unsigned int lin1,unsigned int lin2)
{
    if( (lin1>=this->nlin)||(lin2>=this->nlin) )    return false;
    
    double tmp;
    
    for(unsigned int col=0;col<this->ncol;col++)
    {
        tmp=this->array[lin1][col];
        
        this->array[lin1][col]=this->array[lin2][col];
        this->array[lin2][col]=tmp;
    }
    return true;
}


bool Pds::Matrix::RowMulAssig(unsigned int lin,double alpha)
{
    if( (lin>=this->nlin))    return false;
    
    for(unsigned int col=0;col<this->ncol;col++)
    this->array[lin][col]=this->array[lin][col]*alpha;
    
    return true;
}

bool Pds::Matrix::RowDivAssig(unsigned int lin,double alpha)
{
    if( (lin>=this->nlin))    return false;
    
    for(unsigned int col=0;col<this->ncol;col++)
    this->array[lin][col]=this->array[lin][col]/alpha;
    
    return true;
}


int Pds::Matrix::RowSwapBelow(unsigned int n)
{
    if( (n>=this->nlin)||(n>=this->ncol) )    return -1;
    
    if(this->array[n][n]!=0)    return (int)n;
    
    for(unsigned int i=n+1;i<this->nlin;i++)
    if(this->array[i][n]!=0)
    {
        double tmp;
        for(unsigned int col=0;col<this->ncol;col++)
        {
            tmp=this->array[i][col];
            this->array[i][col]=this->array[n][col];
            this->array[n][col]=tmp;
        }
        return n;
    }
    return -1;
}

bool Pds::Matrix::RowAddAssig(unsigned int lin1,unsigned int lin2,double alpha)
{
    if( (lin1>=this->nlin)||(lin2>=this->nlin) )    return false;
    
    for(unsigned int col=0;col<this->ncol;col++)
    this->array[lin1][col]=this->array[lin1][col]+alpha*this->array[lin2][col];
    
    return true;
}

bool Pds::Matrix::RowReduction(void)
{
    unsigned int lin,i,all;
    double alpha;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return false;
    
    // obtengo una matriz escalonada
    for(lin=0;lin<this->nlin;lin++)
    {
        if(RowSwapBelow(lin)>=0)
        {
            // genero una linea con 1 en la posicion (lin,lin)
            alpha=this->array[lin][lin];
            for(all=0;all<this->ncol;all++)
            {
                this->array[lin][all]=this->array[lin][all]/alpha;
            }
            
            // Abajo de la columna (:,lin) todo sera cerado
            for(i=lin+1;i<this->nlin;i++)
            {
                alpha=this->array[i][lin];
                if(this->array[i][lin]!=0)
                {
                    for(all=lin;all<this->ncol;all++)
                    this->array[i][all]=this->array[i][all]-alpha*(this->array[lin][all]);
                }
            }
            
        }
        else return false;
    }

    // reduzco la matriz
    for(lin=1;lin<this->nlin;lin++)
    {
        for(i=1;i<=lin;i++)
        {
            alpha=this->array[lin-i][lin];
            
            for(all=lin;all<this->ncol;all++)
            this->array[lin-i][all]=this->array[lin-i][all]-alpha*(this->array[lin][all]);
        }
    }
    return true;
}
