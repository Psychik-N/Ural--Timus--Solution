#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 8;

char val[maxn];
LL color[26], C[maxn][30];

inline bool cmp(LL a, LL b)
{
    return a > b;
}

int main()
{

    memset(C, 0, sizeof C);
    for(int i = 0; i <= 26; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    #ifdef LOCAL
    freopen("a.txt", "r", stdin);
    //freopen("b.txt", "w", stdout);
    int T = 3;
    while(T--){
    #endif // LOCAL
    memset(color, 0, sizeof color);
    LL sz = 0, num = 1, k;
    scanf("%s", val);
    scanf("%I64d", &k);
    int len = strlen(val);

    for(int i = 0; i < len; i++)
        color[val[i] - 'a']++;

    sort(color, color + 26, cmp);

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < k; i++){
        sz += color[i];
        if(color[k-1] !=0 && color[i] == color[k-1]) cnt1++;

    }
    for(int i = 0; i < 26; i++){
        if(color[k-1] != 0 && color[i] == color[k-1]) cnt2++;
    }
    if(color[k-1] != 0){
        num = C[cnt2][cnt1];
    }
    printf("%I64d %I64d", sz, num);
    #ifdef LOCAL
    printf("\n");
    }
    #endif // LOCAL
    return 0;
}