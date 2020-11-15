/*
 * Vector.hpp
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

/** \file Vector.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices columna.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de Nlinx1"
 *  \b Nlin es el número de lineas.
 */



#ifndef __PDS_VECTOR_HPP__
#define __PDS_VECTOR_HPP__


/** \defgroup VectorGroup Métodos Pds::Vector
 *  \brief Metodos de la clase Pds::Vector, un vector columna/matriz 
 *  <div class="fragment"> \#include <Pds/Vector> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
   \f[
\mathbf{A}=\left(\begin{matrix}
a_{00}  \\ 
a_{10}  \\
\vdots  \\
a_{(Nlin-2)0}  \\ 
a_{(Nlin-1)0} \\
\end{matrix}\right)
   \f]
   \f[
A\equiv [a_{i0}]
   \f]
 *  \b nlin es el número de lineas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Matrix>
#include <Pds/Size>

#include <sstream>      // std::ostringstream

namespace Pds{

/*! \class Vector
 *  \brief La clase tipo  Pds::Vector .
 *  Esta clase genera una matriz de Nlin lineas y 1 columna.
 *  Para usar incluir Pds/Vector.
 *  \ingroup VectorGroup
 *  \author Fernando Pujaico Rivera
 */
class Vector: public Matrix
{

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Vector
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector
     *  \return un objeto de tipo Pds::Vector.
     *  \ingroup VectorGroup
     */
    Vector(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Vector
     *  \param[in] N El numero de lineas del vector.
     *  \return un objeto de tipo Pds::Vector.
     *  \ingroup VectorGroup
     */
    Vector(unsigned int N);


    /** 
     *  \brief Crea un objeto de tipo Pds::Vector con elementos inicializados con cero.
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
0 \\ 
0 \\
\vdots \\
0 \\ 
0 \\
\end{matrix}\right)
   \f]
   \f[ A\equiv [0]  \f]
   Para crear una matriz A de 6 filas y 1 columna:
\code{.cpp}
    Pds::Matrix B(2,3);
    Pds::Vector A(B.Size());
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] S El tamaño del vector, en general el tamaño es S.Ncol*S.Nlin.
     *  \ingroup VectorGroup
     */
    Vector(const Pds::Size &S);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Vector copiando datos desde 
     *  una matriz. Toda la matriz es vectorizada leyendo columna a columna.
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B\{:\}}
   \f]
   Para crear una matriz A con copia de datos de una matriz B:
\code{.cpp}
    Pds::Matrix B(4,5);
    Pds::Vector A(B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \ingroup VectorGroup
     */
    Vector(const Pds::Matrix &B);

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector copiando datos desde 
     *  una cadena.
     * 
   Para crear una matriz A con los datos de una cadena:
\code{.cpp}
    Pds::Vector A="1 2 3\n4 5 6\n";
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] str Cadena a leer.
     *  \ingroup VectorGroup
     */
    Vector(const char *str);


    /** 
     *  \brief Crea un objeto de tipo Pds::Vector copiando datos desde 
     *  una lista.
     * 
   Para crear una matriz A con los datos de una cadena:
\code{.cpp}
    Pds::Vector A={1, 2, 3, 4, 5 6};
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] list Lista a leer.
     *  \ingroup VectorGroup
     */
    Vector(const std::initializer_list<double> list);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Vector
     *  \param[in] N El numero de lineas del vector.
     *  \param[in] val El valor a inicializar.
     *  \return un objeto de tipo Pds::Vector.
     *  \ingroup VectorGroup
     */
    Vector(unsigned int N,double val);

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector copiando datos desde
     *  una columna de una matriz. 
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B\{:,col\}}
   \f]
   Para crear una matriz A con copia de datos de una matriz B:
\code{.cpp}
    Pds::Matrix B(4,5);
    Pds::Vector A(B,2);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \param[in] col columna a copiar.
     *  \ingroup VectorGroup
     */
    Vector(const Pds::Matrix &B,unsigned int col);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Vector, evaluando mediante una función, 
     *  los datos de otro vector.
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{B})
   \f]
   Para crear un vector A , copia de sin(B):
\code{.cpp}
    Pds::Vector B(4);
    Pds::Vector A(cos,B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Vector a evaluar para copiar los resultados.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     *  \ingroup VectorGroup
     */
    Vector(double (*func)(double),const Pds::Vector &B );

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector, evaluando mediante una función, 
     *  los datos de una matriz vectorizada.
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
B_{Nlin~Ncol,1} \leftarrow func(\mathbf{B(:)})
   \f]
   Para crear un vector A , copia de sin(B(:)):
