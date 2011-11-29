all:	doc quasi

doc:
	max2html --out documentation/openxds.adt.IDictionary.html  source/mtx/IDictionary.mtx.cpp
	max2html --out documentation/openxds.adt.IEIterator.html   source/mtx/IEIterator.mtx.cpp
	max2html --out documentation/openxds.adt.IEntry.html       source/mtx/IEntry.mtx.cpp
	max2html --out documentation/openxds.adt.IIterator.html    source/mtx/IIterator.mtx.cpp
	max2html --out documentation/openxds.adt.IGeneralTour.html source/mtx/IGeneralTour.mtx.cpp
	max2html --out documentation/openxds.adt.IList.html        source/mtx/IList.mtx.cpp
	max2html --out documentation/openxds.adt.IMap.html         source/mtx/IMap.mtx.cpp
	max2html --out documentation/openxds.adt.IPosition.html    source/mtx/IPosition.mtx.cpp
	max2html --out documentation/openxds.adt.IPIterator.html   source/mtx/IPIterator.mtx.cpp
	max2html --out documentation/openxds.adt.ISequence.html    source/mtx/ISequence.mtx.cpp
	max2html --out documentation/openxds.adt.IStack.html       source/mtx/IStack.mtx.cpp
	max2html --out documentation/openxds.adt.ITree.html        source/mtx/ITree.cpp.txt

quasi:
	quasi -f . source/mtx/*mtx*
