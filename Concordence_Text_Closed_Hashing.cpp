#include<iostream>
using namespace std;

class ClosedHashTable{
    public:

        pair<string, int>* arr;
        int filled;
        int loadfactor;
        int table_size;

    ClosedHashTable(){
        filled = 0;
        loadfactor = 0;
        table_size = 37;
        arr = new pair<string, int>[37];
    }

    float load(){
        return filled/table_size;
    }

	int hash(string key){
		int index = 0;
		for(char x : key){
			index += (int(x)*int(x)*32 + 11)%table_size;
			
		}
		return index%table_size;	
	}
	bool is_prime(int val){
		for (int i = 2; i < val/2; i++){
			if (val%i == 0){
				return false;
			}
		}
		return true;
	}
	
	int next_prime(int val){
		int i = table_size;
		i *= 2;
		
		while(true){
			if(is_prime(i)){
				return i;
			}
			else{
				i++;
			}
		}
	}


	void insert(string key){
		int index = hash(key);  
		if(arr[index].first.empty()){
            arr[index].first = key;
            arr[index].second = 1;
			filled++;
		}
		else if(arr[index].first == key){
			arr[index].second++; 
		}
		else{
			// linear probe to another index
			int i = index+1;
			while(i%table_size != index){
                i = i%table_size;
				if(arr[i].first.empty()){
                    arr[i].first = key;
                    arr[i].second = 1;
					filled++;
                    break;
				}
                else if(arr[i].first == key){
			        arr[i].second++; 
                    break;
		        }
				i++;
			}
		}
        return;
	}
	int get(string key){
		
		int index = hash(key);
		
		if (arr[index].first == key){
			
			return arr[index].second;
			
		}
		else if (!arr[index].first.empty() && arr[index].first != key){
			//linear prbe 
			int i = index + 1;
			
			
			while(i%table_size != index){
				
				i = i%table_size;
				
			
				if (!arr[i].first.empty() && arr[i].first == key){
			
					return arr[i].second; 
			
				}
				else{
					i++;
				}
			}
            //if did not find anythinf then return 0.
		}
		return 0;
	}
	

};

int main(){

    ClosedHashTable h;
    h.insert("cha");
    h.insert("cha");
    cout << h.get("cha");
}