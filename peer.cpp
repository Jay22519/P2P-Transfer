#include "peer.hpp"
#include<bits/stdc++.h>
using namespace std ; 

Peer :: Peer()
{
    
}

Peer :: Peer(int guid , list<int> peer_list)
{
    this->guid = guid ; 

    // Now creating routing table for this peer ; 
    int n  = peer_list.size() ; 
    int limit = log2(n) ; 
    for(int i = 0 ; i<=limit ; i++)
    {
        long long int peer_neighbour = ((long long int)pow(2,i) + this->guid)%n ;
        this->Routing_table.insert(peer_neighbour) ;
    }

     

} ;

int Peer ::get_guid()
{
    return this->guid ; 
} 


void Peer :: get_routing_table()
{
    cout<<"Printing Routing table for "<<this->guid<<"\n" ;
    for(auto i = this->Routing_table.begin() ; i != Routing_table.end() ; i++)
    {
        cout<<*i<<" " ; 
    }
    cout<<"\n" ; 
}

string Peer :: get_file(int file_id)
{
    /**
     * The extra layer of decryption is to be done
     */

    if(file_stored[file_id] == "")
    {
        return "File not there !" ; 
    }
    return file_stored[file_id] ; 

} 

void Peer ::add_file(int file_id , string content)
{
    file_stored[file_id] = content ; 
}

void Peer :: rewrite_routing(list<int>peer_list) 
{
    int n  = peer_list.size() ; 
    int limit = log2(n) ; 
    for(int i = 0 ; i<=limit ; i++)
    {
        this->Routing_table.insert(((long long int)pow(2,i) + this->guid)%n) ;
    }

}

int Peer :: ask_directory(int file_id)
{
    return 1 ; 
}

string Peer:: request_peer(int peer_guid , int file_id , Peer peer[])
{
    /**
      Extra layer of encrypting file_id   
     */

    if(peer_guid == guid)
    {
        return this->send_to_peer(this->guid , file_id) ; 
    }


    set<long long int> :: iterator i  ; 
    set<long long int> :: iterator prev  ;
    for(i = Routing_table.begin() ; i != Routing_table.end() ; i++)
    {
        
        if(*i > peer_guid)
        {
            return peer[*prev].pass_message_from_peer(this->guid , peer_guid , file_id , peer) ; 
        }
        else if(*i == peer_guid)
        {
            peer[peer_guid].send_to_peer(this->guid , file_id) ; 
        }
        else
        {
            prev = i ; 
        }
        
    }
    
    


}

string Peer ::pass_message_from_peer(int src_guid , int dst_guid , int file_id , Peer peer[])
{

    set<long long int> :: iterator i  ; 
    set<long long int> :: iterator prev  ;
    for(i = Routing_table.begin() ; i != Routing_table.end() ; i++)
    {

        if(*i > dst_guid)
        {
            return peer[*prev].pass_message_from_peer(this->guid , dst_guid , file_id , peer) ; 
        }
        else if(*i == dst_guid)
        {
            return peer[dst_guid].send_to_peer(src_guid , file_id) ; 
        }
        else
        {
            prev = i ; 
        }
        
    }
    

}

string Peer :: send_to_peer(int src_guid , int file_id)
{
    /**
     * The extra layer of decryption is to be done
     */

    if(file_stored[file_id] == "")
    {
        return "File not there !" ; 
    }
    return file_stored[file_id] ; 
} 






