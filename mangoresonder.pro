TEMPLATE = app
TARGET = mangoresonder
unix:!macx:!android: LIBS += -ldns_sd
!contains(CONFIG,NO_AVAHI): unix:!macx:LIBS += -lavahi-client -lavahi-common

QT += widgets core network
QT -= gui
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += release

SOURCES += main.cpp \
		bonjourregister.cpp

HEADERS += \
		bonjourregister.h

include(deployment.pri)
