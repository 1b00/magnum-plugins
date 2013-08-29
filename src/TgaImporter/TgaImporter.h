#ifndef Magnum_Trade_TgaImporter_h
#define Magnum_Trade_TgaImporter_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013 Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Class Magnum::Trade::TgaImporter
 */

#include <Utility/Visibility.h>
#include <Trade/AbstractImporter.h>

#ifndef DOXYGEN_GENERATING_OUTPUT
#if defined(TgaImporter_EXPORTS) || defined(TgaImporterObjects_EXPORTS)
    #define MAGNUM_TRADE_TGAIMPORTER_EXPORT CORRADE_VISIBILITY_EXPORT
#else
    #define MAGNUM_TRADE_TGAIMPORTER_EXPORT CORRADE_VISIBILITY_IMPORT
#endif
#define MAGNUM_TRADE_TGAIMPORTER_LOCAL CORRADE_VISIBILITY_LOCAL
#endif

namespace Magnum { namespace Trade {

/**
@brief TGA image importer

Supports uncompressed BGR, BGRA or grayscale images with 8 bits per channel.

The images are imported with @ref ImageType::UnsignedByte and @ref ImageFormat::BGR,
@ref ImageFormat::BGRA or @ref ImageFormat::Red, respectively. Grayscale images
require extension @extension{ARB,texture_rg}.

In OpenGL ES BGR and BGRA images are converted to @ref ImageFormat::RGB
and @ref ImageFormat::RGBA. In OpenGL ES 2.0, if @es_extension{EXT,texture_rg}
is not supported, grayscale images use @ref ImageFormat::Luminance instead of
@ref ImageFormat::Red.
*/
class MAGNUM_TRADE_TGAIMPORTER_EXPORT TgaImporter: public AbstractImporter {
    public:
        /** @brief Default constructor */
        explicit TgaImporter();

        /** @brief Plugin manager constructor */
        explicit TgaImporter(PluginManager::AbstractManager* manager, std::string plugin);

        ~TgaImporter();

    private:
        Features MAGNUM_TRADE_TGAIMPORTER_LOCAL doFeatures() const override;
        bool MAGNUM_TRADE_TGAIMPORTER_LOCAL doIsOpened() const override;
        void MAGNUM_TRADE_TGAIMPORTER_LOCAL doOpenData(Containers::ArrayReference<const unsigned char> data) override;
        void MAGNUM_TRADE_TGAIMPORTER_LOCAL doOpenFile(const std::string& filename) override;
        void MAGNUM_TRADE_TGAIMPORTER_LOCAL doClose() override;
        UnsignedInt MAGNUM_TRADE_TGAIMPORTER_LOCAL doImage2DCount() const override;
        ImageData2D MAGNUM_TRADE_TGAIMPORTER_LOCAL * doImage2D(UnsignedInt id) override;

        std::istream* in;
};

}}

#endif
