const int k = 16;
const int N = 1e5;
const int ZERO = 0; // ZERO + x = x + ZERO = x (for any x)

long long table[N][k + 1]; // k + 1 because we need to access table[r][k]
int Arr[N];

int main()
{
    int n, L, R, q;
    cin >> n; // array size
    for(int i = 0; i < n; i++)
        cin >> Arr[i];

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {    //this for loop condition can be 
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
    }

    cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        long long answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = answer + table[L][j];
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        cout << answer << endl;
    }
    return 0;
}





//Range-Minimum-Query




const int k = 16;
const int N = 1e5;
const int ZERO = 1e9 + 1; // min(ZERO, x) = min(x, ZERO) = x (for any x)

int table[N][k + 1]; // k + 1 because we need to access table[r][k]
int Arr[N];

int main()
{
    int n, L, R, q;
    cin >> n; // array size
    for(int i = 0; i < n; i++)
        cin >> Arr[i]; // between -10^9 and 10^9

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        int answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = min(answer, table[L][j]);
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        cout << answer << endl;
    }
    return 0;
}




//Range-gcd-query

const int k = 16;
const int N = 1e5;
const int ZERO = 0; // gcd(ZERO, x) = gcd(x, ZERO) = x (for any x > 0)

int table[N][k + 1]; // k + 1 because we need to access table[r][k]
int Arr[N];

int main()
{
    int n, L, R, q;
    cin >> n; // array size
    for(int i = 0; i < n; i++)
        cin >> Arr[i]; // between 1 and 10^9

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        int answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = __gcd(answer, table[L][j]);
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        cout << answer << endl;
    }
    return 0;
}


