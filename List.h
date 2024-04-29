#pragma once

#include "stdafx.h"
#include "Element.h"

template <class TYPE>
class List{
	private:
		Element<TYPE>* firstElement;
		Element<TYPE>* lastElement;

		int size;

	public:
		List() {
			this->firstElement = nullptr;
			this->lastElement = nullptr;

			this->size = 0;
		}

		~List() {
			clear();
		}

		void push(TYPE* element) {
			this->size++;

			Element<TYPE>* newElement = new Element<TYPE>();
			newElement->setElementInfo(element);

			if (firstElement == nullptr) {
				this->firstElement = newElement;
				this->lastElement = newElement;
				return;
			}

			lastElement->setNextElement(newElement);
			lastElement = newElement;
		}

		Element<TYPE>* getFirstElement() {
			return firstElement;
		}

		void remove(TYPE* element) {
			Element<TYPE>* currentElement = this->firstElement;
			Element<TYPE>* previousElement = nullptr;

			while (currentElement->getElementInfo() != element) {
				previousElement = currentElement;
				currentElement = currentElement->getNextElement();
			}

			if (currentElement == this->firstElement) {
				firstElement = currentElement->getNextElement();

				if (this->size == 1)
					lastElement = nullptr;
			}
			else if (currentElement == this->lastElement) {
				previousElement->setNextElement(nullptr);
				lastElement = previousElement;
			}
			else {
				previousElement->setNextElement(currentElement->getNextElement());
			}

			delete currentElement;
			this->size--;
		}

		TYPE* getItem(int pos) {
			Element<TYPE>* currentElement = this->firstElement;

			for (int i = 0;i < pos;i++) 
				currentElement = currentElement->getNextElement();

			return currentElement->getElementInfo();
		}

		int getSize() {
			return size;
		}

		void clear() {
			Element<TYPE>* element = nullptr;

			for (int i = 0;i < size;i++) {
				element = firstElement;
				firstElement = firstElement->getNextElement();
				delete element;
			}

			firstElement = nullptr;
			lastElement = nullptr;
			this->size = 0;
		}
};


