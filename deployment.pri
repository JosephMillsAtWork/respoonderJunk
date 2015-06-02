unix {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /usr/sbin/
        }
        export(target.path)
    }
INSTALLS += target
}

export(INSTALLS)
