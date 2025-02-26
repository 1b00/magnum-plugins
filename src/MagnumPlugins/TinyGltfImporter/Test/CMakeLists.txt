#
#   This file is part of Magnum.
#
#   Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019,
#               2020, 2021 Vladimír Vondruš <mosra@centrum.cz>
#   Copyright © 2018 Tobias Stein <stein.tobi@t-online.de>
#   Copyright © 2018 Jonathan Hale <squareys@googlemail.com>
#
#   Permission is hereby granted, free of charge, to any person obtaining a
#   copy of this software and associated documentation files (the "Software"),
#   to deal in the Software without restriction, including without limitation
#   the rights to use, copy, modify, merge, publish, distribute, sublicense,
#   and/or sell copies of the Software, and to permit persons to whom the
#   Software is furnished to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be included
#   in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
#   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
#   DEALINGS IN THE SOFTWARE.
#

if(CORRADE_TARGET_EMSCRIPTEN OR CORRADE_TARGET_ANDROID)
    set(TINYGLTFIMPORTER_TEST_DIR ".")
else()
    set(TINYGLTFIMPORTER_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# CMake before 3.8 has broken $<TARGET_FILE*> expressions for iOS (see
# https://gitlab.kitware.com/cmake/cmake/merge_requests/404) and since Corrade
# doesn't support dynamic plugins on iOS, this sorta works around that. Should
# be revisited when updating Travis to newer Xcode (xcode7.3 has CMake 3.6).
if(NOT MAGNUM_TINYGLTFIMPORTER_BUILD_STATIC)
    set(TINYGLTFIMPORTER_PLUGIN_FILENAME $<TARGET_FILE:TinyGltfImporter>)
    if(WITH_BASISIMPORTER)
        set(BASISIMPORTER_PLUGIN_FILENAME $<TARGET_FILE:BasisImporter>)
    endif()
    if(WITH_STBIMAGEIMPORTER)
        set(STBIMAGEIMPORTER_PLUGIN_FILENAME $<TARGET_FILE:StbImageImporter>)
    endif()
endif()

# First replace ${} variables, then $<> generator expressions
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/configure.h.cmake
               ${CMAKE_CURRENT_BINARY_DIR}/configure.h.in)
file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/configure.h
    INPUT ${CMAKE_CURRENT_BINARY_DIR}/configure.h.in)

corrade_add_resource(TinyGltfImporterTest_RESOURCES resources.conf)

