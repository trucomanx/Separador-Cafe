#include <cstdlib>
#include <Pds/Matrix>
#include <Pds/RaDefines>
#include <Pds/RaTools>
#include <Pds/RaString>
#include <Pds/RaFile>

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double),const Pds::Matrix &A)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col]);
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double),const Pds::Matrix &A,double var)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col],var);
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double),const Pds::Matrix &A,const Pds::Matrix &B)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col]);
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double),const Pds::Matrix &A,const Pds::Matrix &B,double var)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],var);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double),const Pds::Matrix &A,const Pds::Matrix &B,const Pds::Matrix &C)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((C.nlin==0)||(C.ncol==0)||(C.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;
    if((A.nlin!=C.nlin)||(A.ncol!=C.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],C.array[lin][col]);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double,double),
                                    const Pds::Matrix &A,
                                    const Pds::Matrix &B,
                                    const Pds::Matrix &C,
                                    double var)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((C.nlin==0)||(C.ncol==0)||(C.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;
    if((A.nlin!=C.nlin)||(A.ncol!=C.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],C.array[lin][col],var);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(double (*func)(double,double,double,double),
                                    const Pds::Matrix &A,
                                    const Pds::Matrix &B,
                                    const Pds::Matrix &C,
                                    const Pds::Matrix &D)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))   return NULL;
    if((B.nlin==0)||(B.ncol==0)||(B.array==NULL))   return NULL;
    if((C.nlin==0)||(C.ncol==0)||(C.array==NULL))   return NULL;
    if((D.nlin==0)||(D.ncol==0)||(D.array==NULL))   return NULL;
    if((A.nlin!=B.nlin)||(A.ncol!=B.ncol))          return NULL;
    if((A.nlin!=C.nlin)||(A.ncol!=C.ncol))          return NULL;
    if((A.nlin!=D.nlin)||(A.ncol!=D.ncol))          return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) 
        array[lin][col]=(*func)(A.array[lin][col],B.array[lin][col],C.array[lin][col],D.array[lin][col]);
    }
    return array;
    
}

////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(const Pds::Matrix &A)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((A.nlin==0)||(A.ncol==0)||(A.array==NULL))    return NULL;

    array= new double*[A.nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < A.nlin; lin++)
    {
        array[lin] = new double[A.ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < A.ncol; col++) array[lin][col]=A.array[lin][col];
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(unsigned int Nlin,unsigned int Ncol, double val)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((Nlin==0)||(Ncol==0))    return NULL;

    array= new double*[Nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        array[lin] = new double[Ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=val;
    }
    return array;
    
}
////////////////////////////////////////////////////////////////////////

double** Pds::Matrix::ArrayAllocate(unsigned int Nlin,unsigned int Ncol)
{
    double **array=NULL;
    unsigned int lin,col;
    
    if((Nlin==0)||(Ncol==0))    return NULL;

    array= new double*[Nlin];
    if(array==NULL) return NULL;
    
    
    for (lin = 0; lin < Nlin; lin++)
    {
        array[lin] = new double[Ncol];
        if(array[lin]==NULL)
        {
            Pds::Matrix::ArrayRelease(array,lin);
            return NULL;
        }
        for (col = 0; col < Ncol; col++) array[lin][col]=0.0;
    }
    return array;
    
}


void Pds::Matrix::ArrayRelease(double** &array,unsigned int Nlin)
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
////////////////////////////////////////////////////////////////////////

double **Pds::Matrix::ArrayFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int nlin;
    unsigned int ncol;
    bool state=Pds::Ra::ArraySizeInString(str,nlin,ncol);
    if(state==false)    return NULL;
    
    double **array=ArrayAllocate(nlin,ncol);
    if(array==NULL)     return NULL;
    
    unsigned int lin,col;
    
    std::list<std::string> strlist=Pds::Ra::SplitString(str," \t\n\v\f\r");
    std::list<std::string>::iterator it=strlist.begin();
    
    for(lin=0;lin<nlin;lin++)
    for(col=0;col<ncol;col++)
    {
        array[lin][col]=std::stod(*it);
        it++;
    }
    
    Ncol=ncol;
    Nlin=nlin;
    
    return array;
}

////////////////////////////////////////////////////////////////////////

