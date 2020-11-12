#include<iostream>
#include "Student.hpp"
class LockStudent
{
    public:
    explicit LockStudent(LockStudent *pm): mutexPtr(pm)
    { 
        lock(mutexPtr); 
    } 
    ~LockStudent() 
    { 
        unlock(mutexPtr); 
    } 
    private:
    LockStudent *mutexPtr;
};