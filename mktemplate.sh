#!/bin/sh

# Create the basic workspace for the daily programmer challenge
# Author: Al Hunt <al@returnzero.org>

# Requires: minunit for unit tests <https://github.com/siu/minunit>

# Check arguments
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 challenge_no program_name"
  exit 1
fi

# Set globals from arguments
CHALLENGE="$1"
PROG="$2"
ROOT_DIR="./${CHALLENGE}"

echo "Challenge: $CHALLENGE"
echo "Program Name: ${PROG}"

# Create directories
mkdir -p ${ROOT_DIR} ${ROOT_DIR}/src ${ROOT_DIR}/test

# Create Makefile
echo "Creating Makefile.."
echo -e "vpath %.c src test\n"                  > ${ROOT_DIR}/Makefile
echo -e "CC=gcc"                               >> ${ROOT_DIR}/Makefile
echo -e "CFLAGS=-I./src"                       >> ${ROOT_DIR}/Makefile
echo -e "CFLAGST=-I./test -I./src\n"           >> ${ROOT_DIR}/Makefile
echo -e "${PROG}: main.o ${PROG}.o"            >> ${ROOT_DIR}/Makefile
echo -e "\t\$(CC) -o ${PROG} main.o ${PROG}.o \$(CFLAGS)\n" \
                                               >> ${ROOT_DIR}/Makefile
echo -e "${PROG}_test: ${PROG} ${PROG}_test.o" >> ${ROOT_DIR}/Makefile
echo -e "\t\$(CC) -o ${PROG}_test ${PROG}_test.o ${PROG}.o \$(CFLAGST)\n" \
                                               >> ${ROOT_DIR}/Makefile
echo -e ".PHONY: test"                         >> ${ROOT_DIR}/Makefile
echo -e "test: ${PROG}_test"                   >> ${ROOT_DIR}/Makefile
echo -e "\t./${PROG}_test"                     >> ${ROOT_DIR}/Makefile
echo -e ".PHONY: clean"                        >> ${ROOT_DIR}/Makefile
echo -e "clean:"                               >> ${ROOT_DIR}/Makefile
echo -e "\trm -f ./*.o"                        >> ${ROOT_DIR}/Makefile

# Create main.c
echo "Creating main.c.."
echo -e "#include <stdio.h>"                  > ./${ROOT_DIR}/src/main.c
echo -e "#include <${PROG}.h>\n"             >> ./${ROOT_DIR}/src/main.c
echo -e "int main(int argc, char* argv[]) {" >> ./${ROOT_DIR}/src/main.c
echo -e "\treturn 0;"                        >> ./${ROOT_DIR}/src/main.c
echo "}"                                     >> ./${ROOT_DIR}/src/main.c

# Create source
echo "Creating ${PROG}.c.."
echo "// TODO: Remove example code"           > ./${ROOT_DIR}/src/${PROG}.c
echo -e "#include \"${PROG}.h\"\n"           >> ./${ROOT_DIR}/src/${PROG}.c
echo "int foo(void) {"                       >> ./${ROOT_DIR}/src/${PROG}.c
echo -e "\treturn 0;"                        >> ./${ROOT_DIR}/src/${PROG}.c
echo -e "}"                                  >> ./${ROOT_DIR}/src/${PROG}.c

# Create header
echo "Creating ${PROG}.h.."
echo "// TODO: Remove example code"           > ./${ROOT_DIR}/src/${PROG}.h
echo "int foo(void);"                        >> ./${ROOT_DIR}/src/${PROG}.h

# Create unit tests
if [ -e minunit/minunit.h ]; then
  echo "Copying minunit.h to ./test.."
  cp minunit/minunit.h ${ROOT_DIR}/test/

  echo "Creating ${PROG}_test.c.."
  echo -e "#include \"minunit.h\""         > ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "#include \"${PROG}.h\"\n"      >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "MU_TEST(test_minunit) {"       >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "\tmu_assert(0, \"No Tests!\");" \
                                          >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "}\n"                           >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "MU_TEST_SUITE(test_suite) {"   >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "\tMU_RUN_TEST(test_minunit);"  >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "}\n"                           >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "int main(int argc, char* argv[]) {" \
                                          >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "\tMU_RUN_SUITE(test_suite);"   >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "\tMU_REPORT();"                >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo -e "\treturn 0;"                   >> ./${ROOT_DIR}/test/${PROG}_test.c
  echo "}"                                >> ./${ROOT_DIR}/test/${PROG}_test.c
else
  echo "Unable to find minunit/minunit.h -- No Unit Tests Created"
fi

# Done
echo "Set up complete!"
exit 0
