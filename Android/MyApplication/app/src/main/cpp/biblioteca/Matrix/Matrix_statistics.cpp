#include <Pds/Matrix>
#include <cmath>
////////////////////////////////////////////////////////////////////////
double Pds::Matrix::MaxAbs(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    S=fabs(this->array[0][0]);
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(fabs(this->array[lin][col])>S)
    {
        S=fabs(this->array[lin][col]);
        if(id!=NULL) *id=col*(this->nlin)+lin;
    }

    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Max(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    S=this->array[0][0];
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]>S)
    {
        S=this->array[lin][col];
        if(id!=NULL) *id=col*(this->nlin)+lin;
    }

    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::MinAbs(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    S=fabs(this->array[0][0]);
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(fabs(this->array[lin][col])<S)
    {
        S=fabs(this->array[lin][col]);
        if(id!=NULL) *id=col*(this->nlin)+lin;
    }

    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Min(unsigned int *id) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    S=this->array[0][0];
    if(id!=NULL) *id=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    if(this->array[lin][col]<S)
    {
        S=this->array[lin][col];
        if(id!=NULL) *id=col*(this->nlin)+lin;
    }

    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Sum(void) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col];
    
    return S;
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Mean(void) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+this->array[lin][col];
    
    return S/(this->nlin*this->ncol);
}

////////////////////////////////////////////////////////////////////////

double Pds::Matrix::R2(const Pds::Matrix &Y) const
{
    unsigned int lin,col;
    
    if(this->IsEmpty())         return Pds::Ra::Nan;
    if(Y.IsEmpty())             return Pds::Ra::Nan;
    if(this->IsNotSimilarTo(Y)) return Pds::Ra::Nan;
    
    double MST=this->Var();
    double MSE=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    MSE=MSE+(this->array[lin][col]-Y.array[lin][col])*(this->array[lin][col]-Y.array[lin][col]);
    MSE=MSE/(this->nlin*this->ncol);
    
    return 1.0-MSE/MST;
}


double Pds::Matrix::Rf(const Pds::Matrix &Y) const
{
    unsigned int lin,col;
    
    if(this->IsEmpty())         return Pds::Ra::Nan;
    if(Y.IsEmpty())             return Pds::Ra::Nan;
    if(this->IsNotSimilarTo(Y)) return Pds::Ra::Nan;
    
    double MST=this->Var();
    double MSE=0;
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    MSE=MSE+(this->array[lin][col]-Y.array[lin][col])*(this->array[lin][col]-Y.array[lin][col]);
    MSE=MSE/(this->nlin*this->ncol);
    
    return sqrt(MSE/MST);
}
////////////////////////////////////////////////////////////////////////

double Pds::Matrix::Mape(const Pds::Matrix &B) const
{
    if(B.IsEmpty())             return Pds::Ra::Nan;
    if(this->IsEmpty())         return Pds::Ra::Nan;
    if(this->IsNotSimilarTo(B)) return Pds::Ra::Nan;

    unsigned int lin,col;
    double S=0;
    unsigned int count=0;
    
    
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        if(this->array[lin][col]!=0.0)
            S=S+fabs((this->array[lin][col]-B.array[lin][col])/this->array[lin][col]);
        else
            count++;
    }
    return 100.0*S/((this->ncol)*(this->nlin)-count);
}
////////////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Var(double *mean) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    double m=this->Mean();
    if(mean!=NULL)  *mean=m;
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+(this->array[lin][col]-m)*(this->array[lin][col]-m);
    
    return S/(this->nlin*this->ncol);
}

////////////////////////////////////////////////////////////////////////
double Pds::Matrix::Std(double *mean) const
{
    unsigned int lin,col;
    double S;
    
    if((this->nlin==0)||(this->ncol==0)||(this->array==NULL))
    return Pds::Ra::Nan;
    
    double m=this->Mean();
    if(mean!=NULL)  *mean=m;
    
    S=0;
    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    S=S+(this->array[lin][col]-m)*(this->array[lin][col]-m);
    
    return sqrt(S/(this->nlin*this->ncol));
}

