#!/bin/zsh

g++ \
	src/main.cpp \
	src/StateHandler.cpp \
	src/GameMenuState.cpp \
	src/GameOverState.cpp \
	src/GameClearState.cpp \
	src/GameState.cpp \
	src/Snake.cpp \
	src/Item.cpp \
	src/ItemHandler.cpp \
	src/Gate.cpp \
	src/GateHandler.cpp \
	src/Map.cpp \
	src/Stage.cpp \
	src/Mission.cpp \
	src/Display.cpp \
	-lncurses -lncursesw -std=c++11 -o a.out;

if [[ 0 == $? ]]; then
	echo "[+] SUCCESS!"
	echo ' '
	./a.out
else
	echo "[-] FAILED.."
	echo ' '
fi

# EOF
