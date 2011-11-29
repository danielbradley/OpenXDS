#ifndef OPENXDS_ADT_STD_STACK_H
#define OPENXDS_ADT_STD_STACK_H

#include <openxds.adt/IStack.h>

#include <openxds/Object.h>
#include <openxds.exceptions/NoSuchElementException.h>

#include <openxds.core.adt.h>
#include <openxds.core.adt/IStack.h>
#include <openxds.core.adt/IValue.h>
#include <openxds.core.adt.std.h>
#include <openxds.core.adt.std/StdADTFactory.h>

#include <cstdio>

namespace openxds {
	namespace adt {
		namespace std {

void* createStack();

template <class E>
class Stack : public openxds::Object, public openxds::adt::IStack<E>
{
public:
    Stack()
	{
		this->_stack = openxds::core::adt::std::StdADTFactory_createStack();
	}

	virtual ~Stack()
	{
		while ( (0 == this->_stack->isEmpty( this->_stack )) )
		{
			delete pop();
		}
	
		this->_stack->free( this->_stack );
		this->_stack = null;
	}

	virtual void push( E* anElement )
	{
		openxds::core::adt::IValue* value = openxds::core::adt::std::StdADTFactory_createValue( anElement );
		this->_stack->push( this->_stack, (openxds::core::IObject*) value );
	}

	virtual E* pop() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( isEmpty() ) throw new openxds::exceptions::NoSuchElementException();
		
		openxds::core::adt::IValue* value = (openxds::core::adt::IValue*) this->_stack->pop( this->_stack );
		E* element = static_cast<E*>( value->replaceValue( value, null ) );
		value->free( value );
	
		return element;
	}
	
	virtual E& top() throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( isEmpty() ) throw new openxds::exceptions::NoSuchElementException();
	
		openxds::core::adt::IValue* value = (openxds::core::adt::IValue*) this->_stack->top( this->_stack );
		E* element = const_cast<E*>( static_cast<const E*>( value->getValue( value ) ) );
		return *element;
	}

	virtual const E& top() const throw (openxds::exceptions::NoSuchElementException*)
	{
		if ( isEmpty() ) throw new openxds::exceptions::NoSuchElementException();
	
		openxds::core::adt::IValue* value = (openxds::core::adt::IValue*) this->_stack->top( this->_stack );
		E* element = const_cast<E*>( static_cast<const E*>( value->getValue( value ) ) );
		return *element;
	}

	virtual bool isEmpty() const
	{
		return this->_stack->isEmpty( this->_stack );
	}

	virtual long size() const
	{
		return this->_stack->size( this->_stack );
	}
	
private:
	openxds::core::adt::IStack* _stack;
}; 

};};};

#endif
