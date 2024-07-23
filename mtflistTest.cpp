#include <iostream>
#include "mtflist.h"
#include <cassert>

using namespace std;

// Test for the copy constructor with a non-empty list
bool CopyConstructorTest1() {
    MtfList test2;
    test2.add(1);
    test2.add(2);
    test2.add(3);

    MtfList test3(test2);

    bool sizeEqual = (test2.getCurrentSize() == test3.getCurrentSize());

    bool elementsEqual = true;
    for (int i = 0; i < test2.getCurrentSize(); ++i) {
        if (test2.retrieve(i) != test3.retrieve(i)) {
            elementsEqual = false;
            break;
        }
    }

    bool isEqual = sizeEqual && elementsEqual;

    return isEqual;
}

// Test for the copy constructor with an empty list
bool CopyConstructorTest2() {
    MtfList test2;

    MtfList test3(test2);

    bool sizeEqual = (test2.getCurrentSize() == test3.getCurrentSize());

    bool elementsEqual = true;
    for (int i = 0; i < test2.getCurrentSize(); ++i) {
        if (test2.retrieve(i) != test3.retrieve(i)) {
            elementsEqual = false;
            break;
        }
    }
    
    bool isEqual = sizeEqual && elementsEqual;

    return isEqual;
}

// Test for the copy constructor with a non-empty list, adding elements to the original list after copying
bool CopyConstructorTest3() {
    MtfList test2;

    for (int i = 0; i < 10; i++) {

        test2.add(i);
    }

    MtfList test3(test2);

    bool sizeEqual = (test2.getCurrentSize() == test3.getCurrentSize());

    bool elementsEqual = true;
    for (int i = 0; i < test2.getCurrentSize(); ++i) {
        if (test2.retrieve(i) != test3.retrieve(i)) {
            elementsEqual = false;
            break;
        }
    }
    
    bool isEqual = sizeEqual && elementsEqual;

    return isEqual;
}

// Test for adding a single element to an empty MtfList
bool AddTest1() {
    int output[] = {1};

    MtfList test1;

    test1.add(1);

    for(int i = 0; i < test1.getCurrentSize(); i++){
        if(output[i] != test1.retrieve(i)){
            return false;
        }
    }

   return true;
}

// Test for adding elements to an MtfList with repetitions
bool AddTest2() {

    MtfList test2;

    test2.add(1);
    test2.add(2);
    test2.add(1);

    int output[] = {1, 2};
    for(int i = 0; i < test2.getCurrentSize(); i++){
        if(output[i] != test2.retrieve(i)){
            return false;
        }
    }

   return true;
}

// Test for adding elements to an MtfList with repetitions
bool AddTest3() {

    MtfList test3;

    test3.add(1);
    test3.add(2);
    test3.add(3);
    test3.add(2);

    int output[] = {2, 3, 1};
    for(int i = 0; i < test3.getCurrentSize(); i++){
        if(output[i] != test3.retrieve(i)){
            return false;
        }
    }

   return true;
}

// Test for adding elements to an MtfList with repetitions and adding a new element
bool AddTest4() { 

    MtfList test4;

    for (int i = 0; i < 6; i++) {

        test4.add(i);
    }

    test4.add(0);

    int output[] = {0, 5, 4, 3, 2, 1};
    for(int i = 0; i < test4.getCurrentSize(); i++){
        if(output[i] != test4.retrieve(i)){
            return false;
        }
    }

   return true;
}

// Test for getting the size of an empty MtfList
bool GetSizeTest1(){

    MtfList test1;

    return test1.getCurrentSize() == 0;
}

// Test for getting the size of an MtfList with elements
bool GetSizeTest2(){

    MtfList test4;

    for (int i = 0; i < 6; i++) {

        test4.add(i);
    }

    return test4.getCurrentSize() == 6;
}

// Test for getting the size of an MtfList after removing an element
bool GetSizeTest3(){

    MtfList test4;

    for (int i = 0; i < 6; i++) {

        test4.add(i);
    }

    test4.remove(5);

    return test4.getCurrentSize() == 5;
}

// Test for removing an element from an empty MtfList
bool RemovalTest1() { 

    MtfList test5;

    return !(test5.remove(1));
}

// Test for removing a single element from an MtfList
bool RemovalTest2() { 

    MtfList test6;

    test6.add(1);

    return test6.remove(1) && test6.getCurrentSize() == 0;
}

// Test for removing a non-existing element from an MtfList
bool RemovalTest3() { 

    MtfList test7;

    test7.add(1);

    return ( !(test7.remove(0)) && test7.getCurrentSize() == 1 ) ;
}

// Test for removing an element from the middle of an MtfList
bool RemovalTest4() { 

    MtfList test8;

    for (int i = 0; i < 3; i++) {

        test8.add(i);
    }

    test8.remove(2);

    int output[] = {1, 0};
    for(int i = 0; i < test8.getCurrentSize(); i++){
        if(output[i] != test8.retrieve(i)){
            return false;
        }
    }

   return true;
}

// Test for removing an element from the middle of an MtfList
bool RemovalTest5() {

    MtfList test9;

    for (int i = 0; i < 6; i++) {

        test9.add(i);
    }

    test9.remove(3);

    int output[] = {5, 4, 2, 1, 0};
    for(int i = 0; i < test9.getCurrentSize(); i++){
        if(output[i] != test9.retrieve(i)){
            return false;
        }
    }

   return true;
}

