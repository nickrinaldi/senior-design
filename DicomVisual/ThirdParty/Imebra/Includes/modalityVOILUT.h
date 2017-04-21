/*

Imebra 4.0.8.1 changeset b15762068bd2

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016
by Paolo Brandoli/Binarno s.p.

All rights reserved.

This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as published by
 the Free Software Foundation.

This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

-------------------

If you want to use Imebra commercially then you have to buy the commercial
 license available at http://imebra.com

After you buy the commercial license then you can use Imebra according
 to the terms described in the Imebra Commercial License.
A copy of the Imebra Commercial License is available at http://imebra.com.

Imebra is available at http://imebra.com

The author can be contacted by email at info@binarno.com or by mail at
 the following address:
 Binarno s.p., Paolo Brandoli
 Rakuseva 14
 1000 Ljubljana
 Slovenia



*/

/*! \file modalityVOILUT.h
    \brief Declaration of the class ModalityVOILUT.

*/

#if !defined(imebraModalityVOILUT__INCLUDED_)
#define imebraModalityVOILUT__INCLUDED_

#include "transform.h"
#include "dataSet.h"
#include "definitions.h"

namespace imebra
{


///
/// \brief The ModalityVOILUT transform applies the Modality VOI or LUT
///        to the input image.
///
/// The Modality VOI/LUT applies a rescale intercept and a slope
/// to transform the pixel values of the image into values that are meaningful
/// to the application.
///
/// For instance, the original pixel values could store a device specific
/// value that has a meaning only when used by the device that generated it:
/// applying the rescale slope/intercept to pixel value converts the original
/// values into optical density or other known measurement units
/// (e.g. Hounsfield).
///
/// When the transformation is not linear, then a LUT (lookup table) is
/// applied.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API ModalityVOILUT: public Transform
{
    ModalityVOILUT(const ModalityVOILUT&) = delete;
    ModalityVOILUT& operator=(const ModalityVOILUT&) = delete;

public:
    /// \brief Constructor.
    ///
    /// \param dataset the DataSet from which the modality VOI or LUT data
    ///                is retrieved
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ModalityVOILUT(const DataSet& dataset);

    virtual ~ModalityVOILUT();
};

}

#endif // imebraModalityVOILUT__INCLUDED_
