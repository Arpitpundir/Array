class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = strs.size();
        string encodedString = "";
        for(int i=0;i<n;i++){
            int currStrLen = strs[i].size();
            encodedString+=(to_string(currStrLen)+"/"+strs[i]);
        }
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.size();
        vector<string> ans;
        for(int i=0;i<n;){
          // check for next /
            int j = i+1;
            while(s[j] != '/') j++;
            // get the length of the next string
            // which is characters between i and j
            int lenOfNxtStr = stoi(s.substr(i, j-i));
            // get the next string
            // which is characters between j+1 and j+1+lenOfNxtStr-1
            ans.push_back(s.substr(j+1, lenOfNxtStr));
            // update i
            // which would be j+1+lenOfNxtStr
            i = j+1+lenOfNxtStr;
        }

        return ans;
    }
};