#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

void replace_str(string& str,char cR,char Rc){
	for(int index=0;index<str.length();index++){
		if(str[index]==cR)
			str[index]=Rc;
		}
}

void URLify(string& str,int n){
	int len=str.length();
	cout<<n<<"*****"<<len<<endl;
	while(n-1 >= 0){
		--n;
		if(str[n] == ' '){
			str[--len]='0';str[--len]='2';str[--len]='%';
		}else{
			str[--len]=str[n];
		}
	}
}
bool checkStr(string input){
	map<char,int> mp;
	int filler_cnt=0;
	for(int ind=0;ind<input.length();ind++){
		if(input[ind] == ' ')
			filler_cnt++;
		else
			mp[input[ind]]++;
	}
	for(map<char,int>::iterator itr=mp.begin();itr != mp.end();itr++){
		if(mp[itr->first]%2 != 0 ){
			if(filler_cnt <= 0)
				return false;
			filler_cnt--;
		}
	}
	return true;
}
bool oneWayStr(const string& str1,const string& str2){
	auto len1=str1.length(),len2=str2.length();
	bool oneWay=false;
	if(len1 == len2){
		for(int ind=0;ind<len1;ind++){
			if(str1[ind] != str2[ind]){
				if(oneWay)
					return false;
				oneWay=true;
			}
		}
	}else if(len1 > len2){
		int ind1=0,ind2=0;
		for(;ind2<len2;){
			cout<<str1[ind1]<<"-"<<str2[ind2];
			if(str1[ind1] != str2[ind2]){ cout<<" NOT MATCHED\n";
				if(ind1+1 < len2){
					if(str1[ind1+1] == str2[ind2]){
						oneWay=true;
						ind1 += 1;
					}else{ return false;}
				}else{ //Last character mismatch
					if(oneWay)
						return false;
					oneWay=true;
				}
			}else{ cout<<" MATCHED\n";
				ind1++;
				ind2++;
			}
		}
	}else{
		int ind1=0,ind2=0;
                for(;ind1<len1;){
                        cout<<str1[ind1]<<"-"<<str2[ind2];
                        if(str1[ind1] != str2[ind2]){ cout<<" NOT MATCHED\n";
                                if(ind2+1 < len1){
                                        if(str2[ind2+1] == str1[ind1]){
                                                oneWay=true;
                                                ind2 += 1;
                                        }else{ return false;}
                                }else{ //Last character mismatch
                                        if(oneWay)
                                                return false;
                                        oneWay=true;
                                }
                        }else{ cout<<" MATCHED\n";
                                ind1++;
                                ind2++;
                        }
                }

	}
return true;
}
string getCompressString(const string& str){
	int len1=str.length(),index=0;
	string out;
	stringstream ss;
	while(index < len1){
		int cnt=1;
		while(index+1 < len1 && str[index] == str[index+1]){
			cnt++;
			index++;
		}
		ss<<str[index];
		ss<<cnt;
		index++;
		//out.push_back(str[index]);
		//out.push_back(to_string(cnt));
	}
	ss>>out;
	if(out.length() > len1)
		return str;
	return out;
}
int main(){
/*string str="Phanindra";
replace_str(str,'a','~');
string URL="Mr John Smith    ";
URLify(URL,13);
cout<<URL<<endl;
cout<<checkStr("hellz e llo")<<endl;
string val1="pale",val2="pake";
cout<<val1<<"-"<<val2<<"***"<<oneWayStr(val1,val2)<<endl;*/
string input="abcd";
cout<<input<<"'s comppressed string is : "<<getCompressString(input)<<endl;
}
