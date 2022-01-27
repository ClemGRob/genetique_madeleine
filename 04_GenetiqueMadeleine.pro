QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
INCLUDEPATH += ../share
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../share/qstd.cpp \
        client.cpp \
        individu.cpp \
        madeleine.cpp \
        main.cpp \
        myrandom.cpp \
        parametres.cpp \
        population.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../share/qstd.h \
    client.h \
    individu.h \
    madeleine.h \
    myrandom.h \
    parametres.h \
    population.h
