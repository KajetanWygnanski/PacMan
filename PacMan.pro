######################################################################
# Automatically generated by qmake (3.1) Fri Jan 24 04:25:36 2025
######################################################################

TEMPLATE = app
TARGET = PacMan
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += Board.h \
           Constants.h \
           Game.h \
           Ghost.h \
           gui.h \
           Moving.h \
           PacMan.h \
           Unmovable.h \
           Ghosts/CyanGhost.h \
           Ghosts/OrangeGhost.h \
           Ghosts/PinkGhost.h \
           Ghosts/RedGhost.h
SOURCES += Board.cpp \
           Game.cpp \
           Ghost.cpp \
           gui.cpp \
           main.cpp \
           Moving.cpp \
           PacMan.cpp \
           Unmovable.cpp \
           Ghosts/CyanGhost.cpp \
           Ghosts/OrangeGhost.cpp \
           Ghosts/PinkGhost.cpp \
           Ghosts/RedGhost.cpp