// Test for removing an element from the middle of an MtfList
bool RemovalTest6() {

    MtfList test10;

    for (int i = 0; i < 20; i++) {

        test10.add(i);
    }

    test10.remove(12);

    int output[] = {19, 18, 17, 16, 15, 14, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for(int i = 0; i < test10.getCurrentSize(); i++){
        if(output[i] != test10.retrieve(i)){
            return false;
        }
    }

   return true;
}

// Test for removing the last element from an MtfList
bool RemovalTest7() { 

    MtfList test11;

    for (int i = 0; i < 5; i++) {

        test11.add(i);
    }

    test11.remove(4);


    int output[] = {3, 2, 1, 0};
    for(int i = 0; i < test11.getCurrentSize(); i++){
        if(output[i] != test11.retrieve(i)){
            return false;
        }
    }
    return true;
}

// Test for removing an element that doesn't exist in an MtfList
bool RemovalTest8() {

    MtfList test12;
    
    for (int i = 0; i < 6; i++) {

        test12.add(i);
    }

    test12.remove(7);


    int output[] = {5, 4, 3, 2, 1, 0};
    for(int i = 0; i < test12.getCurrentSize(); i++){
        if(output[i] != test12.retrieve(i)){
            return false;
        }
    }

    return true;
}

// Test for attempting to remove an element from an empty MtfList
bool RemovalTest9() {

    MtfList test13;

    for (int i = 0; i < 25; i++) {

        test13.add(i);
    }

    return ( !(test13.remove(40)) && test13.getCurrentSize() == 25 );
}

// Test for clearing an MtfList
bool ClearTest1() { 

    MtfList test14;

    for (int i = 0; i < 3; i++) {

        test14.add(i);
    }

    test14.clear();

    return test14.isEmpty();
}

// Test for retrieving an element at a specific index in an MtfList
bool RetrieveTest1() {

    MtfList test15;
    const int index = 10;
    const int result = 9;

    for (int i = 0; i < 20; i++) {

        test15.add(i);
    }

    return test15.retrieve(index) == result;
}

// Test for retrieving an element at a specific index after removing elements from an MtfList
bool RetrieveTest2() {

    MtfList test17;
    const int index = 5;
    const int result = 0;

    for (int i = 0; i < 10; i++) {

        test17.add(i);
    }

    for (int j = 2; j < 6; j++) {

        test17.remove(j);
    }

    return test17.retrieve(index) == result;
}

// Test for checking if an MtfList contains an element
bool ContainsTest1() { 

    MtfList test18;
    
    return !test18.contains(0);
}

// Test for checking if an MtfList contains an element after adding elements
bool ContainsTest2() { 

    MtfList test19;

    for (int i = 0; i < 9; i++) {

        test19.add(i);
    }

    test19.contains(0);

    return test19.retrieve(0) == 0;
}

// Test for checking if an MtfList contains an element after adding elements
bool ContainsTest3() { 

    MtfList test20;

    for (int i = 0; i < 18; i++) {

        test20.add(i);
    }

    test20.contains(17);

    return test20.retrieve(0) == 17;

}

// Test for checking if an MtfList contains an element that doesn't exist
bool ContainsTest4() {

    MtfList test22;

    for (int i = 0; i < 6; i++) {

        test22.add(i);
    } 

    return !test22.contains(10);
}

int main () {
    cout << "CopyConstructorTest1: ";
    cout << ( (CopyConstructorTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "CopyConstructorTest2: ";
    cout << ( (CopyConstructorTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "CopyConstructorTest3: ";
    cout << ( (CopyConstructorTest1()) ? "PASSED" : "FAILED" );
    cout << endl << endl;

    cout << "AddTest1: ";
    cout << ( (AddTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "AddTest2: "; 
    cout << ( (AddTest2()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "AddTest3: "; 
    cout << ( (AddTest3()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "AddTest4: "; 
    cout << ( (AddTest4()) ? "PASSED" : "FAILED" );
    cout << endl << endl;

    cout << "GetSizeTest1: ";
    cout << ( (GetSizeTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "GetSizeTest2: ";
    cout << ( (GetSizeTest2()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "GetSizeTest3: ";
    cout << ( (GetSizeTest3()) ? "PASSED" : "FAILED" );
    cout << endl << endl;

    cout << "RemovalTest1: ";
    cout << ( (RemovalTest1()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RemovalTest2: ";
    cout << ( (RemovalTest2()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RemovalTest3: ";
    cout << ( (RemovalTest3()) ? "PASSED" : "FAILED");
    cout << endl;
    
    cout << "RemovalTest4: ";
    cout << ( (RemovalTest4()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RemovalTest5: ";
    cout << ( (RemovalTest5()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RemovalTest6: ";
    cout << ( (RemovalTest6()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RemovalTest7: ";
    cout << ( (RemovalTest7()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RemovalTest8: ";
    cout << ( (RemovalTest8()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RemovalTest9: ";
    cout << ( (RemovalTest9()) ? "PASSED" : "FAILED");
    cout << endl << endl;

    cout << "ClearTest1: ";
    cout << ( (ClearTest1()) ? "PASSED" : "FAILED");
    cout << endl << endl;

    cout << "RetrieveTest1: ";
    cout << ( (RetrieveTest1()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "RetrieveTest2: ";
    cout << ( (RetrieveTest2()) ? "PASSED" : "FAILED");
    cout << endl << endl;

    cout << "ContainsTest1: ";
    cout << ( (ContainsTest1()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "ContainsTest2: ";
    cout << ( (ContainsTest2()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "ContainsTest3: ";
    cout << ( (ContainsTest3()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "ContainsTest4: ";
    cout << ( (ContainsTest4()) ? "PASSED" : "FAILED");
    cout << endl << endl;

    return 0;
}