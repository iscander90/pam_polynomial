QT -= gui

TEMPLATE = lib
DESTDIR = dist
DEFINES += PAM_POLYNOMIAL_LIBRARY
CONFIG += c++11 build_all

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    pam_polynomial.cpp

HEADERS += \
    pam_polynomial_global.h \
    pam_polynomial.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

# Подключение необходимых библиотек
# Библиотека Linux-PAM
unix:!macx: LIBS += -L$$PWD/../../../../lib/x86_64-linux-gnu/ -lpam

INCLUDEPATH += $$PWD/../../../../lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../lib/x86_64-linux-gnu

# Библиотека для взаимодействия с программой нашим модулем
unix:!macx: LIBS += -L$$PWD/../../../../lib/x86_64-linux-gnu/ -lpam_misc
INCLUDEPATH += $$PWD/../../../../lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../lib/x86_64-linux-gnu
