#ifndef OPENXDS_ADT_STD_GENERALTOUR_H
#define OPENXDS_ADT_STD_GENERALTOUR_H

#include <openxds.adt.h>
#include <openxds.adt/IGeneralTour.h>
#include <openxds.adt/IPIterator.h>
#include <openxds.adt/IPosition.h>
#include <openxds/Object.h>

namespace openxds {
	namespace adt {
		namespace std {

class Result : openxds::Object
{
public:
	Object* intermediateResult;
	Object* finalResult;
	
	Result()
	{
		intermediateResult = NULL;
		finalResult = NULL;
	}
	
	Object* returnFinalResult()
	{
		delete intermediateResult;
		return finalResult;
	}
};

template <class E>
class GeneralTour : public openxds::Object, public openxds::adt::IGeneralTour<E>
{
protected:
	ITree<E>& tree;

public:
	GeneralTour( ITree<E>& t ) : tree( t )
	{}

	virtual ~GeneralTour()
	{}

	virtual Object* doGeneralTour( IPosition<E>& p )
	{
		Result r;
		
		if ( tree.isExternal( p ) )
		{
			this->visitExternal( p, r );
		}
		else
		{
			this->visitPreorder( p, r );
			
			IPIterator<E>* it = tree.children( p );
			{
				while ( it->hasNext() )
				{
					IPosition<E>* child = it->next();
					{
						r.intermediateResult = this->doGeneralTour( *child );
						this->visitBelow( p, r );
					}
					delete child;
				}
				this->visitPostorder( p, r );
			}
			delete it;
		}
		return r.returnFinalResult();
	}

protected:
	virtual void visitPreorder(  IPosition<E>& p, Result& r ) {}
	virtual void visitBelow(     IPosition<E>& p, Result& r ) {}
	virtual void visitPostorder( IPosition<E>& p, Result& r ) {}
	virtual void visitExternal(  IPosition<E>& p, Result& r ) {}


}; 

};};};

#endif
