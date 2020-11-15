#include <Pds/Matrix>
//#include <Pds/RaTools>


Pds::Matrix Pds::Matrix::FromString(const std::string &str)
{
    Pds::Matrix A;
    unsigned int Nlin;
    unsigned int Ncol;
    static double **array=Pds::Matrix::ArrayFromString(str,Nlin,Ncol);
    if(array==NULL) return A;
    
    A.array=array;
    A.ncol=Ncol;
    A.nlin=Nlin;
    
    return A;
}

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::ExportBmpFile(const Pds::Matrix &R,const Pds::Matrix &G,const Pds::Matrix &B,const char* bmpfilename)
{
    if(R.IsEmpty())         return false;
    if(R.IsNotSimilarTo(G)) return false;
    if(R.IsNotSimilarTo(B)) return false;
    if(bmpfilename==NULL)   return false;

    
    bool ret=Pds::Matrix::ArrayWriteBmp(R.array,G.array,B.array,R.nlin,R.ncol,bmpfilename);
    
    return ret;
}
