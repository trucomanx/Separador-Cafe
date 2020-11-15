#include <Pds/Matrix>
#include <list>

////////////////////////////////////////////////////////////////////////////////

std::list<unsigned int> Pds::Matrix::Find(void) const
{
    std::list<unsigned int> IDs;
    
    if(this->IsEmpty())   return IDs;
    
    unsigned int lin,col;

    for(lin=0;lin<this->nlin;lin++)
    for(col=0;col<this->ncol;col++)
    {
        if(1.0==this->array[lin][col])
        {
            IDs.push_back(lin+col*(this->nlin));
        }
    }
    return IDs;
}

