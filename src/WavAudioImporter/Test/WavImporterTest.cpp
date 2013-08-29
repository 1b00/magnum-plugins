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

#include <sstream>
#include <Containers/Array.h>
#include <TestSuite/Tester.h>
#include <Utility/Directory.h>

#include "WavAudioImporter/WavImporter.h"

#include "configure.h"

namespace Magnum { namespace Audio { namespace Test {

class WavImporterTest: public TestSuite::Tester {
    public:
        explicit WavImporterTest();

        void wrongSize();
        void wrongSignature();
        void unsupportedFormat();
        void unsupportedChannelCount();
        void mono16();
        void stereo8();
};

WavImporterTest::WavImporterTest() {
    addTests({&WavImporterTest::wrongSize,
              &WavImporterTest::wrongSignature,
              &WavImporterTest::unsupportedFormat,
              &WavImporterTest::unsupportedChannelCount,
              &WavImporterTest::mono16,
              &WavImporterTest::stereo8});
}

void WavImporterTest::wrongSize() {
    std::ostringstream out;
    Error::setOutput(&out);

    WavImporter importer;
    CORRADE_VERIFY(!importer.openData(Containers::Array<unsigned char>(43)));
    CORRADE_COMPARE(out.str(), "Audio::WavImporter::openData(): the file is too short: 43 bytes\n");
}

void WavImporterTest::wrongSignature() {
    std::ostringstream out;
    Error::setOutput(&out);

    WavImporter importer;
    CORRADE_VERIFY(!importer.openFile(Utility::Directory::join(WAVAUDIOIMPORTER_TEST_DIR, "wrongSignature.wav")));
    CORRADE_COMPARE(out.str(), "Audio::WavImporter::openData(): the file signature is invalid\n");
}

void WavImporterTest::unsupportedFormat() {
    std::ostringstream out;
    Error::setOutput(&out);

    WavImporter importer;
    CORRADE_VERIFY(!importer.openFile(Utility::Directory::join(WAVAUDIOIMPORTER_TEST_DIR, "unsupportedFormat.wav")));
    CORRADE_COMPARE(out.str(), "Audio::WavImporter::openData(): unsupported audio format 2\n");
}

void WavImporterTest::unsupportedChannelCount() {
    std::ostringstream out;
    Error::setOutput(&out);

    WavImporter importer;
    CORRADE_VERIFY(!importer.openFile(Utility::Directory::join(WAVAUDIOIMPORTER_TEST_DIR, "unsupportedChannelCount.wav")));
    CORRADE_COMPARE(out.str(), "Audio::WavImporter::openData(): unsupported channel count 6 with 8 bits per sample\n");
}

void WavImporterTest::mono16() {
    WavImporter importer;
    CORRADE_VERIFY(importer.openFile(Utility::Directory::join(WAVAUDIOIMPORTER_TEST_DIR, "mono16.wav")));

    CORRADE_COMPARE(importer.format(), Buffer::Format::Mono16);
    CORRADE_COMPARE(importer.frequency(), 44000);
    Containers::Array<unsigned char> data = importer.data();
    CORRADE_COMPARE(data.size(), 4);
    CORRADE_COMPARE(data[0], 0x1d);
    CORRADE_COMPARE(data[1], 0x10);
    CORRADE_COMPARE(data[2], 0x71);
    CORRADE_COMPARE(data[3], 0xC5);
}

void WavImporterTest::stereo8() {
    WavImporter importer;
    CORRADE_VERIFY(importer.openFile(Utility::Directory::join(WAVAUDIOIMPORTER_TEST_DIR, "stereo8.wav")));

    CORRADE_COMPARE(importer.format(), Buffer::Format::Stereo8);
    CORRADE_COMPARE(importer.frequency(), 96000);
    Containers::Array<unsigned char> data = importer.data();
    CORRADE_COMPARE(data.size(), 4);
    CORRADE_COMPARE(data[0], 0xde);
    CORRADE_COMPARE(data[1], 0xfe);
    CORRADE_COMPARE(data[2], 0xca);
    CORRADE_COMPARE(data[3], 0x7e);
}

}}}

CORRADE_TEST_MAIN(Magnum::Audio::Test::WavImporterTest)
