typedef long long ll;

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long solution(int w,int h) {
    //if(w == h) return w * h - w;
    
    int cnt = gcd(w, h);
    int x = w / cnt;
    int y = h / cnt;
    
    return ((ll)w * (ll)h) - ((ll)x + (ll)y - 1) * (ll)cnt;
}