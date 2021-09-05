CFLAGS=-Wno-unused-function
CXXFLAGS=-std=c++98

all: quasi build

quasi:
	cd libopenxds_base; make quasi
	cd libopenxds_adt;  make quasi

build:
	cd libopenxds_util; CFLAGS=$(CFLAGS) CXXFLAGS=$(CXXFLAGS)  build --force --all

