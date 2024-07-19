#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    //creation
    unordered_map<string,int> m;

    //insertion

    //1
    pair<string,int> p = make_pair("babbar", 3);
    m.insert(p);

    //2
    pair<string,int> pair2("love", 2);

    //3
    m["mera"]=1;

    //seaRCHING
    cout<<m["mera"] <<endl; //will give one as output
    cout<<m.at("babbar")<<endl;


    cout<<m["unknown"] <<endl; //will give output zero
    cout<<m.at("unknown")<<endl; //will give error until above line is used or unknow is created

    //to check presence
    cout<< m.count("love") << endl;

    //to erase
    m.erase("love");
    //size will also dec by 1

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //or use iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it!=m.end()){
        cout<<it->first << " "<< it->second<< endl;
        it++;
    }




}
/*
### Advantages of Hash Tables

1. **Fast Lookup:** Average time complexity for search, insert, and delete
 operations is \(O(1)\).
2. **Efficient:** Requires less memory compared to some other data structures.
3. **Versatile:** Can handle a wide variety of data types and is used in many
 applications, such as databases, caches, and sets.

### Disadvantages of Hash Tables

1. **Collisions:** While various techniques exist to handle collisions,
 they can degrade performance if not managed properly.
2. **Hash Function Dependence:** The efficiency of a hash table heavily depends
 on the quality of the hash function used.
3. **Not Ordered:** Hash tables do not maintain the order of elements,
 which may be a disadvantage in some applications. 
*/