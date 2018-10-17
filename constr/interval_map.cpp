#include <assert.h>
#include <map>
#include <limits>
#include <iostream>
#include <vector>
using namespace std;

template<class K, class V>
class interval_map {
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd). 
    // Overwrite previous values in this interval. 
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval 
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval, 
    // and assign must do nothing.
void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        //begin value must be less than end value
        if(!(keyBegin < keyEnd))
            return;
        
        /*Consecutive sets shouldn't be having same values*/
        //block 1 for previous set value check
        auto lBegItr=m_map.lower_bound(keyBegin);
        if(lBegItr != m_map.begin()){
            auto prevBegItr=lBegItr;
            prevBegItr--;
            if(prevBegItr->second == val){
                return;
            }
        }
        
        //block 2 for next set value check -in case, map entry is falls between two sets
        auto uEndItr=m_map.upper_bound(keyEnd);
        if(uEndItr != m_map.end()){
            if(uEndItr->second == val){
                return;
            }
        }
        
        //Inserting value to the interval
        for(auto key=keyBegin;key<keyEnd;key++){
            m_map[key]=val;
        }
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
    void print(){
        for(auto itr:m_map){
            cout<<itr.first<<" "<<itr.second<<endl;
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.
void IntervalMapTest(){
    interval_map<unsigned int, char> int_map('x');
    int_map.assign(1, 3, 'A');
    int_map.assign(3, 6, 'B');
    int_map.assign(6, 10, 'C');
    int_map.assign(7, 9, 'P');
    int_map.print();
}
int main() {
    IntervalMapTest();/*
    int myints[] = {2,15,30,30,20,10,10,20};
    std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
    
    std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
    
    std::vector<int>::iterator low,up;
    low=std::lower_bound (v.begin(), v.end(), 5); //          ^
    up= std::upper_bound (v.begin(), v.end(), 5); //                   ^
    
    std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';*/
}
