class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> h ( matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix[0].size();i++){
            int count = 0;
            for(int j=0;j<matrix.size();j++){
                
                if(matrix[j][i] == '1'){
                    count ++;
                }else{
                    count=0;
                }
                h[j][i] = count;
            }
        }
        
        // for(auto r:h){
        //     for(auto rr:r)
        //         cout << rr << " ";
        //     cout << endl;
        // }
        int max_area = 0;
        for(int i=0;i<h.size();i++){
            stack<int> s;
            h[i].push_back(0);
            for(int j=0;j<h[i].size();j++){
                //cout << "now j: " << j << " h: " << h[i][j] << " ";
                while(!s.empty() && h[i][s.top()] >= h[i][j]){
                    //cout << " cur_h: " << h[i][s.top()] << " " ;
                    int cur_idx = s.top();
                    s.pop();
                    int width = s.empty() ? j : j-s.top()-1;
                    //cout << " width: " << width << " area: " << h[i][cur_idx]*width << " "; 
                    max_area = max(max_area, h[i][cur_idx]*width);
                }
                s.push(j);
                //cout << endl;
            }
            
        }
        
        return max_area;
    }
};
