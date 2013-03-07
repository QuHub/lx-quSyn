#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=c++
CXX=c++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/synthesizers/Synthesizer.o \
	${OBJECTDIR}/common.o \
	${OBJECTDIR}/function.o \
	${OBJECTDIR}/conductors/randomconductor.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/option.o \
	${OBJECTDIR}/conductors/conductor.o \
	${OBJECTDIR}/support/Queue.o \
	${OBJECTDIR}/argvparser-20060124/argvparser.o \
	${OBJECTDIR}/support/Rand.o \
	${OBJECTDIR}/support/QRBG.o \
	${OBJECTDIR}/support/Thread.o \
	${OBJECTDIR}/algorithms/coveredsetpartition.o \
	${OBJECTDIR}/support/Helper.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f4

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs yaml-cpp` -lboost_filesystem -lboost_program_options -lcppunit  -lboost_timer -lboost_system  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	c++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/synthesizers/Synthesizer.o: synthesizers/Synthesizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/synthesizers
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/synthesizers/Synthesizer.o synthesizers/Synthesizer.cpp

${OBJECTDIR}/common.o: common.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/common.o common.cpp

${OBJECTDIR}/function.o: function.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/function.o function.cpp

${OBJECTDIR}/conductors/randomconductor.o: conductors/randomconductor.cpp 
	${MKDIR} -p ${OBJECTDIR}/conductors
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/randomconductor.o conductors/randomconductor.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/option.o: option.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/option.o option.cpp

${OBJECTDIR}/conductors/conductor.o: conductors/conductor.cpp 
	${MKDIR} -p ${OBJECTDIR}/conductors
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/conductor.o conductors/conductor.cpp

${OBJECTDIR}/support/Queue.o: support/Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Queue.o support/Queue.cpp

${OBJECTDIR}/argvparser-20060124/argvparser.o: argvparser-20060124/argvparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/argvparser-20060124
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/argvparser-20060124/argvparser.o argvparser-20060124/argvparser.cpp

${OBJECTDIR}/support/Rand.o: support/Rand.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Rand.o support/Rand.cpp

${OBJECTDIR}/support/QRBG.o: support/QRBG.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/QRBG.o support/QRBG.cpp

${OBJECTDIR}/support/Thread.o: support/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Thread.o support/Thread.cpp

${OBJECTDIR}/algorithms/coveredsetpartition.o: algorithms/coveredsetpartition.cpp 
	${MKDIR} -p ${OBJECTDIR}/algorithms
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/algorithms/coveredsetpartition.o algorithms/coveredsetpartition.cpp

${OBJECTDIR}/support/Helper.o: support/Helper.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	${RM} $@.d
	$(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Helper.o support/Helper.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/CoveredSetPartitionRunner.o ${TESTDIR}/tests/CoveredSetPatitionTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} -lcppunit 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/FunctionRunner.o ${TESTDIR}/tests/FunctionTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lcppunit -lcppunit -lcppunit 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/HasseRunner.o ${TESTDIR}/tests/HasseTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} -lcppunit -lcppunit 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/SynthesizerRunner.o ${TESTDIR}/tests/SynthesizerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} -lcppunit 


${TESTDIR}/tests/CoveredSetPartitionRunner.o: tests/CoveredSetPartitionRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/CoveredSetPartitionRunner.o tests/CoveredSetPartitionRunner.cpp


${TESTDIR}/tests/CoveredSetPatitionTest.o: tests/CoveredSetPatitionTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/CoveredSetPatitionTest.o tests/CoveredSetPatitionTest.cpp


${TESTDIR}/tests/FunctionRunner.o: tests/FunctionRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I. -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/FunctionRunner.o tests/FunctionRunner.cpp


${TESTDIR}/tests/FunctionTest.o: tests/FunctionTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I. -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/FunctionTest.o tests/FunctionTest.cpp


${TESTDIR}/tests/HasseRunner.o: tests/HasseRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/HasseRunner.o tests/HasseRunner.cpp


${TESTDIR}/tests/HasseTest.o: tests/HasseTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/HasseTest.o tests/HasseTest.cpp


${TESTDIR}/tests/SynthesizerRunner.o: tests/SynthesizerRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/SynthesizerRunner.o tests/SynthesizerRunner.cpp


${TESTDIR}/tests/SynthesizerTest.o: tests/SynthesizerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -MMD -MP -MF $@.d -o ${TESTDIR}/tests/SynthesizerTest.o tests/SynthesizerTest.cpp


${OBJECTDIR}/synthesizers/Synthesizer_nomain.o: ${OBJECTDIR}/synthesizers/Synthesizer.o synthesizers/Synthesizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/synthesizers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/synthesizers/Synthesizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/synthesizers/Synthesizer_nomain.o synthesizers/Synthesizer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/synthesizers/Synthesizer.o ${OBJECTDIR}/synthesizers/Synthesizer_nomain.o;\
	fi

${OBJECTDIR}/common_nomain.o: ${OBJECTDIR}/common.o common.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/common.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/common_nomain.o common.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/common.o ${OBJECTDIR}/common_nomain.o;\
	fi

${OBJECTDIR}/function_nomain.o: ${OBJECTDIR}/function.o function.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/function.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/function_nomain.o function.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/function.o ${OBJECTDIR}/function_nomain.o;\
	fi

${OBJECTDIR}/conductors/randomconductor_nomain.o: ${OBJECTDIR}/conductors/randomconductor.o conductors/randomconductor.cpp 
	${MKDIR} -p ${OBJECTDIR}/conductors
	@NMOUTPUT=`${NM} ${OBJECTDIR}/conductors/randomconductor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/randomconductor_nomain.o conductors/randomconductor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/conductors/randomconductor.o ${OBJECTDIR}/conductors/randomconductor_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/option_nomain.o: ${OBJECTDIR}/option.o option.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/option.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/option_nomain.o option.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/option.o ${OBJECTDIR}/option_nomain.o;\
	fi

