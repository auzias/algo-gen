#! /bin/bash
ERROR="\033[1;31m [ERR ]"
INFO="\033[1;34m [INFO]"
SUCCESS="\033[1;32m [ OK ]"
NC="\033[0m"

GENERATION="1000"
POPULATION_SIZE="1000"

function info() {
    echo -e "$INFO $1 $NC"
}
function err() {
    echo -e "$ERROR $1 $NC"
    exit
}
function success() {
    echo -e "$SUCCESS $1 $NC"
}

# tar your directory using the command: `tar cf tp.tar tp` (`man tar` will give you all the details)
# by naming the file as follow: "student1name_student2name.tar"

# Uncompress the archive:
info "Uncompress"
tar xf tp.tar && success "Archive uncompressed" || err "Cannot read (or find) file"
cd tp

# `sha512sum Makefile` of the unmodified Makefile output $SHA512SUM.
SHA512SUM_ORIGIN="b42c647fe48a148788dba6241fd5edc8b493260b7fefa0ab56d488026fcb2d71b73d285226e8101f40ecf810773fab4e92c1039caf26b7dd782129c157cb91ee"
info "Calculate the sha512sum"
SHA512SUM_CALCULATED=$(sha512sum Makefile | cut -d " " -f 1)

[[ $SHA512SUM_ORIGIN = $SHA512SUM_CALCULATED ]] && success "Makefile ok" || err "Makefile modified. Exiting"
info "Clear the binaries (that should not be here) and produce them using the source code"
make clean && make test && success "Compilation ok" || err "Error(s) in compilation. Exiting"

time ./projet-test.bin $POPULATION_SIZE $GENERATION > /dev/null
