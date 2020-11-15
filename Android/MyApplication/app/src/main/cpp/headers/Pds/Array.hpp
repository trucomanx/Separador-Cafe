/*
 * Array.hpp
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

/** \file Array.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-09-2018
 *  \brief Funciones que trabajan con un grupo de 2 datos.
 *  
 */



#ifndef __PDS_ARRAY_HPP__
#define __PDS_ARRAY_HPP__


/** \defgroup ArrayGroup Métodos Pds::Array.
 *  \brief Metodos de la clase Pds::Array, una agrupación de 2 datos
 *  <div class="fragment"> \#include <Pds/Array> </div>
 *  
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <string>
#include <Pds/Size>
//#include <iostream>


namespace Pds{

/*! \class Array
 *  \brief La clase tipo  Array .
 *  Esta clase genera una agrupación de 2 datos.
 *  Para usar incluir Pds/Array.
 *  \ingroup ArrayGroup
 *  \author Fernando Pujaico Rivera
 */
template <typename Datum>
class Array
{
public:
    /*! Un arreglo de Nlin lineas y Ncol elementos por linea. */
    Datum **array;
    /*! Número de lineas. */
    unsigned int nlin;
    /*! Número de columnas. */
    unsigned int ncol;
    
public:

/** @name Varios tipos de constructores Pds::Array
 *  Crean una objeto Pds::Array
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Array
     *  \return un objeto de tipo Pds::Array.
     *  \ingroup ArrayGroup
     */
    Array(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Array
     *  \param[in] Nlin El numero de lineas de la array.
     *  \param[in] Ncol El numero de columnas de la array.
     *  \return un objeto de tipo Pds::Array.
     *  \ingroup ArrayGroup
     */
    Array(unsigned int Nlin,unsigned int Ncol);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Array
     *  \param[in] Nlin El numero de lineas de la array.
     *  \param[in] Ncol El numero de columnas de la array.
     *  \param[in] val El valor a usar.
     *  \return un objeto de tipo Pds::Array.
     *  \ingroup ArrayGroup
     */
    Array(unsigned int Nlin,unsigned int Ncol,Datum val);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Array con elementos inicializados con cero.
     * 
   Para crear una array A de 4 filas y 3 columnas:
\code{.cpp}
    Pds::Array B(4,3);
    Pds::Array A(B.Size);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] S El tamaño de la array.
     *  \ingroup ArrayGroup
     */
    Array(const Pds::Size &S);

    /** 
     *  \brief Crea un objeto de tipo Pds::Array copiando datos desde 
     *  otra array. Este es un Copy assignment constructor.
     * 
   Para crear una array A con copia de datos de una array B:
\code{.cpp}
    Pds::Array B(4,3,-1.0);
    Pds::Array A(B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \ingroup ArrayGroup
     */
    Array(const Pds::Array<Datum> &B);

    ~Array(); 

/**
 * @}
 */

public:

/** @name Métodos de asignacion Pds::Array
 *  Indican o establecen el estado de una array.
 * @{
 */

    /** 
     *  \brief Copia en si mismo (A), una array B. Este operador es 
     *  similar al método Copy().
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     * Cuando acontece:
\code{.cpp}
    Pds::Array B(nlin,ncol);
    A=B;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Array A=Pds::Array(nlin,ncol);
\endcode
     *  \param[in] B la array a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una array vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup ArrayGroup
     */
    Pds::Array<Datum>& operator = (const Pds::Array<Datum> &B);
    
    /** 
     *  \brief Copia en si mismo (A), el contenido de una array B. Este 
     *  método es similar a usar el operador = .
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     *  \param[in] B la array a copiar
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el receptor no altera su contenido.
     *  \see Copy
     *  \ingroup ArrayGroup
     */
    bool Copy(const Pds::Array<Datum> &B);
    
/**
 * @}
 */

public:

/** @name Métodos de estado Pds::Array
 *  Indican o establecen el estado de una array.
 * @{
 */

