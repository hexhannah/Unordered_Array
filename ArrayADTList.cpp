#include "ArrayADTList.h"
using namespace std;

//Function Name: ArrayADTList
//Parameters:none
//Return: none
//Purpose: This is a default constructor for the
//ArrayADTList class and it sets length and cursor
//equal to 0 at the start of the declaration
//BigO:1
template<class DataType>
ArrayADTList<DataType>::ArrayADTList() {
    length = 0;                         //set length to 0
    cursor = 0;                         //set cursor to point to the first spot
}

//Function Name: getLength()
//Parameters: none
//Return: int
//Purpose: This is an accessor function and it
//returns the value assigned to the private variable
//length
//BigO:1
template <class Datatype>
int ArrayADTList<Datatype>::getLength() const{
    return (length);
}

//Function Name: putItem()
//Parameters: const DataType &item
//Return: void so none
//Purpose: If list is full will not insert item, throws error
//otherwise it will add item at the end and increase the value
//of length
//BigO:1
template<class DataType>
void ArrayADTList<DataType>::putItem(const DataType &item) {
    if (isFull()==true){                            //check if the list is full
        throw FullError();                          //throw Error if is
    }
    items[length]=item;                             //put new item at the end of the list
    length++;                                       //increase length by 1
}

//Function Name: getItem()
//Parameters: const DataType &item, DataType &found_item
//Return: bool
//Purpose: This function searches the list for "item" and sets
//variable "found_item" to the value in the list that is equivalent
//if item is not found then it returns false
//BigO:n
template<class DataType>
bool ArrayADTList<DataType>::getItem(const DataType &item, DataType &found_item) const{
    for(int i=0;i<length;i++){                      //for loop to look thru length of list
        if(items[i]==item){                         //if found an equivalent item
            found_item = items[i];                  //then set found_item to this value
            return true;                            //successfully found
        }
    }
    return false;                                   //nothing was found
}

//Function Name: isFull()
//Parameters: none
//Return: bool
//Purpose: Will return true if length is equal to MAX_SIZE
//which is 100. It will return false if length is less than
//100.
//BigO:1
template<class DataType>
bool ArrayADTList<DataType>::isFull() const {
    return length == MAX_SIZE;
}

//Function Name: makeEmpty()
//Parameters: none
//Return: void so none
//Purpose: makes length of list equal to 0
//BigO:1
template<class DataType>
void ArrayADTList<DataType>::makeEmpty() {
    length = 0;
}

//Function Name: deleteItem()
//Parameters: const int &item
//Return: bool
//Purpose: This function searches the list for "item" and
//if that item is found it moves that item to the last slot
//in the array then shortens the length by 1 to cut off the
//one we intended to delete
//BigO:n
template<class DataType>
bool ArrayADTList<DataType>::deleteItem(const int &item) {
    for(int i=0;i<length;i++){                          //for loop to iterate thru whole list
        if(items[i]==item){                             //if found an item equal to "item"
            items[i]=items[length-1];                   //move item to the end
            length--;                                   //shorten list by one (aka remove one at end)
            return true;                                //successfully found item
        }
    }
    return false;                                       //did not find item
}

//Function Name: resetList
//Parameters: none
//Return: void so none
//Purpose: The function sets the cursor to point at the beginning of the list
//BigO:1
template<class DataType>
void ArrayADTList<DataType>::resetList() {
    cursor = 0;                         //reset cursor to start
}

//Function Name: getNextItem()
//Parameters: DataType &item
//Return: bool
//Purpose: Checks if pointer is pointing to the end, otherwise makes
//item equal to whatever cursor is pointing to, and increases
//point by 1.
//BigO:1
template<class DataType>
bool ArrayADTList<DataType>::getNextItem(DataType &item){
    if (cursor == length){                      //check if cursor points to end
        return false;                           //cant get next item bc there isnt one
    }
    item = items[cursor];                       //item is what cursor is pointing to
    cursor++;                                   //increase cursor by one
    return true;                                //success aka cursor wasnt pointing at end
}

