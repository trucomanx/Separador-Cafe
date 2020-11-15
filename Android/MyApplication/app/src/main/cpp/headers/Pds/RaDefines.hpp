/*
 * RaDefines.hpp
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

/** \file RaDefines.hpp
 * \brief Archivo de definición de macro defines.
 * 
 */
    


    
#ifndef __PDS_RADEFINES_HPP__
#define __PDS_RADEFINES_HPP__
    
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>


/** \defgroup DefinesGroup Extras Pds::Ra -- Constantes y Defines
 *  \brief Constantes y macros: pds_print_error_message(), Pds::Ra::WarningRCond, etc
 *  <div class="fragment"> \#include <Pds/RaDefines> </div>
 *  
 * @{
 */


/** @name Defines varios
 *  Muchos tipos de defines
 * @{
 */
#ifndef __CURRENT_FILENAME__
#define __CURRENT_FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif    
    
#ifndef pds_print_error_message
/*!
 * \def pds_print_error_message
 * Mensaje de error.
 * \ingroup DefinesGroup
*/
#define pds_print_error_message(msg) \
    std::cout<<"----ERROR :: "<<__CURRENT_FILENAME__<<" -- "<<__PRETTY_FUNCTION__<<" -- line "<<__LINE__<<std::endl \
    <<"----ERROR :: "<<msg<<std::endl
#endif

    
    
#ifndef pds_print_warning_message
/*!
 * \def pds_print_warning_message
 * Mensaje de advertencia.
 * \ingroup DefinesGroup
*/
#define pds_print_warning_message(msg) \
    std::cout<<"--WARNING :: "<<msg<<std::endl
#endif
    
    
#ifndef pds_print_info_message
/*!
 * \def pds_print_info_message
 * Mensaje con informaciones genericas.
 * \ingroup DefinesGroup
*/
#define pds_print_info_message(msg) \
    std::cout<<"-----INFO :: "<<msg<<std::endl
#endif
    
    
/*!
 * @}
 */
    
    
namespace Pds{
namespace Ra{
    
/** @name Variables Matemáticas
 *  Muchos tipos de defines
 * @{
 */

    /*!
     * Número PI.
     * \ingroup DefinesGroup
    */
    const double Pi =3.14159265358979323846264338327950288;
    
    /*!
     * Número aureo.
     * \ingroup DefinesGroup
    */
    const double Phi=1.61803398874989484820458683436563811;
    
    /*!
     * Número de decimales a mostrar cuando se imprime en pantalla o en archivo.
     * \ingroup DefinesGroup
    */
    const unsigned int StringPrecision=14;
    
    /*!
     * Valor minimo que puede tener rcond, abajo de este valor será mostrado un mensaje en pantalla.
     * \ingroup DefinesGroup
    */
    const double WarningRCond=0.000000001;
    
    /*!
     * Factor de conversión de grados a radianes.
     * \ingroup DefinesGroup
    */
    const double ToRadians =Pi/180.0;
    
    /*!
     * Not A Number.
     * \ingroup DefinesGroup
    */
    const double Nan=nan("");
    
    
/*!
 * @}
 */


/** @name Enumeraciones
 *  Muchos tipos de defines
 * @{
 */

    /*!
     * \brief Tipo de dato en la carga de información desde archivo.
     *
     * Cuando existe una carga de datos esta puede proceder de varios tipos de fuentes.
     * \ingroup DefinesGroup
    */
    typedef enum {
        /*!
         *  Formato de texto.
         */
        TextFormat=0,
        /*!
         *  Formato compatible con archivo binario de octave.
         */
        MatFileFormat, 
    } FormatType;

    
/*!
 * @}
 */


    
}
}

/*!
 * @}
 */
    
    
#endif /* __PDS_RADEFINES_HPP__ */
