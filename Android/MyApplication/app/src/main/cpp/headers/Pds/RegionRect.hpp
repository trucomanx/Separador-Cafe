/*
 * RegionRect.hpp
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

/** \file RegionRect.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices columna.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de Nlinx1"
 *  \b Nlin es el número de lineas.
 */



#ifndef __PDS_REGIONRECT_HPP__
#define __PDS_REGIONRECT_HPP__


/** \defgroup RegionRectGroup Métodos Pds::RegionRect
 *  \brief Metodos de la clase Pds::RegionRect
 *  <div class="fragment"> \#include <Pds/RegionRect> </div>
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <sstream>      // std::ostringstream

namespace Pds{

class Matrix;

/*! 
 *  \brief La estructura tipo  Pds::RegionRect .
 *  Esta estructura genera una region.
 *  Para usar incluir <Pds/RegionRect>.
 *  \ingroup RegionRectGroup
 *  \author Fernando Pujaico Rivera
 */
class RegionRect
{
public:
	/*! Linea inicial */
	int L0;
	/*! Columna inicial */
	int C0;
	/*! Numero de Lineas */
	unsigned int Nlin;
	/*! Numero de Columnas */
	unsigned int Ncol;
public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::RegionRect
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::RegionRect
     *  \return un objeto de tipo Pds::RegionRect.
     *  \ingroup RegionRectGroup
     */
    RegionRect(void);
    

    /** 
     *  \brief Crea la variable Pds::RegionRect.
     *  \param[in] L0 Linea inicial.
     *  \param[in] C0 Columna inicial.
     *  \param[in] Nlin Numero de lineas.
     *  \param[in] Ncol Numero de columnas.
     *  \return La variable Pds::RegionRect.
     *  \ingroup RegionRectGroup
     */
    RegionRect(int L0,int C0,unsigned int Nlin,unsigned int Ncol);
    
    ~RegionRect();

/**
 * @}
 */
    
public:

/** @name Variados
 *   
 * @{
 */
 
    /** 
     *  \brief Muestra en pantalla el contenido de Pds::RegionRect, elementos separados por tabulador.
     *  \param[in] str Texto a mostrar antes de imprimir el contenido.
     *  \ingroup RegionRectGroup
     */
    void Print(std::string str="") const;
 
    /** 
     *  \brief Muestra en pantalla el contenido de Pds::RegionRect, en el formato (l0,c0)[nlin,ncol].
     *  \param[in] str Texto a mostrar antes de imprimir el contenido.
     *  \ingroup RegionRectGroup
     */
    void PrintStylized(std::string str="") const;

    /** 
     *  \brief libera los datos internos de la region haciendola nula.
     *  es decir con todos los valores iguales cero.
     * 
     *  \ingroup RegionRectGroup
     */
    void MakeEmpty(void);
/**
 * @}
 */

/** @name Estado 
 *   
 * @{
 */
    /** 
     *  \brief Verifica si la region es nula es decir con lineas o columnas y anchos cero.
     *  
     *  \return Retorna true si es nula e false si no.
     *  \ingroup RegionRectGroup
     */
    bool IsEmpty(void) const;


    /** 
     *  \brief Indica si la region Rin está dentro de la region R.

     *  \param[in] R Region madre o contenedora.
     *  \return true si Rin está adentro de R, o false si no.
     *  \ingroup RegionRectGroup
     */
    bool IsInside(const Pds::RegionRect &R) const;


    /** 
     *  \brief Indica si la region Rin está dentro de la region de una matriz.

     *  \param[in] A Matriz a analizar.
     *  \return true si Rin está adentro de A, o false si no.
     *  \ingroup RegionRectGroup
     */
    bool IsInside(const Pds::Matrix &A) const;

/**
 * @}
 */


/** @name Movimientos
 *   
 * @{
 */

    /** 
     *  \brief mueve la posicion de la region suma R+(L,C).
     *  \param[in] DL Numero de lineas a sumar.
     *  \param[in] DC Numero de columnas a sumar.
     *  \return true si todo fue bien o false si no.
     *  \ingroup RegionRectGroup
     */
    bool Travel(int DL,int DC);

    /** 
     *  \brief Movimentada a (L0,C0).
     *  \param[in] L0 Nueva linea de origen.
     *  \param[in] C0 Nueva columna de origen
     *  \return true si todo fue bien o false si no.
     *  \ingroup RegionRectGroup
     */
    bool Move(int L0,int C0);

/**
 * @}
 */


/** @name Intersecta
 *   
 * @{
 */

    /** 
     *  \brief Intersecta la region actual con la region B.
     *  \param[in] B Segunda region.
     *  \return R Region de interesecion si existe, una region .IsEmpty() igual a true.
     *  \ingroup RegionRectGroup
     */
    Pds::RegionRect Intersection(const Pds::RegionRect &B) const;

/**
 * @}
 */


/** @name Save and load
 *   
 * @{
 */
    /** 
     *  \brief Imprime en un FILE la variable Pds::RegionRect.
     *  \param[in] fd File descriptor.
     *  \return If successful, the total number of characters written is returned. On failure, a negative number is returned.
     *  \ingroup RegionRectGroup
     */
    int FilePrint(FILE *fd) const;

    /** 
     *  \brief Carga de un FILE la variable Pds::RegionRect.
     * 
     *  Se espera que cada region este escrita en una linea, dentro de cada linea 
     *  los elementos son separados por white-spaces:
    \code{.h}
    ' '     (0x20)	space (SPC)
    '\t'    (0x09)	horizontal tab (TAB)
    '\n'    (0x0a)	newline (LF)
    '\v'    (0x0b)	vertical tab (VT)
    '\f'    (0x0c)	feed (FF)
    '\r'    (0x0d)	carriage return (CR)
    \endcode
     *  \param[in] fd File descriptor.
     *  \return true si todo esta bien, o false si no. En caso de error el 
     *  descriptor de fichero fd no es alterado, es decir vuelve a la posicion de inicio
     *  de lectura (No a la posicion del error).
     *  \ingroup RegionRectGroup
     */
    bool FileScan(FILE *fd);


    /** 
     *  \brief Carga la variable de tipo Pds::RegionRect desde una cadena data.
     * 
     *  Dentro de la cadena los elementos de la region son separados por white-spaces:
    \code{.h}
    ' '     (0x20)	space (SPC)
    '\t'    (0x09)	horizontal tab (TAB)
    '\n'    (0x0a)	newline (LF)
    '\v'    (0x0b)	vertical tab (VT)
    '\f'    (0x0c)	feed (FF)
    '\r'    (0x0d)	carriage return (CR)
    \endcode
     *  \param[in] str cadena a leer.
     *  \return true si todo esta bien, o false si no. En caso de error R no es modificado.
     *  \ingroup RegionRectGroup
     */
    bool LoadString(const std::string &str);

/**
 * @}
 */


}; // Class RegionRect

} // namespace Pds


/*!
 * @}
 */

#endif

