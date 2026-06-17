
class Solution {
public:

    int calPoints(vector<string>& operations) {
        stack <int> records;
        vector<int> cumrecords;
        for(string s:operations){
            if(s=="+"){
                int a = records.top();
                records.pop();
                int b = records.top();
                records.push(a);
                cout << a+b << endl;
                records.push(a+b);
                cumrecords.push_back(a+b);
            }
            else if(s == "C"){
                int a = records.top();
                records.pop();
                cumrecords.pop_back();
            }
            else if(s == "D"){
                int a = records.top();
                records.push(a*2);
                cumrecords.push_back(a*2);
            }
            else{
                records.push(stoi(s));
                cumrecords.push_back(stoi(s));
            }
        }
        
        return accumulate(cumrecords.begin(),cumrecords.end(),0);

    }
};

