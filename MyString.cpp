// TODO: Implement this source file
#include "MyString.h"
#include <iostream>

//default constructor
MyString::MyString(){ //Constructs an empty string, with a length of zero characters.
    cap = 1;
    width =0;
    Data = new char[cap];
    Data[0]='\0';
}

// copy contructor
MyString::MyString(const MyString& str){ //creates a copy of str
    cap = str.cap;
    width = str.width;
    Data = new char[cap]; //there can be capacity after null, adding one to include null character
    for(size_t i = 0; i<width;i++){
        Data[i]=str.Data[i];
    }
    Data[width] = '\0'; //adding null character to the end

}

//constructor from c-string
MyString::MyString(const char* s){ //Copies the null-terminated character sequence (C-string) pointed by s.
    size_t k =0;
    while(s[k]!='\0'){
        k++;
    }
    width = k;
    cap = k+1;
    Data = new char[cap]; //add one to make room for the null character
    for(size_t i =0;i<cap;i++){
        Data[i]=s[i];
    }
    // Data[width] = '\0';
}

//destructor
MyString::~MyString(){ //clears all elements
    delete[] Data;
    Data = nullptr;
    width =0;
    cap =0;
}

//resize
void MyString::resize(size_t n){ //Resizes the string to a length of n characters.
    cap = n+1;
    width = n;
    char* temp = new char[cap];
    for(size_t i =0;i<width;i++){
        temp[i] = Data[i];
    }

    // clear();
    Data = temp;
    // for(size_t i=width; i<n; i++){
    //     Data[i] = 'c';
    // }
}

//capacity
size_t MyString::capacity(){ //Tracks the current size of the internal array
    return cap;
} 

//size
size_t MyString::size() const{ //size is the current member of elements in the array
    return width;
}
//length 
size_t MyString::length(){ //size and length return the same value
    return width;
} 

//data
const char* MyString::data(){ //This function returns the internal character array’s reference because it is actually a c-string on the inside, so remember the null terminator
    return Data;
} 

//empty
bool MyString::empty(){ //returns whether string is empty or not
    if(Data[0]=='\0'){
        return true;
    }
    else{
        return false;
    }
} 

//front
const char& MyString::front() const{ //returns reference to first character of the string
    return Data[0];
} 

//at
const char& MyString::at (size_t pos) const{//returns a reference to the character at position pos on the string
    if(pos>=width){
        throw std::out_of_range("");
    }
    return Data[pos];
} 

//clear
void MyString::clear() noexcept{//erases the contents of the string
    if(width!=0){
        // delete[] Data;
        width =0;
        cap =1;
    // Data = nullptr;
        // Data = new char[1];
        Data[0] ='\0';
    }
     //allocate new memory
} 

//operator<<
ostream& operator<< (ostream& os, const MyString& str){ //Inserts the sequence of characters that conforms value of str into os.
    for(size_t i =0;i<str.width;i++){
        os << str.Data[i];
    }
    return os;
} 

//operator=
MyString& MyString::operator= (const MyString& str){ //Assigns a new value to the string, replacing its current contents.
    // if(Data!=nullptr){
    //     delete[] Data; //delete existing data to avoid memory leaks
    // }
    if(this!=&str){
        delete[] Data;
        cap = str.cap;   //was creating shallow copy before (trying to delete both pointers which will cause memory error)
        width = str.width;
        Data = new char[cap]; //there can be capacity after null, adding one to include null character
        for(size_t i = 0; i<width;i++){
            Data[i]=str.Data[i];
        }
        Data[width] = '\0'; //adding null character to the end
    }
    return *this;
} 

//operator+=
MyString& MyString::operator+= (const MyString& str){ //Extends the string by appending additional characters at the end of its current value:
    size_t newSize = width+str.width;
    size_t newCap = cap + str.cap;
    char* d =new char[newCap + 1]; //add one for null
    for(size_t i = 0;i<width;i++){
        d[i] = Data[i];
    }
    for(size_t i = 0; i<str.width;i++){
        d[width+i] = str.Data[i];
    }
    d[newSize] = '\0';
    delete[] Data;
    Data = d;
    width = newSize;
    cap = newCap;
    return *this;
} 

//find
size_t MyString::find (const MyString& str, size_t pos)const noexcept{ //Searches the string for the first occurrence of the sequence specified by its arguments.
    size_t matches = 0;
    size_t start_index =0;
    for(size_t i =pos; i<cap;i++){
        if(matches==str.width){ //full match found
            start_index = i - matches;
            return start_index;
        }
        else if(Data[i]==str.Data[matches]){ //match found
            matches++;
        }
        else{ //no match found
            matches = 0;
        }
    }
    return -1; //no match found
} 

//operator ==
bool operator== (const MyString& lhs, const MyString& rhs){
    if(lhs.width == rhs.width && lhs.cap == rhs.cap){
        for(size_t i =0;i<rhs.width;i++){
            if(lhs.Data[i]!=rhs.Data[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

MyString& operator+(const MyString& lhs, const MyString& rhs){
    size_t newSize = lhs.width+rhs.width;
    size_t newCap = lhs.cap + rhs.cap;
    char* d =new char[newCap + 1]; //add one for null
    for(size_t i = 0;i<lhs.width;i++){
        d[i] = lhs.Data[i];
    }
    for(size_t i = 0; i<rhs.width;i++){
        d[lhs.width + i] = rhs.Data[i];
    }
    d[newSize] = '\0';
    MyString* newString = new MyString();
    newString->Data = d;
    newString-> width = newSize;
    newString->cap = newCap;
    // delete[] Data;
    // Data = d;
    // width = newSize;
    // cap = newCap;
    return *newString;

}

