#include "peer.hpp"
#include<bits/stdc++.h>
using namespace std ; 

void block(long int x , list<int> *answer)
{
    vector<long int> v;
    //cout << "Blocks for " << x << " : ";
    while (x > 0)
    {
        v.push_back(x % 2);
        x = x / 2;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
           
            answer->push_back(i) ; 
            // if (i != v.size() - 1)
            //     cout << ", ";
        }
    }
    cout << endl;
}


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
        this->Routing_table.push_back(peer_neighbour) ;
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
        this->Routing_table.push_back(((long long int)pow(2,i) + this->guid)%n) ;
    }

}

int Peer :: ask_directory(int file_id)
{
    return 1 ; 
}

/**
 *          Request_user is the function invoked when any peer wants to look for file_id in peer with guid = peer_guid . 
 *          3 cases comes here -> 1) guid < peer_guid 
 *                                2) guid == peer_guid 
 *                                3) guid > peer_guid 
 * 
 *                          Now in case 1 , we traverse the routing_table of guid and break when *i > peer_guid and calling pass_message_from_peer
 *                          function for *prev peer
 * 
 *                          For case 2 , simply call send_to_peer function 
 *              
 *                          For case 3 , add n (Total number of peers in network) to peer_guid and traverse in routing table of guid , till -> 
 *                                      a) if *i > 
 */
string Peer :: request_peer(int peer_guid , int file_id , Peer peer[] , int n )
{
    if(peer_guid > guid)
    {
        long long int diff =  fabs(guid - peer_guid) ; 
        list<int> answer ; 
        block(diff , &answer) ; 

        for(auto i = answer.begin() ; i != answer.end() ; i++)
        {
            *i = (*i) + 1 ; 
        }

        long int iter = answer.front() ; 
        long int count =  1 ;  
        list<long long int> :: iterator it = Routing_table.begin() ; 
        while(count < iter)
        {
            it++ ;
            count ++ ;
        }
        answer.pop_front() ; 
        if(answer.empty())
        {     
            return peer[*it].send_to_peer(guid , file_id) ; 
        }
        
        return peer[*it].pass_message_from_peer(guid , peer_guid , file_id , peer , answer) ; 
        
    }
    else if(peer_guid == guid)
    {
        return this->send_to_peer(guid , file_id) ; 
    }
    else // peer_guid < guid
    {
            long long int diff =  n - fabs(guid - peer_guid) ; 
            list<int> answer ; 
            block(diff , &answer) ; 

            for(auto i = answer.begin() ; i != answer.end() ; i++)
            {
                *i = (*i) + 1 ; 
            }
            long int iter = answer.front() ; 
            long int count =  1 ;  
            list<long long int> :: iterator it = Routing_table.begin() ; 
            while(count < iter)
            {
                it++ ;
                count ++ ;
            }
            answer.pop_front() ; 
            if(answer.empty())
            {
                
                return peer[*it].send_to_peer(guid , file_id) ; 
            }
            
            return peer[*it].pass_message_from_peer(guid , peer_guid , file_id , peer , answer) ; 
            




    }
}

// Nearly same logic as request_peer 
string Peer ::  pass_message_from_peer(int src_guid , int dst_guid , int file_id , Peer peer[] , list<int> answer)
{
        if(dst_guid > guid)
        { 
            long int iter = answer.front() ; 
            long int count =  1 ;  
            list<long long int> :: iterator it = Routing_table.begin() ; 
            while(count < iter)
            {
                it++ ;
                count ++ ;
            }
            answer.pop_front() ; 
            if(answer.empty())
            {
                
                return peer[*it].send_to_peer(guid , file_id) ; 
            }
            
            return peer[*it].pass_message_from_peer(guid , dst_guid , file_id , peer , answer) ; 
            
        }
        else if(dst_guid == guid)
        {
                return this->send_to_peer(src_guid , file_id) ; 
        }
        else  // dst_guid < guid
        {
            
            long int iter = answer.front() ; 
            long int count =  1 ;  
            list<long long int> :: iterator it = Routing_table.begin() ; 
            while(count < iter)
            {
                it++ ;
                count ++ ;
            }
            answer.pop_front() ; 
            if(answer.empty())
            {
                
                return peer[*it].send_to_peer(guid , file_id) ; 
            }
            
            return peer[*it].pass_message_from_peer(guid , dst_guid , file_id , peer , answer) ; 
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






