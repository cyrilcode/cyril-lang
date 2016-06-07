cmake_minimum_required(VERSION 3.5)
project(cyril_lang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_compile_options(-Wno-deprecated-register)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(CyrilParser Cyril/cyril.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(CyrilScanner Cyril/cyril.lpp  ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(CyrilScanner CyrilParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
        Cyril/Cyril.cpp
        Cyril/CyrilParser.cpp
        Cyril/CyrilBloom.cpp
        Cyril/CyrilOp.cpp
        Cyril/CyrilPixelate.cpp
        Cyril/Ops/CyrilBlink.cpp
        Cyril/Ops/CyrilBoxOp.cpp
        Cyril/Ops/CyrilAnimation.cpp
        Cyril/Ops/CyrilAnimStep.cpp
        Cyril/Ops/CyrilBackgroundOp.cpp
        Cyril/Ops/CyrilImgOp.cpp
        Cyril/Ops/CyrilPegOp.cpp
        Cyril/Ops/CyrilShape.cpp
        Cyril/Ops/CyrilSphereOp.cpp
        Cyril/Ops/CyrilShape.cpp
        Cyril/Ops/CyrilBallOp.cpp
        Cyril/Ops/CyrilBallDetailOp.cpp
        Cyril/Ops/CyrilConeOp.cpp
        Cyril/Funs/CyrilCosFun.cpp
        Cyril/Funs/CyrilSinFun.cpp
        Cyril/Funs/CyrilFftFun.cpp
        Cyril/Ops/CyrilFillOp.cpp
        Cyril/Ops/CyrilNoFillOp.cpp
        Cyril/Funs/CyrilHsbFun.cpp
        Cyril/Funs/CyrilMapFun.cpp
        Cyril/Ops/CyrilGridOp.cpp
        Cyril/Ops/CyrilLineOp.cpp
        Cyril/Ops/CyrilInitOp.cpp
        Cyril/Ops/CyrilRectOp.cpp
        Cyril/Funs/CyrilTanFun.cpp
        Cyril/Ops/CyrilColorOp.cpp
        Cyril/Ops/CyrilMoveOp.cpp
        Cyril/Lang/CyrilDebugOp.cpp
        Cyril/Funs/CyrilLerpFun.cpp
        Cyril/Ops/CyrilLightOp.cpp
        Cyril/Funs/CyrilRandFun.cpp
        Cyril/Ops/CyrilScaleOp.cpp
        Cyril/Funs/CyrilWaveFun.cpp
        Cyril/Funs/CyrilNoiseFun.cpp
        Cyril/Ops/CyrilRotateOp.cpp
        Cyril/Lang/CyrilColorLoad.cpp
        Cyril/Ops/CyrilNoiseWarp.cpp
        Cyril/Ops/CyrilShapeList.cpp
        Cyril/Funs/CyrilPaletteFun.cpp
        Cyril/Ops/CyrilPaletteItem.cpp
        Cyril/Ops/CyrilPalette.cpp
        Cyril/Ops/CyrilPopMatrixOp.cpp
        Cyril/Ops/CyrilKaleidoscope.cpp
        Cyril/Ops/CyrilPushMatrixOp.cpp
        Cyril/Ops/CyrilSphereDetailOp.cpp
        Cyril/Funs/CyrilFun.cpp
        Cyril/Ops/CyrilParticle.cpp
        Cyril/Ops/CyrilTile.cpp
        )
add_library(cyril_lang ${SOURCE_FILES}
        ${BISON_CyrilParser_OUTPUTS}
        ${FLEX_CyrilScanner_OUTPUTS})

set(CYRIL_LANG_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
