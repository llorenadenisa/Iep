// #include<iostream>
// #include "Student.hpp"
// #include<mutex>
// class LockStudent
// {
//     public:
//     explicit LockStudent(LockStudent *pm): mutexPtr(pm)
//     { 
//         std::lock(mutexPtr); 
//     } 
//     ~LockStudent() 
//     { 
//         std::unlock(mutexPtr); 
//     } 
//     private:
//     LockStudent *mutexPtr;
// };