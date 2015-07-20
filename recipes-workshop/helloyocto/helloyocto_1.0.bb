SUMMARY = "Hello Yocto Example Recipe"

# Cheating
LICENSE = "CLOSED"

SRC_URI += "file://hello_yocto.c"

# Replace/Override compile function
do_compile(){
    ${CC} -o hello_yocto ../hello_yocto.c
}

# Replace/Override install function
do_install(){
    install -d ${D}${bindir}
    install -m 777 hello_yocto ${D}${bindir}/hello_yocto
}

