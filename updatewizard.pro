TEMPLATE = app

QTITANDIR = $$quote($$(QTITANDIR))

isEmpty(QTITANDIR):QTITANDIR = path_to_QTitan

include($$QTITANDIR/src/shared/platform.pri)
include($$QTITANDIR/src/shared/qtitanbase.pri)
include($$QTITANDIR/src/shared/qtitanchart.pri)
include($$QTITANDIR/src/shared/qtitandocking.pri)
include($$QTITANDIR/src/shared/qtitanfastinfoset.pri)
include($$QTITANDIR/src/shared/qtitangrid.pri)
include($$QTITANDIR/src/shared/qtitannavigation.pri)
include($$QTITANDIR/src/shared/qtitanribbon.pri)
include($$QTITANDIR/src/shared/qtitanstyle.pri)
include($$QTITANDIR/src/shared/translations.pri)
DESTDIR = $$QTITANDIR/bin
DESTDIR = $$member(DESTDIR, 0)$$QTITAN_LIB_PREFIX

!debug_and_release|build_pass {
    CONFIG(debug, debug|release) {
        TARGET = $$member(TARGET, 0)d
    }
}

HEADERS += myribbonwindow.h \
    database.h \
    dialog.h \
    product.h \
    switch.h

SOURCES +=             myribbonwindow.cpp             main.cpp \
    database.cpp \
    dialog.cpp \
    product.cpp \
    switch.cpp


FORMS   += myribbonwindow.ui \
    database.ui \
    dialog.ui \
    product.ui \
    switch.ui

macx {
    CONFIG-=app_bundle
}
LIBS += -L"path_to_QTitan/bin" -lQtitanGrid9
LIBS += -L"path_to_QTitan/bin" -lQtitanDocking5
LIBS += -L"path_to_QTitan/bin" -lQtitanBase3
LIBS += -L"path_to_QTitan/bin" -lQtitanChart7
LIBS += -L"path_to_QTitan/bin" -lQtitanFastInfoset3
LIBS += -L"path_to_QTitan/bin" -lQtitanNavigationDesignUI4
LIBS += -L"path_to_QTitan/bin" -lQtitanRibbon7
LIBS += -L"path_to_QTitan/bin" -lQtitanStyle3
!lessThan(QT_VER_MAJ, 5) {
  QT += printsupport
}
RC_ICONS = UpdateWIZARD.ico
