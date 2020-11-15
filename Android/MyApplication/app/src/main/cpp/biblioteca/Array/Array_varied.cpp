#include <string>
#include <iostream>
#include <Pds/Array>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>


// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;


template <class Datum>
void MyArrayRelease(Datum** &array,unsigned int Nlin)
{
    if(array!=NULL)
    {
        for (unsigned int j = 0; j < Nlin; j++)
        { 
            delete [] array[j];
            array[j]=NULL;
        }
        delete [] array;
        array=NULL;
    }
}


template <class Datum>
void Pds::Array<Datum>::MakeEmpty(void)
{
    MyArrayRelease(this->array,this->nlin);
    this->nlin=0;
    this->ncol=0;
}
////////////////////////////////////////////////////////////////////////

#include <iomanip>      // std::setprecision

template <class Datum>
void Pds::Array<Datum>::Print(std::string str) const
{
    std::cout<<str;

    if(this->IsEmpty())   return;
    
    std::cout<<std::setprecision(Pds::Ra::StringPrecision);
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        std::cout<<(0+(this->array[lin][col]));

        if(col!=(this->ncol-1)) std::cout<<"\t";
        else                    std::cout<<"\n";
    }

}

template <class Datum>
void Pds::Array<Datum>::Print(void) const
{
    this->Print("");
}

