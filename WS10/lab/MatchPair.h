/***********************************************************************
// OOP244 Workshop 10 p1: MatchPair Temaplate
//
// File: MatchPair.h
// Version 1.0
// Date: Oct 4, 2023
// Author: Jeevan Pant
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef MATCHPAIR_H
#define MATCHPAIR_H

namespace seneca {

	template<typename T, typename U>
	struct Pair {
		T first{};
		U second{};
	};

	template<typename T, typename U>
	void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size) {
		Pair<T, U>* temp = new Pair<T, U>[size + 1];
		for (int k = 0; pArray && k < size; k++) {
			temp[k] = pArray[k];
		}
		temp[size].first = first;
		temp[size].second = second;
		delete[] pArray;
		pArray = temp;
		size++;
	}

	template<typename T, typename U>
	Pair<T,U>* matches(const T* arr1, const U* arr2, const int size1, const int size2, int& size3) {
		Pair<T, U>* pt{};
		size3 = 0;
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				if (arr1[i] == arr2[j]) {
					addDynamicPairElement(pt, arr1[i], arr2[j], size3);
				}
			}
		}

		return pt;
	}

	template<typename T>
	T* releaseMem(T*& ptr) {
		if (ptr) {
			delete[] ptr;
			ptr = nullptr;
		}

		return ptr;
	}
}

#endif // !MATCHPAIR_H
