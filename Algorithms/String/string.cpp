
bool isPalindrome (const string& s){
    long long aux = s.size()/2+1,
            sz = s.size()-1;
    for(int i = 0; i < aux;i++){
        if(s[i] != s[sz-i])
            return false;
    }

    return true;
}
