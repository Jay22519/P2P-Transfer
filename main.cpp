#include "peer.cpp"
#include "directory.cpp"
#include<bits/stdc++.h>
using namespace std ; 


int main()
{

    Directory d ;
    list<int> peer_list = d.create_perr_list_guid(16) ; 
    Peer peers[16] ; 
    for(int i = 0 ; i<16 ; i++)
    {
        peers[i] = d.add_new_peer() ; 
    }
    // peers[0].get_routing_table() ;
    // peers[1].get_routing_table() ;
    // peers[2].get_routing_table() ;
    // peers[3].get_routing_table() ;
    // peers[9].get_routing_table() ;
    d.add_new_file(0 , "Jay" , 0 , &peers[0]) ; 
    d.add_new_file(1 , "Puri" , 1 , &peers[1]) ; 
    d.add_new_file(2 , "Goswami" , 2 , &peers[2]) ; 
    d.add_new_file(3 , "JPG" , 3 , &peers[3]) ; 
    d.add_new_file(4 , "Hi" , 4 , &peers[4]) ; 

    cout<<peers[3].request_peer(0,0,peers , 16)<<"\n" ; 
    fflush(stdout)  ;
    map<int, string> file = peers[0].get_file_stored() ; 
    for(const auto& elem : file)
    {
        cout<<elem.first<<" "<<elem.second<<"\n" ; 
        fflush(stdout)  ;
    }
    

    return 0 ;
}

// list<int> peer_list ;
    // for(int i = 0 ; i<16 ; i++)
    // {
    //     peer_list.push_back(i) ; 
    // }


    // Peer p[16] ;


    // for(int i = 0 ; i<16 ; i++)
    // {
    //     p[i] = Peer(i , peer_list) ; 
    //     //p[i].get_routing_table() ;
    // } 

    // //p[9].get_routing_table() ;

    // p[0].add_file(1 , "Jay") ;
    // p[1].add_file(2 , "Puri") ; 
    // p[2].add_file(3 , "Goswami") ; 
    // p[3].add_file(4 , "JPG") ; 
    // p[4].add_file(5 , "Hi !!") ;

     
    // cout<<p[0].request_peer(3,4,p , 16)<<"\n" ; 
    // cout<<p[3].request_peer(0,1,p , 16)<<"\n" ;



