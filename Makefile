all: quasi build

quasi:
	cd libopenxds_base; make quasi
	cd libopenxds_adt;  make quasi

build:
	cd libopenxds_util; build --force --all

clean:
	rm -rf libopenxds_base/{obj,lib}
	rm -rf libopenxds_adt/{obj,lib}
	rm -rf libopenxds_adt_std/{obj,lib}
	rm -rf libopenxds_io/{obj,lib}
	rm -rf libopenxds_security/{obj,lib}
	rm -rf libopenxds_util/{obj,lib}
