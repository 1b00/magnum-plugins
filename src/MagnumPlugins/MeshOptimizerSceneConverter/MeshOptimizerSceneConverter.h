#ifndef Magnum_Trade_MeshOptimizerSceneConverter_h
#define Magnum_Trade_MeshOptimizerSceneConverter_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019
              Vladimír Vondruš <mosra@centrum.cz>

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
 * @brief Class @ref Magnum::Trade::MeshOptimizerSceneConverter
 * @m_since_latest_{plugins}
 */

#include <Magnum/Trade/AbstractSceneConverter.h>

#include "MagnumPlugins/MeshOptimizerSceneConverter/configure.h"

#ifndef DOXYGEN_GENERATING_OUTPUT
#ifndef MAGNUM_MESHOPTIMIZERSCENECONVERTER_BUILD_STATIC
    #ifdef MeshOptimizerSceneConverter_EXPORTS
        #define MAGNUM_MESHOPTIMIZERSCENECONVERTER_EXPORT CORRADE_VISIBILITY_EXPORT
    #else
        #define MAGNUM_MESHOPTIMIZERSCENECONVERTER_EXPORT CORRADE_VISIBILITY_IMPORT
    #endif
#else
    #define MAGNUM_MESHOPTIMIZERSCENECONVERTER_EXPORT CORRADE_VISIBILITY_STATIC
#endif
#define MAGNUM_MESHOPTIMIZERSCENECONVERTER_LOCAL CORRADE_VISIBILITY_LOCAL
#else
#define MAGNUM_MESHOPTIMIZERSCENECONVERTER_EXPORT
#define MAGNUM_MESHOPTIMIZERSCENECONVERTER_LOCAL
#endif

namespace Magnum { namespace Trade {

/**
@brief MeshOptimizer converter plugin
@m_since_latest_{plugins}

Integrates various algorithms from [meshoptimizer](https://github.com/zeux/meshoptimizer).

@m_class{m-block m-success}

@thirdparty This plugin makes use of the
    [meshoptimizer](https://github.com/zeux/meshoptimizer) library by Arseny
    Kapoulkine, released under @m_class{m-label m-success} **MIT**
    ([license text](https://github.com/zeux/meshoptimizer/blob/master/LICENSE.md),
    [choosealicense.com](https://choosealicense.com/licenses/mit/)).

TODO: document how to build the dependency, show subproject usage also
TODO: list operations, configuration, ....

@section Trade-MeshOptimizerSceneConverter-usage Usage

This plugin depends on the @ref Trade library and is built if
`WITH_MESHOPTIMIZERSCENECONVERTER` is enabled when building Magnum Plugins. To
use as a dynamic plugin, load @cpp "MeshOptimizerSceneConverter" @ce via
@ref Corrade::PluginManager::Manager.

Additionally, if you're using Magnum as a CMake subproject, bundle the
[magnum-plugins repository](https://github.com/mosra/magnum-plugins) and do the
following:

@code{.cmake}
set(WITH_MESHOPTIMIZERSCENECONVERTER ON CACHE BOOL "" FORCE)
add_subdirectory(magnum-plugins EXCLUDE_FROM_ALL)

# So the dynamically loaded plugin gets built implicitly
add_dependencies(your-app MagnumPlugins::MeshOptimizerSceneConverter)
@endcode

To use as a static plugin or as a dependency of another plugin with CMake, put
[FindMagnumPlugins.cmake](https://github.com/mosra/magnum-plugins/blob/master/modules/FindMagnumPlugins.cmake)
into your `modules/` directory, request the `MeshOptimizerSceneConverter` component of
the `MagnumPlugins` package and link to the
`MagnumPlugins::MeshOptimizerSceneConverter` target:

@code{.cmake}
find_package(MagnumPlugins REQUIRED MeshOptimizerSceneConverter)

# ...
target_link_libraries(your-app PRIVATE MagnumPlugins::MeshOptimizerSceneConverter)
@endcode

See @ref building-plugins, @ref cmake-plugins and @ref plugins for more
information.
*/
class MAGNUM_MESHOPTIMIZERSCENECONVERTER_EXPORT MeshOptimizerSceneConverter: public AbstractSceneConverter {
    public:
        /** @brief Plugin manager constructor */
        explicit MeshOptimizerSceneConverter(PluginManager::AbstractManager& manager, const std::string& plugin);

        ~MeshOptimizerSceneConverter();

    private:
        MAGNUM_MESHOPTIMIZERSCENECONVERTER_LOCAL SceneConverterFeatures doFeatures() const override;

        MAGNUM_MESHOPTIMIZERSCENECONVERTER_LOCAL bool doConvertInPlace(MeshData& mesh) override;
};

}}

#endif
