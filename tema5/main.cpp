#include<iostream>
#include"Hotel.cpp"

int main()
{
    Oras orasUser1("Timis","Timisoara");
    Address adrUser1("str M",12, orasUser1);
    InformUser infoUser1("Ana Popescu",22,adrUser1,748053323);
    User user1("anapop","12345",infoUser1);
    
    Hotel hotel1("Hotel Continental");
    hotel1.makeReservation(user1,"Rezervare1");
    hotel1.getReservations();
    return 0;
}