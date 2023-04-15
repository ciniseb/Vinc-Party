TEMPLATE     = vcapp
TARGET       = JeuP11
CONFIG      += warn_on qt debug windows console
HEADERS     += *.h
SOURCES     += *.cpp
INCLUDEPATH += include/serial
LIBS		+= -lwinmm
QT          += widgets