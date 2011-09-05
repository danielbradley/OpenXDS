#
# Makefile for an Open OCL (Object Class Library) Library
#
# Copyright I.S. Labs
#
# OpenAPI and OpenOCL are Trademarks of Daniel Bradley.

TOP_LEVEL=../..
include $(TOP_LEVEL)/../shared/DefaultOCLMake.rules

# Library Information
#
LIBNAME = security
VERSION = .1.0.0
STATIC_NAME = libopenocl_$(LIBNAME).a
SO_NAME = libopenocl_$(LIBNAME).so

# Library Dependencies
#
LIBS = -L$(OPENOCL_LIB_DIR) -lopenocl_util -lopenocl_base

# Platform Specific Adapter Information
#
PSA =

# Object File Information
#
OBJECTS =	PrivilegedAttribute.o \
		SecurityAttribute.o \
		Principal.o \
          	Right.o RightsList.o \
	      	Policy.o AccessPolicy.o AccessControlList.o \
		UnixRights.o \
		AccessException.o \

#
#  Include the General OpenAPI Makefile
#

include $(TOP_LEVEL)/../shared/OpenOCL.mak
