string lastSubstring(string s) {
    int left=0;
    int right=left+1;
    int step=0;
    while(right + step <s.size()){
        if(s[left+step]<s[right+step]){
            left=right;
            right=left+1;
            step=0;                
        }
        else if(s[left+step]==s[right+step]){
            step++;
        }
        else{ // s[left+step]>s[right+step]
            right+=step+1;
            step=0;
        }
    }
    return s.substr(left, s.size()-left);
}