double **Pds::Matrix::ArrayColFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol)
{
    unsigned int nlin;
    unsigned int ncol=1;
    
    int N=Pds::Ra::ElementsInString(str);
    if(N<0) return NULL;
    
    nlin=(unsigned int)N;
    
    double **array=ArrayAllocate(nlin,ncol);
    if(array==NULL)     return NULL;
    
    unsigned int lin,col;
    
    std::list<std::string> strlist=Pds::Ra::SplitString(str," \t\n\v\f\r");
    std::list<std::string>::iterator it=strlist.begin();
    
    for(lin=0;lin<nlin;lin++)
    for(col=0;col<ncol;col++)
    {
        array[lin][col]=std::stod(*it);
        it++;
    }
    
    Nlin=nlin;
    Ncol=ncol;
    
    return array;
}
////////////////////////////////////////////////////////////////////////

#include <iomanip>      // std::setprecision

std::string Pds::Matrix::ArrayToString(double **array,unsigned int Nlin,unsigned int Ncol)
{
    std::string str="";    
    unsigned int lin,col;

    if(array==NULL) return str;

    for(lin=0;lin<Nlin;lin++)
    {
        if(array[lin]!=NULL)
        for(col=0;col<Ncol;col++)
        {
            str=str+Pds::Ra::ToString(array[lin][col]);
            if(col!=(Ncol-1))   str=str+"\t";
            else                str=str+"\n";
        }
    }
    return str;
}

////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
bool Pds::Matrix::ArraySave(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol)
{
    std::ofstream myfile;
    unsigned int lin,col;

    if(filepath==NULL)  return false;
    if(array==NULL)     return false;

    myfile.open(filepath);
    if(myfile.is_open()==false)    return false;

    myfile<<std::setprecision(Pds::Ra::StringPrecision);
    for(lin=0;lin<Nlin;lin++)
    {
        if(array[lin]!=NULL)
        for(col=0;col<Ncol;col++)
        {
            myfile <<array[lin][col];
            if(col!=(Ncol-1))   myfile<<"\t";
            else                myfile<<"\n";
        }
    }

    myfile.close();
    return true;
}
////////////////////////////////////////////////////////////////////////
double *Pds::Matrix::ArrayToArray(double **array,unsigned int Nlin,unsigned int Ncol)
{
    double *real_dat=NULL; /* pointer to real data */
    unsigned int lin,col,id;
        
    if(array==NULL) return NULL;
    for(lin=0;lin<Nlin;lin++)
    if(array[lin]==NULL) return NULL;

    real_dat=(double *)calloc(Nlin*Ncol,sizeof(double));
    if(real_dat==NULL)  return NULL;
    
    id=0;
    for(col=0;col<Ncol;col++)
    for(lin=0;lin<Nlin;lin++,id++)
    real_dat[id]=array[lin][col];
    
    return real_dat;
}
////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef struct {
    int type;  /* type - 4 bytes */ 
    int nlins; /* row dimension - 4 bytes */
    int ncols; /* column dimension - 4 bytes */
    int imag_flag; /* flag indicating imag part - 4 bytes */
    int name_length; /* name length (including NULL) - 4 bytes */
} Fmatrix;
 

// Version 1.0 MAT File Format
bool Pds::Matrix::ArrayWriteMatFile(FILE *fp,const char *pname,double **array,unsigned int Nlin,unsigned int Ncol)
{
    if(fp==NULL)    return false;
    if(Nlin==0)         return false;
    if(Ncol==0)         return false;
    if(pname==NULL) return false;
    if(array==NULL) return false;
    
    
    Fmatrix HEAD;
    
    HEAD.type=0;
    if(Pds::Ra::IsBigEndian())  HEAD.type=HEAD.type+1000;
    if(sizeof(double)==4)       HEAD.type=HEAD.type+10;
    HEAD.nlins=Nlin;
    HEAD.ncols=Ncol;
    HEAD.imag_flag=0;
    HEAD.name_length=strlen(pname)+1;    
    
    size_t nel;
    
    nel=fwrite(&HEAD   , sizeof(Fmatrix), 1               , fp);
    if(nel!=(size_t)1)    return false;
    
    nel=fwrite(pname   , sizeof(char)   , HEAD.name_length, fp);
    if(nel!=(size_t)HEAD.name_length)    return false;
    
    
    for(unsigned int col=0;col<Ncol;col++)
    for(unsigned int lin=0;lin<Nlin;lin++)
    fwrite(&array[lin][col], sizeof(double), 1, fp);
    
    return true;
}


