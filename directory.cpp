#include "directory.hpp"
#include<bits/stdc++.h>
using namespace std ; 

Directory :: Directory()
{
        this->count = 0 ; 
}

list<int> Directory :: create_perr_list_guid(int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        peer_list_guid.push_back(i) ; 
    }

    return peer_list_guid  ; 
}

Peer Directory :: add_new_peer() 
{
    Peer p = Peer(this->count , peer_list_guid) ; 
    peer_list_map[count] = p ;  
    this->count += 1 ;
    return  p   ; 

}

list<int> Directory :: get_peerlist()
{
    return peer_list_guid  ; 
}

void Directory :: add_new_file(int file_id , string content , int guid , Peer *p) 
{
    // Check if peer with guid exist or not 
    int done = 0 ; 
    for(auto it = peer_list_guid.begin() ; it !=peer_list_guid.end() && !done  ;  it++)
    {
        if(*it == guid)
        {
            done = 1 ; 
        }
    }

    if(!done)
    {
        cout<<"Couldn't add because peer doesn't exist\n" ; 
        return ; 
    }

    // Check if a given file is already in system or not ; 
    if(file_directory[file_id] != "")
    {
        cout<<"File already exist . Use add_file_to_peer( int file_id , int guid) function" ; 
        return ; 
    }

    file_directory[file_id] = content ; 
    peer_list_map[guid].add_file(file_id , content) ; 
    p->add_file(file_id , content) ; 



}


void Directory ::  add_file_to_peer( int file_id , int guid , Peer *p)
{
    // Check if file exist or not 
    int done = 0 ; 
    for(auto it = peer_list_guid.begin() ; it !=peer_list_guid.end() && !done  ;  it++)
    {
        if(*it == guid)
        {
            done = 1 ; 
        }
    }

    if(!done)
    {
        cout<<"Couldn't add because peer doesn't exist\n" ; 
        return ; 
    }

    //Check if given file exist or not 
    if(file_directory[file_id] == "")
    {
        cout<<"File don't exist . Please use add_new_file(int file_id , string content , int guid) " ; 
        return ; 
    }

    peer_list_map[guid].add_file(file_id , file_directory[file_id]) ; 
    p->add_file(file_id , file_directory[file_id]) ; 

}

void Directory ::  remove_file_to_peer(int file_id , int guid , Peer *p) 
{
    // Check if file exist or not 
    int done = 0 ; 
    for(auto it = peer_list_guid.begin() ; it !=peer_list_guid.end() && !done  ;  it++)
    {
        if(*it == guid)
        {
            done = 1 ; 
        }
    }

    if(!done)
    {
        cout<<"Couldn't add because peer doesn't exist\n" ; 
        return ; 
    }

    //Check if given file exist or not 
    if(file_directory[file_id] == "")
    {
        cout<<"File don't exist  " ; 
        return ; 
    }

    //Check if given file exsit in given file or not

    map<int, string> file_stored = peer_list_map[guid].get_file_stored() ;
    if(file_stored[file_id] == "")
    {
        cout<< "Given file doesn;t exist in given peer" ; 
        return ; 
    }

    peer_list_map[guid].remove_file(file_id) ; 
    p->remove_file(file_id) ; 

}

void Directory :: check_system()
{
    return ; 
} 