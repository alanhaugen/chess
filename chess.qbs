import "../solid/solid.qbs" as solid

solid {
    Application {
        name: "Chess"

        files: [
            "data/blender/bishop.blend",
            "data/blender/bishop.blend1",
            "data/blender/board.blend",
            "data/blender/boardandpieces.blend",
            "data/blender/boardandpieces.blend1",
            "data/blender/king.blend",
            "data/blender/king.blend1",
            "data/blender/knight.blend",
            "data/blender/knight.blend1",
            "data/blender/pawn.blend",
            "data/blender/pawn.blend1",
            "data/blender/queen.blend",
            "data/blender/queen.blend1",
            "data/blender/rook.blend",
            "data/blender/rook.blend1",
            "data/blender/shogi.blend",
            "data/blender/shogi.blend1",
            "data/level1.json",
            "data/project.json",
            "source/chess.cpp",
            "source/chess.h",
            "source/main.cpp",
        ]

        property stringList includePaths: "../solid/source"

        Properties {
            condition: qbs.targetOS.contains("macos")

            cpp.frameworks: macosFrameworks

            cpp.dynamicLibraries: macosSharedLibs
            cpp.staticLibraries: staticLibs.concat("SDL2")

            cpp.libraryPaths: [project.buildDirectory, "../solid/lib/debug/darwin/x86_64"]
            cpp.includePaths: includePaths.concat("../solid/include/darwin")
            cpp.defines: project.defines.concat(project.sdlDefines)
        }

        Properties {
            condition: qbs.targetOS.contains("windows")

            cpp.dynamicLibraries: windowsSharedLibs
            cpp.staticLibraries: staticLibs

            cpp.libraryPaths: [project.buildDirectory, "../solid/lib/debug/mingw32/x86"]
            cpp.includePaths: includePaths.concat("../solid/include/mingw32")
            cpp.defines: project.defines.concat(project.windowsDefines)
        }

        Depends { name: "cpp" }
        Depends { name: "core" }
    }
}
