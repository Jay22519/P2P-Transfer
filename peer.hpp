#pragma once
#include<bits/stdc++.h>
using namespace std ; 
class Peer
{
    int guid ; 
    map<int, string> file_stored ; 
    list<long long int> Routing_table ; 
    int connected ; 

    public :
        Peer() ; 
        Peer(int guid , list<int>peer_list) ; 
        int get_guid() ; //Will return guid of Peer 
        map<int, string> get_file_stored() ; 
        void get_routing_table() ; 
        //void path_peer(int peer_id , Peer peer[]) ; 
        string get_file(int file_id) ; // Will return file if it is there otherwise -1 ; 
        void add_file(int file_id , string content)  ;
        void remove_file(int file_id) ; 
        int ask_directory(int file_id) ;  // This will ask directory to return the peer containing given file_id ; 
        void rewrite_routing(list<int>peer_list) ; 
        string request_peer(int peer_guid , int file_id , Peer peer[], int n ) ;
        string pass_message_from_peer(int src_guid , int dst_guid , int file_id , Peer peer[], list<int> answer) ;
        string send_to_peer(int src_guid , int file_id) ;  


} ; 