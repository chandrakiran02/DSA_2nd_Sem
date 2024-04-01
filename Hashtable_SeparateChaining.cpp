#include<iostream>
#include<vector>
using namespace std;

// Declare the table size
// The keys are the words, and the line number and frequency of them is the value, which is a pair.
class node{
    public :
        string key;
        int frequency;
        node* next;
    
        node(string k){

            key = k;
            frequency = 1;
            next = nullptr;

        }
};

class HashTable{
    private:
        node* arr[47];
        int table_size = 47;
    public:

    int hash(string key){
        int return_value = 0;
        int random = 23;
        for (char x : key){
            return_value += (int(x)+table_size + int(x)*random*random + 29)%table_size;
            random+= 5*(return_value)%28;
        }
        return return_value;
    }


    //If you want to insert a key int the hash table,
    void insert(string key){
        int hashed_Index = hash(key);
        if(!(arr[hashed_Index])){
            arr[hashed_Index] = new node(key); 
            return;
        }
        node* curr = arr[hashed_Index];
        //Case when there is already an element present on the hashed index.
        //Search for it in the list, if there no key, insert at the end.
        while(curr){

            if(curr->key == key){
                //if found, update the line, freq.
                curr->frequency++;
                return;
            }
            else if(!(curr->next)){
                curr->next = new node(key);
                return;
            }
            curr = curr->next;

        }
    }
    node* find(string key){
        int index = hash(key);
        node* curr = arr[index];
        while(curr){
            if(curr->key == key){
                return curr;
            }
        }
        return nullptr;
    }

    void remove(string key){
        node* element = find(key);
        if(!element){return;}
        else{
            node* temp = arr[hash(key)];
            while(temp->next != element){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete element;
            return;
        }

    }


};

int main(){
    HashTable s;
    s.insert("chandra");
    s.insert("kiran");
    s.insert("chandra");

    cout << s.find("kiran")->frequency;
}