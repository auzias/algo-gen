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

function integrity() {
    SHA512SUM_ORIGIN="$1"
    FILE="$2"
    info "Calculate the sha512sum of the $FILE"
    SHA512SUM_CALCULATED=$(sha512sum $FILE | cut -d " " -f 1)
    [[ $SHA512SUM_ORIGIN = $SHA512SUM_CALCULATED ]] && success "$FILE ok" || err "$FILE modified. Exiting"
}

# tar your directory using the command: `tar cf tp.tar tp` (`man tar` will give you all the details)
# by naming the file as follow: "student1name_student2name.tar"

# Uncompress the archive:
info "Uncompress"
tar xf tp.tar && success "Archive uncompressed" || err "Cannot read (or find) file"
cd tp

# Check the integrity of the files: `sha512sum Makefile` of the unmodified Makefile output $SHA512SUM.
integrity "b42c647fe48a148788dba6241fd5edc8b493260b7fefa0ab56d488026fcb2d71b73d285226e8101f40ecf810773fab4e92c1039caf26b7dd782129c157cb91ee" "Makefile"
integrity "b6e678ba412e1f48edd39c51b3480e604d7ae11a621709e404d1f2826aa52e12de6f95196fc6e9aaaa6f7838ddd19ce99805bd7b43b2079ea8d29ecf24153664" "src/main-test.c"
integrity "1e7ab9b4640f4ddf970ad8e1b48dfde9cac45ee633a1a4343fd878031d4ddd2987b6da7753585108b26a3131def7a3930e644ad9c4e9788acfb01bd25121521b" "src/algo.h"
integrity "dc1b2049bb854627a1321610c5d956871db2c039bfd73a1a2ef64aa5044ee83120b4e345f2c9c6b6ab35256e48d1a539b46205b89653330aa5f7abba21d3cd52" "src/util.h"
integrity "45f69fceba143d801db64027e2d8d8dbb2a1813d6898c1e3c1dce2ffb53e3ef40fe836fdf5a688f843af7c4bf9f8adafe9451275824ab845fc2544730adf2da2" "src/util.c"


info "Set DEBUG to 0 -- as I asked you to do (so the execution is faster as there should not be any printf() execution)"
sed -i 's/#define\( *\)DEBUG\( *\)1/#define DEBUG 0/g' ./src/util.h

info "Clear the binaries (that should not be here) and produce them using the source code"
make clean
make test && success "Compilation ok" || err "Error(s) in compilation. Exiting"

time ./projet-test.bin $POPULATION_SIZE $GENERATION
