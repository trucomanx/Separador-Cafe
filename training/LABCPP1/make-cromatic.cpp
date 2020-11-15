/** \file make-cromatic.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para compilar o código make-cromatic.cpp:
\code{.sh}
g++ -static -o make-cromatic make-cromatic.cpp -lpdsmlmm -lpdsramm  -lpdsspmm  
\endcode
Para executar o programa:
\code{.sh}
./make-cromatic --input-file ../../data/imagen1.bmp --output-dir /home/fernando/Downloads/output
\endcode  
Retornando por consola:
\verbatim
    
A:
0	2	4
1	3	5

\endverbatim
 *
 * Código make-cromatic.cpp:
 */
    
#include <cmath>
#include <Pds/Ra>
#include <Pds/Sp>
#include <Pds/Ml>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    std::string image_filepath;
    std::string output_dir;
    
    // Verifico los parametros de entrada del programa
    image_filepath=Pds::Ra::GetParamString(argc,argv,"--input-file","");
    output_dir    =Pds::Ra::GetParamString(argc,argv,"--output-dir","output");

    // Muestro los dados de entrada
    std::cout<<"image_filepath: "<<image_filepath<<std::endl;
    std::cout<<"    output_dir: "<<output_dir<<std::endl;

    // Verifico si el archivo de entrada existe
    if(!Pds::Ra::IsFile(image_filepath))
    {
        std::cout<<"File not found: "<<image_filepath<<std::endl<<std::endl;
        return 0;
    }
    
    // Verifico si el directorio de salida existe
    mkdir(output_dir.c_str(),0777);
    if(!Pds::Ra::IsDir(output_dir))
    {
        std::cout<<"Directory not found: "<<output_dir<<std::endl<<std::endl;
        return 0;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    
    // Obtendo basename desde un filepath
    std::string basename=Pds::Ra::Filename(image_filepath);
    
    // Variables a usar
    unsigned int K=32; //clusters   
    Pds::IterationConf Conf; Conf.SetMinError(0.99);
    std::vector<Pds::Matrix> Block;
    std::vector<Pds::Matrix> WPI;
    std::vector<Pds::Matrix> CC;
    Pds::Matrix Colors;
    std::string filepath;

    // Obtendo un bloque de datos a partir de una imagen
    Block=Pds::Matrix::ImportBmpFile(image_filepath);
    
    // Kmeans de grado K: Block --> {Colors,MAPID}
    Pds::Ra::Tic();
    Pds::Array<unsigned int> MAPID;
    Colors=Pds::Clustering::Kmeans(Conf,Block,K,MAPID);
    Pds::Ra::Toc();

    // Salva la matriz con Colors: {MAPID,Colors} -> filepath{output_dir}
    filepath=Pds::Ra::FullFile({output_dir, basename+"-kmeans"+std::to_string(K)+".bmp"});
    std::cout<<"Output filepath: "<<filepath<<std::endl;
    MAPID.ExportBmpFile(Pds::Array<unsigned char>(Colors),filepath);

    // Si la matriz tiene 3 dimensiones (es a colores)
    if(Block.size()==3)
    {
        // Aplica Balance de blancos
        WPI  =Pds::Image::WhitePatch(Block);
        // Obten cordenandas cromaticas
        CC   =Pds::Image::ChromaticityCoordinates(WPI,255);
    
        // Salva la matriz en cordenandas cromaticas
        filepath=Pds::Ra::FullFile({output_dir, basename+"-cc.bmp"});
        std::cout<<"Output filepath: "<<filepath<<std::endl;
        Pds::Matrix::ExportBmpFile(CC[0],CC[1],CC[2],filepath);
    }

    std::cout<<std::endl;
       
    return 0;
}
