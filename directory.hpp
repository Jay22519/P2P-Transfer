#pragma once
#include<bits/stdc++.h>
using namespace std ; 


class Directory 
{
    map<int , string> file_directory ; 
    map<int , list<int>> file_peer_map ;  
    list<int> peer_list_guid ;
    map<int , Peer> peer_list_map ; 
    int count  ; 
    public :
        Directory() ; 
        list<int> create_perr_list_guid(int n) ; 
        Peer add_new_peer() ; 
        list<int> get_peerlist() ; 
        void add_new_file(int file_id , string content  ,  int guid , Peer *p) ;
        void add_file_to_peer( int file_id , int guid  , Peer *p) ; 
        void remove_file_to_peer(int file_id , int guid , Peer *p) ;
        void check_system() ; 

} ; 