\code{.cpp}
    Pds::Matrix B(4);
    Pds::Vector A(cos,B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Vector a evaluar para copiar los resultados.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     *  \ingroup VectorGroup
     */
    Vector(double (*func)(double),const Pds::Matrix &B );
    

    /** 
     *  \brief Crea un objeto de tipo Pds::Vector copiando datos desde 
     *  un archivo.
     * 
\code{.cpp}
    Pds::Vector A(TEXT,"textfile.txt");
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] Type Tipo de archivo de fuente de datos.
     *  \param[in] filepath Path del archivo cargado.
     *  \ingroup VectorGroup
     */
    Vector(Pds::Ra::FormatType Type,std::string filepath);
    
    ~Vector();

/**
 * @}
 */
    
    
/** @name Operadores binarios.
 * @{
 */

    /** 
     *  \brief Calcula la convolución entre A y B. 
     * 
     * \f[ \mathbf{A}\equiv [a_{i}]_{N,1} \overset{func}{\equiv} a(i),~0 \leq i\leq N-1 \f]
     *
     * \f[ \mathbf{B}\equiv [b_{i}]_{M,1} \overset{func}{\equiv} b(i),~0 \leq i\leq M-1 \f]
     * 
     * \f[ \mathbf{C}\equiv [c_{i}]_{M+N-1,1} \overset{func}{\equiv} c(i),~0 \leq i\leq M+N-2\f]
     *
     * \f[ c(l) \leftarrow \sum \limits_{k=-\infty}^{+\infty} a(l-k)b(k) \f]
     *  O seu equivalente
     * \f[ c(l) \leftarrow \sum \limits_{k=-\infty}^{+\infty} a(k)b(l-k) \f]
     *
     *  
     * 
     *  \param[in] B Vector a aplicar la convolución.
     *  \param[in] Same Si Same es igual a true entonces, \f$\mathbf{C}\f$ describe
     *  \f$[c_{i}]_{N,1} \overset{func}{\equiv}  c(i), ~ 0 \leq i \leq N-1\f$.
     *  proveniente de um \f$\mathbf{B}\f$ como \f$[b_{i}]_{M,1} \overset{func}{\equiv} b(i-\left \lfloor M/2 \right \rfloor),~0 \leq i\leq M-1\f$.
     *  Por defecto Same es igual a false.
     *  \return retorna la convolucion.
     *  \ingroup VectorGroup
     */
    Pds::Vector Conv(const Pds::Vector &B, bool Same=false) const;

    /** 
     *  \brief Calcula la correlacion cruzada entre A y B. 
     * 
     * \f[ \mathbf{A}\equiv [a_{i}]_{N,1}  \overset{func}{\equiv} a(i),~0 \leq i\leq N-1 \f]
     * \f[ \mathbf{B}\equiv [b_{i}]_{M,1}  \overset{func}{\equiv} b(i),~0 \leq i\leq M-1 \f]
     * \f[ \mathbf{C}\equiv [c_{i}]_{M+N-1,1}  \overset{func}{\equiv} c(i-(M-1)),~ 0 \leq i \leq M+N-2 \f]
     * \f[ c(l) \leftarrow \sum \limits_{k=-\infty}^{+\infty} a(l+k) b(k) \f]
     *  O seu equivalente
     * \f[ c(l) \leftarrow \sum \limits_{k=-\infty}^{+\infty} a(k) b(k-l) \f]
     *  
     * 
     *  \param[in] B Vector a aplicar la correlacion cruzada.
     *  \param[in] Same indica si la correlación cruzada tendrá el mismo 
     *  tamaño que A, si Same es igual a true entonces,\f$[c_{i}]_{N,1}  \overset{func}{\equiv} c(i), ~0 \leq i \leq N-1\f$.
     *  Por defecto Same es igual a false.
     * \return retorna la correlacion cruzada.
     *  \ingroup VectorGroup
     */
    Pds::Vector XCorr(const Pds::Vector &B, bool Same=false) const;
    
/**
 * @}
 */
    
    
/** @name Operadores unarios.
 * @{
 */

    /** 
     *  \brief Calcula el vector unitario de A. 
     * 
     * \f[ \mathbf{B}\leftarrow \frac{\mathbf{A}}{||\mathbf{A}||} \f]
     * \return retorna un vector unitario \f$\mathbf{B}\f$.
     *  \ingroup VectorGroup
     */
    Pds::Vector Unit(void) const;
    
/**
 * @}
 */
    
    
/** @name Operadores binarios acumuladores y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Vector.
 * @{
 */
    
    /** 
     *  \brief Copia en si mismo (A), una matriz B. Este operador es 
     *  similar al método Copy().
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     * Cuando acontece:
\code{.cpp}
    Pds::Vector B(nlin,ncol);
    A=B;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Vector A=Pds::Vector(nlin,ncol);
\endcode
     *  \param[in] B la matriz a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup VectorGroup
     */
    Pds::Vector& operator = (const Pds::Vector &B);


/**
 * @}
 */

}; // Class Vector

} // namespace Pds


/*!
 * @}
 */

#endif