corrade_add_test(TinyGltfImporterTest
    TinyGltfImporterTest.cpp
    ${TinyGltfImporterTest_RESOURCES}
    LIBRARIES Magnum::Trade
    FILES
        empty.gltf
        empty.glb
        buffer-notfound.gltf
        buffer-notfound.glb
        buffer-no-uri.gltf
        buffer-no-uri.glb
        buffer-wrong-size.gltf
        buffer-wrong-size.glb
        animation.gltf
        animation.glb
        animation.bin
        animation-embedded.gltf
        animation-embedded.glb
        animation-invalid.gltf
        animation-invalid-node-oob.gltf
        animation-invalid-input-accessor-oob.gltf
        animation-invalid-sampler-oob.gltf
        animation-invalid-output-accessor-oob.gltf
        animation-missing-target-node.gltf
        animation-patching.bin
        animation-patching.gltf
        animation-splines-sharing.gltf
        camera.gltf
        camera.glb
        camera-invalid-type.gltf
        encoded-uris.gltf
        escaped-strings.gltf
        external-data.bin
        # external-data.* packed via a resource (but *.bin needed also by
        # buffer-wrong-size.gltf, so added separately as well)
        image.gltf
        image.glb
        image-embedded.gltf
        image-embedded.glb
        image-buffer.gltf
        image-buffer.glb
        image-buffer-embedded.gltf
        image-buffer-embedded.glb
        image-notfound.gltf
        image-basis.gltf
        image-basis.glb
        image-basis-embedded.gltf
        image-basis-embedded.glb
        light.gltf
        light.glb
        light-invalid.gltf
        light-invalid-color-size.gltf
        light-missing-type.gltf
        light-missing-spot.gltf
        material-common.gltf
        material-clearcoat.gltf
        material-invalid-alpha-mode.gltf
        material-invalid-clearcoat-factor-oob.gltf
        material-invalid-clearcoat-normal-oob.gltf
        material-invalid-clearcoat-roughness-oob.gltf
        material-invalid-emissive-oob.gltf
        material-invalid-normal-oob.gltf
        material-invalid-occlusion-oob.gltf
        material-invalid-pbr-base-color-oob.gltf
        material-invalid-pbr-diffuse-oob.gltf
        material-invalid-pbr-metallic-roughness-oob.gltf
        material-invalid-pbr-specular-oob.gltf
        material-metallicroughness.gltf
        material-phong-fallback.gltf
        material-specularglossiness.gltf
        material-texcoord-flip.bin
        material-texcoord-flip.gltf
        material-texcoord-flip-unnormalized.gltf
        material-unlit.gltf
        mesh.gltf
        mesh.bin
        mesh.glb
        mesh-colors.gltf
        mesh-colors.bin
        mesh-custom-attributes.bin
        mesh-custom-attributes.gltf
        mesh-duplicate-attributes.gltf
        mesh-embedded.gltf
        mesh-embedded.glb
        mesh-index-accessor-oob.gltf
        mesh-invalid.bin
        mesh-invalid.gltf
        mesh-invalid-accessor-oob.gltf
        mesh-invalid-buffer-oob.gltf
        mesh-invalid-bufferview-oob.gltf
        mesh-multiple-primitives.gltf
        mesh-primitives-types.gltf
        mesh-primitives-types.bin
        mesh-skin-attributes.gltf
        mesh-skin-attributes.bin
        mesh-unordered-attributes.gltf
        přívodní-šňůra.gltf
        přívodní-šňůra.bin
        přívodní-šňůra.png
        required-extensions.gltf
        required-extensions-unsupported.gltf
        scene.gltf
        scene.glb
        scene-cycle.gltf
        scene-cycle-deep.gltf
        scene-nodefault.gltf
        scene-nodefault.glb
        scene-invalid-camera-oob.gltf
        scene-invalid-child-not-root.gltf
        scene-invalid-child-oob.gltf
        scene-invalid-default-oob.gltf
        scene-invalid-light-oob.gltf
        scene-invalid-material-oob-multi-primitive.gltf
        scene-invalid-material-oob.gltf
        scene-invalid-mesh-oob.gltf
        scene-invalid-multiple-parents.gltf
        scene-invalid-node-oob.gltf
        scene-invalid-skin-oob-multi-primitive.gltf
        scene-invalid-skin-oob.gltf
        skin-embedded.glb
        skin-embedded.gltf
        skin-invalid.gltf
        skin-invalid-accessor-oob.gltf
        skin-invalid-joint-oob.gltf
        skin-no-joints.gltf
        skin.gltf
        skin.bin
        skin.glb
        object-transformation.gltf
        object-transformation.glb
        object-transformation-patching.gltf
        texture.basis
        texture.gltf
        texture.glb
        texture.png
        texture-default-sampler.gltf
        texture-default-sampler.glb
        texture-empty-sampler.gltf
        texture-empty-sampler.glb
        texture-extensions.gltf
        texture-extensions-invalid.gltf
        texture-extensions-invalid-basisu-oob.gltf
        texture-invalid.gltf
        texture-invalid-image-oob.gltf
        texture-invalid-sampler-oob.gltf
        texture-missing-source.gltf
        version-legacy.gltf
        version-supported.gltf
        version-unsupported.gltf
        version-unsupported-min.gltf)
target_include_directories(TinyGltfImporterTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>)
if(MAGNUM_TINYGLTFIMPORTER_BUILD_STATIC)
    target_link_libraries(TinyGltfImporterTest PRIVATE TinyGltfImporter)
    if(WITH_BASISIMPORTER)
        target_link_libraries(TinyGltfImporterTest PRIVATE BasisImporter)
    endif()
    if(WITH_STBIMAGEIMPORTER)
        target_link_libraries(TinyGltfImporterTest PRIVATE StbImageImporter)
    endif()
else()
    # So the plugins get properly built when building the test
    add_dependencies(TinyGltfImporterTest TinyGltfImporter)
    if(WITH_BASISIMPORTER)
        add_dependencies(TinyGltfImporterTest BasisImporter)
    endif()
    if(WITH_STBIMAGEIMPORTER)
        add_dependencies(TinyGltfImporterTest StbImageImporter)
    endif()
endif()
set_target_properties(TinyGltfImporterTest PROPERTIES FOLDER "MagnumPlugins/TinyGltfImporter/Test")
if(CORRADE_BUILD_STATIC AND NOT MAGNUM_TINYGLTFIMPORTER_BUILD_STATIC)
    # CMake < 3.4 does this implicitly, but 3.4+ not anymore (see CMP0065).
    # That's generally okay, *except if* the build is static, the executable
    # uses a plugin manager and needs to share globals with the plugins (such
    # as output redirection and so on).
    set_target_properties(TinyGltfImporterTest PROPERTIES ENABLE_EXPORTS ON)
endif()
