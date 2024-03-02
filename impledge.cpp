// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

// header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // for pbds
#include <ext/pb_ds/tree_policy.hpp>

// namespace
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

/* ordered set*/
template <class T, class cmp = less_equal<T>>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/* ordered map*/
template <class key, class value, class cmp = less_equal<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
/* find_by_order(k)  returns iterator to kth element starting from 0;
 * order_of_key(k) returns count of elements strictly smaller than k;*/

/* min heap*/
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;

// Constants
#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007

// Aliases
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;

// macros
#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define ppc __builtin_popcount
#define parity(x) __builtin_parity(x) // gives true for odd and false for even
#define ppcll __builtin_popcountll
#define msb(x) 63 - __builtin_clzll(x) // gives the most significant bit of the number
#define sz(x) (int)x.size()
#define F first
#define acc accumulate
#define S second
#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define kickstart(x)                 \
    {                                \
        cout << "Case #" << x << ":" \
             << " ";                 \
    }
#define hi cout << "hi" << endl

// Mathematical functions
ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll gcdX(ll a, ll b, ll &x, ll &y) // gcd extended
{
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll lcm(ll a, ll b)
{
    return ((ll)a * b) / gcd(a, b);
}

// modular exponentiation
ll modpow(ll x, ll n, ll m = MOD)
{
    if (x == 0 && n == 0)
        return 0; // undefined case
    ll res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % m) * 1ll * (x % m)) % m;
        }
        x = ((x % m) * 1ll * (x % m)) % m;
        n >>= 1;
    }
    return res;
}

ll modinv(ll x, ll m = MOD)
{
    return modpow(x, m - 2, m);
}

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/* ----------------------------------Things get better by time, hope for the best-----------------*/
// have a winner mentallity
// Brute try krna random idea me

struct Hashing
{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    Hashing(string a)
    {
        s = a;
        n = sz(s);
        primes = sz(hashPrimes);
        hashValues = vector<vector<ll>>(primes, vector<ll>(n));
        powersOfBase = vector<vector<ll>>(primes, vector<ll>(n + 1));
        for (int i = 0; i < primes; i++)
        {
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
        }
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    void addCharacter(char ch)
    {
        s += ch;
        n = sz(s);
        for (int i = 0; i < primes; i++)
        {
            while (sz(powersOfBase[i]) < sz(s))
            {
                powersOfBase[i].pb((powersOfBase[i].back() * base) % hashPrimes[i]);
            }
        }
        for (int i = 0; i < primes; i++)
        {
            while (sz(hashValues[i]) < sz(s))
            {
                if (sz(hashValues[i]) == 0)
                {
                    hashValues[i].pb((s[0] - 'a' + 1LL) % hashPrimes[i]);
                }
                else
                {
                    ll extraHash = hashValues[i].back() + ((s.back() - 'a' + 1LL) * powersOfBase[i][sz(s) - 1]) % hashPrimes[i];
                    hashValues[i].pb((extraHash + hashPrimes[i]) % hashPrimes[i]);
                }
            }
        }
    }
    vector<ll> substringHash(int l, int r)
    { // extra O(log) factor
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            ll val3 = ((val1 - val2) % hashPrimes[i] + hashPrimes[i]) % hashPrimes[i];
            ll val4 = modinv(powersOfBase[i][l], hashPrimes[i]);
            hash[i] = ((val3 * val4) % hashPrimes[i] + hashPrimes[i]) % hashPrimes[i];
        }
        return hash;
    }
    bool compareSubstrings(int l1, int r1, int l2, int r2)
    { // use this for comparing strings faster
        if (l1 > l2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        for (int i = 0; i < primes; i++)
        {
            ll m = hashPrimes[i];
            ll val1 = ((hashValues[i][r1] - (l1 > 0 ? hashValues[i][l1 - 1] : 0LL)) % m + m) % m;
            ll val2 = ((hashValues[i][r2] - (l2 > 0 ? hashValues[i][l2 - 1] : 0LL)) % m + m) % m;
            if (((val1 * powersOfBase[i][l2 - l1]) % m + m) % m != val2)
            {
                return false;
            }
        }
        return true;
    }
};

void solve(int testcase)
{
    // kickstart(testcase);
    // debug(testcase);
    vector<string> a;
    string s;
    set<vector<int>> st;
    while (cin >> s)
    {
        a.pb(s);
        Hashing hs(s);
        st.insert(hs.substringHash(0, sz(s) - 1));
    }
    vector<string> compoundedWord;
    auto check = [&](Hashing &hs, int i, int j, auto &&check) -> bool
    {
        if (i >= sz(hs.s))
        {
            return (j == sz(hs.s));
        }
        bool ans = 0;
        for (; i < sz(hs.s); i++)
        {
            if (st.count(hs.substringHash(j, i)))
            {
                ans |= check(hs, i + 1, i + 1, check);
            }
        }
        return ans;
    };
    for (auto s : a)
    {
        Hashing hs(s);
        st.erase(st.find(hs.substringHash(0, sz(s) - 1)));
        if (check(hs, 0, 0, check))
        {
            compoundedWord.pb(s);
        }
        st.insert(hs.substringHash(0, sz(s) - 1));
    }
    sort(all(compoundedWord), [&](const string &a, const string &b)
         { return (sz(a) > sz(b)); });
    if (!sz(compoundedWord))
    {
        cout << "Not Found" << endl;
        return;
    }
    // cout << "sz(compoundedWord): " << sz(compoundedWord) << endl;
    // cout << compoundedWord << endl;
    cout << "Longest Compound Word " << compoundedWord[0] << endl;
    cout << "Second Longest Compound Word " << compoundedWord[1] << endl;
}

int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int n = 1;
    // cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Time taken : " << ((long double)duration.count()) / ((long double)1e9) << "s " << endl;
    return 0;
}
