cmake_minimum_required(VERSION 3.20)
project(fivechess)

set(CMAKE_CXX_STANDARD 14)

add_executable(fivechess main.cpp Chess.cpp Chess.h Chessboard.cpp Chessboard.h Player.cpp Player.h Judge.cpp Judge.h PC.cpp PC.h Game.cpp Game.h)
