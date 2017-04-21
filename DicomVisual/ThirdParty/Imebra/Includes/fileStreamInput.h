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

/*! \file fileStreamInput.h
    \brief Declaration of the FileStreamInput class.

*/

#if !defined(imebraFileStreamInput__INCLUDED_)
#define imebraFileStreamInput__INCLUDED_

#include <string>
#include "baseStreamInput.h"
#include "definitions.h"

namespace imebra
{

///
/// \brief Represents an input file stream.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API FileStreamInput : public BaseStreamInput
{
    FileStreamInput(const FileStreamInput&) = delete;
    FileStreamInput& operator=(const FileStreamInput&) = delete;

public:
    /// \brief Constructor.
    ///
    /// \param name the path to the file to open in read mode
    ///
    ///////////////////////////////////////////////////////////////////////////////
#ifndef SWIG // Use only UTF-8 strings with SWIG
    FileStreamInput(const std::wstring& name);
#endif

    /// \brief Constructor.
    ///
    /// \param name the path to the file to open in read mode, in encoded in UTF8
    ///
    ///////////////////////////////////////////////////////////////////////////////
    FileStreamInput(const std::string& name);


    /// \brief Destructor. Closes the file.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ~FileStreamInput();
};

}
#endif // !defined(imebraFileStreamInput__INCLUDED_)
