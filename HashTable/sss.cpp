#include<bits/stdc++.h>
using namespace std;
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

int main() {
    unordered_map<string, pair<string, int>> mp;
    string line;
    string curr_word;

    
    ifstream dox("input.txt");
    while (getline(dox, line)) {
        
        stringstream ss(line);
        stack<string> s; // Moved stack declaration outside the inner loop
        while (ss >> curr_word) {
            if (s.empty()) {
                s.push(curr_word);
                continue;
            }
            else if (!s.empty() && (s.top() == "int" || s.top() == "float")) {
                mp[curr_word].first = s.top();
                s.push(curr_word); continue;
            }
            else if(!s.empty() && curr_word == "="){
                s.push("=");continue;
            }
            else if(!s.empty() && s.top() == "="){
                s.pop();
               

				if(check_operator(curr_word)){
					string type1 = mp[s.top()].first;
					string type2 = mp[getString(curr_word[0])].first;
					string type3 = mp[getString(curr_word[2])].first;
					if (type1 == type2 && type2 == type3){

						
						
                        int a = (mp[getString(curr_word[0])].second);
                        int b = mp[getString(curr_word[2])].second;

                        switch (curr_word[1]){
                        case '+':mp[s.top()].second =  a + b; break;
                        case '-': mp[s.top()].second = a - b; break;
                        case '*':mp[s.top()].second = a * b; break;
                        case '/':mp[s.top()].second = a/b; break;
                        case '%' :mp[s.top()].second =  a%b; break;
                        default:
                            break;
                        }

                    

			
				
					}
                    else if (isalnum(curr_word[0]))  {
                        mp[s.top()].second =3;
                    }

					else {						
						mp[s.top()].second = mp[s.top()].second;
					}

				
				}
			}	
        }
    }


        dox.close();

        cout << mp["c"].second;

    return 0;

}
        
    

