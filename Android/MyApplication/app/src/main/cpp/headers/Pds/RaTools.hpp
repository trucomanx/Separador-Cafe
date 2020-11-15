/*
 * RaTools.hpp
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

/** \file RaTools.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición herramientas para a biblioteca Ra.
 *  
 */
    
    
#ifndef __PDS_RATOOLS_HPP__
#define __PDS_RATOOLS_HPP__
    
#include <string>
#include <list>

/** \defgroup PdsRaToolsGroup Extras Pds::Ra -- Version
 *  \brief Funciones con datos de la biblioteca: Pds::Ra::Package(), etc
 *  <div class="fragment"> \#include <Pds/RaTools> </div>
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacio para RA (Real Arrays)
 *  \ingroup PdsRaToolsGroup
 */
namespace Ra{


/** @name Datos de la biblioteca
 *  Datos importantes de la biblioteca.
 * @{
 */

/** 
 *  \brief Retorna la versión de la biblioteca.
 *
 *  Given a version number MAJOR.MINOR.PATCH, increment the:
 *
 *  - MAJOR version when you make incompatible API changes,
 *  - MINOR version when you add functionality in a backwards-compatible manner, and
 *  - PATCH version when you make backwards-compatible bug fixes.
 *
 *  \return Retorna la versión de la biblioteca.
 *  \ingroup PdsRaToolsGroup
 */
std::string Version(void);


/** 
 *  \brief Imprime em pantalla la versión de la biblioteca, imprime un salto de linea al final.
 *
 *  \param[in] str Texto a mostrar antes de la version
 *  \ingroup PdsRaToolsGroup
 */
void PrintVersion(std::string str);

/** 
 *  \brief Retorna el nombre de la biblioteca.
 *
 *  \return Retorna el nombre de la biblioteca.
 *  \ingroup PdsRaToolsGroup
 */
std::string Package(void);


/** 
 *  \brief Imprime em pantalla el nombre de la biblioteca, imprime un salto de linea al final.
 *
 *  \param[in] str Texto a mostrar antes del nombre
 *  \ingroup PdsRaToolsGroup
 */
void PrintPackage(std::string str);
/**
 * @}
 */

/** @name Variados
 *  Funciones interesantes
 * @{
 */
/**
 *  \brief Inicializa las funcion rand y las funciones que la usan.
 *  
 *  \ingroup PdsRaToolsGroup
 */
void Randomize(void);

/**
 *  \brief Indica si es big endian
 *  
 *  \return Retorna true es bigendian o false en caso contrario.
 *  \ingroup PdsRaToolsGroup
 */
bool IsBigEndian(void);

/**
 * @}
 */
    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_RATOOLS_HPP__ */
