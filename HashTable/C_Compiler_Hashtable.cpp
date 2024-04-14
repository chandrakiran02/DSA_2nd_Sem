#include<bits/stdc++.h>
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

	void insert(string x, string type){

		int index = hash(x);
		arr[index].first = type;

	}

	
};

bool check_operator(string s){
	for (char x : s){
		if(x == '+' || x == '-' || x == '*' || x == '%' || x == '/'){
			return true;
		}
	}
	return false;
}

string getString(char x)
{
    string s(1, x);
 
    return s;   
}

int main(){
    // use stack to evaluate the lines that are obtained from stringstream.
	stack<string> s;
	ClosedHashTable h;
	ifstream dox("input.txt", ios_base::in);
	string line;
	string curr_word;
	while(getline(dox,line )){
		stringstream ss(line);
		while(ss>>curr_word){
			if(s.empty() || curr_word == "="){
				s.push(curr_word);
			}
			else if (!s.empty() && curr_word == "="){
				//evaluate and assign 
				s.push(curr_word);
			}
			else if (!s.empty() && (s.top() == "int" || s.top() == "float")){
				// assign
				h.insert(curr_word, s.top());
			}
			else if (!s.empty() && s.top() == "="){

				s.pop(); // now top is the varaibale that is getting the evaluated value.

				if(check_operator(curr_word)){

					int index = h.hash(s.top());
					string type1 = h.arr[h.hash(getString(curr_word[0]))].first;
					string type2 = h.arr[h.hash(getString(curr_word[2]))].first;
					string type3 = h.arr[index].first;
					if (type1 == type2 && type2 == type3){

						if(type1 == "int"){
						
							int a = (h.arr[h.hash(getString(curr_word[0]))].second);
							int b = (h.arr[h.hash(getString(curr_word[2]))].second);

							switch (curr_word[1]){
							case '+': h.arr[index].second = a + b; break;
							case '-': h.arr[index].second = a - b; break;
							case '*':h.arr[index].second = a * b; break;
							case '/':h.arr[index].second = a/b; break;
							case '%' :h.arr[index].second =  a%b; break;
							default:
								break;
							}

						}

						if(type1 == "float"){

							int a = (h.arr[h.hash(getString(curr_word[0]))].second);
							int b = (h.arr[h.hash(getString(curr_word[2]))].second);

							switch (curr_word[1]){
							case '+': h.arr[index].second = a + b; break;
							case '-': h.arr[index].second = a - b; break;
							case '*':h.arr[index].second = a * b; break;
							case '/':h.arr[index].second = a/b; break;
							}

						}
				
					}
					else if (isdigit(curr_word[0])){
						h.arr[index].second = (h.arr[index].first == "int" ? stoi(curr_word) : stof(curr_word));
					}
					else {						
						h.arr[index].second = h.arr[h.hash((curr_word))].second;
					}

				
				}
			}	
			//clear stack
			while(!s.empty()){
				s.pop();
			}
		}
	}


	cout << h.arr[h.hash("c")].first;

}