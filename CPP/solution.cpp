
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

class Search{
public:
	int binarySearch(VI &a, int key){
		int n = a.size();
		int k = 0;
		for(int i=n/2; i>=1; i/=2){
			while(i+k<n && a[i+k] <= key) k+=i;
		}
		if(a[k] == key)
			return k;
		return -1;
	}
};

class Sort{
public:
	int merge(vector<int> &a, int l, int r, int mid){
		VI x, y;
		for(int i=l; i<=mid; i++)
			x.pb(a[i]);
		for(int i=mid+1; i<=r; i++)
			y.pb(a[i]);

		int n = x.size(), m = y.size();
        int i = 0, j = 0, k = l;
		while(i<n && j<m){
			if(x[i] < y[j]){
				a[k++] = x[i++];
			}
			else{
				a[k++] = y[j++];
			}
		}
		while(i<n)
			a[k++] = x[i++];
		while(j<m)
			a[k++] = y[j++];

		return 0;
	}

	int mergeSort(vector<int> &a, int l, int r){
		if(l==r)
			return 0;
		int mid = (l+r)/2;
		mergeSort(a, l, mid);
		mergeSort(a, mid+1, r);

		merge(a, l, r, mid);

		return 0;
	}

};


class CompleteSearch{ //____________Complete Search : generating subsets, generating permutaions____________
public:
	int length;
	vector<int> subset;
	vector<vector<int>> subsets;

	vector<vector<int>> genSubsets(int n){ // _________Generating subsets___________
		length = n;
		search(0);
		return subsets;
	}


	void processSubset(){
		subsets.push_back(subset);
	}

	void search(int k){
		if(k==length){
			processSubset();
		}else{
			search(k+1);
			subset.push_back(k);
			search(k+1);
			subset.pop_back();
		}

	}

};



class Solution{   //_____________________________________________SOLUTION CLASS____________________________________________
public:
    Mytools t;

    Solution(){
    	int T = t.in();
  		for(int i=1; i<=T; i++){
  			// cout << "Case " << i << ": ";// << endl;
  			solve_testcase();
  		}
    }

    
  	int solve_testcase(){

  		string s;
		cin >> s;
		
  		
  		vector<string> tokens;
  		
		string number = "";
		int i = 0;
		while(s[i] != '\0'){
			if(isdigit(s[i])){
				while(s[i] != '\0' && isdigit(s[i])){
					number += s[i++];
				}
			}else{
				if(number.size() > 0){
					tokens.pb(number);
					number = "";
				}
				string sign = "";
				sign += s[i];
				tokens.pb(sign);
				i++;
			}
		}
		if(!number.empty()){
			tokens.pb(number);
		}

		for(auto token: tokens){
			cout << token << sp;
		}

  		map<string, std::function<double(double, double)>> ops = {
  			{"+", [](double a, double b){ return a+b; }},
  			{"-", [](double a, double b){ return a-b; }},
  			{"*", [](double a, double b){ return a*b; }},
  			{"/", [](double a, double b){ return a/b; }},
  		};

  		stack<double> values_st;
  		stack<string> op_st;

  		auto apply_operation = [&](){
  			double right = values_st.top();
  			values_st.pop();
  			double left = values_st.top();
  			values_st.pop();
  			string op = op_st.top();
  			op_st.pop();

  			values_st.push(ops[op](left, right));
  		};

  		map<string, int> precedence = {
  			{"+", 1},
  			{"-", 1},
  			{"*", 2},
  			{"/", 2},
  		};

  		for(string str: tokens){
  			if(str[0] >= '0' && str[0] <= '9'){
  				values_st.push(stod(str));
  			}else if(ops.find(str) != ops.end()){
  				while(!op_st.empty() && precedence[op_st.top()] >= precedence[str]){
  					apply_operation();
  				}
  				op_st.push(str);
  			}
  		}

  		while(!op_st.empty()){
  			apply_operation();
  		}

  		cout << "= " << values_st.top() << endl;

  		return 0;
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
	Solution solution;
    return 0;
}



