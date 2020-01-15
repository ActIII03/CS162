bool remove_largest_int()
{
    if(!head)    
        return false;
    
    //find largest
    int largest_num = head -> data;
    node * current = head -> next;
    while(!current -> next){    
        if(current -> data > largest_num){
            largest_num = current -> data;    
            current = current -> next
        }
        current = head;
       
        //Head is the largest int
        if(head -> data == largest_num){    
            node * temp = head -> next;    
            delete head;    
            head = temp;    
            return true;
        }
        else{    
            node * current = head -> next;    
            node * previous = head;    
            while(!current -> next){        

                if(current -> data == largest_num){            
                    previous -> next = current -> next;            
                    delete current;            
                    return true;        
                }
            }                
            previous = current;        
            current = current -> next;    
            }
            
            //Last item is the largest int

            if(current -> data == largest_num){    
                delete current;    
                previous -> next = NULL;    
                return true;
            }
            else    
                return false;
        }
}
