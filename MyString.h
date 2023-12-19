// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>


using std::ostream;

class MyString{
    private:
        size_t cap = 1; //tracks current size of the internal array
        size_t width = 0; //current number of elements in array
        char* Data = nullptr;
    public:
        //default constructor
        MyString(); //Constructs an empty string, with a length of zero characters.

        //copy contructor
        MyString(const MyString& str); //creates a copy of str

        //constructor from c-string
        MyString(const char* s);  //Copies the null-terminated character sequence (C-string) pointed by s.

        //destructor
        ~MyString(); //clears all elements

        //resize
        void resize(size_t n);  //Resizes the string to a length of n characters.

        //capacity
        size_t capacity(); //Tracks the current size of the internal array

        //size
        size_t size() const; //size is the current member of elements in the array

        //length 
        size_t length(); //size and length return the same value

        //data
        const char* data(); //This function returns the internal character array’s reference because it is actually a c-string on the inside, so remember the null terminator

        //empty
        bool empty(); //returns whether string is empty or not

        //front
        const char& front() const; //returns reference to first character of the string

        //at
        const char& at (size_t pos) const; //returns a reference to the character at position pos on the string

        //clear
        void clear() noexcept; //erases the contents of the string

        //operator<<
        friend ostream& operator<< (ostream& os, const MyString& str); //Inserts the sequence of characters that conforms value of str into os.

        //operator=
        MyString& operator= (const MyString& str); //Assigns a new value to the string, replacing its current contents.

        //operator+=
        MyString& operator+= (const MyString& str); //Extends the string by appending additional characters at the end of its current value:

        //find
        size_t find (const MyString& str, size_t pos = 0) const noexcept; //Searches the string for the first occurrence of the sequence specified by its arguments.

        //operator==
        friend bool operator== (const MyString& lhs, const MyString& rhs);

        //operator+
        friend MyString& operator+ (const MyString& lhs, const MyString& rhs);








};






#endif