// Version 1.0 MAT File Format
bool Pds::Matrix::ArrayWriteMatFile(FILE *fp,const char *pname,double **arrayr,double **arrayi,unsigned int Nlin,unsigned int Ncol)
{
    if(fp==NULL)        return false;
    if(Nlin==0)         return false;
    if(Ncol==0)         return false;
    if(pname==NULL)     return false;
    if((arrayr==NULL)&&(arrayi==NULL))    return false;
    
    
    Fmatrix HEAD;
    
    HEAD.type=0;
    if(Pds::Ra::IsBigEndian())  HEAD.type=HEAD.type+1000;
    if(sizeof(double)==4)       HEAD.type=HEAD.type+10;

    HEAD.nlins=Nlin;
    HEAD.ncols=Ncol;
    if(arrayi==NULL)    HEAD.imag_flag=0;
    else                HEAD.imag_flag=1;
    HEAD.name_length=strlen(pname)+1;    
    
    size_t nel;
    nel=fwrite(&HEAD   , sizeof(Fmatrix), 1               , fp);
    if(nel!=(size_t)1)    return false;
    
    nel=fwrite(pname   , sizeof(char)   , HEAD.name_length, fp);
    if(nel!=(size_t)HEAD.name_length)    return false;
    
    if(arrayr==NULL)
    {
        double dat=0;
        for(unsigned int col=0;col<Ncol;col++)
        for(unsigned int lin=0;lin<Nlin;lin++)
        fwrite(&dat, sizeof(double), 1, fp);
    }
    else
    {
        for(unsigned int col=0;col<Ncol;col++)
        for(unsigned int lin=0;lin<Nlin;lin++)
        fwrite(&arrayr[lin][col], sizeof(double), 1, fp);
    }
    
    if(HEAD.imag_flag!=0)
    {
       for(unsigned int col=0;col<Ncol;col++)
       for(unsigned int lin=0;lin<Nlin;lin++)
       fwrite(&arrayi[lin][col], sizeof(double), 1, fp);
    }
    
    return true;
}
   
////////////////////////////////////////////////////////////////////////////////


bool Pds::Matrix::ArrayWriteCsvFile(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol, char delimitador)
{
    std::ofstream myfile;
    unsigned int lin,col;

    if(filepath==NULL)  return false;
    if(array==NULL)     return false;

    myfile.open(filepath);
    if(myfile.is_open()==false)    return false;

    myfile<<std::setprecision(Pds::Ra::StringPrecision);
    for(lin=0;lin<Nlin;lin++)
    {
        if(array[lin]!=NULL)
        for(col=0;col<Ncol;col++)
        {
            myfile <<array[lin][col];
            if(col!=(Ncol-1))   myfile<<delimitador;
            else                myfile<<"\n";
        }
    }

    myfile.close();
    return true;
}
////////////////////////////////////////////////////////////////////////
#include <cstdlib>
double** Pds::Matrix::ArrayLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol)
{
    unsigned int nlin,ncol;
    unsigned int i,j;

    if(filepath==NULL)  return NULL;
    //if(array!=NULL)     return false;

    if(Pds::Ra::ArraySizeInFile(filepath,nlin,ncol)==false) return NULL;

    double **arr=Pds::Matrix::ArrayAllocate(nlin,ncol);
    if(arr==NULL)   return NULL;


    std::ifstream ifs(filepath, std::ifstream::in);	
    if(ifs.is_open()==false)
    {
        Pds::Matrix::ArrayRelease(arr,nlin);
        return NULL;
    }

    std::string word;

    i=0;j=0;
    for(i=0;(!ifs.eof())&&(i<nlin);i++)
    for(j=0;(!ifs.eof())&&(j<ncol);j++)
    {

        ifs >> word;
        arr[i][j]=strtod(word.c_str(),NULL);

    }
    ifs.close();

    Nlin=nlin;
    Ncol=ncol;

    return arr;
}

////////////////////////////////////////////////////////////////////////

#include <cstdlib>
double** Pds::Matrix::ArrayColLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol)
{
    unsigned int nlin,ncol;
    unsigned int i;

    if(filepath==NULL)  return NULL;

    if(Pds::Ra::ElementsInFile(filepath,nlin)==false) return NULL;
    ncol=1;

    double **arr=Pds::Matrix::ArrayAllocate(nlin,ncol);
    if(arr==NULL)   return NULL;


    std::ifstream ifs(filepath, std::ifstream::in);	
    if(ifs.is_open()==false)
    {
        Pds::Matrix::ArrayRelease(arr,nlin);
        return NULL;
    }

    std::string word;

    i=0;
    for(i=0;(!ifs.eof())&&(i<nlin);i++)
    {
        ifs >> word;
        arr[i][0]=strtod(word.c_str(),NULL);
    }
    ifs.close();

    Nlin=nlin;
    Ncol=ncol;

    return arr;
}


////////////////////////////////////////////////////////////////////////////////


