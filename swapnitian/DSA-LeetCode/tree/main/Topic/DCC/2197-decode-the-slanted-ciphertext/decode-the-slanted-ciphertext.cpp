class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size()/rows ;
        vector<vector<char>> v(rows , vector<char>(cols , '.')) ;

        int idx = 0 ;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                v[i][j] = encodedText[idx] ;
                idx++ ;
            }
        }
        // now we will form orgText string using simulation -- 
        string originalText = "" ;

        for(int j = 0 ; j < cols ; j++){
            int c = j ;
            for(int i = 0 ; i < rows && c < cols ; i++){
                originalText += v[i][c] ;
                c++ ;
            }
        }

        // remove the extraspace from originalText ;

        for(int k = originalText.size()-1 ; k > 0 ; k--){
            if(originalText[k] == ' '){
                originalText.pop_back() ;
            }else break ;
        }

        return originalText ;
    }
};