    /** 
     *  \brief Verifica si la array es nula es decir con lineas o columnas cero o arreglo NULL.
     *  
     *  Una array\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]\f$.
     *  \return Retorna true si es nula e false si no.
     *  \ingroup ArrayGroup
     */
    bool IsEmpty(void) const;

    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una array\f$A_{M,N}\f$ es similar a \f$B_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son similares y true si no.
     *  \ingroup ArrayGroup
     */
    bool IsNotSimilarTo(const Pds::Array<Datum> &B) const;


/**
 * @}
 */

public:

/** @name Métodos de fill  Pds::Array
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    /** 
     *  \brief Inicializa la array con números con unos y ceros con una probabilidad de 1 igual a p1.
     *
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
     *  \param[in] p1 Probabilidad de encontrar un 1.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup ArrayGroup
     */
    bool FillRandC(double p1);
/**
 * @}
 */

public:

/** @name Métodos de tamaño Pds::Array
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    
    /** 
     *  \brief Retorna el numero de lineas de la array.
     *  \return Retorna el numero de lineas de la array.
     *  \ingroup ArrayGroup
     */
    unsigned int Nlin(void) const;
    
    /** 
     *  \brief Retorna el numero de columnas de la array.
     *  \return Retorna el numero de columnas de la array.
     *  \ingroup ArrayGroup
     */
    unsigned int Ncol(void) const;
    
    /** 
     *  \brief Retorna el numero de elementos de la array (Nlin x Ncol).
     *  \return Retorna el numero de elementos de la array.
     *  \ingroup ArrayGroup
     */
    unsigned int Nel(void) const;
    
    /** 
     *  \brief Retorna un objeto de tipo Pds::Size con el numero de lineas y columans.
     *  \return Retorna el tamano de la array.
     *  \ingroup ArrayGroup
     */
    Pds::Size Size(void) const;


/**
 * @}
 */

public:

/** @name Métodos get y set de elementos Pds::Array.
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    /** 
     *  \brief Retorna una variable Datum en la posición (lin,col) de la array. 
     *  Hace una verificación para evitar leer o escribir fuera de la memoria, 
     *  si no está retorna zero 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna una variable Datum en la posición (lin,col). 
     *  \ingroup ArrayGroup
     */
    Datum Get(unsigned int lin,unsigned int col) const;

    /** 
     *  \brief Establece una variable Datum en la posición (lin,col) de la array. 
     *  Hace una verificación para evitar escribir fuera de la memoria, 
     *  si no está retorna false y no escribe nada. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \param[in] val valor a escribir.
     *  \return Retorna true si todo fue bien o false si no. 
     *  \ingroup ArrayGroup
     */
    bool Set(unsigned int lin,unsigned int col,Datum val);

    /** 
     *  \brief Retorna una variable Datum en la posición (lin,col) de la array. 
     *  Hace una verificación para evitar leer o escribir fuera de la memoria, 
     *  con este fin hace lin=lin%Nlin y col=col%Ncol. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna una variable Datum en la posición (lin,col). 
     *  \ingroup ArrayGroup
     */
    Datum &At(unsigned int lin,unsigned int col);

    /** 
     *  \brief Retorna una variable Datum en la posición (id) de la array. 
     *  Hace una verificación para evitar leer o escribir fuera de la memoria, 
     *  con este fin hace id=id%(Nlin*Ncol). 
     *  \param[in] id La posicion en consulta.
     *  \return Retorna una variable Datum en la posición (id). 
     *  \ingroup ArrayGroup
     */
    Datum &At(unsigned int id);
/**
 * @}
 */
    
public:

/** @name Imprimir datos Pds::Array.
 *  Muestra los datos
 * @{
 */


    /** 
     *  \brief libera los datos internos de la array y la convierte en una array nula.
     *  es decir con lineas y columnas cero.
     * 
     *  Una array\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]_{0,0}\f$.
     *  \ingroup ArrayGroup
     */
    void MakeEmpty(void);

    /** 
     *  \brief Imprime en pantalla el contenido del array.
     *  \param[in] str cadena de texto que se mostrara antes del elemento.
     *  \ingroup ArrayGroup
     */
    void Print(std::string str) const;
    
    /** 
     *  \brief Imprime en pantalla el contenido del array.
     *  \ingroup ArrayGroup
     */
    void Print(void) const;
/**
 * @}
 */
   

}; // Class Array


} // namespace Pds



/*!
 * @}
 */

#endif

