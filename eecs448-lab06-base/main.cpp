/**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedListOfInts.h"

TEST_CASE("Items can be added to the list", "[list]"){
	/*testing if adding to the front works*/
	SECTION("adding to the front"){
		LinkedListOfInts listFront;
		/*checing the size and the isEmtpy method*/
		CHECK(listFront.size() == 0);
		CHECK(listFront.isEmpty() == true);

		/*adding nodes to the list*/
		listFront.addFront(2);
		CHECK(listFront.size() == 1);
		/*this check is wrong, the list is not empty at this point*/
		CHECK(listFront.isEmpty() == false);
		std::vector<int> vectorList = listFront.toVector();
		CHECK(vectorList[0] == 2);

		listFront.addFront(1);
		CHECK(listFront.size() == 2);
		listFront.addFront(0);
		CHECK(listFront.size() == 3);
		vectorList = listFront.toVector();
		CHECK(vectorList[0] == 0);
		CHECK(vectorList[1] == 1);
		CHECK(vectorList[2] == 2);
		CHECK(listFront.isEmpty() == false);
	}
	/*checking if the method addBack() works*/
	SECTION("adding to the back"){
		/*there is a bug here, adds to the front instead of to the back*/
		LinkedListOfInts listBack;
		listBack.addBack(0);
		listBack.addBack(1);
		listBack.addBack(2);
		std::vector<int> vList = listBack.toVector();
		CHECK(vList[0] == 0);
		CHECK(vList[1] == 1);
		CHECK(vList[2] == 2);
	}
}

/*testing the two remove methods()*/
TEST_CASE("Items can be removed from the list", "[list]"){
	/*checking removeFront() method*/
	SECTION("removing from the front"){
		/*this does not work at all, nothing is removed from the list, nothing changes*/
		LinkedListOfInts listRF;
		listRF.addFront(2);
		listRF.addFront(1);
		listRF.addFront(0);
		std::vector<int> vectorList = listRF.toVector();
		CHECK(vectorList[0] == 0);
		CHECK(vectorList[1] == 1);
		CHECK(vectorList[2] == 2);
		CHECK(vectorList.size() == 3);

		listRF.removeFront();
		vectorList = listRF.toVector();
		CHECK(vectorList[0] == 1);
		CHECK(vectorList[1] == 2);
		CHECK(vectorList.size() == 3);

		listRF.removeFront();
		vectorList = listRF.toVector();
		CHECK(vectorList[0] == 2);
		CHECK(vectorList.size() == 1);


		listRF.removeFront();
		vectorList = listRF.toVector();
		CHECK(vectorList.size() == 0);
	}
	/*testing the removeBack() method*/
	SECTION("removing from the back"){
		/*this does not work at all, nothing is removed from the list, nothing changes*/
		LinkedListOfInts listRB;
		listRB.addFront(2);
		listRB.addFront(1);
		listRB.addFront(0);
		std::vector<int> vectorList = listRB.toVector();
		CHECK(vectorList[0] == 0);
		CHECK(vectorList[1] == 1);
		CHECK(vectorList[2] == 2);
		CHECK(vectorList.size() == 3);
		CHECK(listRB.size() == 3);

		listRB.removeBack();
		vectorList = listRB.toVector();
		CHECK(vectorList[0] == 0);
		CHECK(vectorList[1] == 1);
		CHECK(vectorList.size() == 2);

		listRB.removeBack();
		vectorList = listRB.toVector();
		CHECK(vectorList[0] == 0);
		CHECK(vectorList.size() == 1);

		listRB.removeBack();
		vectorList = listRB.toVector();
		CHECK(vectorList.size() == 0);
	}
}
/*testing the search() method, should return true if found and false if not*/
TEST_CASE("testing the search method", "[list]"){
		LinkedListOfInts listS;
		listS.addFront(100);
		listS.addFront(2);
		listS.addFront(1);
		listS.addFront(0);
		std::vector<int> vectorList = listS.toVector();

		CHECK(vectorList[0] == 0);
		CHECK(vectorList[1] == 1);
		CHECK(vectorList[2] == 2);

		/*checking if what was added is in the list*/
		CHECK(listS.search(0) == true);
		CHECK(listS.search(2) == true);
		CHECK(listS.search(100) == true);
		/*making sure it returns false if it is not in the list*/
		CHECK(listS.search(10) == false);

}