/** 
 *  \brief Escribe los datos de una matriz en un archivo de en formato BMP.
 *  \param[in] R Matriz donde se leerán los datos de color rojo. 0<= r<= 255
 *  \param[in] G Matriz donde se leerán los datos de color verde. 0<= g<= 255
 *  \param[in] B Matriz donde se leerán los datos de color azul. 0<= b<= 255
 *  \param[in] bmpfilename Nombre del archivo donde se escribirán los datos 
 *  de la matriz.
 *  \return true si todo fue bien o false si no. (ej. R,G,B,bmpfilename==NULL)
 *  \ingroup MatrixGroup
 */
bool Pds::Matrix::ArrayWriteBmp(    double **arrayr,
                                    double **arrayg,
                                    double **arrayb,
                                    unsigned int Nlin,
                                    unsigned int Ncol,
                                    const char *bmpfilename)
{
    FILE *bmpfd=NULL;

    unsigned char *img = NULL;
    double r,g,b;

    if(arrayr==NULL)        return false;
    if(arrayg==NULL)        return false;
    if(arrayb==NULL)        return false;
    if(bmpfilename==NULL)   return false;

    int x,y,i,j;
    int WIDTH  = Ncol;
    int HEIGHT = Nlin;
    int FILESIZE = 54 + 3*WIDTH*HEIGHT; 



    img = (unsigned char *)calloc(3*WIDTH*HEIGHT,sizeof(unsigned char));
    if(img==NULL)   return false;

    for(j=0; j<HEIGHT; j++)
    for(i=0; i<WIDTH ; i++)
    {
        x=i; 
        y=j;

        r = arrayr[j][i];    if (r > 255) r=255;   if (r < 0) r=0;
        g = arrayg[j][i];    if (g > 255) g=255;   if (g < 0) g=0;
        b = arrayb[j][i];    if (b > 255) b=255;   if (b < 0) b=0;
        
        img[(x+(HEIGHT-1-y)*WIDTH)*3+2] = (unsigned char)(r);
        img[(x+(HEIGHT-1-y)*WIDTH)*3+1] = (unsigned char)(g);
        img[(x+(HEIGHT-1-y)*WIDTH)*3+0] = (unsigned char)(b);
    }

    ///////////////////////////////// Cabecera //////////////////////////////////
    // [ 2, 6> tamaño total del archivo (calculalo luego)
    // [ 6,10> puros cero
    // [10,14> Tamanho total de la cabecera
    unsigned char bmpfileheader[14] = {'B','M',   0,0,0,0,  0,0,0,0,  54,0,0,0};

    bmpfileheader[ 2] = (unsigned char)(FILESIZE    );
    bmpfileheader[ 3] = (unsigned char)(FILESIZE>> 8);
    bmpfileheader[ 4] = (unsigned char)(FILESIZE>>16);
    bmpfileheader[ 5] = (unsigned char)(FILESIZE>>24);

    /////////////////////////// Cabecera informativa ////////////////////////////
    // [ 0, 4> Tamanho total de informacion de la cabecera
    // [ 4, 8> Ancho en pixels de la imagen
    // [ 8,12> Alto en pixels de la imagen
    unsigned char bmpinfoheader[40] = {40,0,0,0,  0,0,0,0,  0,0,0,0,  1,0, 24,0};

    bmpinfoheader[ 4] = (unsigned char)(WIDTH    );
    bmpinfoheader[ 5] = (unsigned char)(WIDTH>> 8);
    bmpinfoheader[ 6] = (unsigned char)(WIDTH>>16);
    bmpinfoheader[ 7] = (unsigned char)(WIDTH>>24);

    bmpinfoheader[ 8] = (unsigned char)(HEIGHT    );
    bmpinfoheader[ 9] = (unsigned char)(HEIGHT>> 8);
    bmpinfoheader[10] = (unsigned char)(HEIGHT>>16);
    bmpinfoheader[11] = (unsigned char)(HEIGHT>>24);

    unsigned char bmppad[3] = {0,0,0};

    bmpfd = fopen(bmpfilename,"wb");
    if(bmpfd==NULL)
    {
        free(img);
        return false;
    }
    fwrite(bmpfileheader,1,14,bmpfd);
    fwrite(bmpinfoheader,1,40,bmpfd);
    for(i=0; i<HEIGHT; i++)
    {
        fwrite(img+(WIDTH*i*3),3,WIDTH            ,bmpfd);
        fwrite(bmppad         ,1,(4-(WIDTH*3)%4)%4,bmpfd);
    }
    fclose(bmpfd);
    return true;
}

