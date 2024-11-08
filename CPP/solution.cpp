
//__________________________________________________________DhumketU_________________________________________________________
// _______________________________________________________SaQuiF::SoHoL______________________________________________________

#include <bits/stdc++.h>
using namespace std;

#define sq(_) (_)*(_)
#define write cout<<rslt<<"\n"
#define pb push_back
#define mp make_pair
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mx_e max_element
#define mn_e min_element
#define all(x) x.begin(),x.end()
#define sort_rev(x) sort(x.begin(),x.end(),greater<int>()) //__________less<int>() : is for non decreasing order.
#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define br "\n"
#define sp " "
#define printa(array) for(auto x: array)cout<<x<< sp;cout << br;
#define writea(array) for(auto x: array)cout<<x<< sp;cout << br;
#define printm(m) for(auto _:m) cout << _.first << " : " << _.second << br;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef set<int> SI;
typedef map<int, int> MII;
typedef map<string, string> MSS;
typedef map<string, int> MSI;
typedef map<int, string> MIS;
const int N = 2*1e5 + 10;
const int inf = 1e9;
const int MOD = 1e9+7;
//int even_cnt = count_if(a.begin(), a.end(), [](int it){return !(it&1);});		:: available in C++14 also
//int oddCnt = ranges::count_if(a, [&](int it){return it&1;});                  :: Only C++20 Support range::count_if


class Mytools{ //_____________________________________________MY TOOLS_____________________________________________________
    public:
    inline int in() { int _; scanf("%d", &_); return _; }
    inline long long lin() { long long  _; scanf("%lld",&_); return _; }
    inline string sin(){ string _; cin >> _; return _;}
    inline void ain(vector<int> &_) { for(auto &__: _) 	__ = in();	}
    inline void alin(vector<ll> &_) { for(auto &__: _) 	__ = lin();	}
    bool yn(bool _){ cout << (_? "YES\n": "NO\n");	return NULL;	}
    long int gcd(long long int a, long long int b) {	while (b != 0) { int tmp = a % b;	a = b; b = tmp; }	return a;}
    long long int lcm(long long int a, long long int b){ return a*b / gcd(a, b);}

    vector<int> unique_vector(vector<int> &_){ sort(_.begin(), _.end()); _.resize(unique(_.begin(), _.end()) - _.begin()); return _; }
    vector<string> splitStringIntoWords(string &s){
        vector<string> words; string word; stringstream ss; ss << s; while(ss >> word) words.push_back(word);
        return words;
    }

    void INTpreSum(vector<int> &a, vector<int> &pf){
    	int n = a.size(); pf[0] = a[0]; for(int i=1; i<n; i++){ pf[i] = pf[i-1] + a[i]; }}
    void LLpreSum(vector<long long int> &a, vector<long long int> &pf){ int n = a.size(); pf[0] = a[0];
    	for(int i=1; i<n; i++){ pf[i] = pf[i-1] + a[i]; }
    }

	int stringToInt(string s){
  		int rslt = 0, mul = 1; int r = s.size()-1; reverse(all(s));
  		while(r >= 0){
  			if(s[r] == '-'){
  				mul = -1; r--; continue;
  			}
  			rslt = rslt*10 + s[r] - 48;
  			r--;
  		}
  		return rslt * mul;
  	}

    int binSearch(vector<int> &nums, int to_find){
        int n = nums.size(), l = 0, h = n-1;
        while(h-l > 1){
            int mid = (h+l)/2;
            if(nums[mid] < to_find) l = mid+1;
            else h = mid;
        }
        return nums[l]==to_find? l:nums[h]==to_find? h:-1;
    }

};

class Calculator{
private:
	string qs;
public:

	string helper_sum_add(string a, string b, string op){
		double x = stod(a);
		double y = stod(b);
		if(op == "+"){
			return to_string(x+y);
		}
		return to_string(x-y);
	}

	string helper_div_mul(string a, string b, string op){
		double x = stod(a);
		double y = stod(b);
		if(op == "*"){
			return to_string(x*y);
		}
		return to_string(x/y);
	}

	string bracketless(vector<string> &a){
		stack<string> st;
		for(int i=0; i<a.size(); i++){
			if(a[i]=="*" || a[i]=="/"){
				string rslt = helper_div_mul(st.top(), a[i+1], a[i]);
				st.pop();
				i++;
				st.push(rslt);
			}else{
				st.push(a[i]);
			}
		}
		stack<string> st2;

		while(!st.empty()){
			string tmp = st.top();
			st.pop();
			if(tmp == "+" || tmp == "-"){
				string aa = st2.top();
				st2.pop();
				string bb = st.top();
				st.pop();
				string rslt = helper_sum_add(aa, bb, tmp);
				st2.push(rslt);
			}else{
				st2.push(tmp);
			}

		}

		cout << st2.top();


		return "";

	}
	Calculator(){
		cin >> qs;
		vector<string> vs;
		

		int i=0;
		int n = qs.size();
		while(i<n){
			if(i<n && qs[i] >= '0' && qs[i] <= '9'){
	            string number = "";
	            while(i<n && qs[i] >= '0' && qs[i] <= '9'){
	                    number += qs[i++];
	            }
	            vs.pb(number);
			}else{
			    string tmp = "";
			    tmp += qs[i++];
	            vs.pb(tmp);
			}
		}
		bracketless(vs);

	}
};



void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}


int main(){             // __________________________Main Function________________________

	init_code();
	Calculator calculator;

    return 0;
}



