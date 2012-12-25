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
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/synthesizers/Synthesizer.o \
	${OBJECTDIR}/function.o \
	${OBJECTDIR}/conductors/randomconductor.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/option.o \
	${OBJECTDIR}/algorithms/Algorithm.o \
	${OBJECTDIR}/conductors/conductor.o \
	${OBJECTDIR}/support/Queue.o \
	${OBJECTDIR}/support/Thread.o \
	${OBJECTDIR}/algorithms/coveredsetpartition.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/synthesizers/Synthesizer.o: synthesizers/Synthesizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/synthesizers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/synthesizers/Synthesizer.o synthesizers/Synthesizer.cpp

${OBJECTDIR}/function.o: function.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/function.o function.cpp

${OBJECTDIR}/conductors/randomconductor.o: conductors/randomconductor.cpp 
	${MKDIR} -p ${OBJECTDIR}/conductors
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/randomconductor.o conductors/randomconductor.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/option.o: option.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/option.o option.cpp

${OBJECTDIR}/algorithms/Algorithm.o: algorithms/Algorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/algorithms
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/algorithms/Algorithm.o algorithms/Algorithm.cpp

${OBJECTDIR}/conductors/conductor.o: conductors/conductor.cpp 
	${MKDIR} -p ${OBJECTDIR}/conductors
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/conductor.o conductors/conductor.cpp

${OBJECTDIR}/support/Queue.o: support/Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Queue.o support/Queue.cpp

${OBJECTDIR}/support/Thread.o: support/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Thread.o support/Thread.cpp

${OBJECTDIR}/algorithms/coveredsetpartition.o: algorithms/coveredsetpartition.cpp 
	${MKDIR} -p ${OBJECTDIR}/algorithms
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/algorithms/coveredsetpartition.o algorithms/coveredsetpartition.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/synthesizers/Synthesizer_nomain.o: ${OBJECTDIR}/synthesizers/Synthesizer.o synthesizers/Synthesizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/synthesizers
	@NMOUTPUT=`${NM} ${OBJECTDIR}/synthesizers/Synthesizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/synthesizers/Synthesizer_nomain.o synthesizers/Synthesizer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/synthesizers/Synthesizer.o ${OBJECTDIR}/synthesizers/Synthesizer_nomain.o;\
	fi

${OBJECTDIR}/function_nomain.o: ${OBJECTDIR}/function.o function.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/function.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/function_nomain.o function.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/randomconductor_nomain.o conductors/randomconductor.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/option_nomain.o option.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/option.o ${OBJECTDIR}/option_nomain.o;\
	fi

${OBJECTDIR}/algorithms/Algorithm_nomain.o: ${OBJECTDIR}/algorithms/Algorithm.o algorithms/Algorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/algorithms
	@NMOUTPUT=`${NM} ${OBJECTDIR}/algorithms/Algorithm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/algorithms/Algorithm_nomain.o algorithms/Algorithm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/algorithms/Algorithm.o ${OBJECTDIR}/algorithms/Algorithm_nomain.o;\
	fi

${OBJECTDIR}/conductors/conductor_nomain.o: ${OBJECTDIR}/conductors/conductor.o conductors/conductor.cpp 
	${MKDIR} -p ${OBJECTDIR}/conductors
	@NMOUTPUT=`${NM} ${OBJECTDIR}/conductors/conductor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/conductors/conductor_nomain.o conductors/conductor.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Queue_nomain.o support/Queue.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/support/Queue.o ${OBJECTDIR}/support/Queue_nomain.o;\
	fi

${OBJECTDIR}/support/Thread_nomain.o: ${OBJECTDIR}/support/Thread.o support/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/support
	@NMOUTPUT=`${NM} ${OBJECTDIR}/support/Thread.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/support/Thread_nomain.o support/Thread.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/algorithms/coveredsetpartition_nomain.o algorithms/coveredsetpartition.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/algorithms/coveredsetpartition.o ${OBJECTDIR}/algorithms/coveredsetpartition_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qsyn || true; \
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