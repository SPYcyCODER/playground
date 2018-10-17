#include <iostream>
#include <string>

int main(){
std::string str("discuss.leetcode.com");
std::size_t fnd=str.find(".");
while(fnd != std::string::npos){
	std::cout<<fnd<<"------"<<str<<std::endl;
	str=str.substr(fnd+1);
	fnd=str.find(".");
	if(fnd == std::string::npos){
		std::cout<<fnd<<"------"<<str<<std::endl;
		break;	
	}
}
}
