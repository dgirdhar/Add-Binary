class Solution {
public:
    char sum(char a, char b, char &carry) {
        char res = '0';
        
        if (a == '0' && b =='0') {
            if (carry == '0') {
                res = '0';
            }
            else {
                res = '1';
                carry = '0';
            }
        }
        else if (a == '1' && b == '0') {
            if (carry == '0') {
                res = '1';
            }
            else {
                res = '0';
                carry = '1';
            }
        }
        else if (a == '0' && b == '1') {
            if (carry == '0') {
                res = '1';
            }
            else {
                res = '0';
                carry = '1';
            }
        }
        else {
            if (carry == '0') {
                res = '0';
                carry = '1';
            }
            else {
                res = '1';
                carry = '1';
            }
        }
        
        return res;
    }
    string addBinary(string a, string b) {
        string response = "";
        
        char carry = '0';
        
        int length = a.size() > b.size() ? a.size() : b.size();
        int aIndex = a.size() - 1;
        int bIndex = b.size() - 1;
        
        for (int i = 0; i < length; ++i) {
            char numA = '0';
            char numB = '0';
            char tempResponse = '0';
            
            if (i < a.size()) {
                numA = a[aIndex--];
            }
            
            if (i < b.size()) {
                numB = b[bIndex--];
            }
            
            char result = sum(numA, numB, carry);
            
            response = result + response;
        }
        
        if (carry == '1') {
            response = "1" + response;
        }
        
        return response;
    }
};
