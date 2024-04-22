#include <iostream>
#include <vector>
using namespace std;

class node{
public:
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
public:
    node* arr[47];
    int table_size = 47;
    
    HashTable() {
        for (int i = 0; i < 47; ++i) {
            arr[i] = nullptr;
        }
    }    

    int hash(string key){
        int return_value = 0;
        for (char x : key){
            return_value += (int(x) + table_size + 29)% table_size;
            
        }
        return return_value % table_size; // Ensure return value is within table size
    }

 void insert(string key){
    int hashed_Index = hash(key);
    
    if (!arr[hashed_Index]){
        arr[hashed_Index] = new node(key);
        return;
    }

    node* curr = arr[hashed_Index];
    while (curr){
        if (curr->key == key){
            curr->frequency++;
            return;
        }
        else if (!(curr->next)){
            curr->next = new node(key);
            return;
        }
        curr = curr->next;
    }
}


    node* find(string key){
        int index = hash(key);
        node* curr = arr[index];
        while (curr){
            if (curr->key == key){
                return curr;
            }
            curr = curr->next; // Move to the next node
        }
        return nullptr;
    }

    void remove(string key){
        node* element = find(key);
        if (!element){ return; }
        else{
            node* temp = arr[hash(key)];
            if (temp == element){
                arr[hash(key)] = temp->next;
                delete temp;
                return;
            }
            while (temp->next != element){
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
    s.insert("chandra");
    cout << s.find("chandra")->frequency;
    
}
