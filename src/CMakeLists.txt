
add_library(sourceFiles
  BlockSpawner.cpp
  BlockMover.cpp
  BlockShifter.cpp
  BlockMerger.cpp
  Board.cpp
  gamemanager.cpp
  settings.cpp
  credits.cpp
  gameover.cpp
  functions.cpp
  functionality.cpp
  gameover.cpp
  menu.cpp
  main.cpp
)

add_executable(game functionality.cpp)

target_link_libraries(game sourceFiles)