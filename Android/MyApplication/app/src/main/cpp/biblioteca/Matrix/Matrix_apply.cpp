#include <Pds/Matrix>



////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::Apply( double (*func)(double) )
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col]);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::Apply( double (*func)(double,double),double var)
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col],var);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ApplyInCol(unsigned int col,double (*func)(double))
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin;

    for(lin=0;lin<this->nlin;lin++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col]);
    }
    return true;
}


////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ApplyInCol(unsigned int col, double (*func)(double,double),double var)
{
    if(this->IsEmpty())   return false;
    
    unsigned int lin;

    for(lin=0;lin<this->nlin;lin++)
    {
        this->array[lin][col]=(*func)(this->array[lin][col],var);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

Pds::Matrix Pds::Matrix::OperateRows(double (*func)(const Pds::Matrix &Row)) const
{
    if(this->IsEmpty())   return Pds::Matrix();
    
    unsigned int lin;
    Pds::Matrix matrow;
    Pds::Matrix Ans(this->nlin,1);

    for(lin=0;lin<this->nlin;lin++)
    {
        matrow=this->GetRow(lin);
        Ans.array[lin][0]=(*func)(matrow);
    }
    return Ans;
}

Pds::Matrix Pds::Matrix::OperateCols(double (*func)(const Pds::Matrix &Col)) const
{
    if(this->IsEmpty())   return Pds::Matrix();
    
    unsigned int col;
    Pds::Matrix matcol;
    Pds::Matrix Ans(1,this->ncol);

    for(col=0;col<this->ncol;col++)
    {
        matcol=this->GetCol(col);
        Ans.array[0][col]=(*func)(matcol);
    }
    return Ans;
}


