#include "peer.cpp"
#include<bits/stdc++.h>
using namespace std ; 


int main()
{
    list<int> peer_list ;
    for(int i = 0 ; i<16 ; i++)
    {
        peer_list.push_back(i) ; 
    }


    Peer p[16] ;


    for(int i = 0 ; i<16 ; i++)
    {
        p[i] = Peer(i , peer_list) ; 
        //p[i].get_routing_table() ;
    } 

    //p[9].get_routing_table() ;

    p[0].add_file(1 , "Jay") ;
    p[1].add_file(2 , "Puri") ; 
    p[2].add_file(3 , "Goswami") ; 
    p[3].add_file(4 , "JPG") ; 
    p[4].add_file(5 , "Hi !!") ;

     
    cout<<p[0].request_peer(3,4,p , 16)<<"\n" ; 
    cout<<p[3].request_peer(0,1,p , 16)<<"\n" ;




    return 0 ;
}