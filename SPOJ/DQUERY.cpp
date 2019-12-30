#include <bits/stdc++.h>
using namespace std;

int N, Q;

// Variables, that hold current "state" of computation
long long current_answer=0;
long long cnt[1000005];
//map<long long, long long> cnt; 
// Array to store answers (because the order we achieve them is messed up)
long long answers[200005];
int BLOCK_SIZE;
int arr[200005];

// We will represent each query as three numbers: L, R, idx. Idx is 
// the position (in original order) of this query.
pair< pair<int, int>, int> queries[200005];


// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

// When adding a number, we first nullify it's effect on current
// answer, then update cnt array, then account for it's effect again.

int main()
{
    cin.sync_with_stdio(false);
 //   cin >> N;
    scanf("%d",&N);
    BLOCK_SIZE = static_cast<int>(sqrt(N));

    // Read input array
    for(int i = 0; i < N; i++)
        scanf("%d",&arr[i]);
//cin >> arr[i];
  //  cin>>Q;
    scanf("%d",&Q);
    // Read input queries, which are 0-indexed. Store each query's 
    // original position. We will use it when printing answer.
    for(int i = 0; i < Q; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
 //       cin>>x>>y;
        queries[i].first.first =x-1;
        queries[i].first.second= y-1;
        queries[i].second = i;
    }

    // Sort queries using Mo's special comparator we defined.
    sort(queries, queries + Q, mo_cmp);

    // Set up current segment [mo_left, mo_right].
    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < Q; i++) {
        // [left, right] is what query we must answer now.
        int left = queries[i].first.first;
        int right = queries[i].first.second;

        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while(mo_right < right) {
            mo_right++;
            if(cnt[arr[mo_right]]==0)
                current_answer++;
            cnt[arr[mo_right]]++;
         //   current_answer=cnt.size();
          //  add(arr[mo_right]);
        }
        while(mo_right > right) {
            cnt[arr[mo_right]]--;
            if(cnt[arr[mo_right]]<=0)
                //cnt.erase(arr[mo_right]);
                current_answer--;
          //  remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            cnt[arr[mo_left]]--;
            if(cnt[arr[mo_left]]<=0)
               // cnt.erase(arr[mo_left]);
                current_answer--;
           // remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            if(cnt[arr[mo_left]]==0)
                current_answer++;
            cnt[arr[mo_left]]++;
          //  add(arr[mo_left]);
        }

        // Store the answer into required position.
        answers[queries[i].second] = current_answer;
    }

    // We output answers *after* we process all queries.
    for(int i = 0; i < Q; i++)
    //    cout << answers[i] << "\n";
        printf("%lld\n", answers[i] );
    return 0;
}