bool Pds::Matrix::ArrayWriteBmpWithColormap(double **array,
                                            unsigned int Nlin,
                                            unsigned int Ncol,
                                            const unsigned char colormap[256][3],
                                            const char *bmpfilename)
{
    FILE * bmpfd=NULL;

    unsigned char *img = NULL;
    unsigned char UCHAR;

    int i;
    unsigned int lin,col;

    if(array==NULL)         return false;
    if(bmpfilename==NULL)   return false;
    
    int WIDTH  = Ncol;
    int HEIGHT = Nlin;

    int FILESIZE=54+(int)WIDTH*HEIGHT+1024;
    
    img = (unsigned char *)calloc(WIDTH*HEIGHT,sizeof(unsigned char));
    if(img==NULL)   return false;

    for(lin=0; lin<(unsigned int)HEIGHT; lin++)
    for(col=0; col<(unsigned int)WIDTH ; col++)
    {

        if      (array[lin][col] > 255) UCHAR = 255;
        else if (array[lin][col] <   0) UCHAR = 0;
        else                        UCHAR = (unsigned char)array[lin][col];
        
        //img[col+lin*WIDTH] = UCHAR;
        img[col+(HEIGHT-1-lin)*WIDTH] = UCHAR;
    }

    ///////////////////////////////// Paleta ///////////////////////////////////
    unsigned char paleta[1024];
    for(i=0;i<256;i++)
    {
        paleta[i*4+0]=colormap[i][2];
        paleta[i*4+1]=colormap[i][1];
        paleta[i*4+2]=colormap[i][0];
        paleta[i*4+3]=0;
    }
    ////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////// Cabecera //////////////////////////////////
    // [ 2, 6> tamaño total del archivo (calculalo luego)
    // [ 6,10> puros cero
    // [10,14> Tamanho total de la cabecera (1024+54)
    unsigned char bmpfileheader[14] = {'B','M',  0,0,0,0,  0,0,0,0,  54,4,0,0};
   
    bmpfileheader[ 2] = (unsigned char)(FILESIZE    );
    bmpfileheader[ 3] = (unsigned char)(FILESIZE>> 8);
    bmpfileheader[ 4] = (unsigned char)(FILESIZE>>16);
    bmpfileheader[ 5] = (unsigned char)(FILESIZE>>24);
    ////////////////////////////////////////////////////////////////////////////


    /////////////////////////// Cabecera informativa ////////////////////////////
    // [ 0, 4> Tamanho total de informacion de la cabecera
    // [ 4, 8> Ancho en pixels de la imagen
    // [ 8,12> Alto en pixels de la imagen
    // [12,14> Numero de Planos ¿?
    // [14,16> Numero de bits por pixel (1, 4, 8, 16, 24 o 32.)
    // [16,20> Sin compresion
    unsigned char bmpinfoheader[40] = {40,0,0,0,  0,0,0,0,  0,0,0,0,  1,0,  8,0,  0,0,0,0};
    // [32,36> 100h=256 numero de colores
    // [36,40> 100h=256 numero de colores
    
    bmpinfoheader[ 4] = (unsigned char)(WIDTH    );
    bmpinfoheader[ 5] = (unsigned char)(WIDTH>> 8);
    bmpinfoheader[ 6] = (unsigned char)(WIDTH>>16);
    bmpinfoheader[ 7] = (unsigned char)(WIDTH>>24);

    bmpinfoheader[ 8] = (unsigned char)(HEIGHT    );
    bmpinfoheader[ 9] = (unsigned char)(HEIGHT>> 8);
    bmpinfoheader[10] = (unsigned char)(HEIGHT>>16);
    bmpinfoheader[11] = (unsigned char)(HEIGHT>>24);

    bmpinfoheader[32] = (unsigned char)(0);
    bmpinfoheader[33] = (unsigned char)(1);

    bmpinfoheader[36] = (unsigned char)(0);
    bmpinfoheader[37] = (unsigned char)(1);
    ////////////////////////////////////////////////////////////////////////////

    unsigned char bmppad[3] = {0,0,0};

    bmpfd = fopen(bmpfilename, "wb");
    if (bmpfd == NULL) 
    {
        free(img);
        return false;
    }
    
    fwrite(bmpfileheader, 1,  14, bmpfd);
    fwrite(bmpinfoheader, 1,  40, bmpfd);
    fwrite(paleta       , 1,1024, bmpfd);


    for(i=0;i<HEIGHT;i++)
    {
        fwrite(img+(WIDTH*i),1,WIDTH          ,bmpfd);
        fwrite(bmppad       ,1,(4-(WIDTH%4))%4,bmpfd);
    }

    fclose(bmpfd);

    return true;
}
