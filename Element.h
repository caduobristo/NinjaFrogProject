#pragma once

#include "stdafx.h"

template <class TYPE>
class Element{
	private:
		TYPE* element;
		Element <TYPE>* nextElement;

	public:
		Element() {
			this->element = nullptr;
			this->nextElement = nullptr;
		}

		~Element() {
			this->element = nullptr;
			this->nextElement = nullptr;
		}

		Element<TYPE>* getNextElement() {
			return nextElement;
		}

		void setNextElement(Element<TYPE>* element) {
			this->nextElement = element;
		}

		TYPE* getElementInfo() {
			return this->element;
		}

		void setElementInfo(TYPE* info) {
			this->element = info;
		}

};

