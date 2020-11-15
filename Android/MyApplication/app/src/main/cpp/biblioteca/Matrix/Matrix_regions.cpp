/*
 * Matrix_regions.cpp
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

#include <Pds/RegionRect>
#include <Pds/Matrix>


bool Pds::Matrix::CopyRegion(const Pds::RegionRect &Rin,const Pds::RegionRect &Rout,Pds::Matrix &Mout) const
{
    if(Rin.Nlin!=Rout.Nlin)    return false;
    if(Rin.Ncol!=Rout.Ncol)    return false;

    if(Rin.IsInside(*this)==false)  return  false;
    if(Rout.IsInside(Mout)==false)  return  false;
    
    unsigned int lin,col;

    for(lin=0;lin<Rin.Nlin;lin++)
    for(col=0;col<Rin.Ncol;col++)
    {
        Mout.array[lin+Rout.L0][col+Rout.C0]=this->array[lin+Rin.L0][col+Rin.C0];
    }

    return true;
}


bool Pds::Matrix::InitRegion(Pds::RegionRect R,double val)
{
	unsigned int i,j;

    if(R.IsInside(*this)==false)   return false;

	for(i=0;i<R.Nlin;i++)
	for(j=0;j<R.Ncol;j++)
    {
		this->array[R.L0+i][R.C0+j]=val;
	}

	return true;
}


Pds::RegionRect Pds::Matrix::GetRegion(void) const
{

	if(this->IsEmpty()) return Pds::RegionRect();

    return Pds::RegionRect(0,0,this->nlin,this->ncol);
}
////////////////////////////////////////////////////////////////////////////////
bool Pds::Matrix::MeanSquareOfRegion(const Pds::RegionRect &Rin, double *means) const
{
	unsigned int i,j;
	double S=0;

	if(this->IsEmpty()) return false;
	if(means==NULL)	    return false;

    Pds::RegionRect Rmat(0,0,this->nlin,this->ncol);
    Pds::RegionRect R=Rmat.Intersection(Rin);
    if(R.IsEmpty())     return false;

	for(i=0;i<R.Nlin;i++)
	for(j=0;j<R.Ncol;j++)
    {
        S=S+(this->array[R.L0+i][R.C0+j])*(this->array[R.L0+i][R.C0+j]);
    }

    *means=S/(R.Nlin*R.Ncol);

    return true;
}

double Pds::Matrix::MeanSquareOfRegion(const Pds::RegionRect &Rin) const
{
	unsigned int i,j;
	double S=0;

	if(this->IsEmpty()) return Pds::Ra::Nan;

    Pds::RegionRect Rmat(0,0,this->nlin,this->ncol);
    Pds::RegionRect R=Rmat.Intersection(Rin);
    if(R.IsEmpty())     return Pds::Ra::Nan;

	for(i=0;i<R.Nlin;i++)
	for(j=0;j<R.Ncol;j++)
    {
        S=S+(this->array[R.L0+i][R.C0+j])*(this->array[R.L0+i][R.C0+j]);
    }

    return S/(R.Nlin*R.Ncol);
}

////////////////////////////////////////////////////////////////////////////////
bool Pds::Matrix::MeanOfRegion(const Pds::RegionRect &Rin, double *mean) const
{
	unsigned int i,j;
	double S=0;

	if(this->IsEmpty()) return false;
	if(mean==NULL)	    return false;

    Pds::RegionRect Rmat(0,0,this->nlin,this->ncol);
    Pds::RegionRect R=Rmat.Intersection(Rin);
    if(R.IsEmpty())     return false;

	for(i=0;i<R.Nlin;i++)
	for(j=0;j<R.Ncol;j++)
    {
        S=S+this->array[R.L0+i][R.C0+j];
    }

    *mean=S/(R.Nlin*R.Ncol);

    return true;
}

double Pds::Matrix::MeanOfRegion(const Pds::RegionRect &Rin) const
{
	unsigned int i,j;
	double S=0;

	if(this->IsEmpty()) return Pds::Ra::Nan;

    Pds::RegionRect Rmat(0,0,this->nlin,this->ncol);
    Pds::RegionRect R=Rmat.Intersection(Rin);
    if(R.IsEmpty())     return Pds::Ra::Nan;

	for(i=0;i<R.Nlin;i++)
	for(j=0;j<R.Ncol;j++)
    {
        S=S+this->array[R.L0+i][R.C0+j];
    }

    return S/(R.Nlin*R.Ncol);
}


bool Pds::Matrix::StdAndMeanOfRegion(const Pds::RegionRect &Rin, double *std, double *mean) const
{
	unsigned int i,j;
	double S=0;

	if(this->IsEmpty()) return false;
	if(mean==NULL)	    return false;
	if(std==NULL)	    return false;
    
    Pds::RegionRect Rmat(0,0,this->nlin,this->ncol);
    Pds::RegionRect R=Rmat.Intersection(Rin);
    if(R.IsEmpty())     return false;

    if(this->MeanOfRegion(R,mean)==false)   return false;

	for(i=0;i<R.Nlin;i++)
	for(j=0;j<R.Ncol;j++)
    {
        S=S+(this->array[R.L0+i][R.C0+j]-(*mean))*(this->array[R.L0+i][R.C0+j]-(*mean));
    }

    *std=sqrt(S/(R.Nlin*R.Ncol));

    return true;
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

bool Pds::Matrix::CorrNormRegions(  const Pds::Matrix &M1,
                                    const Pds::RegionRect &R0,
                                    const Pds::RegionRect &R1, 
                                    double *corrn) const
{
    /////////////////////////////////////////////////////////
    // verificación de datos

	if(corrn==NULL)	        return false;
    
    if(R0.Nlin!=R1.Nlin)    return false; // si los tamaños son distintos
    if(R0.Ncol!=R1.Ncol)    return false; // si los tamaños son distintos

    if(R0.IsInside(*this)==false) return false;
    if(R1.IsInside(M1)==false)    return false;

    //////////////////////////////////////////////////////////

	unsigned int i,j;
	double S=0;

    // calculo do desvio padrão
    double means0,means1;
    this->MeanSquareOfRegion(R0,&means0);
    M1.MeanSquareOfRegion(R1,&means1);

    // calculo do corrn
	for(i=0;i<R0.Nlin;i++)
	for(j=0;j<R0.Ncol;j++)
    {
        S=S+(this->array[R0.L0+i][R0.C0+j])*(M1.array[R1.L0+i][R1.C0+j]);
    }
    
    *corrn=S/(R0.Nlin*R0.Ncol*sqrt(means0*means1));
    
    return true;
}

bool Pds::Matrix::CorrNormRegions(  const Pds::Matrix &M1,
                                    const Pds::RegionRect &R0,
                                    const Pds::RegionRect &R1, 
                                    double means0,
                                    double means1,
                                    double *corrn) const
{
    /////////////////////////////////////////////////////////
    // verificación de datos

	if(corrn==NULL)	        return false;
    
    if(R0.Nlin!=R1.Nlin)    return false; // si los tamaños son distintos
    if(R0.Ncol!=R1.Ncol)    return false; // si los tamaños son distintos

    if(R0.IsInside(*this)==false) return false;
    if(R1.IsInside(M1)==false)    return false;

    //////////////////////////////////////////////////////////

	unsigned int i,j;
	double S=0;

    // calculo do corrn
	for(i=0;i<R0.Nlin;i++)
	for(j=0;j<R0.Ncol;j++)
    {
        S=S+(this->array[R0.L0+i][R0.C0+j])*(M1.array[R1.L0+i][R1.C0+j]);
    }
    
    *corrn=S/(R0.Nlin*R0.Ncol*sqrt(means0*means1));
    
    return true;
}


////////////////////////////////////////////////////////////////////////////////
bool pcc_special_cases(double std0,double mean0,double std1,double mean1,double *pcc)
{
    if( ((std0==0.0)&&(std1!=0.0))||((std0!=0.0)&&(std1==0.0)) )
    {
        *pcc=0.0;
        return true;
    }

    if( (std0==0.0)&&(std1==0.0) )
    {
        *pcc= 0.0;
        
        if     ((mean0*mean1)>0.0)          *pcc=+1.0;
        else if((mean0*mean1)<0.0)          *pcc=-1.0;
        else if((mean0==0.0)&&(mean1!=0.0)) *pcc= 0.0;
        else if((mean0!=0.0)&&(mean1==0.0)) *pcc= 0.0;
        else if((mean0==0.0)&&(mean1==0.0)) *pcc=+1.0;
        
        return true;
    }
    return false;
}

bool Pds::Matrix::CorrPearsonRegions(  const Pds::Matrix &M1,
                                const Pds::RegionRect &R0,
                                const Pds::RegionRect &R1, 
                                double *pcc) const
{
    /////////////////////////////////////////////////////////
    // verificación de datos

	if(pcc==NULL)	        return false;
    
    if(R0.Nlin!=R1.Nlin)    return false; // si los tamaños son distintos
    if(R0.Ncol!=R1.Ncol)    return false; // si los tamaños son distintos

    if(R0.IsInside(*this)==false) return false;
    if(R1.IsInside(M1)==false)    return false;

    //////////////////////////////////////////////////////////

	unsigned int i,j;
	double S=0;

    double mean0,mean1;
    double std0,std1; 

    // calculo de la media y el desvio padron
    this->StdAndMeanOfRegion(R0,&std0,&mean0);
    M1.StdAndMeanOfRegion(R1,&std1,&mean1);

    // casos especiales de la correlacion quando std0 o std1 son cero.
    if(pcc_special_cases(std0,mean0,std1,mean1,pcc)==true)  return true;

    // calculo do pcc
	for(i=0;i<R0.Nlin;i++)
	for(j=0;j<R0.Ncol;j++)
    {
        S=S+(this->array[R0.L0+i][R0.C0+j]-mean0)*(M1.array[R1.L0+i][R1.C0+j]-mean1);
    }

    *pcc=S/(R0.Nlin*R0.Ncol*std0*std1);

    return true;
}


bool Pds::Matrix::CorrPearsonRegions(  const Pds::Matrix &M1,
                                const Pds::RegionRect &R0,
                                const Pds::RegionRect &R1,
                                double mean0,
                                double mean1,
                                double std0,
                                double std1,
                                double *pcc) const
{
    /////////////////////////////////////////////////////////
    // verificación de datos

	if(pcc==NULL)	        return false;
    
    if(R0.Nlin!=R1.Nlin)    return false; // si los tamaños son distintos
    if(R0.Ncol!=R1.Ncol)    return false; // si los tamaños son distintos

    if(R0.IsInside(*this)==false) return false;
    if(R1.IsInside(M1)==false)    return false;

    //////////////////////////////////////////////////////////

	unsigned int i,j;
	double S=0;
    
    // casos especiales de la correlacion quando std0 o std1 son cero.
    if(pcc_special_cases(std0,mean0,std1,mean1,pcc)==true)  return true;

    // calculo do pcc
	for(i=0;i<R0.Nlin;i++)
	for(j=0;j<R0.Ncol;j++)
    {
        S=S+(this->array[R0.L0+i][R0.C0+j]-mean0)*(M1.array[R1.L0+i][R1.C0+j]-mean1);
    }

    *pcc=S/(R0.Nlin*R0.Ncol*std0*std1);

    return true;
}

/*

Pds::RegionRect Pds::Matrix::FindRegion(    const Pds::Matrix &Mdest,
                                            const Pds::RegionRect &Rsrc,
                                            double Threshold,
                                            unsigned int Step) const
{
    Pds::RegionRect R(0,0,Rsrc.Nlin,Rsrc.Ncol);
    double pcc,pcc_max;
    Pds::RegionRect Rmax;    
    
    unsigned int lin,col,i=0;

    if(Step==0) Step=1;

    unsigned int LinMax=Mdest.nlin-R.Nlin+1;
    unsigned int ColMax=Mdest.ncol-R.Ncol+1;
    for(lin=0;lin<LinMax;lin=(lin+1+rand()%Step))
    {
        std::cout<<"Working line "<<lin<<" of "<<LinMax-1<<"\r"<<std::flush;
        for(col=0;col<ColMax;col=(col+1+rand()%Step))
        {
            R.L0=lin;
            R.C0=col;
            pcc=0.0;
            
            this->CorrRegions(Mdest,Rsrc,R,&pcc);
            if(pcc>=Threshold)
            {
                if(i==0)
                {
                    pcc_max=pcc;
                    Rmax=R;
                    i++;
                }
                else if(pcc>pcc_max)
                {
                    pcc_max=pcc;
                    Rmax=R;
                }
            }
        }
    }
    printf("\n");
    
    return Rmax;
}
*/
