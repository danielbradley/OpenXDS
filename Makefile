all: quasi build

quasi:
	cd libopenxds_base; make quasi
	cd libopenxds_adt;  make quasi

build:
	cd libopenxds_util; build --force --all

