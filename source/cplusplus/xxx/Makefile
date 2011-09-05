#
# Makefile for the OpenOCL IO Library.
# Copyright I.S. Labs
#
# OpenAPI and OpenOCL are Trademarks of Daniel Bradley.

TOP_LEVEL=../..
include $(TOP_LEVEL)/../shared/DefaultOCLMake.rules

# Library Information
#
LIBNAME = io
VERSION = .1.0.0
STATIC_NAME = libopenocl_$(LIBNAME).a
SO_NAME = libopenocl_$(LIBNAME).so

# Library Dependencies
#
LIBS = -L$(OPENOCL_LIB_DIR) -lopenocl_security

# Platform Specific Adapter Information
#
PSA = IOPSA.o FilePSA.o StatPSA.o

#FileDescriptorPSA.o FilePSA.o StatPSA.o

# Object File Information
#
OBJECTS =		IOException.o \
			FileAlreadyExistsException.o \
			FileNotFoundException.o \
			RaceConditionException.o \
			WouldBlockException.o \
			\
			Address.o \
			Descriptor.o \
			Device.o \
			FileSystem.o \
			FileAddress.o \
			\
			Statistics.o \
			\
			IOEndPoint.o \
			FileDescriptor.o \
			\
			File.o \
			IOBuffer.o \
			\
			InputStream.o \
				PushbackInputStream.o \
			OutputStream.o \
			Reader.o \
				InputStreamReader.o \
			Writer.o \
				OutputStreamWriter.o \
				Printer.o PrintWriter.o \
			LineParser.o \
			IO.o \
				FileInputStream.o \
				FileOutputStream.o \
#			System.o \

#
#  Include the General OpenAPI Makefile
#

include $(TOP_LEVEL)/../shared/OpenOCL.mak
