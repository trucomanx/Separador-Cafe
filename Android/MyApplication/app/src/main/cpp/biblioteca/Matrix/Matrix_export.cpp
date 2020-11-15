#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>

////////////////////////////////////////////////////////////////////////



bool Pds::Matrix::Save(const char* filepath) const
{
    return Pds::Matrix::ArraySave(filepath,this->array,this->nlin,this->ncol);
}

bool Pds::Matrix::Load(const char* filepath)
{
    double **array=NULL;
    unsigned int Nlin,Ncol;
    this->MakeEmpty();

    array=Pds::Matrix::ArrayLoad(filepath,Nlin,Ncol);
    if(array==NULL) return false;
    this->array=array;
    this->nlin=Nlin;
    this->ncol=Ncol;
    return true;
}
////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ExportCsvFile(const char* filepath,char delimitador) const
{
    return Pds::Matrix::ArrayWriteCsvFile(filepath,this->array,this->nlin,this->ncol,delimitador);
}

////////////////////////////////////////////////////////////////////////////////
bool Pds::Matrix::ExportMatFile(const char* pname,const char* filepath) const
{
    if(this->IsEmpty()) return false;
    if(filepath==NULL)  return false;
    if(pname==NULL)     return false;
    
    FILE *fd=fopen(filepath,"wb");
    if(fd==NULL)    return false;
    
    bool ret=Pds::Matrix::ArrayWriteMatFile(fd,pname,this->array,this->nlin,this->ncol);
    fclose(fd);
    
    return ret;
}

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ExportBmpFile(const unsigned char colormap[256][3],const char* filepath) const
{
    if(this->IsEmpty()) return false;
    if(filepath==NULL)  return false;
    if(colormap==NULL)  return false;
    
    bool ret=Pds::Matrix::ArrayWriteBmpWithColormap(this->array,this->nlin,this->ncol,colormap,filepath);
    
    return ret;
}

