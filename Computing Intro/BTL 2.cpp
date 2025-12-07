// Source : 
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define pii  pair<int,int>
#define fi   first
#define se   second
#define ve   vector
#define vi   ve<int>
#define vll  ve<ll>
#define el   '\n'
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define __builtin_popcount __builtin_popcountll
template<class T> bool minimize(T &a, T b){ return (a > (b) ? a = (b), 1 : 0); }
template<class T> bool maximize(T &a, T b){ return (a < (b) ? a = (b), 1 : 0); }
template<class T> T Abs(const T &x) { return (x<0?-x:x);}

const int N = 1e6 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

using namespace std;

void convertString(string &S){
    REP(i, S.size()) if ('A' <= S[i] && S[i] <= 'Z')
    	S[i] += (int) 'a' - 'A';
}

bool checkValid(string S){
    for (char c : S) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'p' || c == 'k' || c == 'h' || c == 'l' || c == 'm' || c == 'n' || c == 'w' || c == ' ' || (int) c == 39 )
        	continue;
        return 0;
    }
    return 1;
}

bool checkConsonant(char x){
    return x == 'p' || x == 'k' || x == 'h' || x == 'l' || x == 'm' || x == 'n' || x == 'w';
}
bool checkVowel(char y){
    return y == 'a' || y == 'e' || y == 'i' || y == 'u' || y == 'o';
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	#define NAME "BTL 2"
	if (fopen(NAME".inp", "r")){
		freopen(NAME".inp", "r", stdin);
   		freopen(NAME".out", "w", stdout);
	}

    string S; getline(cin, S);
    string initial = S;
    
    convertString(S); 
    
    if (!checkValid(S)){
        cout << initial << " contains invalid characters." << endl;
        return 0;
    }
    
    REP(i, S.size()){
        if (S[i] == ' ' || (int) S[i] == 39){
            cout << S[i];
            continue;
        }

        if (checkConsonant(S[i])){
            char c = S[i];
            if(c == 'p' || c == 'k' || c == 'h' || c == 'l' || c == 'm' || c == 'n')
                cout << c;
            else if (c == 'w'){
                if(i==0)
                    cout<< 'w';
                else{
                    char prev = S[i - 1];
                    if (prev == 'a' || prev == 'o' || prev == 'u')
                        cout << 'w';
                    else if (prev == 'e' || prev == 'i')
                        cout << 'v';
                    else
                        cout << 'w'; 
                }
            }
        }
        else if(checkVowel(S[i])){
            char v = S[i];
            if (v == 'a'){
                if (i != (int) S.length() - 1){
                    char next = S[i + 1];
                    if (next == 'i' || next == 'e'){
                        cout << "eye"; i++;
                    }
                    else if (next == 'u' || next == 'o'){
                        cout << "ow"; i++;
                    }
                    else
                        cout << "ah";
                }
                else
                    cout << "ah";
            }
            else if (v == 'e'){
                if (i != (int) S.length() - 1){
                    char next = S[i + 1];
                    if (next == 'i'){
                        cout << "ay"; i++;
                    }
                    else if (next == 'u'){
                        cout << "eh-oo"; i++;
                    }
                    else
                        cout << "eh";
                }
                else
                    cout << "eh";
            }
            else if (v == 'i'){
                if (i != (int) S.length() - 1){
                    char next = S[i + 1];
                    if (next == 'u'){
                        cout << "ew";
                        i++;
                    }
                    else
                        cout << "ee";
                }
                else
                    cout << "ee";
            }
            else if (v == 'o'){
                if (i != (int) S.length() - 1){
                    char next = S[i + 1];
                    if (next == 'i'){
                        cout << "oy"; i++;
                    }
                    if (next == 'u'){
                        cout << "ow"; i++;
                    }
                    else
                        cout << "oh";
                }
                else
                    cout << "oh";
            }
            else if (v == 'u'){
                if (i != (int) S.length() - 1){
                    char next = S[i + 1];
                    if (next == 'i'){
                        cout << "ooey";
                        i++;
                    }
                    else
                        cout << "oo";
                }
                else
                    cout << "oo";
        	}

	        if (i != (int) S.length() - 1){
	            char nextChar = S[i + 1];
	            if (nextChar == ' ' || (int) nextChar == 39) {}
	            else
	                cout << "-";
	        } 
    	}
    }

    cerr << "\nTime used: " << clock() << "ms\n";
    return 0;
}