${OBJECTDIR}/conductors/conductor_nomain.o: ${OBJECTDIR}/conductors/conductor.o conductors/conductor.cpp 
	${MKDIR} -p ${OBJECTDIR}/conductors
	@NMOUTPUT=`${NM} ${OBJECTDIR}/conductors/conductor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/conductor_nomain.o conductors/conductor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/conductors/conductor.o ${OBJECTDIR}/conductors/conductor_nomain.o;\
	fi

${OBJECTDIR}/support/Queue_nomain.o: ${OBJECTDIR}/support/Queue.o support/Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	@NMOUTPUT=`${NM} ${OBJECTDIR}/support/Queue.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Queue_nomain.o support/Queue.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/support/Queue.o ${OBJECTDIR}/support/Queue_nomain.o;\
	fi

${OBJECTDIR}/argvparser-20060124/argvparser_nomain.o: ${OBJECTDIR}/argvparser-20060124/argvparser.o argvparser-20060124/argvparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/argvparser-20060124
	@NMOUTPUT=`${NM} ${OBJECTDIR}/argvparser-20060124/argvparser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/argvparser-20060124/argvparser_nomain.o argvparser-20060124/argvparser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/argvparser-20060124/argvparser.o ${OBJECTDIR}/argvparser-20060124/argvparser_nomain.o;\
	fi

${OBJECTDIR}/support/Rand_nomain.o: ${OBJECTDIR}/support/Rand.o support/Rand.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	@NMOUTPUT=`${NM} ${OBJECTDIR}/support/Rand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Rand_nomain.o support/Rand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/support/Rand.o ${OBJECTDIR}/support/Rand_nomain.o;\
	fi

${OBJECTDIR}/support/QRBG_nomain.o: ${OBJECTDIR}/support/QRBG.o support/QRBG.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	@NMOUTPUT=`${NM} ${OBJECTDIR}/support/QRBG.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/QRBG_nomain.o support/QRBG.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/support/QRBG.o ${OBJECTDIR}/support/QRBG_nomain.o;\
	fi

${OBJECTDIR}/support/Thread_nomain.o: ${OBJECTDIR}/support/Thread.o support/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	@NMOUTPUT=`${NM} ${OBJECTDIR}/support/Thread.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Thread_nomain.o support/Thread.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/support/Thread.o ${OBJECTDIR}/support/Thread_nomain.o;\
	fi

${OBJECTDIR}/algorithms/coveredsetpartition_nomain.o: ${OBJECTDIR}/algorithms/coveredsetpartition.o algorithms/coveredsetpartition.cpp 
	${MKDIR} -p ${OBJECTDIR}/algorithms
	@NMOUTPUT=`${NM} ${OBJECTDIR}/algorithms/coveredsetpartition.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/algorithms/coveredsetpartition_nomain.o algorithms/coveredsetpartition.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/algorithms/coveredsetpartition.o ${OBJECTDIR}/algorithms/coveredsetpartition_nomain.o;\
	fi

${OBJECTDIR}/support/Helper_nomain.o: ${OBJECTDIR}/support/Helper.o support/Helper.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	@NMOUTPUT=`${NM} ${OBJECTDIR}/support/Helper.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Iconductors -Ialgorithms -I. -Isupport -Isynthesizers -Iargvparser-20060124 `pkg-config --cflags yaml-cpp` -std=c++11   -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Helper_nomain.o support/Helper.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/support/Helper.o ${OBJECTDIR}/support/Helper_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
