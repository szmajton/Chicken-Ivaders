TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        animatedsprite.cpp \
        bullet.cpp \
        enemy.cpp \
        main.cpp \
        player.cpp \
        skrzynia.cpp \
        ustawienia.cpp
INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    animatedsprite.h \
    bullet.h \
    enemy.h \
    player.h \
    skrzynia.h \
    ustawienia.h


