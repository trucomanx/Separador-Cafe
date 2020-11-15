/*
 * RaFile.hpp
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

/** \file RaFile.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición herramientas para a biblioteca Ra.
 *  
 */
    
    
#ifndef __PDS_RAFILE_HPP__
#define __PDS_RAFILE_HPP__
    
#include <string>
#include <cstdio>
#include <list>

/** \defgroup PdsRaFileGroup Extras Pds::Ra -- File
 *  \brief Funciones con archivos: Pds::Ra::ElementsInFile(), etc
 *  <div class="fragment"> \#include <Pds/RaFile> </div>
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacio para RA (Real Arrays)
 *  \ingroup PdsRaFileGroup
 */
namespace Ra{


/** @name Trabajar con archivos
 *  Salva datos de matrices
 * @{
 */

    /** 
     *  \brief Retorna el número de lineas significativas de un archivo.
     *  Se asume que es un archivo de texto.
     *
     *  Una linea no significativa solo contiene white-spaces:
    \code{.h}
    ' '     (0x20)	space (SPC)
    '\t'    (0x09)	horizontal tab (TAB)
    '\n'    (0x0a)	newline (LF)
    '\v'    (0x0b)	vertical tab (VT)
    '\f'    (0x0c)	feed (FF)
    '\r'    (0x0d)	carriage return (CR)
    \endcode
     *  \param[in] filepath Dirección de archivo a testar.
     *  \return Retorna el número de lineas significativas de un archivo
     *  o negativo en caso de error
     *  \ingroup PdsRaFileGroup
     */
    long SignificativeLinesInFile(const char*filepath);


    /** 
     *  \brief Retorna el número de elementos de un archivo.
     *  Se asume que es un archivo de texto.
     *
     *  Una un elemento e cualquier grupo de caracteres con elementos que no contienen white-spaces:
    \code{.h}
    ' '     (0x20)	space (SPC)
    '\t'    (0x09)	horizontal tab (TAB)
    '\n'    (0x0a)	newline (LF)
    '\v'    (0x0b)	vertical tab (VT)
    '\f'    (0x0c)	feed (FF)
    '\r'    (0x0d)	carriage return (CR)
    \endcode
     *  \param[in] filepath Dirección de archivo a testar.
     *  \param[out] Nel Variable donde se guardara el numero de elementos.
     *  \return Retorna true si todo fue bien o false si no. Si fue retornado false
     *  entonces Nel no es modificado.
     *  \ingroup PdsRaFileGroup
     */
    bool ElementsInFile(const char*filepath,unsigned int &Nel);

    /** 
     *  \brief Retorna el número de lineas significativas y columnas de un archivo.
     *  Se asume que es un archivo de texto.
     *
     *  Una linea no significativa solo contiene white-spaces:
    \code{.h}
    ' '     (0x20)	space (SPC)
    '\t'    (0x09)	horizontal tab (TAB)
    '\n'    (0x0a)	newline (LF)
    '\v'    (0x0b)	vertical tab (VT)
    '\f'    (0x0c)	feed (FF)
    '\r'    (0x0d)	carriage return (CR)
    \endcode
     *  \param[in] filepath Dirección de archivo a testar.
     *  \param[out] Nlin Variable donde se guardara el numero de lineas.
     *  \param[out] Ncol Variable donde se guardara el numero de columnas.
     *  \return Retorna true si todo fue bien o false si no. Si el numero de columnas 
     *  no es constante entonces se retorna false. Si fue retornado false
     *  entonces Nlin y Ncol no son modificados. 
     *  \ingroup PdsRaFileGroup
     */
    bool ArraySizeInFile(const char*filepath,unsigned int &Nlin,unsigned int &Ncol);

    /** 
     *  \brief Retorna una linea leida desde un desriptor de fichero de texto.
     *  No descarta el salto de linea '\\n' y no descarta 1 retorno de carro '\\r' 
     *  si este existe depues del salto de linea.
     *
     *  \param[in] fd Descriptor de fichero de texto a analizar.
     *  \return Retorna una nueva cadena de texto con una copia de la linea leida 
     *  incluyendo los caracteres de control finales exepto EOF.
     *  \ingroup PdsRaToolsGroup
     */
    char *Fgets(FILE *fd);

/**
 * @}
 */

    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_RAFILE_HPP__ */
